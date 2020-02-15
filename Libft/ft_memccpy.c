/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:24:31 by alongcha          #+#    #+#             */
/*   Updated: 2019/11/12 12:30:26 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dstcop;
	unsigned char	*srccop;
	unsigned char	ccop;

	dstcop = (unsigned char *)dst;
	srccop = (unsigned char *)src;
	ccop = (unsigned char)c;
	while (n > 0)
	{
		*dstcop = *srccop;
		if (*srccop == ccop)
			return (dstcop + 1);
		dstcop++;
		srccop++;
		n--;
	}
	return (0);
}
