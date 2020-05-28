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

int		get_location(int moving_side)
{
	//static int	isbot = 0;

	//printf("lin = %d\tet\tget_col_nbmin(number, %d) = %d\n", lin, col, get_col_nbmin(number, col));
	//sleep(2);
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

int		searching_around(t_map *map, int *coor, int moving_side)
{
	int			location;
	static int	oldlocation = TOP;
	int			fakecoor[2];
	//static int	finish0 = 0;
	//static int	finish1 = 0;
	//static int	counter = 0;
	//static int	cangoright = 0;
	//static int	cangoleft = 0;
	int			ret[2];

	fakecoor[0] = coor[0];
	fakecoor[1] = coor[1];
	//printf("fakecoor[1] = %d\tet\tcoor[1] = %d\n", fakecoor[1], coor[1]);
	location = (get_location(moving_side) == BLOCKED) ?
		oldlocation : get_location(moving_side);
	printf("location = %d\tet\toldlocation = %d\n", location, oldlocation);
	printf("fakecoor[0] = %d\tet\tfakecoor[1] = %d\n", fakecoor[0], fakecoor[1]);
	//sleep(1);
	if (location == TOP)
	{
		/*if (moving_side != RIGHT && (moving_side == TOP || cangoleft))
		{
			printf("saluuuuuut tu vas bien\n");
			//cangoright = 0;
			if (moving_side != TOP)
			{
				printf("J'essaye (top) mais avec bot en 1er\n");
				if ((ret[0] = moving_bot(map->number, coor, fakecoor, map->nbcuby)) == STOP)
					return (STOP);
				if (ret[0] != BLOCKED)
				{
					map->parsepos[fakecoor[0] * get_nbxmax(map->nbcuby) + fakecoor[1]] = 1;
					oldlocation = location;
					//cangoright = 1;
					if ((ret[1] = searching_around(map, fakecoor, ret[0])) == ISFINISH || ret[1] == STOP)
						return (ret[1]);
					else if (ret[1] == BLOCKED)
						fakecoor[0]--;
				}
				else
					//cangoright = 0;
			}
			if (moving_side != RIGHT)
			{			
				if ((ret[0] = moving_left(map->number, coor, fakecoor)) == STOP)
					return (STOP);
				if (ret[0] != BLOCKED)
				{
					map->parsepos[fakecoor[0] * get_nbxmax(map->nbcuby) + fakecoor[1]] = 1;
					oldlocation = location;
					//cangoright = 1;
					if ((ret[1] = searching_around(map, fakecoor, ret[0])) == ISFINISH || ret[1] == STOP)
						return (ret[1]);
					else if (ret[1] == BLOCKED)
						fakecoor[1]++;
				}
				else
					//cangoright = 0;
			}
			if (moving_side != BOT)
			{			
				if ((ret[0] = moving_top(map->number, coor, fakecoor)) == STOP)
					return (STOP);
				if (ret[0] != BLOCKED)
				{
					map->parsepos[fakecoor[0] * get_nbxmax(map->nbcuby) + fakecoor[1]] = 1;
					oldlocation = location;
					//cangoright = 1;
					if ((ret[1] = searching_around(map, fakecoor, ret[0])) == ISFINISH || ret[1] == STOP)
						return (ret[1]);
					else if (ret[1] == BLOCKED)
						fakecoor[0]++;
				}
				else
					//cangoright = 0;
			}
		}
		*/
		//if (!cangoleft)
		//{
			printf("Je m'en blk de toi !!!!!!!!!!!\n");
			if (moving_side != BOT) //laisser le code tel quel dans une autre fonction (ca va surement marcher en fait)
			{
				printf("Je rentre dans (top) top\n");
				if ((ret[0] = moving_top(map->number, coor, fakecoor)) == STOP)
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
						fakecoor[0]++;
				}
			}
			if (moving_side != LEFT)
			{
				printf("Je rentre dans (top) right\n");
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
			printf("map->parsepos[(fakecoor[0] + 1) * map->nbxmax + fakecoor[1] (avant bot) = %d\n", map->parsepos[(fakecoor[0] + 1) * map->nbxmax + fakecoor[1]]);
			if (moving_side != TOP)
			{
				printf("Je rentre dans (top) bot\n");
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
			/*if (moving_side != RIGHT)
			{
				printf("Je rentre dans (top) left\n");
				if ((ret[0] = moving_left(map->number, coor, fakecoor)) == STOP)
					return (STOP);
				if (ret[0] != BLOCKED)
				{
					map->parsepos[fakecoor[0] * map->nbxmax + fakecoor[1]] = 1;
						oldlocation = location;
					if (fakecoor[0] == 0 && fakecoor[1] == get_line_nbmin(map->number, 0))
						return ((ret[0] = ISFINISH));
					if ((ret[1] = searching_around(map, fakecoor, ret[0])) == ISFINISH || ret[1] == STOP)
						return (ret[1]);
					else if (ret[1] == BLOCKED)
						fakecoor[1]++;
				}
			}*/
		//}
	}
	else if (location == RIGHT)
	{
		printf("map->parsepos[%d * %d + %d] = %d\n", fakecoor[0], map->nbxmax, fakecoor[1], map->parsepos[fakecoor[0] * map->nbxmax + fakecoor[1]]);
		if (moving_side != LEFT)
		{
			printf("je rentre dans (right) right\n");
			if ((ret[0] = moving_right(map->number, coor, fakecoor)) == STOP)
				return (STOP);
			if (ret[0] != BLOCKED)
			{
				map->parsepos[fakecoor[0] * map->nbxmax + fakecoor[1]] = 1;
					printf("(right) right location = %d\tet\toldlocation = %d\n", location, oldlocation);
				oldlocation = location;
				if ((fakecoor[0] == 0 && fakecoor[1] == get_line_nbmin(map->number, 0)))
					return ((ret[0] = ISFINISH));
				if ((ret[1] = searching_around(map, fakecoor, ret[0])) == ISFINISH || ret[1] == STOP)
					return (ret[1]);
				else if (ret[1] == BLOCKED)
				{
					fakecoor[1]--;
					printf("(right) en ret[0] de right, coor[0] = %d\tet\tcoor[1] = %d\n", fakecoor[0], fakecoor[1]);
				}
			}
		}
		/*
		printf("map->parsepos[%d + 1 * %d + %d] = %d\n", fakecoor[0], map->nbxmax, fakecoor[1], map->parsepos[(fakecoor[0] + 1) * map->nbxmax + fakecoor[1]]);
		printf("fakecoor[0] = %d\tet\tmap->nbymax = %d\n", fakecoor[0], map->nbymax);
		printf("moving_side = %d\tet\tTOP = %d\n", moving_side, TOP);
		*/
		if (moving_side != TOP)
		{
			printf("je rentre dans (right) bot !!!!!!!!!!!!!!!!!!!!!!\n");
			if ((ret[0] = moving_bot(map->number, coor, fakecoor, map->nbcuby)) == STOP)
				return (STOP);
			if (ret[0] != BLOCKED)
			{
				map->parsepos[fakecoor[0] * map->nbxmax + fakecoor[1]] = 1;
					printf("(right) bot location = %d\tet\toldlocation = %d\n", location, oldlocation);
				oldlocation = location;
				if ((fakecoor[0] == 0 && fakecoor[1] == get_line_nbmin(map->number, 0)))
					return ((ret[0] = ISFINISH));
				if ((ret[1] = searching_around(map, fakecoor, ret[0])) == ISFINISH || ret[1] == STOP)
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
			printf("je rentre dans (right) left\n");
			printf("ret[0] = %d\n", ret[0]);
			printf("(left) coor[0] = %d\tet\tcoor[1] = %d\n", fakecoor[0], fakecoor[1]);
			if ((ret[0] = moving_left(map->number, coor, fakecoor)) == STOP)
				return (STOP);
			printf("ret[0] apres = %d\n", ret[0]);
			printf("(left) (apres) coor[0] = %d\tet\tcoor[1] = %d\n", fakecoor[0], fakecoor[1]);
			if (ret[0] != BLOCKED)
			{
				map->parsepos[fakecoor[0] * map->nbxmax + fakecoor[1]] = 1;
				printf("(right) left location = %d\tet\toldlocation = %d\n", location, oldlocation);
				oldlocation = location;
				if ((fakecoor[0] == 0 && fakecoor[1] == get_line_nbmin(map->number, 0)))
					return ((ret[0] = ISFINISH));
				if ((ret[1] = searching_around(map, fakecoor, ret[0])) == ISFINISH || ret[1] == STOP)
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
			if ((ret[0] = moving_top(map->number, coor, fakecoor)) == STOP)
				return (STOP);
			if (ret[0] != BLOCKED)
			{
				map->parsepos[fakecoor[0] * map->nbxmax + fakecoor[1]] = 1;
					oldlocation = location;
				if ((ret[1] = searching_around(map, fakecoor, ret[0])) == ISFINISH || ret[1] == STOP)
					return (ret[1]);
			}
		}*/
	}
	else if (location == BOT)
	{
		/*
		if (moving_side != LEFT && (moving_side == BOT || cangoright))
		{
			//sleep(1);
			printf("jte dis bonjour\n");
			//sleep(14);
			if (moving_side != BOT) //laisser le code tel quel dans une autre fonction (ca va surement marcher en fait)
			{			
				if ((ret[0] = moving_top(map->number, coor, fakecoor)) == STOP)
					return (STOP);
				if (ret[0] != BLOCKED)
				{
					map->parsepos[fakecoor[0] * map->nbxmax + fakecoor[1]] = 1;
					oldlocation = location;
					//cangoright = 1;
					if ((ret[1] = searching_around(map, fakecoor, ret[0])) == ISFINISH || ret[1] == STOP)
						return (ret[1]);
					else if (ret[1] == BLOCKED)
						fakecoor[0]++;
				}
				else
					//cangoright = 0;
				
			}
			if (moving_side != LEFT)// && ret[1] != BLOCKED)
			{			
				if ((ret[0] = moving_right(map->number, coor, fakecoor)) == STOP)
					return (STOP);
				if (ret[0] != BLOCKED)
				{
					map->parsepos[fakecoor[0] * map->nbxmax + fakecoor[1]] = 1;
					oldlocation = location;
					//cangoright = 1;
					if ((ret[1] = searching_around(map, fakecoor, ret[0])) == ISFINISH || ret[1] == STOP)
						return (ret[1]);
					else if (ret[1] == BLOCKED)
					{
						fakecoor[1]--;
						printf("moving_side (apres etre sorti du right de bot) = %d\n", moving_side);
					}
				}
				else
					//cangoright = 0;
			}
			if (moving_side != TOP)// && ret[1] != BLOCKED)
			{			
				if ((ret[0] = moving_bot(map->number, coor, fakecoor, map->nbcuby)) == STOP)
					return (STOP);
				if (ret[0] != BLOCKED)
				{
					map->parsepos[fakecoor[0] * map->nbxmax + fakecoor[1]] = 1;
					oldlocation = location;
					//cangoright = 1;
					if ((ret[1] = searching_around(map, fakecoor, ret[0])) == ISFINISH || ret[1] == STOP)
						return (ret[1]);
					else if (ret[1] == BLOCKED)
						fakecoor[0]--;
				}
				else
					//cangoright = 0;
			}
			/\*
			if (moving_side != RIGHT)
			{			
				if ((ret[0] = moving_left(map->number, coor, fakecoor)) == STOP)
					return (STOP);
				if (ret[0] != BLOCKED)
				{
					oldlocation = location;
					if ((ret[1] = searching_around(map, fakecoor, ret[0])) == ISFINISH || ret[1] == STOP)
						return (ret[1]);
				}
			}*\/
			//return (BLOCKED);
		}*/
		//if (moving_side != RIGHT && !cangoright) //ca revient a faire aucune condition car si il arrive jusque la c que cangoright = 0, mais si c le cas dans les 3  autres conditions qui suivent, aucune ne va marcher donc ca va finalement backtracker
		//{
			printf("saluuuuuut\n");
			//cangoright = 0;
			if (moving_side != TOP)
			{
				printf("je rentre dans (bot) bot\n");
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
						printf("fakecoor[0] = %d\tet\tfakecoor[1] = %d (en sortant de (bot) left)\n", fakecoor[0], fakecoor[1]);
					}
				}
			}
			if (moving_side != RIGHT)
			{
				printf("je rentre dans (bot) left\n");
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
						printf("fakecoor[0] = %d\tet\tfakecoor[1] = %d (en sortant de (bot) left)\n", fakecoor[0], fakecoor[1]);
					}
				}
			}
			if (moving_side != BOT)
			{
				printf("je rentre dans (bot) top\n");
				if ((ret[0] = moving_top(map->number, coor, fakecoor)) == STOP)
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
						printf("fakecoor[0] = %d\tet\tfakecoor[1] = %d (en sortant de (bot) top)\n", fakecoor[0], fakecoor[1]);
					}
				}
			}/*
			if (moving_side != LEFT)
			{			
				if ((ret[0] = moving_right(map->number, coor, fakecoor)) == STOP)
					return (STOP);
				if (ret[0] != BLOCKED)
				{
					oldlocation = location;
					if ((ret[1] = searching_around(map, fakecoor, ret[0])) == ISFINISH || ret[1] == STOP)
						return (ret[1]);
				}
			}*/
		//}
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
			if ((ret[0] = moving_top(map->number, coor, fakecoor)) == STOP)
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
					fakecoor[0]++;
			}
		}
		if (moving_side != LEFT)
		{
			printf("tchoinnnnnn !!!\n");
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
		/*if (moving_side != TOP)
		{			
			if ((ret[0] = moving_bot(map->number, coor, fakecoor, map->nbcuby)) == STOP)
				return (STOP);
			if (ret[0] != BLOCKED)
			{
				map->parsepos[fakecoor[0] * map->nbxmax + fakecoor[1]] = 1;
					if (fakecoor[0] == 0 && fakecoor[1] == get_line_nbmin(map->number, 0))
					return ((ret[0] = ISFINISH));
				oldlocation = location;
				if ((ret[1] = searching_around(map, fakecoor, ret[0])) == ISFINISH || ret[1] == STOP)
					return (ret[1]);
			}
		}*/
	}
	map->backtrackpos[fakecoor[0] * map->nbxmax + fakecoor[1]] = 1;
	printf("fakecoor[0] = %d\tet\tfakecoor[1] = %d (avant de backtrack)\n", fakecoor[0], fakecoor[1]);
	printf("location = %d\tet\tTOP = %d\n", location, TOP);
	//sleep(2);
	return (BLOCKED);
}
