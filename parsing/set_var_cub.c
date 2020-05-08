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

void		set_cub(t_data data, t_cub *cub, int i, int counter)
{
	cub->exist = true;
	cub->x = counter * data.cubside; //sommet a gauche avec vue du dessus
	cub->y = i * data.cubside; //sommet en haut avec vue du dessus
	cub->stop = get_segmenti(cub->x,
							cub->y,
							cub->x + data.cubside,
							cub->y);
	cub->sright = get_segmenti(cub->x + data.cubside,
							cub->y,
							cub->x + data.cubside,
							cub->y + data.cubside);
	cub->sbot = get_segmenti(cub->x + data.cubside,
							cub->y + data.cubside,
							cub->x,
							cub->y + data.cubside);
	cub->sleft = get_segmenti(cub->x,
							cub->y + data.cubside,
							cub->x,
							cub->y);
}

int		offset_ptrcub(t_map *map, int nblin, int xmax)
{
	int	i;
	int	counter;

	if (!(map->cub = malloc(sizeof(t_cub *) * (nblin + 2))))
	{
		ft_putstr_fd("Error\nLe malloc n'a pas marche\n", 0);
		return (0);
	}
	i = -1;
	while (++i < nblin + 2)
		if (!(map->cub[i] = malloc(sizeof(t_cub) * (xmax + 2))))
		{
			ft_putstr_fd("Error\nLe malloc n'a pas marche\n", 0);
			return (0);
		}
	i = -1; // on remplit tout comme ca, y a moins de ligne puis on ecrasera les donnees plus tard
	counter = -1;
	while (++i < nblin + 2)
	{
		while (++counter < xmax + 2)
			map->cub[i][counter].exist = false;
		map->cub[i]++;
	}
	map->cub++;
	return (1);
}

void		set_obj(t_data data, t_map *map, int i, int counter) //s'occuper des malloc des objets
{
	if (!(map->objects = malloc(sizeof(t_object) * 1)))
	{
		printf("Le malloc fonctionne pas ta mere !\n");
		return ;
	}
	map->cub[i][counter].exist = false;
	if (!(map->objects[0].img = mlx_xpm_file_to_image(data.ptr, "textures/test-sprite.xpm", &map->objects[0].width, &map->objects[0].height)))
		return ;
	map->objects[0].img_data = (int *)mlx_get_data_addr(data.img, &map->objects[0].bpp, &map->objects[0].size_line, &map->objects[0].endian);
	map->objects[0].data_file = (int *)mlx_get_data_addr(map->objects[0].img, &map->objects[0].bppimg, &map->objects[0].size_lineimg, &map->objects[0].endianimg);
	map->objects[0].exist = true;
	map->objects[0].pos.x = counter * data.cubside + map->objects[0].width / 2;
	map->objects[0].pos.y = i * data.cubside + map->objects[0].height / 2;
}
