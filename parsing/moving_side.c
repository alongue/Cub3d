/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_side.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:41:07 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 20:30:16 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		moving_top(char **number, int *coor, int *fakecoor, int *nbcuby)
{
	(void)coor;
	if (fakecoor[0] != get_col_nbmin(number, fakecoor[1], nbcuby)
	&& number[fakecoor[0] - 1][fakecoor[1]] != ' ')
	{
		if (number[fakecoor[0] - 1][fakecoor[1]] == '1')
		{
			fakecoor[0]--;
			return (TOP);
		}
		else
		{
			return (STOP);
		}
	}
	else
		return (BLOCKED);
}

int		moving_right(char **number, int *coor, int *fakecoor)
{
	(void)coor;
	if (fakecoor[1] != get_line_nbmax(number, fakecoor[0]) &&
	number[fakecoor[0]][fakecoor[1] + 1] != ' ')
		if (number[fakecoor[0]][fakecoor[1] + 1] == '1')
		{
			(fakecoor[1])++;
			return (RIGHT);
		}
		else
		{
			return (STOP);
		}
	else
		return (BLOCKED);
}

int		moving_bot(char **number, int *coor, int *fakecoor, int *nbcuby)
{
	(void)coor;
	if (fakecoor[0] != get_col_nbmax(number, fakecoor[1], nbcuby) &&
	number[fakecoor[0] + 1][fakecoor[1]] != ' ')
		if (number[fakecoor[0] + 1][fakecoor[1]] == '1')
		{
			(fakecoor[0])++;
			return (BOT);
		}
		else
		{
			return (STOP);
		}
	else
		return (BLOCKED);
}

int		moving_left(char **number, int *coor, int *fakecoor)
{
	(void)coor;
	if (fakecoor[1] != get_line_nbmin(number, fakecoor[0]) &&
	number[fakecoor[0]][fakecoor[1] - 1] != ' ')
		if (number[fakecoor[0]][fakecoor[1] - 1] == '1')
		{
			(fakecoor[1])--;
			return (LEFT);
		}
		else
		{
			return (STOP);
		}
	else
		return (BLOCKED);
}
