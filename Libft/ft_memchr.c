/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:53:55 by alongcha          #+#    #+#             */
/*   Updated: 2019/12/04 21:06:24 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*scop;
	unsigned char	ccop;
	size_t			counter;

	counter = 0;
	scop = (unsigned char *)s;
	ccop = (unsigned char)c;
	while (counter < n)
	{
		if (*scop == ccop)
			return (scop);
		else if (counter == n)
			return (0);
		counter++;
		scop++;
	}
	return (0);
}
