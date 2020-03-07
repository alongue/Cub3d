/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:21:47 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/07 19:44:00 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		create_win(t_data *data, char **av)
{
	data->file = av[1];
	if (((*data).mlx_win = mlx_new_window((*data).mlx_ptr, data->win_width, data->win_height, "Hello World")) == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
