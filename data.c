/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:21:47 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/12 15:49:25 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		create_data(t_data *data, char **av)
{
	data->nbcoldone = 0;
	data->file = ft_strdup(av[1]);
	printf("data->file = %s\n", data->file);
	ft_memseti(data->coldone, 0, 320);
	if (((*data).mlx_win = mlx_new_window((*data).mlx_ptr, data->win_width, data->win_height, "Hello World")) == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
