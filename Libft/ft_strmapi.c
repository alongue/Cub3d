/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:26:28 by alongcha          #+#    #+#             */
/*   Updated: 2019/11/16 11:35:18 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*scop;
	unsigned int	counter;

	if (!s)
		return (NULL);
	if (!(scop = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	counter = 0;
	while (s[counter])
	{
		scop[counter] = (*f)(counter, s[counter]);
		counter++;
	}
	scop[counter] = '\0';
	return (scop);
}
