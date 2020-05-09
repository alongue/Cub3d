/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_moving.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:41:07 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/04 12:10:39 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		try_moving_top(char **number, int *nbcuby, int *col, int *lin)
{
	if (*lin != get_col_nbmin(number, *col) && number[*lin - 1][*col] != ' ')
		if (number[--(*lin)][*col] == '1')
		{
			moving_side = 
			return (TOP);
		}
		else
			return (STOP);
	if (*col != get_line_nbmax(number, *lin) && number[*lin][*col + 1] != ' ')
		if (number[*lin][++(*col)] == '1')
			return (MOVING);
		else
			return (STOP);
	if ()
	moving_side = BLOCKED;
}
