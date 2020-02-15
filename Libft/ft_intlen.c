/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 22:04:34 by alongcha          #+#    #+#             */
/*   Updated: 2019/12/09 22:05:28 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(int n)
{
	unsigned int	ncop;
	size_t			nbchar;

	nbchar = 0;
	if (n < 0)
	{
		ncop = -n;
		nbchar++;
	}
	else
		ncop = n;
	while (ncop > 9)
	{
		ncop /= 10;
		nbchar++;
	}
	nbchar++;
	return (nbchar);
}
