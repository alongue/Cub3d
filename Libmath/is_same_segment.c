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
	if (s1.a.x == s2.a.x && s1.a.y == s2.a.y &&
		s1.b.x == s2.b.x && s1.b.y == s2.b.y)
		return (true);
	return (false);
}
