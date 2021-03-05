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
		else if (map->number[i][counter] == '2' && !set_obj(data, map, i, counter))
				return (0);
		else if (ft_get_nbchar("SNEW", map->number[i][counter]) == 1)
		{
			if (player->exist)
				return (ft_putstrreti_fd("Error\nUn seul joueur est accepte sur la map.\n", 0, 0));
			//vscode printf("player->exist = %d\n", player->exist);
			*player = get_player(counter * data.cubside, i * data.cubside, map->number[i][counter], data);
			//vscode printf("player->exist = %d\n", player->exist);
			map->cub[i][counter].exist = 0;
		}
		else
			map->cub[i][counter].exist = 0;
		//vscode printf("map->cub[0][2].sbot.a.x = %f\n", map->cub[0][2].sbot.a.x);
	}
	return (1);
}

int			get_nbcuby(t_map *map, int xmax, int nblin)
{
	int		x;
	int		y[2];

	x = -1;
	//vscode printf("xmax = %d\n", xmax);
	if (!(map->nbcuby = malloc(sizeof(int) * xmax + 1)))
		return (ft_putstrreti_fd("Error\nUn malloc n'a pas fonctionne\n", 0,
		free_all_stuff(STDOUT_FILENO, map, NULL, 0)));
	//vscode printf("xmax = %d\tet\tnblin = %d\n", xmax, nblin);
	while (++x < xmax)
	{
		y[0] = 0;
		while (map->number[y[0]][x] == ' ' && y[0] < nblin)
			y[0]++;
		y[1] = nblin - 1;
		while (map->number[y[1]][x] == ' ' && y[1] > 0)
		{
			y[1]--;
			//printf("y[1] = %d\tet\tnblin = %d\n", y[1], nblin);
		}
		map->nbcuby[x] = (y[1] - y[0] + 1 < 0) ? 0 : y[1] - y[0] + 1;
		//vscode printf("map->nbcuby[%d] = %d\n", x, map->nbcuby[x]);
	}
	//vscode printf("test\n");
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
		return (free_all_stuff(0, map, NULL, 0));
	while ((ret = get_next_line(fd, &map->number[i])) != -1 &&
	!ft_isonlychar(map->number[i], " "))
	{
		if (!ft_isonlychar(map->number[i], "012SNEW "))
		{
			printf("map->number[%d] = %s\n", i, map->number[i]);
			free_all_stuff(0, map, NULL, 0);
			return (get_next_free(NULL, NULL, "Error\nUn des caracteres n'est pas valide\n", &fd)); // mettre ces 2 if dans une fonction d'erreur
		}
		//vscode printf("map->number[i] = %s\n", map->number[i]);
		//vscode printf("i = %d\n", i);
		max = ((int)ft_strlen(map->number[i])) > max ? (int)ft_strlen(map->number[i]) : max;
		i++;
		//vscode printf("je m'apprete a realloc\n");
		//map->number[i] = NULL;
		if (!(map->number = ft_realloc((void **)&map->number, sizeof(char *) * (i + 1), sizeof(char *) * i, 0)))
		{
			free_all_stuff(0, map, NULL, 0); // creer get_next_free_all
			return (get_next_free(NULL, NULL, "Error\nUn des caracteres n'est pas valide\n", &fd)); // mettre ces 2 if dans une fonction d'erreur
		}// regrouper ces malloc peut etre
	}
	if (map->number[i])
		free(map->number[i]);
	map->number[i] = NULL; // il est mis a null 1 fois ou 2 fois selon si malloc fail
	if (ret == -1)
	{
		free_all_stuff(0, map, NULL, 0); // creer get_next_free_all
		return (get_next_free(NULL, NULL, "Error\nUne erreur est survenue lors de la lecture du fichier\n", &fd)); // mettre ces 2 if dans une fonction d'erreur
	}
	*nblin = i;
	*xmax = max;
	//vscode printf("max = %d\n", max);
	//vscode printf("nblin = %d\n", *nblin);
	//vscode sleep(1);
	i = -1;
	while (++i < *nblin)
	{
		printf("(avant) map->number[%d] = %s\n", i, map->number[i]);
		max1 = ft_strlen(map->number[i]) - 1;
		printf("ligne -> %d\tmax1 = %d\tet\t*xmax = %d\n", i, max1, *xmax);
		if (!(map->number[i] = ft_realloc((void **)&map->number[i], sizeof(char) * *xmax + 1, max1 + 1, 1)))
		{
			free_all_stuff(0, map, NULL, 0); // creer get_next_free_all
			return (get_next_free(NULL, NULL, "Error\nUn malloc n'a pas fonctionne\n", &fd)); // mettre ces 2 if dans une fonction d'erreur
		}
		while (++max1 < *xmax)
			map->number[i][max1] = ' ';
		map->number[i][*xmax] = '\0';
		printf("(apres) map->number[%d] = %s\n", i, map->number[i]);
	}
	return (1);
}

void		initmap(t_map *map)
{
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
	int		i;

	map.exist = 0;
	initmap(&map);
	player->exist = 0;
	xmax = 0;
	nblin = 0;
	if (!data->filename || !ft_strstrpart(data->filename, ft_strlen(data->filename) - 4,
	".cub"))
		return (putstrret_fd("Error\nArguments valables : \"map.cub\" [--save]\n", map,
		free_data_stuff(STDOUT_FILENO, data)));
	if ((fd = open(data->filename, O_RDONLY)) == -1 && close(fd) == -1)
		return (putstrret_fd("Error\nLe fichier ne peut pas s'ouvrir\n", map,
		free_data_stuff(STDOUT_FILENO, data)));
	//vscode printf("test ta grand mere\n");
	if (!parse_elements(data, fd))
		return (map);
	//vscode printf("test2\n");
	if (!get_number(&map, fd, &nblin, &xmax) || !verify_end(fd, data, &map)
	|| !get_nbcuby(&map, xmax, nblin) || !offset_ptrcub(&map, nblin, xmax)) // on lui passe le fd car gnl va etre utilise pour arriver jusqu'a la map
	{
		get_next_free(NULL, data, NULL, NULL);
		return (map);
	}
	//vscode printf("test4\n");
	i = -1;
	if (!is_surrounded(map))
	{
		free_all_stuff(free_data_stuff(0, data), &map, NULL, 1);
		return (putstrret_fd("Error\nLa map n'est pas entoure de murs\n", map, 0));
	}
	//vscode printf("test5\n");
	while (++i < nblin)
		if (!get_cub(&map, player, *data, i))
			return (map);
	//vscode printf("test5\n");
	if (!player->exist)
		return (putstrret_fd("Error\nLe joueur n'a pas ete mis sur la map\n", map, 0));
	if ((data->window = mlx_new_window(data->ptr, data->win_width, data->win_height, "Cub3d")) == NULL)
		return (map);
	map.exist = 1;

	//vscode printf("test3\n");
	return (map);
}
