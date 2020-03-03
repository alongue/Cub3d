/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_segment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 11:52:04 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/02 15:13:01 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void	split_segment_inc(t_segment segment, t_point point,
						t_segment *s1, t_segment *s2)
{
	if (!segment.exist)
		return ;
	*s1 = get_segment(segment.a, point);
	*s2 = get_segment(point, segment.b);
}
