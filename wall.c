/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:25:22 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/12 16:19:03 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdio.h>
#include <stdlib.h>

# define ZMIN 1 // derriere zmin, c'est derriere le joueur (on prend 1 pour ne laisser aucun point egale a 0 sinon div by 0)

//Ce fichier va me premettre de creer des murs et d'ajouter des attributs a ces murs

/*void			set_dim_north_wall(t_wall *wall, int width, int height) //la valeur x et y du wall precise l'endroit du coin en haut a gauche du wall
{
	//t_wall	wall;

	wall->width = width;
	wall->height = height;
	wall->color = 0xCECECE; //gris
	//return (wall);
}*/


// ------- !!! DEPRECATED !!! ------- 

/*void			set_north_wall(t_wall *wall, t_segment left, t_segment right, unsigned int color) //la valeur x et y du wall precise l'endroit du coin en haut a gauche du wall
{
	//t_wall	wall;

	wall->left = dup_segment(left);
	wall->right = dup_segment(right);
	wall->color = color; //gris
	//return (wall);
}*/


// ------- !!! DEPRECATED !!! ------- 

/*int			display_wall_def(t_data *data, t_wall wall) //la valeur x et y du wall precise l'endroit du coin en haut a gauche du wall
{
	int	x;
	int	y;

	x = wall.width;
	y = wall.height;
	while (x > 0)
	{
		y = wall.height;
		while (y > 0)
		{
			mlx_pixel_put(data->ptr, data->window, wall.x + x, wall.y + y, wall.color);
			y--;
		}
		mlx_pixel_put(data->ptr, data->window, wall.x + x, wall.y, wall.color);
		x--;
	}
	return (EXIT_SUCCESS);
}*/


// ------- !!! DEPRECATED !!! ------- 

/*int				display_wall(t_data *data, t_wall wall)
{
	int	bpp;
	int	size_line;
	int	endian;
	int	x;
	int	y;

	wall.img = mlx_new_image(data->ptr, wall.width, wall.height);
	wall.img_data = (int *)mlx_get_data_addr(wall.img, &bpp, &size_line, &endian);
	x = -1;
	y = -1;
	while (++x < wall.width)
	{
		y = -1;
		while (++y < wall.height)
			wall.img_data[wall.height * y + x] = wall.color;
	}
	mlx_put_image_to_window(data->ptr, data->window, wall.img, wall.x, wall.y);
	return (EXIT_SUCCESS);
}*/

void			replace_poly(t_polygon *polygon, t_player player)
{
	t_point	a;
	t_point	b;
//	t_point	tmp;

	get_extremity(polygon->segment, &a, &b);
	translate_point(&a, -player.x, -player.z);// on prend ce segment qu'on va ensuite clipper
	translate_point(&b, -player.x, -player.z);// on prend ce segment qu'on va ensuite clipper
	printf("(dans replace_poly) polygon->newsegment.a.y = %f\tet\tb.y = %f\na.x = %f\tet\tb.x = %f\n", a.y, b.y, a.x, b.x);
	polygon->newsegment = get_segmenti(a.x * cos(-player.angle)
									- a.y * sin(-player.angle),
									a.y * cos(-player.angle)
							 		+ a.x * sin(-player.angle),
									b.x * cos(-player.angle)
									 - b.y * sin(-player.angle),
									b.y * cos(-player.angle)
									+ b.x * sin(-player.angle));
	/*printf("(dans replace_poly) polygon->segment.a.y = %f\tet\tb.y = %f\na.x = %f\tet\tb.x = %f\n", polygon->segment.a.y, polygon->segment.b.y, polygon->segment.a.x, polygon->segment.b.x);
	printf("(dans replace_poly) polygon->newsegment.a.y = %f\tet\tb.y = %f\na.x = %f\tet\tb.x = %f\n", polygon->newsegment.a.y, polygon->newsegment.b.y, polygon->newsegment.a.x, polygon->newsegment.b.x);
	if (((player.angle > 3 * M_PI / 2 && player.angle <= 2 * M_PI) || (player.angle >= 0 && player.angle < M_PI / 2)) && ((polygon->newsegment.a.y > polygon->newsegment.b.y && polygon->newsegment.a.x == polygon->newsegment.b.x) ||
		(polygon->newsegment.a.y == polygon->newsegment.b.y && (
																!(polygon->newsegment.a.x < polygon->newsegment.b.x && polygon->newsegment.a.y < 0) &&
																!(polygon->newsegment.a.x > polygon->newsegment.b.x && polygon->newsegment.a.y > 0))))) ||
		(((player.angle >= M_PI / 2 && player.angle < 3 * M_PI / 2) && ((polygon->newsegment.a.y < polygon->newsegment.b.y && polygon->newsegment.a.x == polygon->newsegment.b.x)||
		(polygon->newsegment.a.y == polygon->newsegment.b.y && (
																!(polygon->newsegment.a.x > polygon->newsegment.b.x && polygon->newsegment.a.y > 0) &&
																!(polygon->newsegment.a.x < polygon->newsegment.b.x && polygon->newsegment.a.y < 0)))))))
	{
		tmp = dup_point(polygon->newsegment.b);
		polygon->newsegment.b = dup_point(polygon->newsegment.a);
		polygon->newsegment.a = dup_point(tmp);
	}
	printf("(dans replace_poly) polygon->newsegment.a.y = %f\tet\tb.y = %f\na.x = %f\tet\tb.x = %f\n", polygon->newsegment.a.y, polygon->newsegment.b.y, polygon->newsegment.a.x, polygon->newsegment.b.x);*/
}

