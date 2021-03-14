/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boundaries.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:48:43 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/12 17:50:00 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		is_boundaries(int x, int y)
{
	int		boundend;
	char	**xtreme;
	int		i;

	xtreme = recover_xtreme(NULL, &boundend, 0);
	i = -1;
	while (++i < boundend)
	{
		if (x == get_xtreme_x(xtreme[i]) && y == get_xtreme_y(xtreme[i]))
			return (1);
	}
	return (0);
}

int		is_rlly_btwn(int y, char **boundx, int max)
{
	int	i[2];

	i[0] = -1;
	i[1] = -1;
	while (++i[0] < max)
	{
		while (++i[1] < max)
		{
			if (i[0] != i[1])
				if (is_btwn(y, get_xtreme_x(boundx[i[0]]),
				get_xtreme_x(boundx[i[1]])))
				{
					if ((ft_atoi(&boundx[i[0]][4]) == LEFT &&
					ft_atoi(&boundx[i[1]][4]) == RIGHT)
					|| (ft_atoi(&boundx[i[0]][4]) == RIGHT &&
					ft_atoi(&boundx[i[1]][4]) == LEFT))
						return (1);
					i[0] = i[1];
				}
		}
	}
	return (0);
}
