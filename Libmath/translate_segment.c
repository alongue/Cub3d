/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_segment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:44:25 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 22:57:37 by alongcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

int	translate_segment(t_segment *segment, double x, double y)
{
	int	ret;

	ret = 1;
	ret = translate_point(&segment->a, x, y);
	ret = translate_point(&segment->b, x, y);
	return (ret);
}
