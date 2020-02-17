/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bsp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:02:24 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/17 13:04:55 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	renderbsp(t_data *data, t_node *current, t_player *player)
{
	int		result;

	result = classifypoint(player, current->polygon);
	if (result == FRONT)
	{
		if (current->backchild)
			renderbsp(current->backchild);
		display_wall(data, current->wall);
		if (current->frontchild)
			renderbsp(current->frontchild);
	}
	else
	{
		if (current->frontchild)
			renderbsp(current->frontchild);
		display_wall(data, current->wall);
		if (current->backchild)
			renderbsp(current->backchild);
	}
}
