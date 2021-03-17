/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:11:59 by alongcha          #+#    #+#             */
/*   Updated: 2019/11/16 11:56:34 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	slen;
	size_t	s2len;

	if (!(s))
		return (0);
	slen = 0;
	while (s[slen])
		slen++;
	if (!(s2 = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	s2len = 0;
	if (!(start > slen))
		while (s[s2len + start] && s2len < len)
		{
			s2[s2len] = s[start + s2len];
			s2len++;
		}
	s2[s2len] = '\0';
	return (s2);
}
