/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_segment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:53:05 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/16 16:20:55 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_segment	dup_segment(t_segment s)
{
	t_segment	segment;

	segment.p = dup_point(s.p);
	segment.q = dup_point(s.q);
	return (segment);
}
