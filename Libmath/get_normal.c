/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:20:49 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/07 19:36:25 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_normal	get_normal(t_segment s)
{
	t_normal	n;

	n.xlen = s.b.y - s.a.y;
	n.ylen = s.a.x - s.b.x;
	return (n);
}
