/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_lin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:59:52 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/17 16:01:25 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		get_line_nbmin(char **number, int lin)
{
	int	i;

	i = 0;
	while (number[lin][i] == ' ')
		i++;
	return (i);
}

int		get_line_nbmax(char **number, int lin)
{
	int	i;

	i = ft_strlen(number[lin]) - 1;
	while (number[lin][i] == ' ')
		i--;
	return (i);
}

int		get_col_nbmin(char **number, int col)
{
	int	i;

	i = 0;
	////vscode printf("number[%d][%d] = %c\n", i, col, number[i][col]);
	while (number[i][col] == ' ')
		i++;
	return (i);
}

int		get_col_nbmax(char **number, int col, int *nbcuby)
{
	return (get_col_nbmin(number, col) + nbcuby[col] - 1);
}