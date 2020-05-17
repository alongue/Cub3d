/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_side.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:41:07 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/04 12:10:39 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		moving_top(char **number, int *coor, int *fakecoor)
{
	(void)coor;
	//printf("fakecoor[0] = %d\t\tget_col_nbmin(number, %d) = %d\n", fakecoor[0], fakecoor[1], get_col_nbmin(number, fakecoor[1]));
	if (fakecoor[0] != get_col_nbmin(number, fakecoor[1]) && number[fakecoor[0] - 1][fakecoor[1]] != ' ')
	{
		//printf("jte plante\n");
		if (number[fakecoor[0] - 1][fakecoor[1]] == '1')
		{
			fakecoor[0]--;
			return (TOP);
		}
		else
		{
			printf("STOP pour fakecoor[0] - 1 = %d et fakecoor[1] = %d\n", fakecoor[0] - 1, fakecoor[1]);
			//sleep(4);
			return (STOP);
		}
	}
	else
		return (BLOCKED);
}

int		moving_right(char **number, int *coor, int *fakecoor)
{
	(void)coor;
	if (fakecoor[1] != get_line_nbmax(number, fakecoor[0]) && number[fakecoor[0]][fakecoor[1] + 1] != ' ')
		if (number[fakecoor[0]][fakecoor[1] + 1] == '1')
		{
			(fakecoor[1])++;
			return (RIGHT);
		}
		else
		{
			printf("STOP pour fakecoor[0] = %d et fakecoor[1] + 1 = %d\n", fakecoor[0], fakecoor[1] + 1);
			//sleep(4);
			return (STOP);
		}
	else
		return (BLOCKED);
}

int		moving_bot(char **number, int *coor, int *fakecoor, int *nbcuby)
{
	(void)coor;
	if (fakecoor[0] != get_col_nbmax(number, fakecoor[1], nbcuby) && number[fakecoor[0] + 1][fakecoor[1]] != ' ')
		if (number[fakecoor[0] + 1][fakecoor[1]] == '1')
		{
			(fakecoor[0])++;
			return (BOT);
		}
		else
		{
			printf("STOP pour fakecoor[0] + 1 = %d et fakecoor[1] = %d\n", fakecoor[0] + 1, fakecoor[1]);
			//sleep(4);
			return (STOP);
		}
	else
		return (BLOCKED);
}

int		moving_left(char **number, int *coor, int *fakecoor)
{
	(void)coor;
	//printf("fakecoor[1] = %d\tet\tget_line_nbmin(number, %d) = %d\n", fakecoor[1], fakecoor[0], get_line_nbmin(number, fakecoor[0]));
	if (fakecoor[1] != get_line_nbmin(number, fakecoor[0]) && number[fakecoor[0]][fakecoor[1] - 1] != ' ')
		if (number[fakecoor[0]][fakecoor[1] - 1] == '1')
		{
			(fakecoor[1])--;
			return (LEFT);
		}
		else
		{
			printf("STOP pour fakecoor[0] = %d et fakecoor[1] - 1 = %d\n", fakecoor[0], fakecoor[1] - 1);
			//sleep(4);
			return (STOP);
		}
	else
		return (BLOCKED);
}
