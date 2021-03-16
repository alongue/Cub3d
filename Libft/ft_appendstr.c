/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appendstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 20:59:16 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 21:08:42 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_appendstr(char *s, char c)
{
	int		len;
	char	*test;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!(test = ft_realloc(s, len + 2, len + 1)))
	{
		free(s);
		return (NULL);
	}
	s = test;
	s[len] = c;
	s[len + 1] = '\0';
	return (s);
}
