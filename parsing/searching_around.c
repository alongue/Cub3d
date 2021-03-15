/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching_around.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:41:07 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 20:27:51 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

#define MIN 0
#define MAX 1
#define X 0
#define Y 1

int		set_oldlocation(int *oldlocation, int location, int condition)
{
	if (condition)
		*oldlocation = location;
	return (condition);
}

t_map	*deref_params(void **params, int *location,
int *oldlocation, int *moving_side)
{
	t_map	*map;

	location = (int *)params[0];
	oldlocation = (int *)params[1];
	moving_side = (int *)params[2];
	map = (t_map *)params[3];
	(void)location;
	(void)oldlocation;
	(void)moving_side;
	return (map);
}

void	**get_params(int *location, int *oldlocation,
int *moving_side, t_map *map)
{
	void	**params;

	if (!(params = malloc(sizeof(void *) * 4)))
		return (free_xtreme(NULL, MALLOC));
	params[0] = (void *)location;
	params[1] = (void *)oldlocation;
	params[2] = (void *)moving_side;
	params[3] = (void *)map;
	return (params);
}

int		init_searching_around(int *fakecoor, int *coor,
int moving_side, int oldlocation)
{
	int		location;

	fakecoor[0] = coor[0];
	fakecoor[1] = coor[1];
	location = (get_location(moving_side) == BLOCKED) ?
		oldlocation : get_location(moving_side);
	if (remind(coor[1], coor[0]) != -1)
		return (BLOCKED);
	if (!recover_xtreme(coor, &coor[2], location))
		return (BLOCKED);
	return (location);
}

int		searching_around(t_map *map, int *coor, int moving_side)
{
	int			location;
	static int	oldlocation = TOP;
	int			fakecoor[2];
	int			ret[3];
	void		**params;

	if ((location = init_searching_around(fakecoor,
	coor, moving_side, oldlocation)) == BLOCKED || !(params =
	get_params(&location, &oldlocation, &moving_side, map)))
		return (BLOCKED);
	if (location == TOP)
		ret[2] = do_location_top(params, fakecoor, coor, ret);
	else if (location == RIGHT)
		ret[2] = do_location_right(params, fakecoor, coor, ret);
	else if (location == BOT)
		ret[2] = do_location_bot(params, fakecoor, coor, ret);
	else if (location == LEFT)
		ret[2] = do_location_left(params, fakecoor, coor, ret);
	if (ret[2] == ISFINISH || ret[2] == STOP)
		return (ft_free_ret(ret[2], (void **)&params,
		(free_xtreme(NULL, MALLOC)), NULL));
	if (!recover_xtreme(coor, &coor[2], BLOCKED))
		return (BLOCKED);
	return (BLOCKED);
}
