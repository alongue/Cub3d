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
	int		lin;
	int		col;
	int		i;
	char	*strcop;
	int		ret;

	lin = -1;
	while (++lin < get_nbymax(nbcuby))
	{
		strcop = ft_strtrim(number[lin], " ");
		printf("number[%d] = %s\n", lin, number[lin]);
		printf("strcop = %s\n", strcop);
		if (strcop[0] != '1' || strcop[ft_strlen(strcop) - 1] != '1')
			return (false);
	}
	col = -1;
	while (++col < get_nbxmax(nbcuby))
	{
		if (number[get_col_nbmin(number, col)][col] != '1' ||
			number[get_col_nbmax(number, col)][col] != '1')
		{
			printf("nbcuby[col] = %d\n", nbcuby[col]);
			printf("number[i][col] = %c\n", number[i][col]);
			return (false);
		}
	}
	if (searching_around(number, nbcuby, 0, 0) == ISFINISH)
		return (true);
	else
		return (false);
}
