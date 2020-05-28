/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:44:56 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/12 16:23:15 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int			get_cub(t_map *map, t_player *player, t_data data, int i)
{
	int			counter;

	counter = -1;
	player->exist = 0;
	while (map->number[i][++counter])
	{
		if (map->number[i][counter] == '1')
			set_cub(data, &map->cub[i][counter], i, counter);
		else if (map->number[i][counter] == '2') //s'occuper des malloc des objets
			set_obj(data, map, i, counter);
		else if (ft_get_nbchar("SNEW", map->number[i][counter]) == 1)
		{
			if (player->exist)
				ft_putstrreti_fd("Error\nUn seul joueur est accepte sur la map.\n", 0, 0);
			*player = get_player(counter * data.cubside, i * data.cubside, map->number[i][counter], data);
			map->cub[i][counter].exist = 0;
		}
		else
			map->cub[i][counter].exist = 0;
		printf("map->cub[0][2].sbot.a.x = %f\n", map->cub[0][2].sbot.a.x);
	}
	return (1);
}

int			get_nbcuby(t_map *map, int xmax, int nblin)
{
	int		x;
	int		y[2];

	x = -1;
	printf("xmax = %d\n", xmax);
	if (!(map->nbcuby = malloc(sizeof(int) * xmax + 1)))
		return (0);
	while (++x < xmax)
	{
		y[0] = 0;
		while (map->number[y[0]][x] == ' ')
			y[0]++;
		y[1] = nblin - 1;
		while (map->number[y[1]][x] == ' ')
			y[1]--;
		map->nbcuby[x] = y[1] - y[0] + 1;
	}
	map->nbcuby[xmax] = -1;
	map->nbxmax = get_nbxmax(map->nbcuby);
	map->nbymax = get_nbymax(map->nbcuby);
	return (1);
}

int			get_number(t_map *map, int fd, int *nblin, int *xmax)
{
	int		ret;
	int		i;
	int		max;
	int		max1;

	i = 0;
	max = 0;
	map->nbobjects = 0;
	if (!(map->number = malloc(sizeof(char *) * (i + 1))))
		return (0);
	while ((ret = get_next_line(fd, &map->number[i])) != -1 &&
	!ft_isonlychar(map->number[i], " "))
	{
		if (!ft_isonlychar(map->number[i], "012SNEW "))
		{
			printf("map->number[%d] = %s\n", i, map->number[i]);
			return (ft_putstrreti_fd("Error\nUn des caracteres n'est pas valide\n", 0, 0)); // mettre ces 2 if dans une fonction d'erreur
		}
		printf("map->number[i] = %s\n", map->number[i]);
		printf("i = %d\n", i);
		max = ((int)ft_strlen(map->number[i])) > max ? (int)ft_strlen(map->number[i]) : max;
		i++;
		printf("je m'apprete a realloc\n");
		if (!(map->number = ft_realloc(map->number, sizeof(char *) * (i + 1))))
			return (0); // regrouper ces malloc peut etre
	}
	if (ret == -1)
		return (ft_putstrreti_fd("Error\nVeuillez verifiez le fichier\n", 0, 0));
	if (!verify_end(fd))
		return (ft_putstrreti_fd("Error\nLa map doit etre le dernier element\n", 0, 0));
	*nblin = i;
	*xmax = max;
	printf("max = %d\n", max);
	printf("nblin = %d\n", *nblin);
	sleep(1);
	i = -1;
	while (++i < *nblin)
	{
		//printf("map->number[%d] = %s\n", i, map->number[i]);
		max1 = ft_strlen(map->number[i]) - 1;
		printf("ligne -> %d\tmax1 = %d\tet\t*xmax = %d\n", i, max1, *xmax);
		if (!(map->number[i] = ft_realloc(map->number[i], sizeof(char) * *xmax + 1)))
			return (0);
		while (++max1 < *xmax)
			map->number[i][max1] = ' ';
		map->number[i][*xmax] = '\0';
	}
	return (1);
}

t_map		create_map(t_data *data, t_player *player)
{
	t_map	map;
	int		fd;
	int		xmax;
	int		nblin;
	int		i;

	map.exist = 0;
	map.objects = NULL;
	xmax = 0;
	nblin = 0;
	if (!data->filename || !ft_strstrpart(data->filename, ft_strlen(data->filename) - 4,
									".cub"))
		return (putstrret_fd("Error\nVeuillez mettre une map\n", map, 0));
	fd = open(data->filename, O_RDONLY);
	if (!parse_elements(&map, data, fd))
		return (map);
	if (!get_number(&map, fd, &nblin, &xmax) || !get_nbcuby(&map, xmax, nblin)
		|| !offset_ptrcub(&map, nblin, xmax)) // on lui passe le fd car gnl va etre utilise pour arriver jusqu'a la map
		return (map);
	i = -1;
	if (!is_surrounded(map))
		return (putstrret_fd("Error\nLa map n'est pas entoure de murs\n", map, 0));
	while (++i < nblin)
		if (!get_cub(&map, player, *data, i))
			return (map);
	

	if ((data->window = mlx_new_window(data->ptr, data->win_width, data->win_height, "Cub3d")) == NULL)
		return (map);
	data->img = mlx_new_image(data->ptr, data->win_width, data->win_height);
	data->img_data = (int *)mlx_get_data_addr(data->img, &data->bpp, &data->size_line, &data->endian);

	map.exist = 1;
	return (map);
}
