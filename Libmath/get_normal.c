/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:20:49 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/16 15:11:40 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_normal	*get_normal(t_segment s)
{
	t_normal	*n;

	if (!(n = malloc(sizeof(t_normal))))
		return (NULL);
	n->xlen = s.q->x - s.p->x;
	n->ylen = s.p->y - s.q->y;
	return (n);
}
