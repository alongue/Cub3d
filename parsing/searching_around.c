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
#include <string.h>

# define MIN 0
# define MAX 1
# define X 0
# define Y 1

#include <stdio.h>

int		get_location(int moving_side)
{
	//static int	isbot = 0;

	////vscode printf("lin = %d\tet\tget_col_nbmin(number, %d) = %d\n", lin, col, get_col_nbmin(number, col));
	////vscode sleep(2);
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
		{
			printf("remind\n");
			return (i);
		}
	}
	return (-1);
}

char	**recover_xtreme(int *coor, int *end, int location) // modification de max et utilisation de ft_realloc
{
	static char	**xtreme; // xtreme[n] = "1507" -> x = 15 et y = 07 157
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
	
	printf("coor[0] (y) = %d\tet\tcoor[1] (x) = %d\tet\tlocation = %d\tet\ti = %d\n", coor[0], coor[1], location, i);
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
	xtreme[i] = ft_strjoin_free(temp[0], ft_strjoin_free(temp[1], ft_itoa(location)));
	printf("xtreme[%i] = %s\n", i, xtreme[i]);
	//while () // on verifie si le tableau n'a pas ete cree car on realloc
	//xtreme[X][coor[1]][MIN * i] = coor[0];
	return (xtreme);
}

