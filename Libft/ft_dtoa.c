/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:56:19 by alongcha          #+#    #+#             */
/*   Updated: 2019/12/04 16:34:03 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_nbchar(double n)
{
	double	ncop;
	char	*itoa;
	int		nbchar;

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
	if (!(itoa = (char *)malloc(sizeof(char) * nbchar + 7 + 1)))
		return (0);
	return (itoa);
}

static void		ft_append(char *tab, double n, int imax)
{
	double		ncop;
	static int	i = 0;

	if (n < 0)
	{
		ncop = -n;
		tab[i] = '-';
		i += 1;
	}
	else
		ncop = n;
	if (ncop >= 0 && ncop <= 9)
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

char			*ft_dtoa(double n)
{
	double	ncop;
	char	*itoa;
	double	nb[2];

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
	nb[0] += 8;
	itoa[(int)nb[0]] = '\0';
	ft_append(itoa, nb[1], nb[0]);
	return (itoa);
}
