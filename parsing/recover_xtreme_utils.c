/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover_xtreme_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 18:43:05 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/13 18:43:17 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		init_recover_xtreme(char ***xtreme, int *icop, int *coor, int location)
{
	int		i;

	if (location != BLOCKED)
	{
		(*icop)++;
		i = *icop;
	}
	else if ((i = remind(coor[1], coor[0])) == -1)
		return (-1);
	if (i == 0 && location != BLOCKED)
	{
		if (!(*xtreme = malloc(sizeof(char *) * 1)))
			return (-1);
	}
	else if (location != BLOCKED)
	{
		if (!(*xtreme = ft_realloc(*xtreme, sizeof(char *) * (i + 1))))
			return (-1);
	}
	return (i);
}
