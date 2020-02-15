/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:36:35 by alongcha          #+#    #+#             */
/*   Updated: 2019/12/04 17:16:41 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_nbchar(long n, const char *base)
{
	unsigned long	ncop;
	char			*itoa;
	int				nbchar;
	unsigned int	size;

	size = ft_strlen(base);
	nbchar = 0;
	if (n < 0)
	{
		ncop = -n;
		nbchar++;
	}
	else
		ncop = n;
	while (ncop > size)
	{
		ncop /= size;
		nbchar++;
	}
	nbchar++;
	if (!(itoa = (char *)malloc(sizeof(char) * nbchar + 1)))
		return (0);
	return (itoa);
}

static void		ft_append(char *tab, long n, int imax, const char *base)
{
	unsigned long	ncop;
	static int		i = 0;

	if (n < 0)
	{
		ncop = -n;
		tab[i] = '-';
		i += 1;
	}
	else
		ncop = n;
	if (ncop <= ft_strlen(base) - 1)
	{
		tab[i] = base[ncop];
		i++;
		ncop %= ft_strlen(base);
	}
	if (ncop > ft_strlen(base) - 1)
	{
		ft_append(tab, ncop / ft_strlen(base), imax, base);
		tab[i++] = base[(ncop % ft_strlen(base))];
	}
	if (i == imax)
		i = 0;
}

char			*ft_ltoa_base(long n, const char *base)
{
	unsigned long	ncop;
	char			*itoa;
	long			nb[2];

	nb[0] = 0;
	if (!(itoa = ft_nbchar(n, base)))
		return (0);
	if (n < 0)
	{
		ncop = -n;
		nb[0]++;
	}
	else
		ncop = n;
	nb[1] = n;
	while (ncop > ft_strlen(base) - 1)
	{
		ncop /= ft_strlen(base);
		nb[0]++;
	}
	nb[0]++;
	itoa[nb[0]] = '\0';
	ft_append(itoa, nb[1], nb[0], base);
	return (itoa);
}
