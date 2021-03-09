/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:44:56 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 20:51:42 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

#define NBELEM 8

int		set_wall(t_data *data, char *line, int inc)
{
	char	**parameters;
	char	begline[3];
	int		(*set_data[3])(t_data *data, char *line, char *letters);

	parameters = (char *[9]){"R", "NO", "SO", "WE", "EA", "S", "F", "C", 0};
	set_data[0] = &set_resolution;
	set_data[1] = &set_texture;
	set_data[2] = &set_color_value;
	begline[0] = line[0];
	begline[1] = (line[1] == ' ') ? 0 : line[1];
	begline[2] = 0;
	while (parameters[++inc] &&
	(ft_isalpha(line[0]) || ft_strncmp(line, "", 1) == 0))
		if (ft_strncmp(begline, parameters[inc],
		ft_strlen(parameters[inc])) == 0)
		{
			if (inc == 0)
				return (set_data[0](data, line, parameters[inc]));
			else if (inc < 6)
				return (set_data[1](data, line, parameters[inc]));
			else if (inc < 9)
				return (set_data[2](data, line, parameters[inc]));
		}
	return (ft_putstrreti_fd("Error\nVeuillez verifier la ligne\n", 0, 0));
}

int		get_next_free(char *line, t_data *data, char *msg, int ret)
{
	if (line)
		free(line);
	get_next_line(-1, NULL);
	if (msg)
		return (ft_putstrreti_fd(msg, ret,
	free_data(STDOUT_FILENO, data)));
	else
		return (free_data(ret, data));
}

int		check_error_elem(int fd, char *line, t_data *data, int *counter)
{
	if (counter[0] != NBELEM)
	{
		return (get_next_free(line, data,
		"Error\nVeuillez verifier le nombre de parametres\n", 0));
	}
	get_next_free(line, NULL, NULL, 0);
	while (--counter[2] >= 0)
	{
		get_next_line(fd, &line);
	}
	return (1);
}

int		parse_elements(t_data *data, int fd)
{
	int		ret;
	char	*line;
	int		newfd;
	int		counter[3];

	ft_memseti(counter, 0, 3);
	if ((newfd = open(data->filename, O_RDONLY)) == -1 && close(newfd) == -1)
		return (ft_putstrreti_fd(ERRFILE, 0, free_data(STDOUT_FILENO, data)));
	while ((ret = get_next_line(newfd, &line)) == 1 &&
	(counter[0] < NBELEM || ft_strncmp(line, "", 1) == 0))
	{
		if (ft_strncmp(line, "", 1) != 0)
		{
			counter[1] = counter[0];
			counter[0] += set_wall(data, line, -1);
			if (counter[1] == counter[0])
				return (get_next_free(line, data, NULL, 0));
		}
		free(line);
		counter[2]++;
	}
	if (ret == -1)
		return (get_next_free(line, data, ERRFILE, 0));
	return (check_error_elem(fd, line, data, counter));
}

int		verify_end(int fd)
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(fd, &line)) != -1)
	{
		if (!ft_isonlychar(line, " "))
			return (0);
		if (ret == 0)
			return (1);
	}
	return (0);
}
