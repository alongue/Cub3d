/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtreme_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:47:19 by user42            #+#    #+#             */
/*   Updated: 2021/03/12 17:47:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	**xtreme_sorted_y(int y, int *max)
{
	char	**xtreme;
	char	**boundy;
	int		boundend;
	int		i;
	int		k;

	xtreme = recover_xtreme(NULL, &boundend, 0);
	i = -1;
	k = 0;
	boundy = malloc(sizeof(char *) * (k + 1));
	while (++i < boundend)
	{
		if (y == get_xtreme_y(xtreme[i]))
		{
			if (k != 0)
				boundy = ft_realloc(boundy, sizeof(char *) * (k + 1));
			boundy[k] = ft_strdup(xtreme[i]);
			k++;
		}
	}
	*max = k;
	sort_table_y(boundy, k);
	return (boundy);
}
