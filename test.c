/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:21:47 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/05 10:24:08 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		create_win(t_data *data)
{
	if (((*data).mlx_win = mlx_new_window((*data).mlx_ptr, data->win_width, data->win_height, "Hello World")) == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
