/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 20:51:55 by alongcha          #+#    #+#             */
/*   Updated: 2019/12/11 21:55:06 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getpos(const char *str, int c, int num)
{
	int		i;
	int		counter;
	int		pos;

	i = -1;
	counter = 1;
	pos = -1;
	if (str == NULL)
		return (-1);
	while (str[++i])
		if (str[i] == c)
		{
			pos = i;
			if (counter++ == num)
				return (pos);
		}
	return (pos);
}
