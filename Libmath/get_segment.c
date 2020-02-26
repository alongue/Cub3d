/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_segment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 09:48:51 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/17 17:35:16 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_segment	get_segment(t_point p, t_point q)
{
	t_segment	s;

	s.a = get_point(p.x, p.y);
	s.b = get_point(q.x, q.y);
	return (s);
}
