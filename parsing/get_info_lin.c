/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_lin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:59:52 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 20:29:19 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		get_line_nbmin(char **number, int col)
{
	int	i;

	i = 0;
	while (number[col][i] == ' ')
		i++;
	return (i);
}

int		get_line_nbmax(char **number, int col)
{
	int	i;

	i = ft_strlen(number[col]) - 1;
	while (number[col][i] == ' ')
		i--;
	return (i);
}

int		get_col_nbmin(char **number, int lin, int *nbcuby)
{
	int	i;

	i = 0;
	if (nbcuby[lin] == 0)
		return (0);
	while (number[i][lin] == ' ')
		i++;
	return (i);
}

int		get_col_nbmax(char **number, int lin, int *nbcuby)
{
	if (nbcuby[lin] == 0)
		return (0);
	return (get_col_nbmin(number, lin, nbcuby) + nbcuby[lin] - 1);
}
