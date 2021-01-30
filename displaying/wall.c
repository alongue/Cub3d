/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:25:22 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/05 16:21:17 by alongcha         ###   ########.fr       */
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
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = polygon->segment.a.x - player.x;// on prend ce segment qu'on va ensuite clipper
	y1 = polygon->segment.a.y - player.y;
	x2 = polygon->segment.b.x - player.x;// on prend ce segment qu'on va ensuite clipper
	y2 = polygon->segment.b.y - player.y;
	polygon->newsegment.a.x = (int)(x1 * cos(-player.angle)
							 - y1 * sin(-player.angle));
	polygon->newsegment.a.y = (int)(y1 * cos(-player.angle)
							 + x1 * sin(-player.angle));
	polygon->newsegment.b.x = (int)(x2 * cos(-player.angle)
							 - y2 * sin(-player.angle));
	polygon->newsegment.b.y = (int)(y2 * cos(-player.angle)
							 + x2 * sin(-player.angle));
}

int			do_display_poly(t_polygon *polygon)
{
	double	tanpoly;

	tanpoly = (polygon->newsegment.a.y - polygon->newsegment.b.y)
	/ (polygon->newsegment.a.x - polygon->newsegment.b.x);
	if (polygon->newsegment.a.x < ZMIN && polygon->newsegment.b.x < ZMIN)
		return (0);
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
	return (1);
}

t_wall			create_wall(t_polygon poly, t_player player, t_cub cub)
{
	t_wall wall;

	wall.left.a = set_point(poly.newsegment.a.x, cub.wall.realside);
	wall.left.b = set_point(poly.newsegment.a.x, 0);
	wall.right.a = set_point(poly.newsegment.b.x, cub.wall.realside);
	wall.right.b = set_point(poly.newsegment.b.x, 0);
	translate(&wall.left, 0, -player.height);
	translate(&wall.right, 0, -player.height);
	return (wall);
}

int				display_wall(t_data *data, t_wall wall)
{
	int		i;
	int		ptraddr[2];

	initbe4display(&wall, &i, data);
	while (++i <= wall.leftcl.a.x)
	{
		if (!wall.coldone[i])
		{
			wall.topcl = fmax(wall.top, 0);
			wall.botcl = fmin(wall.bot, data->win_height);
			ptraddr[0] = /*(int)*/wall.topcl * DEFX + i;
			ptraddr[1] = /*(int)*/wall.botcl * DEFX + i;
			while (ptraddr[0] < ptraddr[1])
			{
				wall.img_data[ptraddr[0]] = wall.color;
				ptraddr[0] += data->win_width;
			}
			wall.coldone[i] = 1;
			wall.nbcoldone++;
		}
		wall.top += wall.deltatop;
		wall.bot += wall.deltabot;
	}
	mlx_put_image_to_window(data->ptr, data->window, wall.img, wall.leftcl.a.x, wall.leftcl.a.y);
	return (EXIT_SUCCESS);
}


/*
**		*(img.data + (x * 4 + 2) + (img.size * y)) = (unsigned)color.r;
**		*(img.data + (x * 4 + 1) + (img.size * y)) = (unsigned)color.g;
**		*(img.data + (x * 4 + 0) + (img.size * y)) = (unsigned)color.b;
*/
