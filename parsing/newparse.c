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
		if (!is_surrounded(map->number, map->nbcuby))
			return (ft_putstrreti_fd("Error\nLa map n'est pas entoure de murs\n", 0, 0));
		if (map->number[i][counter] == '1')
			set_cub(&map->cub[i][counter], i, counter);
		else if (map->number[i][counter] == '2') //s'occuper des malloc des objets
			set_obj(data, map, i, counter);
		else if (ft_get_nbchar("SNEW", map->number[i][counter]) == 1)
		{
			*player = get_player(counter * map->cub[0][0].side, i * map->cub[0][0].side, map->number[i][counter], data);
			map->cub[i][counter].exist = false;
		}
		else
			map->cub[i][counter].exist = false;
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

int			get_malloc_cub(t_map *map, int fd, int *nblin, size_t *xmax)
{
	int		ret;
	int		i;
	size_t	max;

	i = 0;
	max = 0;
	if (!(map->number = malloc(sizeof(char *) * (i + 1))))
		return (0);
	if (!(map->cub = malloc(sizeof(t_cub *) * (i + 1))))
		return (0); //gerer l'erreur du \n a la fin du fichier
	while ((ret = get_next_line(fd, &map->number[i])) == 1 || ft_strncmp(map->number[i], "", 1) != 0 || !ft_isonlychar(map->number[i], "012SNEW "))
	{
		if (ret == -1)
			return (ft_putstrreti_fd("Error\nVeuillez verifiez le fichier\n", 0, 0));
		if (!ft_isonlychar(map->number[i], "012SNEW "))
			return (ft_putstrreti_fd("Error\nUn des caracteres n'est pas valide\n", -1, 0)); // mettre ces 2 if dans une fonction d'erreur
		max = (ft_strlen(map->number[i])) > max ? ft_strlen(map->number[i]) : max;
		if (!(map->cub[i] = malloc(sizeof(t_cub) * ft_strlen(map->number[i]))))
			return (0);
		i++;
		printf("je m'apprete a realloc\n");
		//printf("map->number[0] = %s\n", map->number[0]);
		if (!(map->number = ft_realloc(map->number, sizeof(char *) * (i + 1))))
			return (0); // regrouper ces malloc peut etre
		printf("map->number[0] = %s\n", map->number[0]);
		if (!(map->cub = ft_realloc(map->cub, sizeof(t_cub *) * (i + 1))))
			return (0);
	}
	*nblin = i;
	*xmax = max;
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
	if (!data.filename || !ft_strstrpart(data.filename, ft_strlen(data.filename) - 4,
									".cub"))
		return (putstrret_fd("Error\nVeuillez mettre une map\n", map, 0));
	fd = open(data.filename, O_RDONLY);
	if (!get_malloc_cub(&map, fd, &nblin, &xmax) || !get_nbcuby(&map, xmax, nblin)) // on lui passe le fd car gnl va etre utilise pour arriver jusqu'a la map
		return (map);
	i = -1;
	while (++i < nblin)
		if (!get_cub(&map, player, data, i))
			return (map);
	map.exist = true;
	return (map);
}
