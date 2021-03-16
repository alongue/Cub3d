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

int		free_msg_once(int ret, char *msg, void **to_free, void **to_free2)
{
	static int	isprinted = 0;

	if (!isprinted)
	{
		ft_putstr_fd(msg, STDOUT_FILENO);
		isprinted = 1;
	}
	return (ft_free_ret(ret, to_free, to_free2, NULL));
}

void	*free_msg_nl(void *ret, char *msg, void **to_free, void **to_free2)
{
	static int	isprinted = 0;

	if (!isprinted)
	{
		ft_putstr_fd(msg, STDOUT_FILENO);
		isprinted = 1;
	}
	ft_free_ret(0, to_free, to_free2, NULL);
	return (ret);
}

char	***xtreme_addr(char ***xtreme, int *end)
{
	static char		***xtremecop;
	static int		endcop;

	if (xtreme)
	{
		xtremecop = xtreme;
		endcop = *end;
	}
	else
		*end = endcop;
	return (xtremecop);
}

int		init_recover_xtreme(char ***xtreme, int *icop, int *coor, int location)
{
	int		i;
	char	**testxtreme;

	if (location != BLOCKED)
	{
		(*icop)++;
		i = *icop;
	}
	else
	{
		printf("est cense s'en rappeler car location = BLOCKED donc backtrack interne\n");
		if ((i = remind(coor[1], coor[0])) == -1)
			return (-1);
	}
	if (i == 0 && location != BLOCKED)
	{
		if (!(testxtreme = malloc(sizeof(char *) * 1)))
			return (ft_putstrreti_fd(MALLOC, -1, STDOUT_FILENO));
		*xtreme = testxtreme;
	}
	else if (location != BLOCKED)
	{
		if (!(testxtreme = ft_realloc(*xtreme, sizeof(char *) * (i + 1),
		sizeof(char *) * i)))
			return (free_msg_once(-1, MALLOC, (void **)xtreme, NULL));
		*xtreme = testxtreme;
	}
	return (i);
}

int		finish_recover(int location, char ***xtreme, char **temp, int i)
{
	int		counter;

	counter = -1;
	if (location == BLOCKED)
		free((*xtreme)[i]);
	if (!((*xtreme)[i] = ft_strjoin_free(temp[0],
	ft_strjoin_free(temp[1], ft_itoa(location)))))
	{
		while (++counter < i)
			ft_free_ret(0, (void **)&(*xtreme)[counter], NULL, NULL);
		ft_free_ret(0, (void **)xtreme, NULL, NULL);
		return (free_msg_once(0, MALLOC, NULL, NULL));
	}
	return (1);
}
