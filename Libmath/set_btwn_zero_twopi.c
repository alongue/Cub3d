/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_btwn_zero_twopi.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 10:38:56 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 22:31:24 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

#define HALFMAX M_PI
#define MIN 0

void	set_btwn_zero_twopi(double *angle)
{
	int		i;
	double	anglecop;

	if (*angle >= MIN && *angle < HALFMAX * 2)
		return ;
	if (*angle > -HALFMAX * 2)
		*angle = HALFMAX * 2 - *angle;
	i = 1;
	anglecop = *angle;
	while ((*angle /= (HALFMAX * 2 * i)) > HALFMAX * 2 || *angle < -HALFMAX * 2)
	{
		*angle = anglecop;
		i++;
	}
	*angle = (*angle <= HALFMAX * 2) ? HALFMAX * 2 - *angle : *angle;
}
