/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:25:22 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/10 13:47:45 by alongcha         ###   ########.fr       */
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
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, wall.x + x, wall.y + y, wall.color);
			y--;
		}
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, wall.x + x, wall.y, wall.color);
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

	wall.img = mlx_new_image(data->mlx_ptr, wall.width, wall.height);
	wall.img_data = (int *)mlx_get_data_addr(wall.img, &bpp, &size_line, &endian);
	x = -1;
	y = -1;
	while (++x < wall.width)
	{
		y = -1;
		while (++y < wall.height)
			wall.img_data[wall.height * y + x] = wall.color;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, wall.img, wall.x, wall.y);
	return (EXIT_SUCCESS);
}*/

void			replace_poly(t_polygon *polygon, t_player player)
{
	t_point	*a;
	t_point	*b; //mettre les points en float a mon avis

	a = malloc(sizeof(t_point));
	b = malloc(sizeof(t_point));
	get_extremity(polygon->segment, a, b);
	translate_point(a, -player.x, -player.z);// on prend ce segment qu'on va ensuite clipper
	translate_point(b, -player.x, -player.z);// on prend ce segment qu'on va ensuite clipper
	if (a->y < b->y)
		ft_swap((void *)&a, (void *)&b);
	polygon->newsegment = get_segmenti(a->x * cos(-player.angle)
									- a->y * sin(-player.angle),
									a->y * cos(-player.angle)
							 		+ a->x * sin(-player.angle),
									b->x * cos(-player.angle)
									 - b->y * sin(-player.angle),
									b->y * cos(-player.angle)
									+ b->x * sin(-player.angle));
}

bool			do_display_poly(t_polygon *polygon)
{
	double	tanpoly;

	printf("polygon->newsegment.a.x = %d\n", polygon->newsegment.a.x);
	tanpoly = (polygon->newsegment.a.x - polygon->newsegment.b.x != 0) ?
	(polygon->newsegment.a.y - polygon->newsegment.b.y)
	/ (polygon->newsegment.a.x - polygon->newsegment.b.x) :
	0;
	if (polygon->newsegment.a.x < ZMIN && polygon->newsegment.b.x < ZMIN)
		return ((polygon->dodisplay = false));
	if (polygon->newsegment.a.x < ZMIN)
	{
		polygon->newsegment.a.y += (ZMIN - polygon->newsegment.a.x) * tanpoly;
		polygon->newsegment.a.x = ZMIN;
	}
	if (polygon->newsegment.b.x < ZMIN)
	{
		polygon->newsegment.b.y += (ZMIN - polygon->newsegment.b.x) * tanpoly;
		polygon->newsegment.b.x = ZMIN;
	}
	polygon->newsegment.a.x = min(9999, polygon->newsegment.a.x);
	polygon->newsegment.b.x = min(9999, polygon->newsegment.b.x);
	return (polygon->dodisplay = raycast(polygon));
}

t_wall			create_wall(t_polygon poly, t_player player, t_cub cub)
{
	t_wall wall;

	wall.left = get_segmenti(poly.newsegment.a.x, cub.side,
							 poly.newsegment.a.x, 0);
	wall.right = get_segmenti(poly.newsegment.b.x, cub.side,
								poly.newsegment.b.x, 0);
	if (player.exist)
	{
		translate_segment(&wall.left, 0, -player.y);
		translate_segment(&wall.right, 0, -player.y);
	}
	raycastfps(&wall, player);
	set_delta(&wall);
	printf("wall.left.b.x (apres la translation) = %d\n", wall.left.b.x);
	return (wall);
}

int				display_wall(t_data *data, t_wall wall)
{
	int		i;
	int		ptraddr[2];

	printf("--- JE SUIS DANS LE DISPL WALL ---\n");
	initbe4display(&wall, &i, data);
	printf("wall.leftcl.a.x = %d\n", wall.leftcl.a.x);
	while (++i <= wall.leftcl.a.x)
	{
		if (!wall.coldone[i])
		{
			wall.topcl = fmax(wall.top, 0);
			wall.botcl = fmin(wall.bot, 200);
			ptraddr[0] = /*(int)*/wall.topcl * DEFX + i;
			ptraddr[1] = /*(int)*/wall.botcl * DEFX + i;
			//printf("wall.color = %u\n", wall.color);
			while (ptraddr[0] < ptraddr[1])
			{
				wall.img_data[ptraddr[0]] = wall.color;
				ptraddr[0] += 320;
			}
			wall.coldone[i] = true;
			wall.nbcoldone++;
		}
		wall.top += wall.deltatop;
		wall.bot += wall.deltabot;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, wall.img, wall.leftcl.a.x, wall.leftcl.a.y);
	return (EXIT_SUCCESS);
}


/*
**		*(img.data + (x * 4 + 2) + (img.size * y)) = (unsigned)color.r;
**		*(img.data + (x * 4 + 1) + (img.size * y)) = (unsigned)color.g;
**		*(img.data + (x * 4 + 0) + (img.size * y)) = (unsigned)color.b;
*/
