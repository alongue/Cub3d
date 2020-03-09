/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_segment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:53:05 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/05 19:01:54 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_segment	dup_segment(t_segment s)
{
	t_segment	segment;

	segment.a = dup_point(s.a);
	segment.b = dup_point(s.b);
	segment.coeff = s.coeff;
	segment.intercept = s.intercept;
	segment.exist = true;
	return (segment);
}
