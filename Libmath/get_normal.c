/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:20:49 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/17 17:22:06 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_normal	get_normal(t_segment s)
{
	t_normal	n;

	n.xlen = s.b.x - s.a.x;
	n.ylen = s.a.y - s.b.y;
	return (n);
}
