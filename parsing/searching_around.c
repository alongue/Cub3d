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
	static int	isbot = false;

	printf("lin = %d\tet\tget_col_nbmin(number, %d) = %d\n", lin, col, get_col_nbmin(number, col));
	//sleep(2);
	if (!isbot && (lin == get_col_nbmin(number, col)))
		return (TOP);
	else if (col == get_line_nbmax(number, lin))
		return (RIGHT);
	else if (lin == get_col_nbmax(number, col, nbcuby))
	{
		isbot = true;
		return (BOT);
	}
	else if (col == get_line_nbmin(number, lin))
		return (LEFT);
	return (BLOCKED);
}

int		searching_around(char **number, int *coor, int moving_side, int *nbcuby)
{
	int			location;
	static int	oldlocation = TOP;
	int			fakecoor[2];
	static int	cangoright = false;
	int			ret;

	fakecoor[0] = coor[0];
	fakecoor[1] = coor[1];
	//printf("fakecoor[1] = %d\tet\tcoor[1] = %d\n", fakecoor[1], coor[1]);
	location = (get_location(number, fakecoor[1], fakecoor[0], nbcuby) == BLOCKED) ?
		oldlocation : get_location(number, fakecoor[1], fakecoor[0], nbcuby);
	printf("location = %d\tet\toldlocation = %d\n", location, oldlocation);
	//printf("fakecoor[0] = %d\tet\tfakecoor[1] = %d\n", fakecoor[0], fakecoor[1]);
	sleep(1);
	if (location == TOP)
	{
		if (moving_side != BOT) //laisser le code tel quel dans une autre fonction (ca va surement marcher en fait)
		{			
			if ((ret = moving_top(number, coor, fakecoor)) == STOP)
				return (STOP);
			if (ret != BLOCKED)
			{
				oldlocation = location;
				if (fakecoor[0] == get_col_nbmin(number, 0) && fakecoor[1] == get_line_nbmin(number, 0))
					return ((ret = ISFINISH));
				if ((ret = searching_around(number, fakecoor, ret, nbcuby)) == ISFINISH || ret == STOP)
					return (ret);
			}
		}
		if (moving_side != LEFT)
		{
			if ((ret = moving_right(number, coor, fakecoor)) == STOP)
				return (STOP);
			if (ret != BLOCKED)
			{
				oldlocation = location;
				if (fakecoor[0] == get_col_nbmin(number, 0) && fakecoor[1] == get_line_nbmin(number, 0))
					return ((ret = ISFINISH));
				if ((ret = searching_around(number, fakecoor, ret, nbcuby)) == ISFINISH || ret == STOP)
					return (ret);
			}
		}
		if (moving_side != TOP)
		{
			if ((ret = moving_bot(number, coor, fakecoor, nbcuby)) == STOP)
				return (STOP);
			if (ret != BLOCKED)
			{
				oldlocation = location;
				if (fakecoor[0] == get_col_nbmin(number, 0) && fakecoor[1] == get_line_nbmin(number, 0))
					return ((ret = ISFINISH));
				if ((ret = searching_around(number, fakecoor, ret, nbcuby)) == ISFINISH || ret == STOP)
					return (ret);
			}
		}
	}
	else if (location == RIGHT)
	{
		if (moving_side != LEFT)
		{			
			if ((ret = moving_right(number, coor, fakecoor)) == STOP)
				return (STOP);
			if (ret != BLOCKED)
			{
				printf("(right) right location = %d\tet\toldlocation = %d\n", location, oldlocation);
				oldlocation = location;
				if ((ret = searching_around(number, fakecoor, ret, nbcuby)) == ISFINISH || ret == STOP)
					return (ret);
			}
		}
		if (moving_side != TOP)
		{			
			if ((ret = moving_bot(number, coor, fakecoor, nbcuby)) == STOP)
				return (STOP);
			if (ret != BLOCKED)
			{
				printf("(right) bot location = %d\tet\toldlocation = %d\n", location, oldlocation);
				oldlocation = location;
				if ((ret = searching_around(number, fakecoor, ret, nbcuby)) == ISFINISH || ret == STOP)
					return (ret);
			}
			printf("(bot) coor[0] = %d\tet\tcoor[1] = %d\n", fakecoor[0], fakecoor[1]);
		}
		if (moving_side != RIGHT)
		{
			printf("ret = %d\n", ret);
			printf("(left) coor[0] = %d\tet\tcoor[1] = %d\n", fakecoor[0], fakecoor[1]);
			if ((ret = moving_left(number, coor, fakecoor)) == STOP)
				return (STOP);
			printf("(left) (apres) coor[0] = %d\tet\tcoor[1] = %d\n", fakecoor[0], fakecoor[1]);
			if (ret != BLOCKED)
			{
				printf("(right) left location = %d\tet\toldlocation = %d\n", location, oldlocation);
				oldlocation = location;
				if ((ret = searching_around(number, fakecoor, ret, nbcuby)) == ISFINISH || ret == STOP)
					return (ret);
			}
		}
	}
	else if (location == BOT)
	{
		if (moving_side != LEFT && (oldlocation != location || cangoright))
		{
			if (moving_side != BOT) //laisser le code tel quel dans une autre fonction (ca va surement marcher en fait)
			{			
				if ((ret = moving_top(number, coor, fakecoor)) == STOP)
					return (STOP);
				if (ret != BLOCKED)
				{
					oldlocation = location;
					cangoright = true;
					if (fakecoor[0] == get_col_nbmin(number, 0) && fakecoor[1] == get_line_nbmin(number, 0))
						return ((ret = ISFINISH));
					if ((ret = searching_around(number, fakecoor, ret, nbcuby)) == ISFINISH || ret == STOP)
						return (ret);
				}
				else
					cangoright = false;
				
			}
			if (moving_side != LEFT)
			{			
				if ((ret = moving_right(number, coor, fakecoor)) == STOP)
					return (STOP);
				if (ret != BLOCKED)
				{
					oldlocation = location;
					cangoright = true;
					if (fakecoor[0] == get_col_nbmin(number, 0) && fakecoor[1] == get_line_nbmin(number, 0))
						return ((ret = ISFINISH));
					if ((ret = searching_around(number, fakecoor, ret, nbcuby)) == ISFINISH || ret == STOP)
						return (ret);
				}
				else
					cangoright = false;
			}
			if (moving_side != TOP)
			{			
				if ((ret = moving_bot(number, coor, fakecoor, nbcuby)) == STOP)
					return (STOP);
				if (ret != BLOCKED)
				{
					oldlocation = location;
					cangoright = true;
					if (fakecoor[0] == get_col_nbmin(number, 0) && fakecoor[1] == get_line_nbmin(number, 0))
						return ((ret = ISFINISH));
					if ((ret = searching_around(number, fakecoor, ret, nbcuby)) == ISFINISH || ret == STOP)
						return (ret);
				}
				else
					cangoright = false;
			}
		}
		if (!cangoright) //ca revient a faire aucune condition car si il arrive jusque la c que cangoright = false, mais si c le cas dans les 3  autres conditions qui suivent, aucune ne va marcher donc ca va finalement backtracker
		{
			printf("saluuuuuut\n");
			cangoright = false;
			if (moving_side != TOP)
			{			
				if ((ret = moving_bot(number, coor, fakecoor, nbcuby)) == STOP)
					return (STOP);
				if (ret != BLOCKED)
				{
					oldlocation = location;
					if ((ret = searching_around(number, fakecoor, ret, nbcuby)) == ISFINISH || ret == STOP)
						return (ret);
				}
			}
			if (moving_side != RIGHT)
			{			
				if ((ret = moving_left(number, coor, fakecoor)) == STOP)
					return (STOP);
				if (ret != BLOCKED)
				{
					oldlocation = location;
					if ((ret = searching_around(number, fakecoor, ret, nbcuby)) == ISFINISH || ret == STOP)
						return (ret);
				}
			}
			if (moving_side != BOT)
			{			
				if ((ret = moving_top(number, coor, fakecoor)) == STOP)
					return (STOP);
				if (ret != BLOCKED)
				{
					oldlocation = location;
					if ((ret = searching_around(number, fakecoor, ret, nbcuby)) == ISFINISH || ret == STOP)
						return (ret);
				}
			}
		}
	}
	else if (location == LEFT)
	{
		if (moving_side != RIGHT)
		{			
			if ((ret = moving_left(number, coor, fakecoor)) == STOP)
				return (STOP);
			if (ret != BLOCKED)
			{
				oldlocation = location;
				if (fakecoor[0] == get_col_nbmin(number, 0) && fakecoor[1] == get_line_nbmin(number, 0))
					return ((ret = ISFINISH));
				if ((ret = searching_around(number, fakecoor, ret, nbcuby)) == ISFINISH || ret == STOP)
					return (ret);
			}
		}
		if (moving_side != BOT)
		{			
			if ((ret = moving_top(number, coor, fakecoor)) == STOP)
				return (STOP);
			if (ret != BLOCKED)
			{
				oldlocation = location;
				if (fakecoor[0] == get_col_nbmin(number, 0) && fakecoor[1] == get_line_nbmin(number, 0))
					return ((ret = ISFINISH));
				if ((ret = searching_around(number, fakecoor, ret, nbcuby)) == ISFINISH || ret == STOP)
					return (ret);
			}
		}
		if (moving_side != LEFT)
		{
			if ((ret = moving_right(number, coor, fakecoor)) == STOP)
				return (STOP);
			if (ret != BLOCKED)
			{
				oldlocation = location;
				if (fakecoor[0] == get_col_nbmin(number, 0) && fakecoor[1] == get_line_nbmin(number, 0))
					return ((ret = ISFINISH));
				if ((ret = searching_around(number, fakecoor, ret, nbcuby)) == ISFINISH || ret == STOP)
					return (ret);
			}
		}
	}
	printf("location = %d\tet\tTOP = %d\n", location, TOP);
	return (BLOCKED);
}
