/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:48:16 by alongcha          #+#    #+#             */
/*   Updated: 2019/11/16 12:02:44 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isequal(char c, const char *s)
{
	int	counter;

	counter = 0;
	while (s[counter])
	{
		if (c == s[counter])
			return (1);
		counter++;
	}
	return (0);
}

static int	ft_strless(const char *s1, const char *set, int isbeginning)
{
	int	counter;
	int	res;

	res = 0;
	if (isbeginning)
		counter = 0;
	else
		counter = ft_strlen(s1) - 1;
	while (ft_isequal(s1[counter], set) && ((s1[counter] && isbeginning)
	|| (counter != 0 && !isbeginning)))
	{
		res += 1;
		if (isbeginning)
			counter++;
		else
			counter--;
	}
	return (res);
}

static int	ft_strcount(const char *s1, const char *set)
{
	int	res;

	res = ft_strlen(s1);
	res -= ft_strless(s1, set, 1);
	res -= ft_strless(s1, set, 0);
	return (res);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*s1cop;
	int		start;
	int		stop;
	int		counter;
	int		size;

	if (!s1 || !set)
		return (0);
	size = sizeof(char) * ft_strcount(s1, set) + 1;
	if (size < 0)
		return (ft_strdup(""));
	if (!(s1cop = (char *)malloc(size)))
		return (0);
	counter = 0;
	start = ft_strless(s1, set, 1);
	stop = ft_strlen(s1) - ft_strless(s1, set, 0);
	while (start < stop)
	{
		s1cop[counter] = s1[start];
		counter++;
		start++;
	}
	s1cop[counter] = '\0';
	return (s1cop);
}
