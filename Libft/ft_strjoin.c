/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:46:01 by alongcha          #+#    #+#             */
/*   Updated: 2019/11/16 11:47:32 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		reslen;
	int		counter;
	int		counter2;

	if (!s1 || !s2)
		return (0);
	reslen = ft_strlen(s1) + ft_strlen(s2);
	if (!(res = (char *)malloc(sizeof(char) * (reslen + 1))))
		return (0);
	counter = 0;
	while (s1[counter])
	{
		res[counter] = s1[counter];
		counter++;
	}
	counter2 = counter;
	counter = 0;
	while (s2[counter])
	{
		res[counter2 + counter] = s2[counter];
		counter++;
	}
	res[counter2 + counter] = '\0';
	return (res);
}
