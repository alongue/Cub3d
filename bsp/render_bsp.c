/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bsp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:02:24 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/10 13:50:26 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	renderbsp(t_data *data, t_node current, t_player player)
{
	int		result;

	printf("HOLA !!\n");
	if (current.isleaf)
	{
		display_wall(data, current.splitter.wall);
		return ;
	}
	result = classify_point(current.splitter, player.pos);
	if (result == FRONT || result == COINCIDING)
	{
		//if (current.backchild->exist)
			renderbsp(data, *current.backchild, player);
		//if (current.frontchild->exist)
			renderbsp(data, *current.frontchild, player);
	}
	else
	{
		//if (current.frontchild->exist)
			renderbsp(data, *current.frontchild, player);
		//if (current.backchild->exist)
			renderbsp(data, *current.backchild, player);
	}
}
