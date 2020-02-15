/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:44:56 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/14 19:22:05 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int		count(char *line)
{
	char	*str;

	str = ft_rmchar(line, ' ');
	printf("line = %s\n", line);
	if (!ft_isonlychar(line, "01SNEW"))
		return (ft_putstrreti_fd("Error\nUn des caracteres n'est pas valide\n", -1, 0));
	return (ft_strlen(str));
}

static int		*get_counter(int fd)
{
	int				ret;
	char			*line;
	static int		counter[2];

	ret = 2;
	while (ret != 0)
	{
		ret = get_next_line(fd, &line);
		if ((counter[1] = count(line)) == -1)
			return (NULL);
		printf("ret = %d\n", ret);
		free(line);
		counter[0]++;
	}
	return (counter);
}

static t_cub	**get_malloc(t_data data)
{
	t_cub	**cub;
	int		fd;
	int		ret;
	int		*counter;

	fd = open(data.file, O_RDONLY);
	ret = 2;
	//ft_memseti(counter, 0, 2);
	if (!(counter = get_counter(fd)))
		return (NULL);
	if (!(cub = malloc(sizeof(t_cub *) * (counter[0] + 0))))
		return (ft_putstrret_fd("Error\nNo space left on device\n", NULL, 0));
	while (--counter[0] >= 0)
	{
		if (!(cub[counter[0]] = malloc(sizeof(t_cub) * (counter[1] + 0)))) // faudra free le reste
		{
			while (--counter[0] >= 0)
				free(cub[counter[0]]);
			return (ft_putstrret_fd("Error\nNo space left on device\n", NULL, 0));
		}
		ft_memseti(cub[counter[0]], 0, --counter[1]);
	}
	return (cub);
}

static int		parse(char *line, int i, int ret, t_cub ***cub)
{
	int		counter;

	counter = -1;
	while (line[++counter])
	{
		if (((counter == 0 || ret == 0) && ft_get_nbchar(line, '0')) ||
			line[0] != '1' || line[ft_strlen(line) - 1] != '1')
				return (ft_putstrreti_fd("Error\nLa map n'est pas entoure de murs\n", 0, 0));
		if (line[i] == '1')
			set_cub(cub);
		else
			cub[i][counter] = NULL;
	}
	return (1);
}

t_cub			**get_coor(t_data data, t_wall wall)
{
	char	*line;
	int		ret;
	int		fd;
	int		counter;
	t_cub	**cub;

	ret = 2;
	counter = 0;
	if (!data.file)
		return (ft_putstrret_fd("Error\nVeuillez mettre une map\n", NULL, 0));
	fd = open(data.file, O_RDONLY);
	if (!(cub = get_malloc(data)))
		return (NULL);
	printf("wall.realside = %d\n", wall.realside);
	initcub(&cub, wall);
	while (ret != 0)
	{
		if ((ret = get_next_line(fd, &line)) < 0)
			return (NULL);
		if (!(parse(line, counter++, ret, &cub)))
			return (NULL);
	}
	return (cub);
}
