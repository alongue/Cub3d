/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_var_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 19:42:34 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 20:10:56 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

#define SPRITE_NOT_LOADED "Error\nL'image ne s'est pas charge (sprite)\n"

void	set_cub(t_data data, t_cub *cub, int i, int counter)
{
	cub->exist = 1;
	cub->x = counter * data.cubside;
	cub->y = i * data.cubside;
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

	if (!(map->cub = malloc(sizeof(t_cub *) * (nblin + 2 + 1))))
		return (ft_putstrreti_fd(MALLOC, 0, STDOUT_FILENO));
	i = -1;
	while (++i < nblin + 2)
	{
		if (!(map->cub[i] = malloc(sizeof(t_cub) * (xmax + 2))))
			return (ft_putstrreti_fd(MALLOC, 0, STDOUT_FILENO));
		map->cub[i + 1] = NULL;
	}
	i = -1;
	counter = -1;
	while (++i < nblin + 2)
	{
		counter = -1;
		while (++counter < xmax + 2)
			map->cub[i][counter].exist = 0;
		map->cub[i]++;
	}
	map->cub++;
	return (1);
}

int		malloc_obj(t_map *map)
{
	t_object		*testobjects;

	testobjects = NULL;
	if (++map->nbobjects == 1)
	{
		if (!(map->objects = malloc(sizeof(t_object) * map->nbobjects)))
			return (ft_putstrreti_fd(MALLOC, 0, 0));
	}
	else
	{
		if (!(testobjects = ft_realloc(map->objects, sizeof(t_object) *
		map->nbobjects, sizeof(t_object) * (map->nbobjects - 1))))
			return (ft_putstrreti_fd(MALLOC, 0, 0));
		map->objects = testobjects;
	}
	return (1);
}

int		set_obj(t_data data, t_map *map, int i, int counter)
{
	if (!malloc_obj(map))
		return (0);
	map->cub[i][counter].exist = 0;
	if (!(map->objects[map->nbobjects - 1].img = mlx_xpm_file_to_image(data.ptr,
	data.sprite, &map->objects[map->nbobjects - 1].width,
	&map->objects[map->nbobjects - 1].height)))
		return (ft_putstrreti_fd(SPRITE_NOT_LOADED, 0, 0));
	map->objects[map->nbobjects - 1].height = (map->objects[map->nbobjects - 1].
	height > data.cubside) ? data.cubside :
	map->objects[map->nbobjects - 1].height;
	map->objects[map->nbobjects - 1].img_data = (int *)mlx_get_data_addr(
	data.img, &map->objects[map->nbobjects - 1].bpp,
	&map->objects[map->nbobjects - 1].size_line,
	&map->objects[map->nbobjects - 1].endian);
	map->objects[map->nbobjects - 1].data_file =
	(int *)mlx_get_data_addr(map->objects[map->nbobjects - 1].img,
	&map->objects[map->nbobjects - 1].bppimg,
	&map->objects[map->nbobjects - 1].size_lineimg,
	&map->objects[map->nbobjects - 1].endianimg);
	map->objects[map->nbobjects - 1].exist = 1;
	map->objects[map->nbobjects - 1].pos.x = counter *
	data.cubside + data.cubside / 2;
	map->objects[map->nbobjects - 1].pos.y = i *
	data.cubside + data.cubside / 2;
	return (1);
}
