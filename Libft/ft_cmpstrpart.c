/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmpstrpart.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 19:27:17 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/28 19:43:45 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_smaller(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int		ft_cmpstrpart(char *str, int start, int len, char *cmp)
{
	int		reallen;
	int		res;

	if (!str || !cmp)
		return (0);
	reallen = get_smaller(len, ft_strlen(str) - start);
	res = 0;
	while (res == 0 && reallen >= 0 && *cmp != '\0')
	{
		res = str[reallen] - *cmp;
		cmp++;
		reallen--;
	}
	return (res);
}
