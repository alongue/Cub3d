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
#include <string.h>

#define MIN 0
#define MAX 1
#define X 0
#define Y 1

#include <stdio.h>

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

	xtreme = recover_xtreme(NULL, &boundend, 0);
	i = -1;
	while (++i < boundend)
	{
		if (x == get_xtreme_x(xtreme[i]) && y == get_xtreme_y(xtreme[i]))
			return (i);
	}
	return (-1);
}

char	**recover_xtreme(int *coor, int *end, int location)
{
	static char	**xtreme;
	static int	i = -1;
	static int	icop = -1;
	char		*temp[2];

	*end = i + 1;
	if (!coor)
		return (xtreme);
	if (location != BLOCKED)
	{
		icop++;
		i = icop;
	}
	else
	{
		i = remind(coor[1], coor[0]);
	}
	if (i == 0 && location != BLOCKED)
		xtreme = malloc(sizeof(char *) * 1);
	else if (location != BLOCKED)
		xtreme = ft_realloc(xtreme, sizeof(char *) * (i + 1));
	temp[0] = ft_itoa(coor[1]);
	if (coor[1] <= 9)
		temp[0] = ft_strjoin_free(ft_strdup("0"), temp[0]);
	temp[1] = ft_itoa(coor[0]);
	if (coor[0] <= 9)
		temp[1] = ft_strjoin_free(ft_strdup("0"), temp[1]);
	if (location == BLOCKED)
		free(xtreme[i]);
	xtreme[i] = ft_strjoin_free(temp[0],
	ft_strjoin_free(temp[1], ft_itoa(location)));
	return (xtreme);
}

