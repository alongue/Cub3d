/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtreme_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:47:19 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/12 17:47:40 by alongcha         ###   ########.fr       */
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
	if (!(boundy = malloc(sizeof(char *) * (k + 1))))
		return (NULL);
	while (++i < boundend)
	{
		if (y == get_xtreme_y(xtreme[i]))
			if (!(boundy = set_boundy(boundy, &k, xtreme, i)))
				return (NULL);
	}
	*max = k;
	sort_table_y(boundy, k);
	return (boundy);
}
