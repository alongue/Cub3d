/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_btwn_minpitw_pitw.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 10:38:56 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 22:37:56 by alongcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

#define DBLMAX M_PI

void	set_btwn_zero_twopi(double *angle)
{
	int		i;
	double	anglecop;

	if (*angle >= -DBLMAX / 2 && *angle < DBLMAX / 2)
		return ;
	i = 1;
	anglecop = *angle;
	while ((*angle /= (DBLMAX / 2 * i)) > DBLMAX / 2 || *angle < -DBLMAX / 2)
	{
		*angle = anglecop;
		i++;
	}
	*angle = (*angle <= DBLMAX / 2) ? DBLMAX / 2 - *angle : *angle;
}
