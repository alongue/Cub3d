/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:25:22 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/17 15:15:11 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdio.h>
#include <stdlib.h>

//Ce fichier va me premettre de creer des murs et d'ajouter des attributs a ces murs

/*void			set_dim_north_wall(t_wall *wall, int width, int height) //la valeur x et y du wall precise l'endroit du coin en haut a gauche du wall
{
	//t_wall	wall;

	wall->width = width;
	wall->height = height;
	wall->color = 0xCECECE; //gris
	//return (wall);
}*/

void			set_north_wall(t_wall *wall, int heightleft, int heightright, int x) //la valeur x et y du wall precise l'endroit du coin en haut a gauche du wall
{
	//t_wall	wall;

	wall->x = x;
	wall->heightleft = heightleft;
	wall->heightright = heightright;
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

int				display_wall(t_data *data, t_wall wall, t_player *player)
{
	int		i;
	int		ptraddr;
	int		ptraddrend;

	wall.img = mlx_new_image(data->mlx_ptr, wall.width, wall.height);
	wall.img_data = (int *)mlx_get_data_addr(wall.img, &wall.bpp, &wall.size_line, &wall.endian);
	clip(&wall);
	i = wall.rightcl.p.x;
	wall.nbcoldone = 0;
	while (i <= wall.leftcl.p.x)
	{
		if (!wall.coldone[i])
		{
			wall.realtop = fmax(wall.top, 0);
			wall.realbot = fmin(wall.bot, 200);
			ptraddr = /*(int)*/wall.realtop * DEFX + i;
			ptraddrend = /*(int)*/wall.realbot * DEFX + i;
			while (ptraddr < ptraddrend)
			{
				wall.img_data[realtop] = wall.color;
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

void			grow_wall(t_data *data, t_wall *wall)
{
	//set_north_wall(wall->xtopleft - 5, wall->ytopleft - 5, wall->width + 10, wall->height + 10);
	//display_wall(data, *wall);
	(void)data;
	(void)wall;
	printf("test\n");
}


/*
**		*(img.data + (x * 4 + 2) + (img.size * y)) = (unsigned)color.r;
**		*(img.data + (x * 4 + 1) + (img.size * y)) = (unsigned)color.g;
**		*(img.data + (x * 4 + 0) + (img.size * y)) = (unsigned)color.b;
*/
