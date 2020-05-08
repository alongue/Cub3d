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

	lin = -1;
	while (++lin < get_nbymax(nbcuby))
	{
		strcop = ft_strtrim(number[lin], " ");
		//printf("number[lin] = %s\n", number[lin]);
		//printf("strcop = %s\n", strcop);
		if (strcop[0] != '1' || strcop[ft_strlen(strcop) - 1] != '1')
			return (false);
	}
	col = -1;
	while (++col < get_nbxmax(nbcuby))
	{
		i = 0;
		while (number[i][col] == ' ')
			i++;
		if (number[i][col] != '1' || number[i + nbcuby[col] - 1][col] != '1')
		{
			printf("nbcuby[col] = %d\n", nbcuby[col]);
			printf("number[i][col] = %c\n", number[i][col]);
			return (false);
		}
	}
	return (true);
}
