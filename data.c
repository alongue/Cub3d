/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:21:47 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/12 16:21:37 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		create_data(t_data *data, char **av)
{
	//data->nbcoldone = 0;
	data->coldone = malloc(sizeof(bool) * data->win_width);
	ft_memseti(data->coldone, 0, data->win_width);
	data->heightcol = malloc(sizeof(double) * data->win_width);
	ft_memseti(data->heightcol, 0, data->win_width);
	printf("av[1] = %s\n", av[1]);
	data->filename = malloc(sizeof(char) * ft_strlen(av[1]) + 1);
	data->filename = ft_strcpy(data->filename, av[1]);
	if (((*data).window = mlx_new_window((*data).ptr, data->win_width, data->win_height, "Hello World")) == NULL)
		return (EXIT_FAILURE);
	data->img = mlx_new_image(data->ptr, data->win_width, data->win_height);
	data->img_data = (int *)mlx_get_data_addr(data->img, &data->bpp, &data->size_line, &data->endian);
	return (EXIT_SUCCESS);
}

void	reset_data(t_data *data)
{
	int	x;
	int	y;

	ft_memseti(data->coldone, 0, data->win_width);
	ft_memseti(data->heightcol, 0, data->win_width);
	x = -1;
	y = -1;
	while (++y < data->win_height)
	{
		x = -1;
		while (++x < data->win_width)
			data->img_data[y * data->win_width + x] = 0x000000;
	}
}

int		free_elements(t_data data, t_tree tree, t_map map)
{
	(void)data;
	(void)tree;
	(void)map;
	return (0);
}
