/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:22:54 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 23:01:02 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

int	translate_point(t_point *point, double x, double y)
{
	int		ret;
	int		ispos[2];

	ispos[0] = (point->x >= 0) ? 1 : 0;
	ispos[1] = (point->y >= 0) ? 1 : 0;
	point->x += x;
	ret = 1;
	if ((point->x < 0 && ispos[0] == 1) || (point->x >= 0 && ispos[0] == 0))
		ret = 0;
	point->y += y;
	if ((point->y < 0 && ispos[1] == 1) || (point->y >= 0 && ispos[1] == 0))
		ret = 0;
	return (ret);
}
