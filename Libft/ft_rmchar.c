/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rmcarac.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 21:35:08 by alongcha          #+#    #+#             */
/*   Updated: 2019/12/12 04:09:38 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_rmchar(const char *str, int c)
{
	int		nb;
	int		counter;
	int		count;
	char	*s;

	counter = -1;
	count = 0;
	nb = ft_get_nbchar(str, c);
	if (str == NULL || nb == 0)
		return (ft_strdup(str));
	if (!(s = (char *)malloc(sizeof(char) * (ft_strlen(str) - nb + 1))))
		return (ft_strdup(str));
	while (str[++counter])
	{
		while (str[counter] == c && str[counter])
			counter++;
		s[count++] = str[counter];
	}
	s[count] = '\0';
	return (s);
}
