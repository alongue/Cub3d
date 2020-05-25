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
	data->nbcoldone = 0;
	printf("(avant ptr)\n");
	if ((data->ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	printf("av[1] (avant window) = %s\n", av[1]);
	data->win_width = 0;
	data->win_height = 0;
	data->colceil = (unsigned int)-1;
	data->colfloor = (unsigned int)-1;
	data->texnorth = NULL;
	data->texsouth = NULL;
	data->texeast = NULL;
	data->texwest = NULL;
	data->sprite = NULL;
	data->coldone = malloc(sizeof(int) * data->win_width);
	data->coldone = ft_memseti(data->coldone, false, data->win_width);
	data->heightcol = malloc(sizeof(double) * data->win_width);
	data->heightcol = ft_memseti(data->heightcol, 0, data->win_width);
	data->filename = ft_strdup(av[1]);
	printf("data->coldone = %p\tet\tdata->heightcol = %p\n", &data->coldone, &data->heightcol);
	printf("data->win_width = %p\tet\tdata->win_height = %p\n", &data->win_width, &data->win_height);
	printf("data = %p\tet\tdata->window = %p\tet\tdata->ptr = %p\n", &data, &data->window, &data->ptr);
	if ((data->window = mlx_new_window(data->ptr, data->win_width, data->win_height, "Cub3d")) == NULL)
		return (EXIT_FAILURE);
	printf("av[1] = %s\n", av[1]);
	data->img = mlx_new_image(data->ptr, data->win_width, data->win_height);
	data->img_data = (int *)mlx_get_data_addr(data->img, &data->bpp, &data->size_line, &data->endian);
	data->cubside = 64;
	return (EXIT_SUCCESS);
}

void	reset_data(t_data *data)
{
	int	x;
	int	y;

	data->coldone = ft_memseti(data->coldone, false, data->win_width);
	data->heightcol = ft_memseti(data->heightcol, 0, data->win_width);
	x = -1;
	y = -1;
	while (++y < data->win_height)
	{
		x = -1;
		while (++x < data->win_width)
			data->img_data[y * data->win_width + x] = 0x000000;
	}
	data->nbcoldone = 0;
	display_ceilfloor(*data);
}

int		free_elements(t_data data, t_tree tree, t_map map)
{
	(void)data;
	(void)tree;
	(void)map;
	return (0);
}
