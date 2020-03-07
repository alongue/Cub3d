/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_poly.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 13:37:02 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/06 19:49:15 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_polygon			create_polytop(t_map map, int x, int y, t_player player)
{
	t_polygon	p;
	t_cub		**cub;

	cub = map.cub;
	p.segment = dup_segment(cub[y][x].stop);
	p.normal = get_normal(cub[y][x].stop);
	p.nbwall = 1;
	while (cub[y][++x].exist && cub[y][x - 1].exist
		&& !cub[y - 1][x].exist && !cub[y - 1][x - 1].exist)
	{
		//printf("p.segment.exist (top) = %d\n", p.segment.exist);
		p.segment = join_segment(p.segment, cub[y][x].stop);
		p.nbwall += 1;
	}
	replace_poly(&p, player);
	p.dodisplay = do_display_poly(&p);
	p.wall = create_wall(p, player, map.cub[0][0]);
	//printf("p.segment.exist (top) = %d\n", p.segment.exist);
	p.exist = true;
	return (p);
}

t_polygon			create_polybot(t_map map, int x, int y, t_player player)
{
	t_polygon	p;
	t_cub		**cub;

	cub = map.cub;
	p.segment = dup_segment(cub[y][x].sbot);
	p.normal = get_normal(cub[y][x].sbot);
	p.nbwall = 1;
	while (cub[y][++x].exist && cub[y][x - 1].exist
		&& !cub[y + 1][x].exist && !cub[y + 1][x - 1].exist)
	{
		//printf("p.segment.exist (bot boucle) = %d\n", p.segment.exist);
		p.segment = join_segment(p.segment, cub[y][x].sbot);
		p.nbwall += 1;
	}
	replace_poly(&p, player);
	p.dodisplay = do_display_poly(&p);
	p.wall = create_wall(p, player, map.cub[0][0]);
	//printf("p.segment.exist (bot) = %d\n", p.segment.exist);
	p.exist = true;
	return (p);
}

t_polygon			create_polyright(t_map map, int x, int y, t_player player)
{
	t_polygon	p;
	t_cub		**cub;

	cub = map.cub;
	p.segment = dup_segment(cub[y][x].sright);
	p.normal = get_normal(cub[y][x].sright);
	p.nbwall = 1;
	while (cub[++y][x].exist && cub[y - 1][x].exist
		&& !cub[y - 1][x + 1].exist && !cub[y][x + 1].exist)
	{
		//printf("p.segment.exist (right boucle) = %d\n", p.segment.exist);
		p.segment = join_segment(p.segment, cub[y][x].sright);
		p.nbwall += 1;
	}
	replace_poly(&p, player);
	//printf("p.newsegment.a.y = %d\n", p.newsegment.a.y);
	p.dodisplay = do_display_poly(&p);
	p.wall = create_wall(p, player, map.cub[0][0]);
	//printf("p.segment.exist (right) = %d\n", p.segment.exist);
	p.exist = true;
	return (p);
}

t_polygon			create_polyleft(t_map map, int x, int y, t_player player)
{
	t_polygon	p;
	t_cub		**cub;

	cub = map.cub;
	p.segment = dup_segment(cub[y][x].sleft);
	p.normal = get_normal(cub[y][x].sleft);
	p.nbwall = 1;
	while (cub[++y][x].exist && cub[y - 1][x].exist
		&& !cub[y - 1][x - 1].exist && !cub[y][x - 1].exist)
	{
		//printf("p.segment.exist (left boucle) = %d\n", p.segment.exist);
		p.segment = join_segment(p.segment, cub[y][x].sleft);
		p.nbwall += 1;
	}
	replace_poly(&p, player);
	p.dodisplay = do_display_poly(&p);
	p.wall = create_wall(p, player, map.cub[0][0]);
	//printf("p.segment.exist (left) = %d\n", p.segment.exist);
	p.exist = true;
	return (p);
}
