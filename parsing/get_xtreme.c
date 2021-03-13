/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_xtreme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:44:27 by user42            #+#    #+#             */
/*   Updated: 2021/03/12 17:44:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		get_xtreme_x(char *xtreme)
{
	int		x;
	char	*temp;

	if (!xtreme)
		return (-1);
	temp = ft_strjoin_free(ft_ctos(xtreme[0]), ft_ctos(xtreme[1]));
	x = ft_atoi(temp);
	free(temp);
	return (x);
}

int		get_xtreme_y(char *xtreme)
{
	int		y;
	char	*temp;

	if (!xtreme)
		return (-1);
	temp = ft_strjoin_free(ft_ctos(xtreme[2]), ft_ctos(xtreme[3]));
	y = ft_atoi(temp);
	free(temp);
	return (y);
}

char	*get_xtreme(int x, int y)
{
	char	**xtreme;
	int		boundend;
	int		i;

	xtreme = recover_xtreme(NULL, &boundend, 0);
	i = -1;
	while (++i < boundend)
	{
		if (x == get_xtreme_x(xtreme[i]) && y == get_xtreme_y(xtreme[i]))
			return (ft_strdup(xtreme[i]));
	}
	return (NULL);
}

int		get_xtreme_location(int x, int y)
{
	char	**xtreme;
	int		boundend;
	int		i;

	xtreme = recover_xtreme(NULL, &boundend, 0);
	i = -1;
	while (++i < boundend)
	{
		if (x == get_xtreme_x(xtreme[i]) && y == get_xtreme_y(xtreme[i]))
			return (ft_atoi(&xtreme[i][4]));
	}
	return (-2);
}

char	**recover_xtreme(int *coor, int *end, int location)
{
	static char	**xtreme = NULL;
	static int	i = -1;
	static int	icop = -1;
	char		*temp[2];

	*end = i + 1;
	if (!coor)
		return (xtreme);
	if (location != BLOCKED)
	{
		icop++;
		i = icop;
	}
	else
		i = remind(coor[1], coor[0]);
	if (i == 0 && location != BLOCKED)
		xtreme = malloc(sizeof(char *) * 1);
	else if (location != BLOCKED)
		xtreme = ft_realloc(xtreme, sizeof(char *) * (i + 1));
	temp[0] = ft_itoa(coor[1]);
	if (coor[1] <= 9)
		temp[0] = ft_strjoin_free(ft_strdup("0"), temp[0]);
	temp[1] = ft_itoa(coor[0]);
	if (coor[0] <= 9)
		temp[1] = ft_strjoin_free(ft_strdup("0"), temp[1]);
	if (location == BLOCKED)
		free(xtreme[i]);
	xtreme[i] = ft_strjoin_free(temp[0],
	ft_strjoin_free(temp[1], ft_itoa(location)));
	return (xtreme);
}
