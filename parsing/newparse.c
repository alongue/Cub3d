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
	if (!(map->testnumber = malloc(sizeof(char *) * (*maxlin + 1))))
		return (get_next_free(NULL, NULL, MALLOC, 0));
	while ((map->number = map->testnumber)
	&& (ret = get_next_line(fd, &map->number[*maxlin]))
	!= -1 && !ft_isonlychar(map->number[*maxlin], " "))
	{
		if (!ft_isonlychar(map->number[*maxlin], "012SNEW "))
			return (get_next_free(NULL, NULL, CHAR, 0));
		*maxcol = ((int)ft_strlen(map->number[*maxlin])) > *maxcol ?
		(int)ft_strlen(map->number[*maxlin]) : *maxcol;
		(*maxlin)++; // admettons *maxlin = 2
		if (!(map->testnumber = ft_realloc(map->number,
		sizeof(char *) * (*maxlin + 1), sizeof(char *) * *maxlin)))
			return (get_next_free(NULL, NULL, MALLOC,
			ft_free_ret(0, (void **)&map->number[*maxlin - 1], NULL, NULL))); // on a un malloc de 1 pr map->number
	}
	ft_free_ret(0, (void **)&map->number[*maxlin], NULL, NULL);
	if (ret == -1)
		return (get_next_free(NULL, NULL, ERRFILE, 0));
	if (*maxlin < 3)
		return (get_next_free(NULL, NULL, MAP, 0));
	
	return (1);
}

int			adjust_number(t_map *map, int fd, int *nblin, int *xmax)
{
	int		max1;
	int		i;

	if (!get_number(map, nblin, xmax, fd))
		return (0);
	if (!verify_end(fd))
		return (0);
	i = -1;
	while (++i < *nblin)
	{
		max1 = ft_strlen(map->number[i]) - 1;
		if (!(map->number[i] = ft_realloc(map->number[i],
		sizeof(char) * *xmax + 1, sizeof(char) * max1 + 2)))
			return (ft_putstrreti_fd(MALLOC, 0, STDOUT_FILENO));
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
		return (free_all_stuff(0, map, data, 1));
	while (++i < nblin)
		if (!get_cub(map, player, *data, i))
			return (0);
	if (!player->exist)
	{
		return (ft_putstrreti_fd(PLAYER, 0,
		free_all_stuff(0, map, data, 1)));
	}
	if ((data->window = mlx_new_window(data->ptr, data->win_width,
	data->win_height, "Cub3d")) == NULL)
		return (0);
	map->exist = 1;
	return (1);
}

void		init(t_map *map, t_player *player, int *xmax, int *nblin)
{
	map->exist = 0;
	map->objects = NULL;
	map->nbcuby = NULL;
	map->number = NULL;
	map->testnumber = NULL;
	map->cub = NULL;
	map->tree.rootnode = NULL;
	map->nbxcharmax = -1;
	map->nbymax = -1;
	player->exist = 0;
	*xmax = 0;
	*nblin = 0;
}

t_map		create_map(t_data *data, t_player *player)
{
	t_map	map;
	int		fd;
	int		xmax;
	int		nblin;

	init(&map, player, &xmax, &nblin);
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
	{
		return (putstrret_fd(NULL, map,
		free_all_stuff(STDOUT_FILENO, &map, data, 0)));
	}
	if (!verify_map(&map, player, data, nblin))
		return (map);
	return (map);
}
