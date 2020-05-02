/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_var_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 19:42:34 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/09 12:28:44 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void		set_cub(t_cub *cub, int i, int counter)
{
	cub->exist = true;
	cub->x = counter * cub->side; //sommet a gauche avec vue du dessus
	cub->y = i * cub->side; //sommet en haut avec vue du dessus
	cub->stop = get_segmenti(cub->x + 0.1*0,
							cub->y,
							cub->x + cub->side - 0.1*0,
							cub->y);
	cub->sright = get_segmenti(cub->x + cub->side,
							cub->y + 0.1*0,
							cub->x + cub->side,
							cub->y + cub->side - 0.1*0);
	cub->sbot = get_segmenti(cub->x + cub->side - 0.1*0,
							cub->y + cub->side,
							cub->x + 0.1*0,
							cub->y + cub->side);
	cub->sleft = get_segmenti(cub->x,
							cub->y + cub->side - 0.1*0,
							cub->x,
							cub->y + 0.1*0);
}

void		set_obj(t_data data, t_map *map, int i, int counter) //s'occuper des malloc des objets
{
	if (!(map->objects = malloc(sizeof(t_object) * 1)))
	{
		printf("Le malloc fonctionne pas ta mere !\n");
		return ;
	}
	if (!(map->objects[0].img = mlx_xpm_file_to_image(data.ptr, "textures/mur-1.xpm", &map->objects[0].width, &map->objects[0].height)))
		return ;
	map->objects[0].img_data = (int *)mlx_get_data_addr(data.img, &map->objects[0].bpp, &map->objects[0].size_line, &map->objects[0].endian);
	map->objects[0].data_file = (int *)mlx_get_data_addr(map->objects[0].img, &map->objects[0].bppimg, &map->objects[0].size_lineimg, &map->objects[0].endianimg);
	map->objects[0].heighttop = map->objects[0].height / 2;
	map->objects[0].heightbot = -map->objects[0].height / 2;
	map->objects[0].exist = true;
	map->objects[0].pos.x = counter * data.cubside + map->objects[0].width / 2;
	map->objects[0].pos.y = i * data.cubside + map->objects[0].height / 2;
}
