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
	(void)av;
	data->coldone = malloc(sizeof(bool) * data->win_width);
	ft_memseti(data->coldone, 0, data->win_width);
	data->heightCol = malloc(sizeof(float) * data->win_width);
	ft_memseti(data->heightCol, 0, data->win_width);
	printf("av[1] = %s\n", av[1]);
	data->file = malloc(sizeof(char) * ft_strlen(av[1]) + 1);
	ft_strcpy(data->file, av[1]);
	if (((*data).mlx_win = mlx_new_window((*data).mlx_ptr, data->win_width, data->win_height, "Hello World")) == NULL)
		return (EXIT_FAILURE);
	data->img = mlx_new_image(data->mlx_ptr, data->win_width, data->win_height);
	return (EXIT_SUCCESS);
}

//void	reset_data(t_data *data)
