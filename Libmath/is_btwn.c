/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_btwn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 13:24:12 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/08 17:16:26 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

int	is_btwn(int towatch, int a, int b)
{
	if (a < b)
		if (towatch > a && towatch < b)
			return (1);
	if (a > b)
		if (towatch < a && towatch > b)
			return (1);
	return (0);
}
