/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:56:19 by alongcha          #+#    #+#             */
/*   Updated: 2019/12/04 15:55:56 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_nbchar(int n)
{
	unsigned int	ncop;
	char			*itoa;
	int				nbchar;

	nbchar = 0;
	if (n < 0)
	{
		ncop = -n;
		nbchar++;
	}
	else
		ncop = n;
	while (ncop > 9)
	{
		ncop /= 10;
		nbchar++;
	}
	nbchar++;
	if (!(itoa = (char *)malloc(sizeof(char) * (nbchar + 1))))
		return (0);
	return (itoa);
}

static void		ft_append(char *tab, int n, int imax)
{
	unsigned int	ncop;
	static int		i = 0;

	if (n < 0)
	{
		ncop = -n;
		tab[i] = '-';
		i += 1;
	}
	else
		ncop = n;
	if (ncop <= 9)
	{
		tab[i] = ncop + '0';
		i++;
		ncop %= 10;
	}
	if (ncop > 9)
	{
		ft_append(tab, ncop / 10, imax);
		tab[i++] = (ncop % 10) + '0';
	}
	if (i == imax)
		i = 0;
}

char			*ft_itoa(int n)
{
	unsigned int	ncop;
	char			*itoa;
	int				nb[2];

	nb[0] = 0;
	if (!(itoa = ft_nbchar(n)))
		return (0);
	if (n < 0)
	{
		ncop = -n;
		nb[0]++;
	}
	else
		ncop = n;
	nb[1] = n;
	while (ncop > 9)
	{
		ncop /= 10;
		nb[0]++;
	}
	nb[0]++;
	itoa[nb[0]] = '\0';
	ft_append(itoa, nb[1], nb[0]);
	return (itoa);
}
