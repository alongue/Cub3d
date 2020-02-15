/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_powl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:04:37 by alongcha          #+#    #+#             */
/*   Updated: 2019/12/04 16:11:38 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_powl(long nb, long power)
{
	long	result;

	if (nb == 0)
		return (0);
	if (power == 1)
		return (nb);
	if (power == 0)
		return (1);
	if (power > 1)
		result = nb * ft_pow(nb, power - 1);
	else
		result = ft_pow(nb, power + 1) / nb;
	return (result);
}
