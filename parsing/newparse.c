/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:44:56 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 20:18:08 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int			get_number(t_map *map, int *maxlin, int *maxcol, int fd)
{
	int	ret;

	map->nbobjects = 0;
	if (!(map->number = malloc(sizeof(char *) * (*maxlin + 1))))
		return (0);
	while ((ret = get_next_line(fd, &map->number[*maxlin])) != -1 &&
	!ft_isonlychar(map->number[*maxlin], " "))
	{
		if (!ft_isonlychar(map->number[*maxlin], "012SNEW "))
		{
			return (ft_putstrreti_fd(
			"Error\nUn des caracteres n'est pas valide\n", 0, STDOUT_FILENO));
		}
		*maxcol = ((int)ft_strlen(map->number[*maxlin])) > *maxcol ?
		(int)ft_strlen(map->number[*maxlin]) : *maxcol;
		(*maxlin)++;
		if (!(map->number = ft_realloc(map->number,
		sizeof(char *) * (*maxlin + 1))))
			return (0);
	}
	if (ret == -1)
		return (ft_putstrreti_fd(ERRFILE, 0, STDOUT_FILENO));
	else
		return (1);
}

int			adjust_number(t_map *map, int fd, int *nblin, int *xmax)
{
	int		max1;
	int		i;

	if (!get_number(map, nblin, xmax, fd))
		return (0);
	if (!verify_end(fd))
	{
		return (ft_putstrreti_fd(
		"Error\nLa map doit etre le dernier element\n", 0, 0));
	}
	i = -1;
	while (++i < *nblin)
	{
		max1 = ft_strlen(map->number[i]) - 1;
		if (!(map->number[i] = ft_realloc(map->number[i],
		sizeof(char) * *xmax + 1)))
			return (0);
		while (++max1 < *xmax)
			map->number[i][max1] = ' ';
		map->number[i][*xmax] = '\0';
	}
	return (1);
}

int			verify_map(t_map *map, t_player *player, t_data *data, int nblin)
{
	int		i;

	i = -1;
	if (!is_surrounded(*map))
		return (ft_putstrreti_fd(WALL, 0, 0));
	while (++i < nblin)
		if (!get_cub(map, player, *data, i))
			return (0);
	if (!player->exist)
		return (ft_putstrreti_fd(PLAYER, 0, 0));
	if ((data->window = mlx_new_window(data->ptr, data->win_width,
	data->win_height, "Cub3d")) == NULL)
		return (0);
	map->exist = 1;
	return (1);
}

void		init(t_map *map)
{
	map->exist = 0;
	map->objects = NULL;
	map->nbcuby = NULL;
	map->number = NULL;
	map->cub = NULL;
	map->tree.rootnode = NULL;
	map->nbxmax = -1;
	map->nbymax = -1;
}

t_map		create_map(t_data *data, t_player *player)
{
	t_map	map;
	int		fd;
	int		xmax;
	int		nblin;

	init(&map);
	player->exist = 0;
	xmax = 0;
	nblin = 0;
	if (!data->filename || !ft_strstrpart(data->filename,
	ft_strlen(data->filename) - 4,
	".cub"))
		return (putstrret_fd(ARGUMENTS, map, free_data(STDOUT_FILENO, data)));
	if ((fd = open(data->filename, O_RDONLY)) == -1 && close(fd) == -1)
		return (putstrret_fd(ERRFILE, map, free_data(STDOUT_FILENO, data)));
	if (!parse_elements(data, fd))
		return (map);
	if (!adjust_number(&map, fd, &nblin, &xmax) ||
		!get_nbcuby(&map, xmax, nblin) || !offset_ptrcub(&map, nblin, xmax))
		return (map);
	if (!verify_map(&map, player, data, nblin))
		return (map);
	return (map);
}
