/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_xtreme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:44:27 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/12 17:44:41 by alongcha         ###   ########.fr       */
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

	*end = icop + 1;
	printf("icop = %d\n", icop);
	xtreme_addr(&xtreme, end);
	if (!coor)
		return (xtreme);
	if ((i = init_recover_xtreme(&xtreme, &icop, coor, location)) == -1)
		return (NULL);
	if (!(temp[0] = ft_itoa(coor[1])))
		return (free_msg_nl(NULL, MALLOC, (void **)&xtreme, NULL));
	if (coor[1] <= 9 && !(temp[0] = ft_strjoin_free(ft_strdup("0"), temp[0])))
		return (free_msg_nl(NULL, MALLOC, (void **)&xtreme, NULL));
	if (!(temp[1] = ft_itoa(coor[0])))
		return (free_msg_nl(NULL, MALLOC, (void **)&xtreme, (void **)&temp[0]));
	if (coor[0] <= 9 && !(temp[1] = ft_strjoin_free(ft_strdup("0"), temp[1])))
		return (free_msg_nl(NULL, MALLOC, (void **)&xtreme, (void **)&temp[0]));
	if (!finish_recover(location, &xtreme, temp, i))
		return (NULL);
	return (xtreme);
}
