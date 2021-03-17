/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:47:04 by alongcha          #+#    #+#             */
/*   Updated: 2019/11/11 22:05:26 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		s1len;
	int		counter;

	s1len = 0;
	while (s1[s1len])
		s1len++;
	if (!(s2 = (char *)malloc(sizeof(char) * (s1len + 1))))
		return (0);
	counter = 0;
	while (counter < s1len)
	{
		s2[counter] = s1[counter];
		counter++;
	}
	s2[counter] = '\0';
	return (s2);
}
