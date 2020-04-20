/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_segment_exc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 11:56:10 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/09 12:21:48 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void	split_segment_exc(t_segment segment, t_point point,
						t_segment *s1, t_segment *s2)
{
	t_point newpoint[2];

	newpoint[0] = dup_point(point);
	newpoint[1] = dup_point(point);
	if (!segment.exist)
		return ;
	get_prev_point(segment, &newpoint[0], 0.1);
	get_next_point(segment, &newpoint[1], 0.1);
	if (segment.a.x < segment.b.x)
	{
		*s1 = get_segment(segment.a, newpoint[0]);
		*s2 = get_segment(newpoint[1], segment.b);
	}
	else
	{
		*s1 = get_segment(segment.a, newpoint[1]);
		*s2 = get_segment(newpoint[0], segment.b);
	}
}
