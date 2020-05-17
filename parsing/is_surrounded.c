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

int		is_surrounded(t_map map) //int *map.nbcuby --> tableau qui indique le nombre de caractere qui a dans une colonne (dernier nb = -1)
{
	int		coor[2];
	char	*strcop;

	coor[0] = -1;
	coor[1] = 0;
	while (++coor[0] < get_nbymax(map.nbcuby))
	{
		strcop = ft_strtrim(map.number[coor[0]], " ");
		coor[1] += ft_strlen(map.number[coor[0]]);
		//printf("map.number[%d] = %s\n", coor[0], map.number[coor[0]]);
		printf("strcop = %s\n", strcop);
		if (strcop[0] != '1' || strcop[ft_strlen(strcop) - 1] != '1')
			return (false);
	}
	if (!(map.parsepos = malloc(sizeof(int) * coor[1])))
		return (3);
	map.parsepos = ft_memseti(map.parsepos, 0, coor[1]);
	coor[1] = -1;
	while (++coor[1] < get_nbxmax(map.nbcuby))
	{
		if (map.number[get_col_nbmin(map.number, coor[1])][coor[1]] != '1' ||
			map.number[get_col_nbmax(map.number, coor[1], map.nbcuby)][coor[1]] != '1')
		{
			printf("map.nbcuby[coor[1]] = %d\n", map.nbcuby[coor[1]]);
			return (false);
		}
	}
	coor[1] = get_line_nbmax(map.number, 0);
	coor[0] = 0;
	if (searching_around(map, coor, BLOCKED) == ISFINISH)
		return (true);
	else
		return (false);
}
