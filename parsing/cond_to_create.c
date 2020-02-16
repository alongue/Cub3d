/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cond_to_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:06:18 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/16 14:06:55 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool		cond_horizontal(t_cub main, t_cub top, t_cub topleft, t_cub left)
{
	if (!main)
		return (false);
	if (left && !top && !topleft)
		return (true);
	return (false);
}

bool		cond_vertical(t_cub main, t_cub top, t_cub topleft, t_cub left)
{
	if (!main)
		return (false);
	if (!left && !topleft && top)
		return (true);
	return (false);
}
