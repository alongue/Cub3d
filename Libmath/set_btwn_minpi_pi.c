/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_btwn_minpi_pi.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 10:38:56 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 22:59:23 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

#define MAX M_PI

void	set_btwn_minpi_pi(double *angle)
{
	int		i;
	double	anglecop;

	if (*angle >= -MAX && *angle < MAX)
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
