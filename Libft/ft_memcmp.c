/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:37:37 by alongcha          #+#    #+#             */
/*   Updated: 2019/11/11 22:01:13 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1cop;
	unsigned char	*s2cop;
	int				res;

	s1cop = (unsigned char *)s1;
	s2cop = (unsigned char *)s2;
	res = 0;
	while (res == 0 && n > 0)
	{
		res = *s1cop - *s2cop;
		s1cop++;
		s2cop++;
		n--;
	}
	return (res);
}
