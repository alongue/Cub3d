/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_segment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 09:48:51 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/16 16:20:26 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_segment	get_segment(t_point p, t_point q)
{
	t_segment	s;

	s.p = get_point(p.x, p.y);
	s.q = get_point(q.x, q.y);
	return (s);
}
