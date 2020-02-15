/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:55:26 by alongcha          #+#    #+#             */
/*   Updated: 2019/12/04 21:08:08 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ccop;
	char	*scop;
	int		counter;

	ccop = (char)c;
	scop = (char *)s;
	counter = 0;
	while (scop[counter])
		counter++;
	if (ccop == '\0')
		return (&scop[counter]);
	while (counter > 0)
	{
		counter--;
		if (scop[counter] == ccop)
			return (&scop[counter]);
	}
	return (0);
}