int		searching_around(t_map *map, int *coor, int moving_side)
{
	// === Pour trouver si y a des trucs en dehors de la map === //

	// On prend la (ou les) direction(s) avec un temps de retard (ex : si on va en bas (admettons droite -> bas -> gauche) on va regarder si y a rien droite)
	// Avec le meme exemple si on va a gauche on 
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
	////vscode printf("fakecoor[1] = %d\tet\tcoor[1] = %d\n", fakecoor[1], coor[1]);
	//recover_xtreme(coor, &coor[2], get_location(moving_side));
	location = (get_location(moving_side) == BLOCKED) ?
		oldlocation : get_location(moving_side);
	if (remind(coor[1], coor[0]) != -1)
		return (BLOCKED);
	recover_xtreme(coor, &coor[2], location);
	//vscode printf("location = %d\tet\toldlocation = %d\n", location, oldlocation);
	//vscode printf("fakecoor[0] = %d\tet\tfakecoor[1] = %d\n", fakecoor[0], fakecoor[1]);
	////vscode sleep(1);
	if (location == TOP)
	{
		/*if (moving_side != RIGHT && (moving_side == TOP || cangoleft))
		{
			//vscode printf("saluuuuuut tu vas bien\n");
			//cangoright = 0;
			if (moving_side != TOP)
			{
				//vscode printf("J'essaye (top) mais avec bot en 1er\n");
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
				if ((ret[0] = moving_top(map->number, coor, fakecoor, map->nbcuby)) == STOP)
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
			//vscode printf("Je m'en blk de toi !!!!!!!!!!!\n");
			if (moving_side != BOT) //laisser le code tel quel dans une autre fonction (ca va surement marcher en fait)
			{
				//vscode printf("Je rentre dans (top) top\n");
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
						fakecoor[0]++;
				}
			}
			if (moving_side != LEFT)
			{
				//vscode printf("Je rentre dans (top) right\n");
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
			//vscode printf("map->parsepos[(fakecoor[0] + 1) * map->nbxmax + fakecoor[1] (avant bot) = %d\n", map->parsepos[(fakecoor[0] + 1) * map->nbxmax + fakecoor[1]]);
			if (moving_side != TOP)
			{
				//vscode printf("Je rentre dans (top) bot\n");
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
				//vscode printf("Je rentre dans (top) left\n");
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
		//vscode printf("map->parsepos[%d * %d + %d] = %d\n", fakecoor[0], map->nbxmax, fakecoor[1], map->parsepos[fakecoor[0] * map->nbxmax + fakecoor[1]]);
		if (moving_side != LEFT)
		{
			//vscode printf("je rentre dans (right) right\n");
			if ((ret[0] = moving_right(map->number, coor, fakecoor)) == STOP)
				return (STOP);
			if (ret[0] != BLOCKED)
			{
				map->parsepos[fakecoor[0] * map->nbxmax + fakecoor[1]] = 1;
					//vscode printf("(right) right location = %d\tet\toldlocation = %d\n", location, oldlocation);
				oldlocation = location;
				if ((fakecoor[0] == 0 && fakecoor[1] == get_line_nbmin(map->number, 0)))
					return ((ret[0] = ISFINISH));
				if ((ret[1] = searching_around(map, fakecoor, ret[0])) == ISFINISH || ret[1] == STOP)
					return (ret[1]);
				else if (ret[1] == BLOCKED)
				{
					fakecoor[1]--;
					//vscode printf("(right) en ret[0] de right, coor[0] = %d\tet\tcoor[1] = %d\n", fakecoor[0], fakecoor[1]);
				}
			}
		}
		/*
		//vscode printf("map->parsepos[%d + 1 * %d + %d] = %d\n", fakecoor[0], map->nbxmax, fakecoor[1], map->parsepos[(fakecoor[0] + 1) * map->nbxmax + fakecoor[1]]);
		//vscode printf("fakecoor[0] = %d\tet\tmap->nbymax = %d\n", fakecoor[0], map->nbymax);
		//vscode printf("moving_side = %d\tet\tTOP = %d\n", moving_side, TOP);
		*/
		if (moving_side != TOP)
		{
			//vscode printf("je rentre dans (right) bot !!!!!!!!!!!!!!!!!!!!!!\n");
			if ((ret[0] = moving_bot(map->number, coor, fakecoor, map->nbcuby)) == STOP)
				return (STOP);
			if (ret[0] != BLOCKED)
			{
				map->parsepos[fakecoor[0] * map->nbxmax + fakecoor[1]] = 1;
					//vscode printf("(right) bot location = %d\tet\toldlocation = %d\n", location, oldlocation);
				oldlocation = location;
				if ((fakecoor[0] == 0 && fakecoor[1] == get_line_nbmin(map->number, 0)))
					return ((ret[0] = ISFINISH));
				if ((ret[1] = searching_around(map, fakecoor, ret[0])) == ISFINISH || ret[1] == STOP)
					return (ret[1]);
				else if (ret[1] == BLOCKED)
				{
					fakecoor[0]--;
					//vscode printf("(right) en ret[0] de bot, coor[0] = %d\tet\tcoor[1] = %d\n", fakecoor[0], fakecoor[1]);
				}
			}
		}
		if (moving_side != RIGHT)
		{
			//vscode printf("je rentre dans (right) left\n");
			//vscode printf("ret[0] = %d\n", ret[0]);
			//vscode printf("(left) coor[0] = %d\tet\tcoor[1] = %d\n", fakecoor[0], fakecoor[1]);
			if ((ret[0] = moving_left(map->number, coor, fakecoor)) == STOP)
				return (STOP);
			//vscode printf("ret[0] apres = %d\n", ret[0]);
			//vscode printf("(left) (apres) coor[0] = %d\tet\tcoor[1] = %d\n", fakecoor[0], fakecoor[1]);
			if (ret[0] != BLOCKED)
			{
				map->parsepos[fakecoor[0] * map->nbxmax + fakecoor[1]] = 1;
				//vscode printf("(right) left location = %d\tet\toldlocation = %d\n", location, oldlocation);
				oldlocation = location;
				if ((fakecoor[0] == 0 && fakecoor[1] == get_line_nbmin(map->number, 0)))
					return ((ret[0] = ISFINISH));
				if ((ret[1] = searching_around(map, fakecoor, ret[0])) == ISFINISH || ret[1] == STOP)
					return (ret[1]);
				else if (ret[1] == BLOCKED)
				{
					fakecoor[1]++;
					//vscode printf("(right) en ret[0] de left, coor[0] = %d\tet\tcoor[1] = %d\n", fakecoor[0], fakecoor[1]);
				}
			}
		}/*
		//vscode printf("moving_side avant de rentrer dans top = %d\n", moving_side);
		if (moving_side != BOT) //laisser le code tel quel dans une autre fonction (ca va surement marcher en fait)
		{			
			if ((ret[0] = moving_top(map->number, coor, fakecoor, map->nbcuby)) == STOP)
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
			////vscode sleep(1);
			//vscode printf("jte dis bonjour\n");
			////vscode sleep(14);
			if (moving_side != BOT) //laisser le code tel quel dans une autre fonction (ca va surement marcher en fait)
			{			
				if ((ret[0] = moving_top(map->number, coor, fakecoor, map->nbcuby)) == STOP)
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
						//vscode printf("moving_side (apres etre sorti du right de bot) = %d\n", moving_side);
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
			//vscode printf("saluuuuuut\n");
			//cangoright = 0;
			if (moving_side != TOP)
			{
				//vscode printf("je rentre dans (bot) bot\n");
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
						//vscode printf("fakecoor[0] = %d\tet\tfakecoor[1] = %d (en sortant de (bot) left)\n", fakecoor[0], fakecoor[1]);
					}
				}
			}
			if (moving_side != RIGHT)
			{
				//vscode printf("je rentre dans (bot) left\n");
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
						//vscode printf("fakecoor[0] = %d\tet\tfakecoor[1] = %d (en sortant de (bot) left)\n", fakecoor[0], fakecoor[1]);
					}
				}
			}
			if (moving_side != BOT)
			{
				//vscode printf("je rentre dans (bot) top\n");
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
						//vscode printf("fakecoor[0] = %d\tet\tfakecoor[1] = %d (en sortant de (bot) top)\n", fakecoor[0], fakecoor[1]);
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
					fakecoor[0]++;
			}
		}
		if (moving_side != LEFT)
		{
			//vscode printf("tchoinnnnnn !!!\n");
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
	printf("backtrack is coming\n");
	recover_xtreme(coor, &coor[2], BLOCKED);
	map->backtrackpos[fakecoor[0] * map->nbxmax + fakecoor[1]] = 1;
	//vscode printf("fakecoor[0] = %d\tet\tfakecoor[1] = %d (avant de backtrack)\n", fakecoor[0], fakecoor[1]);
	//vscode printf("location = %d\tet\tTOP = %d\n", location, TOP);
	//vscode sleep(2);
	return (BLOCKED);
}