bool			do_display_poly(t_polygon *polygon, t_data data, t_player player)
{
	double	tanpoly;

	if (!raycastx_img(player, polygon))
		return (false);
	if (polygon->newsegment.a.x < ZMIN)
	{
		tanpoly = (polygon->newsegment.a.x - polygon->newsegment.b.x != 0) ?
		(polygon->newsegment.a.y - polygon->newsegment.b.y)
		/ (polygon->newsegment.a.x - polygon->newsegment.b.x) :
		0;
		polygon->newsegment.a.y += (ZMIN - polygon->newsegment.a.x) * tanpoly;
		polygon->newsegment.a.x = ZMIN;
	}
	if (polygon->newsegment.b.x < ZMIN)
	{
		tanpoly = (polygon->newsegment.b.x - polygon->newsegment.a.x != 0) ?
		(polygon->newsegment.b.y - polygon->newsegment.a.y)
		/ (polygon->newsegment.b.x - polygon->newsegment.a.x) :
		0;
		polygon->newsegment.b.y += (ZMIN - polygon->newsegment.b.x) * tanpoly;
		polygon->newsegment.b.x = ZMIN;
	}
	polygon->newsegment.a.x = min(9999, polygon->newsegment.a.x);
	polygon->newsegment.b.x = min(9999, polygon->newsegment.b.x);
	polygon->dodisplay = raycastx(&polygon->wall, polygon, data);
	printf("polygon->dodisplay = %d\n", polygon->dodisplay);
	return (polygon->dodisplay);
}

t_wall			create_wall(t_polygon poly, t_player player, t_data data)
{
	t_wall	wall;

	printf("poly.wall.left.a.x = %f (dans create_wall)\n", poly.wall.left.a.x);
	wall.left = get_segmenti(poly.wall.left.a.x, 0,
							 poly.wall.left.a.x, data.cubside); //on met left.b.x = left.a.x
	wall.right = get_segmenti(poly.wall.right.a.x, 0,
								poly.wall.right.a.x, data.cubside);
	if (player.exist)
	{
		translate_segment(&wall.left, 0, -player.y);
		translate_segment(&wall.right, 0, -player.y);
	}
	raycastfps(&wall, player, poly, data);
	printf("wall.left.a.y (apres la translation) = %f\t\tet\t\tb.y = %f\n", wall.left.b.y, wall.left.a.y);
	set_delta(&wall);
	return (wall);
}

