/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_btwn_minpitw_pitw.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 10:38:56 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/14 14:45:46 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

#define MAX M_PI / 2
#define MIN -M_PI / 2

void	set_btwn_zero_twopi(double *angle)
{
	int		i;
	double	anglecop;

	if (*angle >= MIN && *angle < MAX)
		return ;
	i = 1;
	anglecop = *angle;
	while ((*angle /= (MAX * i)) > MAX || *angle < -MAX)
	{
		*angle = anglecop;
		i++;
	}
	*angle = (*angle <= MAX) ? MAX - *angle : *angle;
}
