/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_boundy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:24:42 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/12 17:24:44 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	**get_all_boundy(int y, int *max, char **xtreme, int boundend)
{
	char	**boundy;
	int		k;
	int		i;
	int		isoutside;
	int		isoutsidecop;

	boundy = malloc(sizeof(char *) * 1);
	k = 0;
	i = -1;
	isoutside = 1;
	isoutsidecop = 1;
	while (++i < boundend)
	{
		if (ft_atoi(&xtreme[i][4]) == BLOCKED || isoutside
		!= (isoutsidecop = getside(y, xtreme[i], isoutside)))
		{
			if (k != 0)
				boundy = ft_realloc(boundy, sizeof(char *) * (k + 1));
			boundy[k++] = ft_strdup(xtreme[i]);
		}
		isoutside = isoutsidecop;
	}
	sort_table_y(boundy, k);
	*max = k;
	return (boundy);
}
