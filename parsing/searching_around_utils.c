/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching_around_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 18:11:42 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/12 18:11:55 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		get_location(int moving_side)
{
	if (moving_side == RIGHT)
		return (TOP);
	else if (moving_side == LEFT)
		return (BOT);
	else if (moving_side == TOP)
		return (LEFT);
	else if (moving_side == BOT)
		return (RIGHT);
	return (BLOCKED);
}

int		remind(int x, int y)
{
	char	**xtreme;
	int		boundend;
	int		i;

	if (!(xtreme = recover_xtreme(NULL, &boundend, 0)))
		return (BLOCKED);
	i = -1;
	while (++i < boundend)
	{
		if (x == get_xtreme_x(xtreme[i]) && y == get_xtreme_y(xtreme[i]))
			return (i);
	}
	return (-1);
}

void	*free_xtreme(void *ret, char *msg, int can_do)
{
	char	***xtreme;
	int		boundend;
	int		counter;

	xtreme = xtreme_addr(NULL, &boundend);
	counter = -1;
	if (*xtreme && (can_do == 1 || can_do == 2 || can_do == STOP))
	{
		if (can_do == 2 || can_do == STOP)
			boundend--;
		while (++counter <= boundend)
		{
			free((*xtreme)[counter]);
		}
	}
	if (can_do == 1 || can_do == 2 || can_do == STOP)
	{
		free_msg_once(0, msg, NULL, NULL);
		ft_free_ret(0, (void **)xtreme, NULL, NULL);
	}
	return (ret);
}
