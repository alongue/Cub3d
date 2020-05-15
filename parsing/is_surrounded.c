/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_surrounded.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:41:07 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/04 12:10:39 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

bool	is_surrounded(char **number, int *nbcuby) //int *nbcuby --> tableau qui indique le nombre de caractere qui a dans une colonne (dernier nb = -1)
{
	int		coor[2];
	char	*strcop;

	coor[0] = -1;
	while (++coor[0] < get_nbymax(nbcuby))
	{
		strcop = ft_strtrim(number[coor[0]], " ");
		//printf("number[%d] = %s\n", coor[0], number[coor[0]]);
		printf("strcop = %s\n", strcop);
		if (strcop[0] != '1' || strcop[ft_strlen(strcop) - 1] != '1')
			return (false);
	}
	coor[1] = -1;
	while (++coor[1] < get_nbxmax(nbcuby))
	{
		if (number[get_col_nbmin(number, coor[1])][coor[1]] != '1' ||
			number[get_col_nbmax(number, coor[1], nbcuby)][coor[1]] != '1')
		{
			printf("nbcuby[coor[1]] = %d\n", nbcuby[coor[1]]);
			return (false);
		}
	}
	coor[1] = get_line_nbmax(number, 0);
	coor[0] = 0;
	if (searching_around(number, coor, BLOCKED, nbcuby) == ISFINISH)
		return (true);
	else
		return (false);
}
