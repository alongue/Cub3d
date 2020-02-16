/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_segmenti.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:29:46 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/16 14:41:13 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_segment	*get_segmenti(int px, int py, int qx, int qy)
{
	t_segment	*s;

	if (!(s = malloc(sizeof(t_segment))))
		return (NULL);
	s.p = get_point(px, py);
	s.q = get_point(qx, qy);
	return (s);
}