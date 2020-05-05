/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:44:56 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/12 16:23:15 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int		count(char *line, int *counter1)
{
	char	*str;

	str = ft_rmchar(line, ' ');
	if (!ft_isonlychar(str, "012SNEW "))
		return (ft_putstrreti_fd("Error\nUn des caracteres n'est pas valide\n", -1, 0));
	*counter1 = (int)ft_strlen(str);
	return (*counter1);
}
//#include <string.h>
static int		get_counter(int fd, int *counterx, int *countery)
{
	int				ret;
	char			*line;

	ret = 2;
	*counterx = 0;
	*countery = 0;
	while ((ret = get_next_line(fd, &line)) == 1 || ft_strncmp(line, "", 1) != 0 || !ft_isonlychar(line, "012SNEW "))
	{
		if (ret == -1)
			return (ft_putstrreti_fd("Error\nVeuillez verifiez le fichier\n", 0, 0));
		if ((count(line, counterx)) == -1)
			return (0);
		//free(line);
		(*countery)++;
	}
	return (1);
}

static t_cub	**get_malloc(t_data data, int *counterx, int *countery)
{
	t_cub	**cub;
	int		fd;
	int		ret;
	int		counter0;

	fd = open(data.filename, O_RDONLY);			//counter1 --> counterx
	ret = 2;
	if (!get_counter(fd, counterx, countery))
		return (NULL);
	counter0 = *countery;
	if (!(cub = malloc(sizeof(t_cub *) * (*countery + 0)))) // peut-etre faire + 1
		return (ft_putstrret_fd("Error\nNo space left on device\n", NULL, 0));
	while (--counter0 >= 0)
	{
		if (!(cub[counter0] = malloc(sizeof(t_cub) * (*counterx + 0)))) // faudra //free le reste
		{
			while (--counter0 >= 0)
				//free(cub[counter0]);
			return (ft_putstrret_fd("Error\nNo space left on device\n", NULL, 0));
		}
		//ft_memseti(cub[counter[0]], 0, --counter[1]);
		cub[counter0][*counterx].exist = true;
	}
	return (cub);
}

static int		parse(char *line, t_map *map, t_player *player, t_data data)
{
	int			counter;
	static int	i = 0;

	counter = -1;
	while (line[++counter])
	{
		if (((i == 0 || i == map->nbcuby - 1) && ft_get_nbchar(line, '1') != ft_strlen(line))
			|| line[0] != '1' || line[ft_strlen(line) - 1] != '1')
			return (ft_putstrreti_fd("Error\nLa map n'est pas entoure de murs\n", 0, 0));
		if (line[counter] == '1')
			set_cub(&map->cub[i][counter], i, counter);
		else if (line[counter] == '2') //s'occuper des malloc des objets
			set_obj(data, map, i, counter);
		else if (ft_get_nbchar("SNEW", line[counter]) == 1)
		{
			*player = get_player(counter * map->cub[0][0].side, i * map->cub[0][0].side, line[counter], data);
			map->cub[i][counter].exist = false;
		}
		else
			map->cub[i][counter].exist = false;
	}
	i++;
	return (1);
}

t_map			get_coor(t_data data, t_player *player)
{
	char	*line;
	int		ret;
	int		fd;
	int		counter[2];
	t_map	map;

	ret = 2;
	ft_memseti(counter, 0, 2);
	map.exist = false;
	printf("data.filename = %s\n", data.filename);
	if (!data.filename || !ft_strstrpart(data.filename, ft_strlen(data.filename) - 4,
									".cub"))
		return (putstrret_fd("Error\nVeuillez mettre une map\n", map, 0));
	fd = open(data.filename, O_RDONLY);
	if (!(map.cub = get_malloc(data, &map.nbcubx, &map.nbcuby)))
		return (map);
	initcub(&map, data.cubside);
	while (ret != 0)
	{
		if ((ret = get_next_line(fd, &line)) == -1)
			return (putstrret_fd("Error\nVeuillez mettre une map (ret = -1) \n", map, 0));
		//printf("map.objets[0] -> %p (get_coor)\n", &map.objects[0]);
		if (!(parse(line, &map, player, data)))
			return (map);
	}
	printf("map.objects[0].pos.x = (get_coor) %f\n", map.objects[0].pos.x);
	if (!player->exist)
		return (putstrret_fd("Error\nVeuillez mettre un joueur\n", map, 0));
	map.exist = true;
	return (map);
}
