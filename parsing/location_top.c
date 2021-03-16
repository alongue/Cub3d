/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   location_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 12:23:18 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/13 12:23:29 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		do_moving_top(t_map *map, int *fakecoor, int moving_result, int *ret)
{
	if ((ret[0] = moving_result) == STOP)
		return (STOP);
	if (ret[0] != BLOCKED)
	{
		if ((fakecoor[0] == 0 &&
		fakecoor[1] == get_line_nbmin(map->number, 0)))
			return ((ret[0] = ISFINISH));
		if ((ret[1] = searching_around(map, fakecoor, ret[0]))
		== ISFINISH || ret[1] == STOP)
			return (ret[1]);
		else if (ret[1] == BLOCKED)
			fakecoor[0]++;
	}
	return (BLOCKED);
}

int		do_location_top(void **params, int *fakecoor, int *coor, int *ret)
{
	int		*location;
	int		*oldlocation;
	int		*moving_side;
	t_map	*map;
	int		*test;

	location = NULL;
	oldlocation = NULL;
	moving_side = NULL;
	map = deref_params(params, &location, &oldlocation, &moving_side);
	test = params[2];
	printf("avant\n");
	printf("params[2] = %d (dans do_location_top) alors que moving_side = %d\n", *test, *moving_side);
	printf("apres\n");
	if (*moving_side != BOT)
		if ((ret[2] = do_moving_top(map, fakecoor, set_oldlocation(oldlocation,
		*location, moving_top(map->number, coor, fakecoor, map->nbcuby)),
		ret)) == ISFINISH || ret[2] == STOP)
			return (ret[2]);
	printf("moving_side = %d\n", *moving_side);
	printf("did not move up\n");
	if (*moving_side != LEFT)
		if ((ret[2] = do_moving_right(map, fakecoor, set_oldlocation(
		oldlocation, *location, moving_right(map->number, coor, fakecoor)),
		ret)) == ISFINISH || ret[2] == STOP)
			return (ret[2]);
	printf("did not move right\n");
	if (*moving_side != TOP)
		if ((ret[2] = do_moving_bot(map, fakecoor, set_oldlocation(oldlocation,
		*location, moving_bot(map->number, coor, fakecoor, map->nbcuby)),
		ret)) == ISFINISH || ret[2] == STOP)
			return (ret[2]);
	printf("did not move down\n");
	return (BLOCKED);
}
