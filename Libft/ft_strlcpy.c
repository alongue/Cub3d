/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:18:29 by alongcha          #+#    #+#             */
/*   Updated: 2019/12/11 21:37:57 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	dstnbchar;
	size_t	srclen;

	dstnbchar = 0;
	if (!(src))
		return (0);
	if (dstsize > 0)
	{
		while (src[dstnbchar] != '\0' && dstnbchar < (dstsize - 1))
		{
			dst[dstnbchar] = src[dstnbchar];
			dstnbchar++;
		}
		dst[dstnbchar] = '\0';
	}
	srclen = 0;
	while (src[srclen])
		srclen++;
	return (srclen);
}