t_wall			dup_wall(t_wall wall)
{
	t_wall	wallcop;

	wallcop.exist = wall.exist;
	wallcop.bpp = wall.bpp;
	wallcop.size_line = wall.size_line;
	wallcop.endian = wall.endian;
	wallcop.bppimg = wall.bppimg;
	wallcop.size_lineimg = wall.size_lineimg;
	wallcop.endianimg = wall.endianimg;
	wallcop.top = wall.top;
	wallcop.topcl = wall.topcl;
	wallcop.bot = wall.bot;
	wallcop.botcl = wall.botcl;
	wallcop.left = wall.left;
	wallcop.leftcl = wall.leftcl;
	wallcop.right = wall.right;
	wallcop.rightcl = wall.rightcl;
	wallcop.deltatop = wall.deltatop;
	wallcop.deltabot = wall.deltabot;
	wallcop.color = wall.color;
	wallcop.img = wall.img;
	wallcop.imgwidth = wall.imgwidth;
	wallcop.imgheight = wall.imgheight;
	wallcop.img_data = wall.img_data;
	wallcop.data_file = wall.data_file;
	return (wallcop);
}

int				display_wall(t_data *data, t_wall wall, t_polygon polygon, t_player player)
{
	int		i;
	int		ptraddr[2];
	double	tanindex;
//	double	cumul;
//	double	anglewallpl;
	int		index;
//	double	realindex;
	double	incr[2];

	//sleep(5);
//	printf("--- JE SUIS DANS LE DISPL WALL ---\n");
	initbe4display(&wall, &i, data);
	ft_memseti(ptraddr, 0, 2);
	ft_memseti(incr, 0, 2);
//	anglewallpl = atan(polygon.btobp / polygon.pdist);
//	cumul = polygon.btobp;
//	realindex = 0;
//	printf("wall.leftcl.a.x = %f\tet\twall.rightcl.a.x = %f\n", wall.leftcl.a.x, wall.rightcl.a.x);
	while (++i <= (int)round(wall.rightcl.a.x))
	{
		//printf("i = %d\n", i);
		if (can_draw(wall, data, i))
		{
			wall.topcl = fmax(wall.top, 0.);
			wall.botcl = fmin(wall.bot, data->win_height);
			tanindex = polygon.newangle + to_rad(90) - player.angleray[i];
			index = (int)round(polygon.pdist * tan(-tanindex) + polygon.btobp) % wall.imgwidth;
//			index = tan(anglewallpl + player.anglerayy * (i - wall.leftcl.a.x)) * polygon.pdist - cumul;
//			cumul += index;
			printf("index = %d\n", index);
			index = (index < 0) ? 0 : index;
//			if (i > index)
//				realindex++;
			incr[0] = wall.imgheight / (wall.bot - wall.top);
			incr[1] = (wall.topcl - wall.top) * incr[0];
			incr[1] = (incr[1] < 0) ? 0 : incr[1];
			ptraddr[0] = (int)(round(wall.topcl) * data->win_width + i);
			ptraddr[1] = (int)(round(wall.botcl) * data->win_width + i);
//			printf("topcl = %f\tet\tbotcl = %f\n", wall.topcl, wall.botcl);
//			printf("(avant la boucle) ptraddr[0] = %d\tet\tptraddr[1] = %d\n", ptraddr[0], ptraddr[1]);
			while (ptraddr[0] < ptraddr[1])
			{
				//get(index, incr[1]);
//				printf("(pdt la boucle) incr[1] = %f\tet\tindex = %d\n", incr[1], index);
				//printf("wall.imgwidth = %d\tet\twall.imgheight = %d\n", wall.imgwidth, wall.imgheight);
				//printf("avant\n");
				wall.img_data[ptraddr[0]] = wall.data_file[(int)(round(incr[1]) * wall.imgwidth + (int)round(index))];
				//printf("pdist = %f\n", polygon.pdist);
				//printf("apres\n");
				incr[1] += incr[0];
				ptraddr[0] += data->win_width;
			}
			//printf("(apres la boucle) ptraddr[0] = %d\tet\tptraddr[1] = %d\n", ptraddr[0], ptraddr[1]);
			data->coldone[i] = true;
		}
		wall.top += wall.deltatop;
		wall.bot += wall.deltabot;
	}
//	printf("Je suis sorti\n");
	return (EXIT_SUCCESS);
}


/*
**		*(img.data + (x * 4 + 2) + (img.size * y)) = (unsigned)color.r;
**		*(img.data + (x * 4 + 1) + (img.size * y)) = (unsigned)color.g;
**		*(img.data + (x * 4 + 0) + (img.size * y)) = (unsigned)color.b;
*/
