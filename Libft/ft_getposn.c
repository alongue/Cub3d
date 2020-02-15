/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getposn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 21:08:52 by alongcha          #+#    #+#             */
/*   Updated: 2019/12/04 21:11:37 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getposn(const char *str, int c, int num, int start)
{
	int		i;
	int		counter;
	int		pos;

	i = start - 1;
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
