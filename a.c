/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:30:54 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/09 17:40:18 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main()
{
	t_segment	s;
	t_segment	s2;
	t_polygon	p;
	t_polygon	p2;

	s = get_segmenti(384, 129, 384, 255);
	s2 = get_segmenti(768, 193, 768, 255);
	p.segment = s;
	p2.segment = s2;
	p.normal = get_normal(s);
	p2.normal = get_normal(s2);
	printf("side = %d\n", get_side(p, p2));
}
