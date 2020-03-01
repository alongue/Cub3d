/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:44:56 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/01 14:45:10 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int		count(char *line, int *counter1)
{
	char	*str;

	str = ft_rmchar(line, ' ');
	if (!ft_isonlychar(str, "01SNEW"))
		return (ft_putstrreti_fd("Error\nUn des caracteres n'est pas valide\n", -1, 0));
	*counter1 = (int)ft_strlen(str);
	return (*counter1);
}

static int		get_counter(int fd, int *counter)
{
	int				ret;
	char			*line;

	ret = 2;
	ft_memseti(counter, 0, 2);
	while ((ret = get_next_line(fd, &line)) == 1 || ft_strncmp(line, "", 1) != 0 || !ft_isonlychar(line, "01SNEW"))
	{
		if (ret == -1)
			return (ft_putstrreti_fd("Error\nVeuillez verifiez le fichier\n", 0, 0));
		if ((count(line, &counter[1])) == -1)
			return (0);
		free(line);
		counter[0]++;
	}
	return (1);
}

static t_cub	**get_malloc(t_data data, int *counter)
{
	t_cub	**cub;
	int		fd;
	int		ret;
	int		counter0;

	fd = open(data.file, O_RDONLY);
	ret = 2;
	if (!get_counter(fd, counter))
		return (NULL);
	counter0 = counter[0];
	if (!(cub = malloc(sizeof(t_cub *) * (counter[0] + 0))))
		return (ft_putstrret_fd("Error\nNo space left on device\n", NULL, 0));
	while (--counter0 >= 0)
	{
		if (!(cub[counter0] = malloc(sizeof(t_cub) * (counter[1] + 0)))) // faudra free le reste
		{
			while (--counter0 >= 0)
				free(cub[counter0]);
			return (ft_putstrret_fd("Error\nNo space left on device\n", NULL, 0));
		}
		//ft_memseti(cub[counter[0]], 0, --counter[1]);
		cub[counter0][counter[1]].exist = true;
	}
	printf("counter[0] = %d\n", counter[0]);
	return (cub);
}

static int		parse(char *line, t_cub **cub, int lastline)
{
	int			counter;
	static int	i = 0;

	counter = -1;
	printf("lastline = %d\n", lastline);
	while (line[++counter])
	{
		if (((i == 0 || i == lastline - 1) && ft_get_nbchar(line, '1') != ft_strlen(line))
			|| line[0] != '1' || line[ft_strlen(line) - 1] != '1')
			return (ft_putstrreti_fd("Error\nLa map n'est pas entoure de murs\n", 0, 0));
		if (line[i] == '1')
			set_cub(&cub[i][counter], i, counter);
		else
			cub[i][counter].exist = false;
	}
	i++;
	return (1);
}

t_map			get_coor(t_data data, int wallside)
{
	char	*line;
	int		ret;
	int		fd;
	int		counter[2];
	t_map	map;

	ret = 2;
	ft_memseti(counter, 0, 2);
	map.exist = false;
	if (!data.file || !ft_strstrpart(data.file, ft_strlen(data.file) - 4,
									".cub"))
		return (putstrret_fd("Error\nVeuillez mettre une map\n", map, 0));
	fd = open(data.file, O_RDONLY);
	if (!(map.cub = get_malloc(data, counter)))
		return (map);
	initcub(&map, wallside);
	while (ret != 0)
	{
		if ((ret = get_next_line(fd, &line)) == -1)
			return (putstrret_fd("Error\nVeuillez mettre une map\n", map, 0));
		if (!(parse(line, map.cub, counter[0])))
			return (map);
	}
	map.exist = true;
	return (map);
}
