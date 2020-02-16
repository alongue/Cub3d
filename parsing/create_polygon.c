/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_polygon.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 13:37:02 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/16 15:10:54 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_polygon			create_polytop(t_cub *main, t_cub *top, t_cub *topleft, t_cub *left)
{
	t_polygon	p;

	if ((main && !left && !topleft && !top) ||
		(main && left && topleft && !top))
	{
		p.segment = dup_segment(main.stop);
		p.normal = get_normal(main.stop);
	}
	return (p);
		
}

t_polygon			create_polybot(t_map map)
{

}

t_polygon			create_polyright(t_map map)
{

}

t_polygon			create_polyleft(t_map map)
{

}
