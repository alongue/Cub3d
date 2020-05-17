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
	if ((lin == get_col_nbmin(number, col) && lin != get_col_nbmax(number, col, nbcuby))
	|| (lin == get_col_nbmax(number, col, nbcuby) && lin == get_col_nbmin(number, col)
	&& !isbot))
		return (TOP);
	else if (col == get_line_nbmax(number, lin))
		return (RIGHT);
	else if ((lin == get_col_nbmax(number, col, nbcuby) && lin != get_col_nbmin(number, col))
	|| (lin == get_col_nbmax(number, col, nbcuby) && lin == get_col_nbmin(number, col)
	&& isbot))
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
	static int	finish0 = 0;
	static int	finish1 = 0;
	static int	counter = 0;
	static int	cangoright = false;
	static int	cangoleft = false;
	int			ret[2];

	fakecoor[0] = coor[0];
	fakecoor[1] = coor[1];
	//printf("fakecoor[1] = %d\tet\tcoor[1] = %d\n", fakecoor[1], coor[1]);
	location = (get_location(number, fakecoor[1], fakecoor[0], nbcuby) == BLOCKED) ?
		oldlocation : get_location(number, fakecoor[1], fakecoor[0], nbcuby);
	if (location == TOP)
		counter++;
	if (counter == 2)
	{
		finish0 = fakecoor[0];
		finish1 = fakecoor[1];
	}
	printf("location = %d\tet\toldlocation = %d\n", location, oldlocation);
	printf("fakecoor[0] = %d\tet\tfakecoor[1] = %d\n", fakecoor[0], fakecoor[1]);
	//sleep(1);
	if (location == TOP)
	{
		if (moving_side != RIGHT && (moving_side == TOP || cangoleft))
		{
			printf("saluuuuuut\n");
			cangoleft = false;
			if (moving_side != TOP)
			{			
				if ((ret[0] = moving_bot(number, coor, fakecoor, nbcuby)) == STOP)
					return (STOP);
				if (ret[0] != BLOCKED)
				{
					oldlocation = location;
					cangoleft = true;
					if ((ret[1] = searching_around(number, fakecoor, ret[0], nbcuby)) == ISFINISH || ret[1] == STOP)
						return (ret[1]);
					else if (ret[1] == BLOCKED)
						fakecoor[0]--;
				}
				else
					cangoleft = false;
			}
			if (moving_side != RIGHT)
			{			
				if ((ret[0] = moving_left(number, coor, fakecoor)) == STOP)
					return (STOP);
				if (ret[0] != BLOCKED)
				{
					oldlocation = location;
					cangoleft = true;
					if ((ret[1] = searching_around(number, fakecoor, ret[0], nbcuby)) == ISFINISH || ret[1] == STOP)
						return (ret[1]);
					else if (ret[1] == BLOCKED)
						fakecoor[1]++;
				}
				else
					cangoleft = false;
			}
			if (moving_side != BOT)
			{			
				if ((ret[0] = moving_top(number, coor, fakecoor)) == STOP)
					return (STOP);
				if (ret[0] != BLOCKED)
				{
					oldlocation = location;
					cangoleft = true;
					if ((ret[1] = searching_around(number, fakecoor, ret[0], nbcuby)) == ISFINISH || ret[1] == STOP)
						return (ret[1]);
					else if (ret[1] == BLOCKED)
						fakecoor[0]++;
				}
				else
					cangoleft = false;
			}
		}
		if (moving_side != LEFT && !cangoleft)
		{
			if (moving_side != BOT) //laisser le code tel quel dans une autre fonction (ca va surement marcher en fait)
			{			
				if ((ret[0] = moving_top(number, coor, fakecoor)) == STOP)
					return (STOP);
				if (ret[0] != BLOCKED)
				{
					oldlocation = location;
					if ((fakecoor[0] == 0 && fakecoor[1] == get_line_nbmax(number, 0)) || (fakecoor[0] == finish0 && fakecoor[1] == finish1))
						return ((ret[0] = ISFINISH));
					if ((ret[1] = searching_around(number, fakecoor, ret[0], nbcuby)) == ISFINISH || ret[1] == STOP)
						return (ret[1]);
					else if (ret[1] == BLOCKED)
						fakecoor[0]++;
				}
			}
			if (moving_side != LEFT)
			{
				if ((ret[0] = moving_right(number, coor, fakecoor)) == STOP)
					return (STOP);
				if (ret[0] != BLOCKED)
				{
					oldlocation = location;
					if ((fakecoor[0] == 0 && fakecoor[1] == get_line_nbmax(number, 0)) || (fakecoor[0] == finish0 && fakecoor[1] == finish1))
						return ((ret[0] = ISFINISH));
					if ((ret[1] = searching_around(number, fakecoor, ret[0], nbcuby)) == ISFINISH || ret[1] == STOP)
						return (ret[1]);
					else if (ret[1] == BLOCKED)
						fakecoor[1]--;
				}
			}
			if (moving_side != TOP)
			{
				if ((ret[0] = moving_bot(number, coor, fakecoor, nbcuby)) == STOP)
					return (STOP);
				if (ret[0] != BLOCKED)
				{
					oldlocation = location;
					if ((fakecoor[0] == 0 && fakecoor[1] == get_line_nbmax(number, 0)) || (fakecoor[0] == finish0 && fakecoor[1] == finish1))
						return ((ret[0] = ISFINISH));
					if ((ret[1] = searching_around(number, fakecoor, ret[0], nbcuby)) == ISFINISH || ret[1] == STOP)
						return (ret[1]);
					else if (ret[1] == BLOCKED)
						fakecoor[0]--;
				}
			}
		}
		if (moving_side != RIGHT)
		{			
			if ((ret[0] = moving_left(number, coor, fakecoor)) == STOP)
				return (STOP);
			if (ret[0] != BLOCKED)
			{
				oldlocation = location;
				if (fakecoor[0] == 0 && fakecoor[1] == get_line_nbmin(number, 0))
					return ((ret[0] = ISFINISH));
				if ((ret[1] = searching_around(number, fakecoor, ret[0], nbcuby)) == ISFINISH || ret[1] == STOP)
					return (ret[1]);
				else if (ret[1] == BLOCKED)
					fakecoor[1]++;
			}
		}
	}
	else if (location == RIGHT)
	{
		if (moving_side != LEFT)
		{			
			if ((ret[0] = moving_right(number, coor, fakecoor)) == STOP)
				return (STOP);
			if (ret[0] != BLOCKED)
			{
				printf("(right) right location = %d\tet\toldlocation = %d\n", location, oldlocation);
				oldlocation = location;
				if ((fakecoor[0] == 0 && fakecoor[1] == get_line_nbmax(number, 0)) || (fakecoor[0] == finish0 && fakecoor[1] == finish1))
					return ((ret[0] = ISFINISH));
				if ((ret[1] = searching_around(number, fakecoor, ret[0], nbcuby)) == ISFINISH || ret[1] == STOP)
					return (ret[1]);
				else if (ret[1] == BLOCKED)
				{
					fakecoor[1]--;
					printf("(right) en ret[0] de right, coor[0] = %d\tet\tcoor[1] = %d\n", fakecoor[0], fakecoor[1]);
				}
			}
		}
		if (moving_side != TOP)
		{			
			if ((ret[0] = moving_bot(number, coor, fakecoor, nbcuby)) == STOP)
				return (STOP);
			if (ret[0] != BLOCKED)
			{
				printf("(right) bot location = %d\tet\toldlocation = %d\n", location, oldlocation);
				oldlocation = location;
				if ((fakecoor[0] == 0 && fakecoor[1] == get_line_nbmax(number, 0)) || (fakecoor[0] == finish0 && fakecoor[1] == finish1))
					return ((ret[0] = ISFINISH));
				if ((ret[1] = searching_around(number, fakecoor, ret[0], nbcuby)) == ISFINISH || ret[1] == STOP)
					return (ret[1]);
				else if (ret[1] == BLOCKED)
				{
					fakecoor[0]--;
					printf("(right) en ret[0] de bot, coor[0] = %d\tet\tcoor[1] = %d\n", fakecoor[0], fakecoor[1]);
				}
			}
		}
		if (moving_side != RIGHT)
		{
			printf("ret[0] = %d\n", ret[0]);
			printf("(left) coor[0] = %d\tet\tcoor[1] = %d\n", fakecoor[0], fakecoor[1]);
			if ((ret[0] = moving_left(number, coor, fakecoor)) == STOP)
				return (STOP);
			printf("ret[0] apres = %d\n", ret[0]);
			printf("(left) (apres) coor[0] = %d\tet\tcoor[1] = %d\n", fakecoor[0], fakecoor[1]);
			if (ret[0] != BLOCKED)
			{
				printf("(right) left location = %d\tet\toldlocation = %d\n", location, oldlocation);
				oldlocation = location;
				if ((fakecoor[0] == 0 && fakecoor[1] == get_line_nbmax(number, 0)) || (fakecoor[0] == finish0 && fakecoor[1] == finish1))
					return ((ret[0] = ISFINISH));
				if ((ret[1] = searching_around(number, fakecoor, ret[0], nbcuby)) == ISFINISH || ret[1] == STOP)
					return (ret[1]);
				else if (ret[1] == BLOCKED)
				{
					fakecoor[1]++;
					printf("(right) en ret[0] de left, coor[0] = %d\tet\tcoor[1] = %d\n", fakecoor[0], fakecoor[1]);
				}
			}
		}/*
		printf("moving_side avant de rentrer dans top = %d\n", moving_side);
		if (moving_side != BOT) //laisser le code tel quel dans une autre fonction (ca va surement marcher en fait)
		{			
			if ((ret[0] = moving_top(number, coor, fakecoor)) == STOP)
				return (STOP);
			if (ret[0] != BLOCKED)
			{
				oldlocation = location;
				if ((ret[1] = searching_around(number, fakecoor, ret[0], nbcuby)) == ISFINISH || ret[1] == STOP)
					return (ret[1]);
			}
		}*/
	}
	else if (location == BOT)
	{
		if (moving_side != LEFT && ((moving_side == BOT && location != oldlocation) || cangoright))
		{
			//sleep(1);
			printf("jte dis bonjour\n");
			if (moving_side != BOT) //laisser le code tel quel dans une autre fonction (ca va surement marcher en fait)
			{			
				if ((ret[0] = moving_top(number, coor, fakecoor)) == STOP)
					return (STOP);
				if (ret[0] != BLOCKED)
				{
					oldlocation = location;
					cangoright = true;
					if ((ret[1] = searching_around(number, fakecoor, ret[0], nbcuby)) == ISFINISH || ret[1] == STOP)
						return (ret[1]);
					else if (ret[1] == BLOCKED)
						fakecoor[0]++;
				}
				else
					cangoright = false;
				
			}
			if (moving_side != LEFT)// && ret[1] != BLOCKED)
			{			
				if ((ret[0] = moving_right(number, coor, fakecoor)) == STOP)
					return (STOP);
				if (ret[0] != BLOCKED)
				{
					oldlocation = location;
					cangoright = true;
					if ((ret[1] = searching_around(number, fakecoor, ret[0], nbcuby)) == ISFINISH || ret[1] == STOP)
						return (ret[1]);
					else if (ret[1] == BLOCKED)
					{
						fakecoor[1]--;
						printf("moving_side (apres etre sorti du right de bot) = %d\n", moving_side);
					}
				}
				else
					cangoright = false;
			}
			if (moving_side != TOP)// && ret[1] != BLOCKED)
			{			
				if ((ret[0] = moving_bot(number, coor, fakecoor, nbcuby)) == STOP)
					return (STOP);
				if (ret[0] != BLOCKED)
				{
					oldlocation = location;
					cangoright = true;
					if ((ret[1] = searching_around(number, fakecoor, ret[0], nbcuby)) == ISFINISH || ret[1] == STOP)
						return (ret[1]);
					else if (ret[1] == BLOCKED)
						fakecoor[0]--;
				}
				else
					cangoright = false;
			}
			/*
			if (moving_side != RIGHT)
			{			
				if ((ret[0] = moving_left(number, coor, fakecoor)) == STOP)
					return (STOP);
				if (ret[0] != BLOCKED)
				{
					oldlocation = location;
					if ((ret[1] = searching_around(number, fakecoor, ret[0], nbcuby)) == ISFINISH || ret[1] == STOP)
						return (ret[1]);
				}
			}*/
			//return (BLOCKED);
		}
		if (moving_side != RIGHT && !cangoright) //ca revient a faire aucune condition car si il arrive jusque la c que cangoright = false, mais si c le cas dans les 3  autres conditions qui suivent, aucune ne va marcher donc ca va finalement backtracker
		{
			printf("saluuuuuut\n");
			cangoright = false;
			if (moving_side != TOP)
			{
				printf("je rentre dans (bot) bot\n");
				if ((ret[0] = moving_bot(number, coor, fakecoor, nbcuby)) == STOP)
					return (STOP);
				if (ret[0] != BLOCKED)
				{
					oldlocation = location;
					if ((fakecoor[0] == 0 && fakecoor[1] == get_line_nbmax(number, 0)) || (fakecoor[0] == finish0 && fakecoor[1] == finish1))
						return ((ret[0] = ISFINISH));
					if ((ret[1] = searching_around(number, fakecoor, ret[0], nbcuby)) == ISFINISH || ret[1] == STOP)
						return (ret[1]);
					else if (ret[1] == BLOCKED)
					{
						fakecoor[0]--;
						printf("fakecoor[0] = %d\tet\tfakecoor[1] = %d (en sortant de (bot) left)\n", fakecoor[0], fakecoor[1]);
					}
				}
			}
			if (moving_side != RIGHT)
			{
				printf("je rentre dans (bot) left\n");
				if ((ret[0] = moving_left(number, coor, fakecoor)) == STOP)
					return (STOP);
				if (ret[0] != BLOCKED)
				{
					oldlocation = location;
					if ((fakecoor[0] == 0 && fakecoor[1] == get_line_nbmax(number, 0)) || (fakecoor[0] == finish0 && fakecoor[1] == finish1))
						return ((ret[0] = ISFINISH));
					if ((ret[1] = searching_around(number, fakecoor, ret[0], nbcuby)) == ISFINISH || ret[1] == STOP)
						return (ret[1]);
					else if (ret[1] == BLOCKED)
					{
						fakecoor[1]++;
						printf("fakecoor[0] = %d\tet\tfakecoor[1] = %d (en sortant de (bot) left)\n", fakecoor[0], fakecoor[1]);
					}
				}
			}
			if (moving_side != BOT)
			{
				printf("je rentre dans (bot) top\n");
				if ((ret[0] = moving_top(number, coor, fakecoor)) == STOP)
					return (STOP);
				if (ret[0] != BLOCKED)
				{
					oldlocation = location;
					if ((fakecoor[0] == 0 && fakecoor[1] == get_line_nbmax(number, 0)) || (fakecoor[0] == finish0 && fakecoor[1] == finish1))
						return ((ret[0] = ISFINISH));
					if ((ret[1] = searching_around(number, fakecoor, ret[0], nbcuby)) == ISFINISH || ret[1] == STOP)
						return (ret[1]);
					else if (ret[1] == BLOCKED)
					{
						fakecoor[0]++;
						printf("fakecoor[0] = %d\tet\tfakecoor[1] = %d (en sortant de (bot) top)\n", fakecoor[0], fakecoor[1]);
					}
				}
			}/*
			if (moving_side != LEFT)
			{			
				if ((ret[0] = moving_right(number, coor, fakecoor)) == STOP)
					return (STOP);
				if (ret[0] != BLOCKED)
				{
					oldlocation = location;
					if ((ret[1] = searching_around(number, fakecoor, ret[0], nbcuby)) == ISFINISH || ret[1] == STOP)
						return (ret[1]);
				}
			}*/
		}
	}
	else if (location == LEFT)
	{
		if (moving_side != RIGHT)
		{			
			if ((ret[0] = moving_left(number, coor, fakecoor)) == STOP)
				return (STOP);
			if (ret[0] != BLOCKED)
			{
				oldlocation = location;
				if ((fakecoor[0] == 0 && fakecoor[1] == get_line_nbmax(number, 0)) || (fakecoor[0] == finish0 && fakecoor[1] == finish1))
					return ((ret[0] = ISFINISH));
				if ((ret[1] = searching_around(number, fakecoor, ret[0], nbcuby)) == ISFINISH || ret[1] == STOP)
					return (ret[1]);
				else if (ret[1] == BLOCKED)
					fakecoor[1]++;
			}
		}
		if (moving_side != BOT)
		{			
			if ((ret[0] = moving_top(number, coor, fakecoor)) == STOP)
				return (STOP);
			if (ret[0] != BLOCKED)
			{
				oldlocation = location;
				if ((fakecoor[0] == 0 && fakecoor[1] == get_line_nbmax(number, 0)) || (fakecoor[0] == finish0 && fakecoor[1] == finish1))
					return ((ret[0] = ISFINISH));
				if ((ret[1] = searching_around(number, fakecoor, ret[0], nbcuby)) == ISFINISH || ret[1] == STOP)
					return (ret[1]);
				else if (ret[1] == BLOCKED)
					fakecoor[0]++;
			}
		}
		if (moving_side != LEFT)
		{
			printf("tchoinnnnnn !!!\n");
			if ((ret[0] = moving_right(number, coor, fakecoor)) == STOP)
				return (STOP);
			if (ret[0] != BLOCKED)
			{
				oldlocation = location;
				if ((fakecoor[0] == 0 && fakecoor[1] == get_line_nbmax(number, 0)) || (fakecoor[0] == finish0 && fakecoor[1] == finish1))
					return ((ret[0] = ISFINISH));
				if ((ret[1] = searching_around(number, fakecoor, ret[0], nbcuby)) == ISFINISH || ret[1] == STOP)
					return (ret[1]);
				else if (ret[1] == BLOCKED)
					fakecoor[1]--;
			}
		}
		/*if (moving_side != TOP)
		{			
			if ((ret[0] = moving_bot(number, coor, fakecoor, nbcuby)) == STOP)
				return (STOP);
			if (ret[0] != BLOCKED)
			{
				if (fakecoor[0] == 0 && fakecoor[1] == get_line_nbmin(number, 0))
					return ((ret[0] = ISFINISH));
				oldlocation = location;
				if ((ret[1] = searching_around(number, fakecoor, ret[0], nbcuby)) == ISFINISH || ret[1] == STOP)
					return (ret[1]);
			}
		}*/
	}
	printf("fakecoor[0] = %d\tet\tfakecoor[1] = %d (avant de backtrack)\n", fakecoor[0], fakecoor[1]);
	printf("location = %d\tet\tTOP = %d\n", location, TOP);
	//sleep(2);
	return (BLOCKED);
}
