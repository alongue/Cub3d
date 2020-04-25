/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lengthp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 10:38:56 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/14 14:45:46 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

double	get_lengthp(t_point a, t_point b)
{
	double	x;
	double	y;

	x = pow(b.x - a.x, 2);
	y = pow(b.y - a.y, 2);
	return (sqrt(x + y));
}
