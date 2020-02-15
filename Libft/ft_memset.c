/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:04:45 by alongcha          #+#    #+#             */
/*   Updated: 2019/11/11 22:01:40 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	counter;
	unsigned char	*bcop;

	counter = 0;
	bcop = (unsigned char *)b;
	while (counter != len)
	{
		*bcop = (unsigned char)c;
		bcop++;
		counter++;
	}
	return (b);
}
