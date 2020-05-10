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

int		moving_top(char **number, int *col, int *lin)
{
	if (*lin != get_col_nbmin(number, *col) && number[*lin - 1][*col] != ' ')
	{
		if (number[--(*lin)][*col] == '1')
			return (TOP);
		else
			return (STOP);
	}
	else
		return (BLOCKED);
}

int		moving_right(char **number, int *col, int *lin)
{
	if (*col != get_line_nbmax(number, *lin) && number[*lin][*col + 1] != ' ')
		if (number[*lin][++(*col)] == '1')
			return (RIGHT);
		else
			return (STOP);
	else
		return (BLOCKED);
}

int		moving_bot(char **number, int *col, int *lin, int *nbcuby)
{
	if (*lin != get_col_nbmax(number, *col, nbcuby) && number[*lin + 1][*col] != ' ')
		if (number[++(*lin)][*col] == '1')
			return (BOT);
		else
		{
			printf("STOP\n");
			return (STOP);
		}
	else
		return (BLOCKED);
}

int		moving_left(char **number, int *col, int *lin)
{
	if (*col != get_line_nbmin(number, *lin) && number[*lin][*col - 1] != ' ')
		if (number[*lin][--(*col)] == '1')
			return (LEFT);
		else
			return (STOP);
	else
		return (BLOCKED);
}
