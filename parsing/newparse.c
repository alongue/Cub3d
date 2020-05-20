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
	while (map->number[i][++counter])
	{
		if (map->number[i][counter] == '1')
			set_cub(data, &map->cub[i][counter], i, counter);
		else if (map->number[i][counter] == '2') //s'occuper des malloc des objets
			set_obj(data, map, i, counter);
		else if (ft_get_nbchar("SNEW", map->number[i][counter]) == 1)
		{
			*player = get_player(counter * data.cubside, i * data.cubside, map->number[i][counter], data);
			map->cub[i][counter].exist = false;
		}
		else
			map->cub[i][counter].exist = false;
		printf("map->cub[0][2].sbot.a.x = %f\n", map->cub[0][2].sbot.a.x);
	}
	return (1);
}

int			get_nbcuby(t_map *map, size_t xmax, int nblin)
{
	size_t	x;
	int		y[2];

	x = -1;
	if (!(map->nbcuby = malloc(sizeof(size_t) * xmax + 1)))
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
	return (1);
}

int			get_number(t_map *map, int fd, int *nblin, size_t *xmax)
{
	int		ret;
	int		i;
	size_t	max;
	size_t	max1;

	i = 0;
	max = 0;
	map->nbobjects = 0;
	if (!(map->number = malloc(sizeof(char *) * (i + 1))))
		return (0);
	while ((ret = get_next_line(fd, &map->number[i])) == 1 || ft_strncmp(map->number[i], "", 1) != 0 || !ft_isonlychar(map->number[i], "012SNEW "))
	{
		if (ret == -1)
			return (ft_putstrreti_fd("Error\nVeuillez verifiez le fichier\n", 0, 0));
		if (!ft_isonlychar(map->number[i], "012SNEW "))
			return (ft_putstrreti_fd("Error\nUn des caracteres n'est pas valide\n", -1, 0)); // mettre ces 2 if dans une fonction d'erreur
		printf("map->number[i] = %s\n", map->number[i]);
		printf("i = %d\n", i);
		max = (ft_strlen(map->number[i])) > max ? ft_strlen(map->number[i]) : max;
		i++;
		printf("je m'apprete a realloc\n");
		if (!(map->number = ft_realloc(map->number, sizeof(char *) * (i + 1))))
			return (0); // regrouper ces malloc peut etre
	}
	*nblin = i;
	*xmax = max;
	i = -1;
	while (++i < *nblin)
	{
		//printf("map->number[%d] = %s\n", i, map->number[i]);
		max1 = ft_strlen(map->number[i]) - 1;
		printf("ligne -> %d\tmax1 = %zu\tet\t*xmax = %zu\n", i, max1, *xmax);
		if (!(map->number[i] = ft_realloc(map->number[i], sizeof(char) * *xmax + 1)))
			return (0);
		while (++max1 < *xmax)
			map->number[i][max1] = ' ';
		map->number[i][*xmax] = '\0';
	}
	return (1);
}

t_map		create_map(t_data data, t_player *player)
{
	t_map	map;
	int		fd;
	size_t	xmax;
	int		nblin;
	int		i;

	map.exist = false;
	map.objects = NULL;
	if (!data.filename || !ft_strstrpart(data.filename, ft_strlen(data.filename) - 4,
									".cub"))
		return (putstrret_fd("Error\nVeuillez mettre une map\n", map, 0));
	fd = open(data.filename, O_RDONLY);
	if (!get_number(&map, fd, &nblin, &xmax) || !get_nbcuby(&map, xmax, nblin)
		|| !offset_ptrcub(&map, nblin, xmax)) // on lui passe le fd car gnl va etre utilise pour arriver jusqu'a la map
		return (map);
	i = -1;
	if (!is_surrounded(map))
		return (putstrret_fd("Error\nLa map n'est pas entoure de murs\n", map, 0));
	while (++i < nblin)
		if (!get_cub(&map, player, data, i))
			return (map);
	map.exist = true;
	return (map);
}
