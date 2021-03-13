/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getside.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 11:14:51 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/12 11:14:53 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		is_boundaries_to_count(int x, int y)
{
	if (((is_boundaries(x, y - 1) && !is_boundaries(x, y + 1))
	|| (is_boundaries(x, y - 1) && is_boundaries(x, y + 1) &&
	get_xtreme_location(x, y + 1) != BLOCKED)
	|| (is_boundaries(x, y + 1) && !is_boundaries(x, y - 1))
	|| (is_boundaries(x, y + 1) && is_boundaries(x, y - 1) &&
	get_xtreme_location(x, y - 1) != BLOCKED))
	&& !(is_boundaries(x, y - 1) && get_xtreme_location(x, y - 1) != BLOCKED
	&& is_boundaries(x, y + 1) && get_xtreme_location(x, y + 1) != BLOCKED))
		return (1);
	else
		return (0);
}

int		clean(char *b4_xtreme, int *side, int *static_outside, int ret)
{
	free(b4_xtreme);
	*side = BLOCKED;
	*static_outside = BLOCKED;
	return (ret);
}

int		do_bot(int *coor, int *side, int *static_outside, int oldside)
{
	char		*b4_xtreme;

	printf("coor[0] = %d\tet\tcoor[1] = %d (bot)\n", coor[0], coor[1]);
	if (is_boundaries(coor[0], coor[1] + 1))
	{
		b4_xtreme = get_xtreme(coor[0], coor[1] + 1);
		if (ft_atoi(&b4_xtreme[4]) != BLOCKED && *static_outside == 0)
			return (clean(b4_xtreme, side, static_outside, oldside));
		else if (ft_atoi(&b4_xtreme[4]) != BLOCKED &&
		*static_outside == 1)
			return (clean(b4_xtreme, side, static_outside, !oldside));
	}
	else if (is_boundaries(coor[0], coor[1] - 1))
	{
		b4_xtreme = get_xtreme(coor[0], coor[1] - 1);
		if (ft_atoi(&b4_xtreme[4]) != BLOCKED &&
		*static_outside == 0)
			return (clean(b4_xtreme, side, static_outside, !oldside));
		else if (ft_atoi(&b4_xtreme[4]) !=
		BLOCKED && *static_outside == 1)
			return (clean(b4_xtreme, side, static_outside, oldside));
	}
	return (-1);
}

int		do_top(int *coor, int *side, int *static_outside, int oldside)
{
	char		*b4_xtreme;

	printf("coor[0] = %d\tet\tcoor[1] = %d (top)\n", coor[0], coor[1]);
	if (is_boundaries(coor[0], coor[1] - 1))
	{
		b4_xtreme = get_xtreme(coor[0], coor[1] - 1);
		if (ft_atoi(&b4_xtreme[4]) != BLOCKED
		&& *static_outside == 0)
			return (clean(b4_xtreme, side, static_outside, oldside));
		else if (ft_atoi(&b4_xtreme[4]) !=
		BLOCKED && *static_outside == 1)
			return (clean(b4_xtreme, side, static_outside, !oldside));
	}
	else if (is_boundaries(coor[0], coor[1] + 1))
	{
		b4_xtreme = get_xtreme(coor[0], coor[1] + 1);
		if (ft_atoi(&b4_xtreme[4]) != BLOCKED &&
		*static_outside == 0)
			return (clean(b4_xtreme, side, static_outside, !oldside));
		else if (ft_atoi(&b4_xtreme[4]) != BLOCKED &&
		*static_outside == 1)
			return (clean(b4_xtreme, side, static_outside, oldside));
	}
	return (-1);
}

int		getside(int y, char *xtreme, int oldside)
{
	int			coor[2];
	static int	side = BLOCKED;
	static int	static_outside = BLOCKED;
	static int	ycop = 0;

	coor[0] = get_xtreme_x(xtreme);
	coor[1] = y;
	init_getside(coor, &ycop, &side, &static_outside);
	if (is_boundaries_to_count(coor[0], coor[1]))
	{
		if (side == BOT)
			return (do_bot(coor, &side, &static_outside, oldside));
		else if (side == TOP)
			return (do_top(coor, &side, &static_outside, oldside));
		else if (is_boundaries(coor[0], coor[1] - 1))
			return (start_from_up(coor, &side, &static_outside, oldside));
		else if (is_boundaries(coor[0], coor[1] + 1))
			return (start_from_down(coor, &side, &static_outside, oldside));
	}
	if (is_boundaries(coor[0] + 1, coor[1]))
		return (oldside);
	return (!oldside);
}
