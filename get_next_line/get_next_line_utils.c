/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 10:58:45 by alongcha          #+#    #+#             */
/*   Updated: 2019/12/04 18:30:59 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	counter;

	counter = 0;
	while (s[counter])
		counter++;
	return (counter);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		reslen;
	int		counter;
	int		counter2;

	if (!s1 || !s2)
		return (0);
	reslen = ft_strlen(s1) + ft_strlen(s2);
	if (!(res = (char *)malloc(sizeof(char) * reslen + 1)))
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
	if (!(s2 = (char *)malloc(sizeof(char) * len + 1)))
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

int		ft_ischar(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		s1len;
	int		counter;

	s1len = 0;
	if (!s1)
		return (NULL);
	while (s1[s1len])
		s1len++;
	if (!(s2 = (char *)malloc(sizeof(char) * s1len + 1)))
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
