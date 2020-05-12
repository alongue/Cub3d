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

int		try_moving_top(char **number, int *nbcuby, int fakecoor[1], int fakecoor[0])
{
	if (fakecoor[0] != get_col_nbmin(number, fakecoor[1]) && number[fakecoor[0] - 1][fakecoor[1]] != ' ')
		if (number[--(fakecoor[0])][fakecoor[1]] == '1')
		{
			moving_side = 
			return (TOP);
		}
		else
			return (STOP);
	if (fakecoor[1] != get_line_nbmax(number, fakecoor[0]) && number[fakecoor[0]][fakecoor[1] + 1] != ' ')
		if (number[fakecoor[0]][++(fakecoor[1])] == '1')
			return (MOVING);
		else
			return (STOP);
	if ()
	moving_side = BLOCKED;
}
