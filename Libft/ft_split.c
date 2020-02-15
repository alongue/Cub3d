/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:44:09 by alongcha          #+#    #+#             */
/*   Updated: 2019/11/18 11:47:15 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **tab, int i)
{
	i = i - 1;
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return ((void *)0);
}

static void	ft_strncpy(char *dest, const char *src, char c)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static int	ft_nbwords(const char *str, char c)
{
	int i;
	int words;

	if (!str)
		return (-1);
	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			words++;
			while (str[i] != c && str[i])
				i++;
		}
		else
			i++;
	}
	return (words);
}

static int	ft_count(const char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

char		**ft_split(char const *s, char c)
{
	int		i[4];
	char	**split;

	i[3] = 0;
	if (((i[2] = ft_nbwords(s, c)) == -1) ||
	(!(split = (char**)malloc(sizeof(char*) * (i[2] + 1)))))
		return (NULL);
	i[0] = 0;
	i[1] = 0;
	while (s[i[0]])
	{
		if (s[i[0]] != c)
		{
			i[3] = ft_count(&s[i[0]], c);
			if (!(split[i[1]] = (char *)malloc(i[3] + 1)))
				return (ft_free(split, i[1]));
			ft_strncpy(split[i[1]], s + i[0], c);
			i[0] = i[0] + i[3];
			i[1]++;
		}
		else
			i[0]++;
	}
	split[i[1]] = 0;
	return (split);
}
