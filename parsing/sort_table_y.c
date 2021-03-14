/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_table_y.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:20:39 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/12 17:20:42 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	sort_table_y(char **table, int max)
{
	int		i;
	int		j;
	int		x[2];

	ft_memseti(x, 0, 2);
	i = -1;
	while (++i < max)
	{
		j = i - 1;
		while (++j < max)
		{
			x[0] = get_xtreme_x(table[i]);
			x[1] = get_xtreme_x(table[j]);
			if (i != j)
				if (x[0] > x[1])
				{
					ft_swap((void **)&table[i], (void **)&table[j]);
					j = i - 1;
				}
		}
	}
}
