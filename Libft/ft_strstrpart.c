/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrpart.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 19:27:17 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/29 16:20:36 by alongcha         ###   ########.fr       */
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

int		ft_strstrpart(char *str, size_t start, char *cmp)
{
	int		res;

	if (!str || !cmp || start >= ft_strlen(str) ||
		ft_strlen(str) - start < ft_strlen(cmp))
		return (0);
	res = 1;
	while (res == 1 && *cmp != '\0')
	{
		res = (str[start] - *cmp != 0) ? 0 : 1;
		cmp++;
		start++;
	}
	return (res);
}
