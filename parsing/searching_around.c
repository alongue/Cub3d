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

int		searching_around(char **number, int *nbcuby, int col, int lin)
{
	static int	moving_side = TOP;
	static int	location = TOP;
	static int	ret = TOP;

	if (moving_side == ISFINISH || moving_side == STOP)
		return (moving_side);
	location = (get_location(number, nbcuby, col, lin) == BLOCKED) ?
		location : get_location(number, nbcuby, col, lin);
	if (location == TOP)
	{
		if (moving_side != BOT)
			moving_side = ((ret = moving_top(number, nbcuby, &col, &lin)) == BLOCKED) ?
				moving_side : ret;
		else if (moving_side == TOP)
			moving_side = searching_around(number, nbcuby, col, lin);
		if (moving_side != LEFT)
			moving_side = ((ret = moving_right(number, nbcuby, &col, &lin)) == BLOCKED) ?
				moving_side : ret;
		else if (moving_side == RIGHT)
			moving_side = searching_around(number, nbcuby, col, lin);
		if (moving_side != RIGHT)
			moving_side = ((ret = moving_left(number, nbcuby, &col, &lin)) == BLOCKED) ?
				moving_side : ret;
		else if (moving_side == LEFT)
			moving_side = searching_around(number, nbcuby, col, lin);
		return ((moving_side = BLOCKED));
	}
	if (location == RIGHT)
	{

	}
	if (location == BOT)
	{
	}
	if (location == LEFT)
	{
		if (col == 0 && lin == 0)
			return ((moving_side = ISFINISH));
	}
}
