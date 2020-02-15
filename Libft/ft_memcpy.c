/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:43:11 by alongcha          #+#    #+#             */
/*   Updated: 2019/11/11 22:01:22 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*srccop;
	unsigned char	*dstcop;
	void			*oridst;

	if ((!dst) && (!src))
		return (0);
	oridst = dst;
	srccop = (unsigned char *)src;
	dstcop = (unsigned char *)dst;
	while (n > 0)
	{
		*dstcop = *srccop;
		srccop++;
		dstcop++;
		n--;
	}
	return (oridst);
}
