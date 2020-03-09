/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_poly.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 13:37:02 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/08 18:18:34 by alongcha         ###   ########.fr       */
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
		if (p.segment.a.x  > 3000|| p.segment.a.y > 3000 || p.segment.b.x > 3000 || p.segment.b.y > 3000)
		{
			printf("x -> %d\tet\ty -> %d\n", x, y);
			printf("p.segment.a.x = %d || p.segment.a.y = %d || p.segment.b.x = %d || top.b.y = %d\n", cub[y][x].stop.a.x, cub[y][x].stop.a.y, cub[y][x].stop.b.x, cub[y][x].stop.b.y);
			sleep(10);
		}
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
		if (p.segment.a.x > 3000 || p.segment.a.y > 3000 || p.segment.b.x > 3000 || p.segment.b.y > 3000)
		{
			printf("x -> %d\tet\ty -> %d\n", x, y);
			printf("p.segment.a.x = %d || p.segment.a.y = %d || p.segment.b.x = %d || bot.b.y = %d\n", cub[y][x].sright.a.x, cub[y][x].sright.a.y, cub[y][x].sright.b.x, cub[y][x].sright.b.y);
			sleep(10);
		}
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
		if (p.segment.a.x  > 3000|| p.segment.a.y  > 3000|| p.segment.b.x  > 3000|| p.segment.b.y > 3000)
		{
			printf("x -> %d\tet\ty -> %d\n", x, y);
			printf("p.segment.a.x = %d || p.segment.a.y = %d || p.segment.b.x = %d || right.b.y = %d\n", cub[y][x].sright.a.x, cub[y][x].sright.a.y, cub[y][x].sright.b.x, cub[y][x].sright.b.y);
			sleep(10);
		}
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
		if (p.segment.a.x  > 3000|| p.segment.a.y  > 3000|| p.segment.b.x  > 3000|| p.segment.b.y > 3000)
		{
			printf("x -> %d\tet\ty -> %d\n", x, y);
			printf("p.segment.a.x = %d || p.segment.a.y = %d || p.segment.b.x = %d || left.b.y = %d\n", cub[y][x].sleft.a.x, cub[y][x].sleft.a.y, cub[y][x].sleft.b.x, cub[y][x].sleft.b.y);
			sleep(10);
		}
	}
	replace_poly(&p, player);
	p.dodisplay = do_display_poly(&p);
	p.wall = create_wall(p, player, map.cub[0][0]);
	//printf("p.segment.exist (left) = %d\n", p.segment.exist);
	p.exist = true;
	return (p);
}