int		searching_around(t_map *map, int *coor, int moving_side)
{
	int			location;
	static int	oldlocation = TOP;
	int			fakecoor[2];
	int			ret[2];

	fakecoor[0] = coor[0];
	fakecoor[1] = coor[1];
	location = (get_location(moving_side) == BLOCKED) ?
		oldlocation : get_location(moving_side);
	if (remind(coor[1], coor[0]) != -1)
		return (BLOCKED);
	recover_xtreme(coor, &coor[2], location);
	if (location == TOP)
	{
		if (moving_side != BOT)
		{
			if ((ret[0] = moving_top(map->number,
			coor, fakecoor, map->nbcuby)) == STOP)
			{
				return (STOP);
			}
			if (ret[0] != BLOCKED)
			{
				map->parsepos[fakecoor[0] * map->nbxmax + fakecoor[1]] = 1;
				oldlocation = location;
				if ((fakecoor[0] == 0 && fakecoor[1] == get_line_nbmin(map->number, 0)))
					return ((ret[0] = ISFINISH));
				if ((ret[1] = searching_around(map, fakecoor, ret[0])) == ISFINISH || ret[1] == STOP)
					return (ret[1]);
				else if (ret[1] == BLOCKED)
					fakecoor[0]++;
			}
		}
		if (moving_side != LEFT)
		{
			if ((ret[0] = moving_right(map->number, coor, fakecoor)) == STOP)
				return (STOP);
			if (ret[0] != BLOCKED)
			{
				map->parsepos[fakecoor[0] * map->nbxmax + fakecoor[1]] = 1;
				oldlocation = location;
				if ((fakecoor[0] == 0 && fakecoor[1] == get_line_nbmin(map->number, 0)))
					return ((ret[0] = ISFINISH));
				if ((ret[1] = searching_around(map, fakecoor, ret[0])) == ISFINISH || ret[1] == STOP)
					return (ret[1]);
				else if (ret[1] == BLOCKED)
					fakecoor[1]--;
			}
		}
		if (moving_side != TOP)
		{
			if ((ret[0] = moving_bot(map->number, coor, fakecoor, map->nbcuby)) == STOP)
				return (STOP);
			if (ret[0] != BLOCKED)
			{
				map->parsepos[fakecoor[0] * map->nbxmax + fakecoor[1]] = 1;
				oldlocation = location;
				if ((fakecoor[0] == 0 && fakecoor[1] == get_line_nbmin(map->number, 0)))
					return ((ret[0] = ISFINISH));
				if ((ret[1] = searching_around(map, fakecoor, ret[0])) == ISFINISH || ret[1] == STOP)
					return (ret[1]);
				else if (ret[1] == BLOCKED)
					fakecoor[0]--;
			}
		}
	}
	else if (location == RIGHT)
	{
		if (moving_side != LEFT)
		{
			if ((ret[0] = moving_right(map->number, coor, fakecoor)) == STOP)
				return (STOP);
			if (ret[0] != BLOCKED)
			{
				map->parsepos[fakecoor[0] * map->nbxmax + fakecoor[1]] = 1;
				oldlocation = location;
				if ((fakecoor[0] == 0 && fakecoor[1] == get_line_nbmin(map->number, 0)))
					return ((ret[0] = ISFINISH));
				if ((ret[1] = searching_around(map, fakecoor, ret[0])) == ISFINISH || ret[1] == STOP)
					return (ret[1]);
				else if (ret[1] == BLOCKED)
				{
					fakecoor[1]--;
				}
			}
		}
		if (moving_side != TOP)
		{
			if ((ret[0] = moving_bot(map->number, coor, fakecoor, map->nbcuby)) == STOP)
				return (STOP);
			if (ret[0] != BLOCKED)
			{
				map->parsepos[fakecoor[0] * map->nbxmax + fakecoor[1]] = 1;
				oldlocation = location;
				if ((fakecoor[0] == 0 && fakecoor[1] == get_line_nbmin(map->number, 0)))
					return ((ret[0] = ISFINISH));
				if ((ret[1] = searching_around(map, fakecoor, ret[0])) == ISFINISH || ret[1] == STOP)
					return (ret[1]);
				else if (ret[1] == BLOCKED)
				{
					fakecoor[0]--;
				}
			}
		}
		if (moving_side != RIGHT)
		{
			if ((ret[0] = moving_left(map->number, coor, fakecoor)) == STOP)
				return (STOP);
			if (ret[0] != BLOCKED)
			{
				map->parsepos[fakecoor[0] * map->nbxmax + fakecoor[1]] = 1;
				oldlocation = location;
				if ((fakecoor[0] == 0 && fakecoor[1] == get_line_nbmin(map->number, 0)))
					return ((ret[0] = ISFINISH));
				if ((ret[1] = searching_around(map, fakecoor, ret[0])) == ISFINISH || ret[1] == STOP)
					return (ret[1]);
				else if (ret[1] == BLOCKED)
				{
					fakecoor[1]++;
				}
			}
		}
	}
	else if (location == BOT)
	{
		if (moving_side != TOP)
		{
			if ((ret[0] = moving_bot(map->number, coor, fakecoor, map->nbcuby)) == STOP)
				return (STOP);
			if (ret[0] != BLOCKED)
			{
				map->parsepos[fakecoor[0] * map->nbxmax + fakecoor[1]] = 1;
				oldlocation = location;
				if ((fakecoor[0] == 0 && fakecoor[1] == get_line_nbmin(map->number, 0)))
					return ((ret[0] = ISFINISH));
				if ((ret[1] = searching_around(map, fakecoor, ret[0])) == ISFINISH || ret[1] == STOP)
					return (ret[1]);
				else if (ret[1] == BLOCKED)
				{
					fakecoor[0]--;
				}
			}
		}
		if (moving_side != RIGHT)
		{
			if ((ret[0] = moving_left(map->number, coor, fakecoor)) == STOP)
				return (STOP);
			if (ret[0] != BLOCKED)
			{
				map->parsepos[fakecoor[0] * map->nbxmax + fakecoor[1]] = 1;
				oldlocation = location;
				if ((fakecoor[0] == 0 && fakecoor[1] == get_line_nbmin(map->number, 0)))
					return ((ret[0] = ISFINISH));
				if ((ret[1] = searching_around(map, fakecoor, ret[0])) == ISFINISH || ret[1] == STOP)
					return (ret[1]);
				else if (ret[1] == BLOCKED)
				{
					fakecoor[1]++;
				}
			}
		}
		if (moving_side != BOT)
		{
			if ((ret[0] = moving_top(map->number, coor, fakecoor, map->nbcuby)) == STOP)
				return (STOP);
			if (ret[0] != BLOCKED)
			{
				map->parsepos[fakecoor[0] * map->nbxmax + fakecoor[1]] = 1;
				oldlocation = location;
				if ((fakecoor[0] == 0 && fakecoor[1] == get_line_nbmin(map->number, 0)))
					return ((ret[0] = ISFINISH));
				if ((ret[1] = searching_around(map, fakecoor, ret[0])) == ISFINISH || ret[1] == STOP)
					return (ret[1]);
				else if (ret[1] == BLOCKED)
				{
					fakecoor[0]++;
				}
			}
		}
	}
	else if (location == LEFT)
	{
		if (moving_side != RIGHT)
		{
			if ((ret[0] = moving_left(map->number, coor, fakecoor)) == STOP)
				return (STOP);
			if (ret[0] != BLOCKED)
			{
				map->parsepos[fakecoor[0] * map->nbxmax + fakecoor[1]] = 1;
				oldlocation = location;
				if ((fakecoor[0] == 0 && fakecoor[1] == get_line_nbmin(map->number, 0)))
					return ((ret[0] = ISFINISH));
				if ((ret[1] = searching_around(map, fakecoor, ret[0])) == ISFINISH || ret[1] == STOP)
					return (ret[1]);
				else if (ret[1] == BLOCKED)
					fakecoor[1]++;
			}
		}
		if (moving_side != BOT)
		{
			if ((ret[0] = moving_top(map->number,
			coor, fakecoor, map->nbcuby)) == STOP)
			{
				return (STOP);
			}
			if (ret[0] != BLOCKED)
			{
				map->parsepos[fakecoor[0] * map->nbxmax + fakecoor[1]] = 1;
				oldlocation = location;
				if ((fakecoor[0] == 0 && fakecoor[1] == get_line_nbmin(map->number, 0)))
					return ((ret[0] = ISFINISH));
				if ((ret[1] = searching_around(map, fakecoor, ret[0])) == ISFINISH || ret[1] == STOP)
					return (ret[1]);
				else if (ret[1] == BLOCKED)
					fakecoor[0]++;
			}
		}
		if (moving_side != LEFT)
		{
			if ((ret[0] = moving_right(map->number, coor, fakecoor)) == STOP)
				return (STOP);
			if (ret[0] != BLOCKED)
			{
				map->parsepos[fakecoor[0] * map->nbxmax + fakecoor[1]] = 1;
				oldlocation = location;
				if ((fakecoor[0] == 0 && fakecoor[1] ==
				get_line_nbmin(map->number, 0)))
				{
					return ((ret[0] = ISFINISH));
				}
				if ((ret[1] = searching_around(map, fakecoor,
				ret[0])) == ISFINISH || ret[1] == STOP)
				{
					return (ret[1]);
				}
				else if (ret[1] == BLOCKED)
					fakecoor[1]--;
			}
		}
	}
	recover_xtreme(coor, &coor[2], BLOCKED);
	map->backtrackpos[fakecoor[0] * map->nbxmax + fakecoor[1]] = 1;
	return (BLOCKED);
}
