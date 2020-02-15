/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 21:10:12 by alongcha          #+#    #+#             */
/*   Updated: 2019/12/03 13:29:38 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_get_nbprint(const char *str)
{
	int	i;
	int	counter;

	i = -1;
	counter = 0;
	while (str[++i])
	{
		if (ft_isprint(str[i]))
			counter++;
	}
	return (counter);
}
