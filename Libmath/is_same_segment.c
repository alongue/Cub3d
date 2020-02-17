/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_same_segment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:31:28 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/17 16:35:26 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

bool	is_same_segment(t_segment s1, t_segment s2)
{
	if (s1.p.x == s2.p.x && s1.p.y == s2.p.y &&
		s1.q.x == s2.q.x && s1.q.y == s2.q.y)
		return (true);
	return (false);
}
