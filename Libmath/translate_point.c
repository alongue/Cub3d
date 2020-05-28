/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:22:54 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/11 15:45:36 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

int	translate_point(t_point *point, double x, double y) // si le point en x ou en y fais faire un overflow on renvoie un chiffre d'erreur
{
	int		ret;
	int	ispos[2];

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
