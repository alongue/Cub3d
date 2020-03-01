/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bsp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:02:24 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/01 14:48:38 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	renderbsp(t_data *data, t_node current, t_player player)
{
	int		result;

	result = classify_point(current.splitter, player.pos);
	if (result == FRONT)
	{
		if (current.backchild)
			renderbsp(data, *current.backchild, player);
		display_wall(data, current.splitter.wall);
		if (current.frontchild)
			renderbsp(data, *current.frontchild, player);
	}
	else
	{
		if (current.frontchild)
			renderbsp(data, *current.frontchild, player);
		display_wall(data, current.splitter.wall);
		if (current.backchild)
			renderbsp(data, *current.backchild, player);
	}
}
