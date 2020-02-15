/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 09:42:55 by alongcha          #+#    #+#             */
/*   Updated: 2019/11/12 14:52:16 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1cop;
	unsigned char	*s2cop;

	if (n > 0)
	{
		s1cop = (unsigned char *)s1;
		s2cop = (unsigned char *)s2;
		while (*s1cop == *s2cop && n - 1 > 0 && *s1cop && *s2cop)
		{
			s1cop++;
			s2cop++;
			n--;
		}
		return (*s1cop - *s2cop);
	}
	else
		return (0);
}
