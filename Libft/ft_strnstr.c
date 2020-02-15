/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:58:58 by alongcha          #+#    #+#             */
/*   Updated: 2019/11/11 22:06:22 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	counter1;
	unsigned int	counter2;
	char			*haystackcop;

	haystackcop = (char *)haystack;
	if (needle[0] == '\0')
		return (haystackcop);
	counter1 = 0;
	counter2 = 0;
	while (haystack[counter1] != '\0' && counter1 < len)
	{
		counter2 = 0;
		while (haystack[counter1 + counter2] ==
needle[counter2] && counter1 + counter2 < len)
		{
			counter2++;
			if (needle[counter2] == '\0')
				return (&haystackcop[counter1]);
		}
		counter1++;
	}
	return (0);
}
