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

char	**set_boundy(char **boundy, int *k, char **xtreme, int i)
{
	char	**test;

	if (*k != 0)
	{
		if (!(test = ft_realloc(boundy, sizeof(char *) * (*k + 1),
		sizeof(char *) * *k)))
		{
			free_boundy(0, boundy, *k, NULL);
			return (NULL);
		}
		boundy = test;
	}
	if (!(boundy[(*k)++] = ft_strdup(xtreme[i])))
	{
		free_boundy(0, boundy, *k - 1, NULL);
		return (NULL);
	}
	return (boundy);
}

char	**get_all_boundy(int y, int *max, char **xtreme, int boundend)
{
	char	**boundy;
	int		k;
	int		i;
	int		isoutside;
	int		isoutsidecop;

	if (!(boundy = malloc(sizeof(char *) * 1)) &&
	!free_boundy(0, xtreme, boundend, NULL))
		return (NULL);
	k = 0;
	i = -1;
	isoutside = 1;
	isoutsidecop = 1;
	while (++i < boundend)
	{
		if (ft_atoi(&xtreme[i][4]) == BLOCKED || isoutside
		!= (isoutsidecop = getside(y, xtreme[i], isoutside)))
			if (!(boundy = set_boundy(boundy, &k, xtreme, i)))
				return (NULL);
		isoutside = isoutsidecop;
	}
	sort_table_y(boundy, k);
	*max = k;
	free_boundy(0, xtreme, boundend, NULL);
	return (boundy);
}

int		free_boundy(int ret, char **boundy, int max, char *msg)
{
	int		i;

	i = -1;
	if (boundy)
		while (++i < max)
			free(boundy[i]);
	free(boundy);
	ft_putstr_fd(msg, STDOUT_FILENO);
	return (ret);
}
