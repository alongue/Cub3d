/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching_around.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:41:07 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/04 12:10:39 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		get_location(char **number, int col, int lin, int *nbcuby)
{
	if (lin == get_col_nbmin(number, col))
		return (TOP);
	else if (col == get_line_nbmax(number, lin))
		return (RIGHT);
	else if (lin == get_col_nbmax(number, col, nbcuby))
		return (BOT);
	else if (col == get_line_nbmin(number, lin))
		return (LEFT);
	return (BLOCKED);
}

int		searching_around(char **number, int *coor, int moving_side, int *nbcuby)
{
	static int	location = TOP;
	static int	ret = BLOCKED;

	location = (get_location(number, coor[1], coor[0], nbcuby) == BLOCKED) ?
		location : get_location(number, coor[1], coor[0], nbcuby);
	if (location == TOP)
	{
		if (moving_side != BOT)
		{
			moving_side = moving_top(number, &coor[1], &coor[0]);
			if (moving_side != BLOCKED)
				if ((ret = searching_around(number, coor, moving_side, nbcuby)) == ISFINISH || ret == STOP)
					return (ret);
		}
		if (moving_side != LEFT)
		{
			moving_side = moving_right(number, &coor[1], &coor[0]);
			if (moving_side != BLOCKED)
				if ((ret = searching_around(number, coor, moving_side, nbcuby)) == ISFINISH || ret == STOP)
					return (ret);
		}
		if (moving_side != RIGHT)
		{
			moving_side = moving_left(number, &coor[1], &coor[0]);
			if (moving_side != BLOCKED)
				if ((ret = searching_around(number, coor, moving_side, nbcuby)) == ISFINISH || ret == STOP)
					return (ret);
		}
		if (moving_side == BLOCKED)
			return (moving_side);
	}
	else if (location == RIGHT)
	{
		if (moving_side != LEFT)
		{
			moving_side = moving_right(number, &coor[1], &coor[0]);
			if (moving_side != BLOCKED)
				if ((ret = searching_around(number, coor, moving_side, nbcuby)) == ISFINISH || ret == STOP)
					return (ret);
		}
		if (moving_side != TOP)
		{
			moving_side = moving_bot(number, &coor[1], &coor[0], nbcuby);
			if (moving_side != BLOCKED)
				if ((ret = searching_around(number, coor, moving_side, nbcuby)) == ISFINISH || ret == STOP)
					return (ret);
		}
		if (moving_side != RIGHT)
		{
			moving_side = moving_left(number, &coor[1], &coor[0]);
			if (moving_side != BLOCKED)
				if ((ret = searching_around(number, coor, moving_side, nbcuby)) == ISFINISH || ret == STOP)
					return (ret);
		}
		if (moving_side == BLOCKED)
			return (moving_side);
	}
	else if (location == BOT)
	{
		if (moving_side != TOP)
		{
			moving_side = moving_bot(number, &coor[1], &coor[0], nbcuby);
			if (moving_side != BLOCKED)
				if ((ret = searching_around(number, coor, moving_side, nbcuby)) == ISFINISH || ret == STOP)
					return (ret);
		}
		if (moving_side != RIGHT)
		{
			moving_side = moving_left(number, &coor[1], &coor[0]);
			if (moving_side != BLOCKED)
				if ((ret = searching_around(number, coor, moving_side, nbcuby)) == ISFINISH || ret == STOP)
					return (ret);
		}
		if (moving_side != BOT)
		{
			moving_side = moving_top(number, &coor[1], &coor[0]);
			if (moving_side != BLOCKED)
				if ((ret = searching_around(number, coor, moving_side, nbcuby)) == ISFINISH || ret == STOP)
					return (ret);
		}
		if (moving_side == BLOCKED)
			return (moving_side);
	}
	else if (location == LEFT)
	{
		if (coor[0] == 0 && coor[1] == 0)
			return ((moving_side = ISFINISH));
		if (moving_side != RIGHT)
		{
			moving_side = moving_left(number, &coor[1], &coor[0]);
			if (moving_side != BLOCKED)
				if ((ret = searching_around(number, coor, moving_side, nbcuby)) == ISFINISH || ret == STOP)
					return (ret);
		}
		if (moving_side != BOT)
		{
			moving_side = moving_top(number, &coor[1], &coor[0]);
			if (moving_side != BLOCKED)
				if ((ret = searching_around(number, coor, moving_side, nbcuby)) == ISFINISH || ret == STOP)
					return (ret);
		}
		if (moving_side != LEFT)
		{
			moving_side = moving_right(number, &coor[1], &coor[0]);
			if (moving_side != BLOCKED)
				if ((ret = searching_around(number, coor, moving_side, nbcuby)) == ISFINISH || ret == STOP)
					return (ret);
		}
		if (moving_side == BLOCKED)
			return (moving_side);
	}
	return (moving_side == BLOCKED);
}
