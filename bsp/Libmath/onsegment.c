/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onsegment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:29:52 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/02 14:00:26 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

bool	onsegment(t_point p, t_point q, t_point r)
{
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x)
		&& q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
		return (true);
	return (false);
}
