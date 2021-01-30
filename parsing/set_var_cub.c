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
	printf("yo\n");
	cub->exist = 1;
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

	printf("nblin avant malloc = %d\n", nblin);
	sleep(1);
	if (!(map->cub = malloc(sizeof(t_cub *) * (nblin + 2))))
	{
		ft_putstr_fd("Error\nLe malloc n'a pas marche\n", 0);
		return (0);
	}
	i = -1;
	printf("xmax avant malloc = %d\n", xmax);
	while (++i < nblin + 2)
		if (!(map->cub[i] = malloc(sizeof(t_cub) * (xmax + 2))))
		{
			ft_putstr_fd("Error\nLe malloc n'a pas marche\n", 0);
			return (0);
		}
	i = -1; // on remplit tout comme ca, y a moins de ligne puis on ecrasera les donnees plus tard
	counter = -1;
	while (++i < nblin + 2) // '<' car il part de 0 donc
	{
		counter = -1;
		while (++counter < xmax + 2) // '<' car il part de 0 donc
		{
			printf("(boucle malloc) map->cub[%d][%d]\n", i, counter);
			map->cub[i][counter].exist = 0;
		}
		printf("i = %d\tet\tnblin = %d\n", i, nblin);
		map->cub[i]++; // on va bouger le pointeur de 1 de sorte a ce qu'on accede cub[-1][-1]
	}
	map->cub++;
	return (1);
}

void		set_obj(t_data data, t_map *map, int i, int counter) //s'occuper des malloc des objets
{
	map->nbobjects++;
	printf("map->nbobjects = %d\n", map->nbobjects);
	if (!(map->objects = ft_realloc(map->objects, sizeof(t_object) * map->nbobjects)))
	{
		printf("Le malloc fonctionne pas ta mere !\n");
		return ;
	}
	printf("&map->objects = %p\n", &map->objects);
	map->cub[i][counter].exist = 0;
	if (!(map->objects[map->nbobjects - 1].img = mlx_xpm_file_to_image(data.ptr, "textures/test-sprite.xpm", &map->objects[map->nbobjects - 1].width, &map->objects[map->nbobjects - 1].height)))
		return ;
	map->objects[map->nbobjects - 1].img_data = (int *)mlx_get_data_addr(data.img, &map->objects[map->nbobjects - 1].bpp, &map->objects[map->nbobjects - 1].size_line, &map->objects[map->nbobjects - 1].endian);
	map->objects[map->nbobjects - 1].data_file = (int *)mlx_get_data_addr(map->objects[map->nbobjects - 1].img, &map->objects[map->nbobjects - 1].bppimg, &map->objects[map->nbobjects - 1].size_lineimg, &map->objects[map->nbobjects - 1].endianimg);
	map->objects[map->nbobjects - 1].exist = 1;
	map->objects[map->nbobjects - 1].pos.x = counter * data.cubside + map->objects[map->nbobjects - 1].width / 2;
	map->objects[map->nbobjects - 1].pos.y = i * data.cubside + map->objects[map->nbobjects - 1].height / 2;
}
