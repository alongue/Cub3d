/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:39:58 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/09 16:40:10 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

#define SPACEIDX "Error\nMettez au moins un espace (ID et res X)\n"
#define RESNUM "Error\nVeuillez verifier les nombres de la resolution\n"
#define SPACEXY "Error\nMettez au moins un espace (res X et res Y)\n"

int		get_reslen(char *line)
{
	int counter;

	counter = 1;
	while (*line != '\0' && *line != ' ')
	{
		if (counter > 7)
			return (counter);
		line++;
		counter++;
	}
	return (counter - 1);
}

int		check_first_part(char *line, int *i, t_data *data)
{
	int		max;

	if ((!ft_isdigit(line[*i]) && line[*i] != '-') || *i == 1)
		return (ft_putstrreti_fd(SPACEIDX, 0, STDOUT_FILENO));
	if (line[*i] == '-' && !ft_isdigit(line[*i + 1]))
		return (ft_putstrreti_fd(RESNUM, 0, STDOUT_FILENO));
	max = data->win_width;
	if (get_reslen(&line[*i]) < 7)
	{
		if ((ft_atoi(&line[*i]) >= 1))
			data->win_width = ft_atoi(&line[*i]);
		if (data->win_width >= max)
			data->win_width = max;
	}
	if (line[*i] == '-')
		(*i)++;
	while (ft_isdigit(line[*i]))
		(*i)++;
	while (line[*i] == ' ')
		(*i)++;
	return (1);
}

int		set_resolution(t_data *data, char *line, char *c)
{
	int i;
	int max;

	(void)c;
	i = 0;
	while (line[++i] == ' ')
		;
	if (!check_first_part(line, &i, data))
		return (0);
	if (!ft_isdigit(line[i]) && line[i] != '-')
		return (ft_putstrreti_fd(SPACEXY, 0, STDOUT_FILENO));
	if (line[i] == '-' && !ft_isdigit(line[i + 1]))
		return (ft_putstrreti_fd(RESNUM, 0, STDOUT_FILENO));
	max = data->win_height;
	if (get_reslen(&line[i]) < 7)
	{
		if ((ft_atoi(&line[i]) >= 1))
			data->win_height = ft_atoi(&line[i]);
		if (data->win_height >= max)
			data->win_height = max;
	}
	return (create_mlx_img(data));
}

int		create_mlx_img(t_data *data)
{
	if (!(data->img = mlx_new_image(data->ptr,
	data->win_width, data->win_height)))
		return (ft_putstrreti_fd(MALLOC, 0, STDOUT_FILENO));
	data->img_data = (int *)mlx_get_data_addr(data->img, &data->bpp,
	&data->size_line, &data->endian);
	return (1);
}
