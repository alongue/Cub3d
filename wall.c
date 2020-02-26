/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:25:22 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/17 15:32:54 by alongcha         ###   ########.fr       */
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

void			set_north_wall(t_wall *wall, t_segment left, t_segment right) //la valeur x et y du wall precise l'endroit du coin en haut a gauche du wall
{
	//t_wall	wall;

	wall->x = left.a.x;
	wall->left = dup_segment(left);
	wall->right = dup_segment(right);
	wall->color = 0xCECECE; //gris
	//return (wall);
}


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

int				replace_wall(t_wall *wall, t_player player)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = wall->left.a.x - player.x// on prend ce segment qu'on va ensuite clipper
	y1 = wall->left.a.y - player.y
	x2 = wall->right.a.x - player.x// on prend ce segment qu'on va ensuite clipper
	y2 = wall->right.a.y - player.y
	wall->newleft.a.x = (int)(x1 * cos(-player.angle)
							 - y1 * sin(-player.angle));
	wall->newleft.a.y = (int)(y1 * cos(-player.angle)
							 + x1 * sin(-player.angle));
	wall->newright.a.x = (int)(x2 * cos(-player.angle)
							 - y2 * sin(-player.angle));
	wall->newright.a.y = (int)(y2 * cos(-player.angle)
							 + x2 * sin(-player.angle));
}

bool			do_display_wall(t_wall *wall)
{
	double	tanwall;

	tanwall = (wall->newleft.a.y - wall->newright.a.y) / (wall->newleft.a.x - wall->newright.a.x);
	if (wall->newleft.a.x < ZMIN && wall->newright.a.x < ZMIN)
		return (false);
	if (wall->newleft.a.x < ZMIN)
	{
		wall->newleft.a.y += (ZMIN - wall->newleft.a.x) * tanwall;
		wall->newleft.a.x = ZMIN;
	}
	if (wall->newright.a.x < ZMIN)
	{
		wall->newright.a.y += (ZMIN - wall->newright.a.x) * tanwall;
		wall->newright.a.x = ZMIN;
	}
	wall->newleft.a.x = min(9999, wall->newleft.a.x);
	wall->newright.a.x = min(9999, wall->newright.a.x);
	return (true);
}

int				display_wall(t_data *data, t_wall wall)
{
	int		i;
	int		ptraddr;
	int		ptraddrend;

	initbe4display(&wall, &i);
	while (++i <= wall.leftcl.a.x)
	{
		if (!wall.coldone[i])
		{
			wall.topcl = fmax(wall.top, 0);
			wall.botcl = fmin(wall.bot, 200);
			ptraddr = /*(int)*/wall.realtop * DEFX + i;
			ptraddrend = /*(int)*/wall.realbot * DEFX + i;
			while (ptraddr < ptraddrend)
			{
				wall.img_data[ptraddr] = wall.color;
				ptraddr += 320;
			}
			wall.coldone[i] = true;
			wall.nbcoldone++;
		}
		wall.top += wall.deltatop;
		wall.bot += wall.deltabot;
	}
	return (EXIT_SUCCESS);
}


/*
**		*(img.data + (x * 4 + 2) + (img.size * y)) = (unsigned)color.r;
**		*(img.data + (x * 4 + 1) + (img.size * y)) = (unsigned)color.g;
**		*(img.data + (x * 4 + 0) + (img.size * y)) = (unsigned)color.b;
*/
