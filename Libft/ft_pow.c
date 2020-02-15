/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 17:30:17 by alongcha          #+#    #+#             */
/*   Updated: 2019/12/04 16:13:35 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_pow(double nb, double power)
{
	double	result;

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
