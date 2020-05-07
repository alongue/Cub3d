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
		if (strcop[0] != '1' || strcop[ft_strlen(strcop)] != '1')
			return (false);
	}
	col = -1;
	while (++col < get_nbxmax(nbcuby))
	{
		i = -1;
		while (number[i][col] == ' ')
			i++;
		if (number[i][col] != '1' || number[i + nbcuby[col]][col] != '1')
			return (false);
	}
	return (true);
}
