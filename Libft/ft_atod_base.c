/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:27:33 by alongcha          #+#    #+#             */
/*   Updated: 2019/12/09 22:06:22 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_offset(const char *str)
{
	int	i;
	int	neg;

	i = 0;
	neg = 1;
	while (str[i] && (ft_isspace(str[i])))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	return (i * neg);
}

static int	ft_counter(const char *str, const char *base)
{
	int	i;
	int	now;
	int	counter;

	counter = 1;
	i = ft_abs(ft_offset(str));
	now = ft_getpos(str, '.', 1);
	while (str[i] && counter > 0)
	{
		if (i == now)
		{
			counter = 1;
			i++;
		}
		counter = ft_get_nbchar(base, str[i++]);
	}
	return (counter);
}

static int	ft_check(const char *str, const char *base)
{
	int	size;
	int	i;
	int	counter;

	if (str == NULL || base == NULL)
		return (0);
	size = ft_strlen(base);
	i = -1;
	counter = 1;
	if (size == 0 || size == 1 || ft_get_nbspace(base) > 0
	|| ft_get_nbprint(base) != ft_strlen(base) ||
	ft_get_nbchar(str, '.') > 1)
		return (0);
	while (base[++i] && counter < 2)
		counter = ft_get_nbchar(base, base[i]);
	if (counter > 1 || ft_get_nbchar(base, '+') > 0
	|| ft_get_nbchar(base, '-') > 0)
		return (0);
	counter = ft_counter(str, base);
	counter = (counter == 0) ? 0 : 1;
	return (counter);
}

double		ft_atod_base(const char *str, const char *base)
{
	double	result;
	int		size[2];
	int		i[3];
	int		neg;

	result = 0;
	if (!ft_check(str, base))
		return (result);
	size[0] = ft_strlen(base);
	size[1] = ft_strlen(str);
	neg = (ft_offset(str)) < 0 ? -1 : 1;
	i[0] = 0;
	i[1] = 0;
	i[2] = ft_getpos(str, '.', 1) - 1;
	while (i[2] > ft_abs(ft_offset(str)))
	{
		i[2] = ft_getpos(str, '.', 1) - 1 - i[0]++;
		result += (str[i[2]] - '0') * ft_pow(size[0], i[1]++);
	}
	i[0] = 0;
	i[1] = 0;
	while ((i[2] = (ft_getpos(str, '.', 1) + 1) + i[0]++) < size[1])
		result += (str[i[2]] - '0') * ft_pow(size[0], --i[1]);
	return (result * neg);
}
