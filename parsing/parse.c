/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:44:56 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/29 19:31:43 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int		count(char *line)
{
	char	*str;

	str = ft_rmchar(line, ' ');
	//printf("line = %s\n", line);
	if (!ft_isonlychar(line, "01SNEW"))
		return (ft_putstrreti_fd("Error\nUn des caracteres n'est pas valide\n", -1, 0));
	return ((int)ft_strlen(str));
}

static int		*get_counter(int fd)
{
	int				ret;
	char			*line;
	static int		counter[2];

	ret = 2;
	ft_memseti(counter, 0, 2);
	while ((ret = get_next_line(fd, &line)) == 1 || ft_strncmp(line, "", 1) != 0 || !ft_isonlychar(line, "01SNEW"))
	{
		if (ret == -1)
			return (ft_putstrret_fd("Error\nVeuillez verifiez le fichier\n", 0, 0));
		if ((counter[1] = count(line)) == -1)
			return (NULL);
		//printf("ret = %d\n", ret);
		free(line);
		counter[0]++;
	}
	return (counter);
}

static t_cub	**get_malloc(t_data data, int *counter)
{
	t_cub	**cub;
	int		fd;
	int		ret;

	fd = open(data.file, O_RDONLY);
	ret = 2;
	//ft_memseti(counter, 0, 2);
	if (!(counter = get_counter(fd)))
		return (NULL);
	if (!(cub = malloc(sizeof(t_cub *) * (counter[0] + 0))))
		return (ft_putstrret_fd("Error\nNo space left on device\n", NULL, 0));
	printf("counter[0] = %d\t\tet\t\tcounter[1] = %d\n", counter[0], counter[1]);
	while (--counter[0] >= 0)
	{
		if (!(cub[counter[0]] = malloc(sizeof(t_cub) * (counter[1] + 0)))) // faudra free le reste
		{
			while (--counter[0] >= 0)
				free(cub[counter[0]]);
			return (ft_putstrret_fd("Error\nNo space left on device\n", NULL, 0));
		}
		//ft_memseti(cub[counter[0]], 0, --counter[1]);
		cub[counter[0]][counter[1]].exist = true;
	}
	return (cub);
}

static int		parse(char *line, t_cub **cub, int lastline)
{
	int			counter;
	static int	i = 0;

	counter = -1;
	printf("ft_get_nbchar(line, '1') = %ld\n", ft_get_nbchar(line, '1'));
	printf("lastline = %d\n", lastline);
	while (line[++counter])
	{
		if (((i == 0 || i == lastline) && ft_get_nbchar(line, '1') != ft_strlen(line))
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
		if (!(ret = get_next_line(fd, &line)))
			return (map);
		if (!(parse(line, map.cub, counter[0])))
			return (map);
	}
	map.exist = true;
	return (map);
}
