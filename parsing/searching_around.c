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

int		get_location(char **number, int *nbcuby, int col, int lin)
{
	if (lin == get_col_nbmin(number, col))
		return (TOP);
	else if (col == get_line_nbmax(number, lin))
		return (RIGHT);
	else if (lin == get_col_nbmax(number, col))
		return (BOT);
	else if (col == get_lin_nbmin(number, lin))
		return (LEFT);
	return (BLOCKED);
}

int		searching_around(char **number, int *nbcuby, int *coor, int moving_side)
{
	static int	location = TOP;
	static int	ret = BLOCKED;

	location = (get_location(number, nbcuby, &coor[1], &coor[0]) == BLOCKED) ?
		location : get_location(number, nbcuby, &coor[1], &coor[0]);
	if (location == TOP)
	{
		if (moving_side != BOT)
		{
			moving_side = moving_top(number, nbcuby, &coor[1], &coor[0]);
			if (moving_side != BLOCKED)
				if ((ret = searching_around(number, nbcuby, coor, moving_side)) == ISFINISH || ret == STOP)
					return (ret);
		}
		if (moving_side != LEFT)
		{
			moving_side = moving_right(number, nbcuby, &coor[1], &coor[0]);
			if (moving_side != BLOCKED)
				if ((ret = searching_around(number, nbcuby, coor, moving_side)) == ISFINISH || ret == STOP)
					return (ret);
		}
		if (moving_side != RIGHT)
		{
			moving_side = moving_left(number, nbcuby, &coor[1], &coor[0]);
			if (moving_side != BLOCKED)
				if ((ret = searching_around(number, nbcuby, coor, moving_side)) == ISFINISH || ret == STOP)
					return (ret);
		}
		if (moving_side == BLOCKED)
			return (moving_side);
	}
	else if (location == RIGHT)
	{
		if (moving_side != LEFT)
		{
			moving_side = moving_right(number, nbcuby, &coor[1], &coor[0]);
			if (moving_side != BLOCKED)
				if ((ret = searching_around(number, nbcuby, coor, moving_side)) == ISFINISH || ret == STOP)
					return (ret);
		}
		if (moving_side != TOP)
		{
			moving_side = moving_bot(number, nbcuby, &coor[1], &coor[0]);
			if (moving_side != BLOCKED)
				if ((ret = searching_around(number, nbcuby, coor, moving_side)) == ISFINISH || ret == STOP)
					return (ret);
		}
		if (moving_side != RIGHT)
		{
			moving_side = moving_left(number, nbcuby, &coor[1], &coor[0]);
			if (moving_side != BLOCKED)
				if ((ret = searching_around(number, nbcuby, coor, moving_side)) == ISFINISH || ret == STOP)
					return (ret);
		}
		if (moving_side == BLOCKED)
			return (moving_side);
	}
	else if (location == BOT)
	{
		if (moving_side != TOP)
		{
			moving_side = moving_bot(number, nbcuby, &coor[1], &coor[0]);
			if (moving_side != BLOCKED)
				if ((ret = searching_around(number, nbcuby, coor, moving_side)) == ISFINISH || ret == STOP)
					return (ret);
		}
		if (moving_side != RIGHT)
		{
			moving_side = moving_left(number, nbcuby, &coor[1], &coor[0]);
			if (moving_side != BLOCKED)
				if ((ret = searching_around(number, nbcuby, coor, moving_side)) == ISFINISH || ret == STOP)
					return (ret);
		}
		if (moving_side != BOT)
		{
			moving_side = moving_top(number, nbcuby, &coor[1], &coor[0]);
			if (moving_side != BLOCKED)
				if ((ret = searching_around(number, nbcuby, coor, moving_side)) == ISFINISH || ret == STOP)
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
			moving_side = moving_left(number, nbcuby, &coor[1], &coor[0]);
			if (moving_side != BLOCKED)
				if ((ret = searching_around(number, nbcuby, coor, moving_side)) == ISFINISH || ret == STOP)
					return (ret);
		}
		if (moving_side != BOT)
		{
			moving_side = moving_top(number, nbcuby, &coor[1], &coor[0]);
			if (moving_side != BLOCKED)
				if ((ret = searching_around(number, nbcuby, coor, moving_side)) == ISFINISH || ret == STOP)
					return (ret);
		}
		if (moving_side != LEFT)
		{
			moving_side = moving_right(number, nbcuby, &coor[1], &coor[0]);
			if (moving_side != BLOCKED)
				if ((ret = searching_around(number, nbcuby, coor, moving_side)) == ISFINISH || ret == STOP)
					return (ret);
		}
		if (moving_side == BLOCKED)
			return (moving_side);
	}
}
