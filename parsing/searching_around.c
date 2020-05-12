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
	printf("col = %d\tet\tget_line_nbmax(number, %d) = %d\n", col, lin, get_line_nbmax(number, lin));
	//sleep(2);
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
	int			location;
	static int	oldlocation = TOP;
	int			fakecoor[2];

	fakecoor[0] = coor[0];
	fakecoor[1] = coor[1];
	//printf("fakecoor[1] = %d\tet\tcoor[1] = %d\n", fakecoor[1], coor[1]);
	location = (get_location(number, fakecoor[1], fakecoor[0], nbcuby) == BLOCKED) ?
		oldlocation : get_location(number, fakecoor[1], fakecoor[0], nbcuby);
	oldlocation = location;
	printf("fakecoor[0] = %d\tet\tfakecoor[1] = %d\n", fakecoor[0], fakecoor[1]);
	printf("location = %d\n", location);
	if (location == TOP)
	{
		if (moving_side != BOT) //laisser le code tel quel dans une autre fonction (ca va surement marcher en fait)
		{			
			if ((moving_side = moving_top(number, coor, fakecoor)) == STOP)
				return (STOP);
			if (moving_side != BLOCKED)
			{
				if (fakecoor[0] == get_col_nbmin(number, 0) && fakecoor[1] == get_line_nbmin(number, 0))
					return ((moving_side = ISFINISH));
				if ((moving_side = searching_around(number, fakecoor, moving_side, nbcuby)) == ISFINISH || moving_side == STOP)
					return (moving_side);
			}
		}
		if (moving_side != LEFT)
		{			
			if ((moving_side = moving_right(number, coor, fakecoor)) == STOP)
				return (STOP);
			if (moving_side != BLOCKED)
			{
				if (fakecoor[0] == get_col_nbmin(number, 0) && fakecoor[1] == get_line_nbmin(number, 0))
					return ((moving_side = ISFINISH));
				if ((moving_side = searching_around(number, fakecoor, moving_side, nbcuby)) == ISFINISH || moving_side == STOP)
					return (moving_side);
			}
		}
		if (moving_side != TOP)
		{			
			if ((moving_side = moving_bot(number, coor, fakecoor, nbcuby)) == STOP)
				return (STOP);
			if (moving_side != BLOCKED)
			{
				if (fakecoor[0] == get_col_nbmin(number, 0) && fakecoor[1] == get_line_nbmin(number, 0))
					return ((moving_side = ISFINISH));
				if ((moving_side = searching_around(number, fakecoor, moving_side, nbcuby)) == ISFINISH || moving_side == STOP)
					return (moving_side);
			}
		}
	}
	else if (location == RIGHT)
	{
		if (moving_side != LEFT)
		{			
			if ((moving_side = moving_right(number, coor, fakecoor)) == STOP)
				return (STOP);
			if (moving_side != BLOCKED)
				if ((moving_side = searching_around(number, fakecoor, moving_side, nbcuby)) == ISFINISH || moving_side == STOP)
					return (moving_side);
		}
		if (moving_side != TOP)
		{			
			if ((moving_side = moving_bot(number, coor, fakecoor, nbcuby)) == STOP)
				return (STOP);
			if (moving_side != BLOCKED)
				if ((moving_side = searching_around(number, fakecoor, moving_side, nbcuby)) == ISFINISH || moving_side == STOP)
					return (moving_side);
			printf("(bot) coor[0] = %d\tet\tcoor[1] = %d\n", coor[0], fakecoor[1]);
		}
		if (moving_side != RIGHT)
		{
			printf("(left) coor[0] = %d\tet\tcoor[1] = %d\n", coor[0], fakecoor[1]);
			if ((moving_side = moving_left(number, coor, fakecoor)) == STOP)
				return (STOP);
			if (moving_side != BLOCKED)
				if ((moving_side = searching_around(number, fakecoor, moving_side, nbcuby)) == ISFINISH || moving_side == STOP)
					return (moving_side);
		}
	}
	else if (location == BOT)
	{
		if (moving_side != TOP)
		{			
			if ((moving_side = moving_bot(number, coor, fakecoor, nbcuby)) == STOP)
				return (STOP);
			if (moving_side != BLOCKED)
				if ((moving_side = searching_around(number, fakecoor, moving_side, nbcuby)) == ISFINISH || moving_side == STOP)
					return (moving_side);
		}
		if (moving_side != RIGHT)
		{			
			if ((moving_side = moving_left(number, coor, fakecoor)) == STOP)
				return (STOP);
			if (moving_side != BLOCKED)
				if ((moving_side = searching_around(number, fakecoor, moving_side, nbcuby)) == ISFINISH || moving_side == STOP)
					return (moving_side);
		}
		if (moving_side != BOT)
		{			
			if ((moving_side = moving_top(number, coor, fakecoor)) == STOP)
				return (STOP);
			if (moving_side != BLOCKED)
				if ((moving_side = searching_around(number, fakecoor, moving_side, nbcuby)) == ISFINISH || moving_side == STOP)
					return (moving_side);
		}
	}
	else if (location == LEFT)
	{
		if (moving_side != RIGHT)
		{			
			if ((moving_side = moving_left(number, coor, fakecoor)) == STOP)
				return (STOP);
			if (moving_side != BLOCKED)
			{
				if (fakecoor[0] == get_col_nbmin(number, 0) && fakecoor[1] == get_line_nbmin(number, 0))
					return ((moving_side = ISFINISH));
				if ((moving_side = searching_around(number, fakecoor, moving_side, nbcuby)) == ISFINISH || moving_side == STOP)
					return (moving_side);
			}
		}
		if (moving_side != BOT)
		{			
			if ((moving_side = moving_top(number, coor, fakecoor)) == STOP)
				return (STOP);
			if (moving_side != BLOCKED)
			{
				if (fakecoor[0] == get_col_nbmin(number, 0) && fakecoor[1] == get_line_nbmin(number, 0))
					return ((moving_side = ISFINISH));
				if ((moving_side = searching_around(number, fakecoor, moving_side, nbcuby)) == ISFINISH || moving_side == STOP)
					return (moving_side);
			}
		}
		if (moving_side != LEFT)
		{
			if ((moving_side = moving_right(number, coor, fakecoor)) == STOP)
				return (STOP);
			if (moving_side != BLOCKED)
			{
				if (fakecoor[0] == get_col_nbmin(number, 0) && fakecoor[1] == get_line_nbmin(number, 0))
					return ((moving_side = ISFINISH));
				if ((moving_side = searching_around(number, fakecoor, moving_side, nbcuby)) == ISFINISH || moving_side == STOP)
					return (moving_side);
			}
		}
	}
	printf("location = %d\tet\tTOP = %d\n", location, TOP);
	printf("moving_side = %d\n", moving_side);
	return (BLOCKED);
}
