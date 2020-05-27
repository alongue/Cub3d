/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_poly.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 13:37:02 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/11 11:23:24 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_polygon			create_polytop(t_map map, int *coor, t_data data, t_player player)
{
	t_polygon	p;
	t_cub		**cub;
	int			x;
	int			y;

	x = coor[0];
	y = coor[1];
	cub = map.cub;
	p.segment = dup_segment(cub[y][x].stop);
	p.normal = get_normal(cub[y][x].stop);
	p.nbwall = 1;
	while ((cub[y][++x].exist && cub[y][x - 1].exist
		&& !cub[y - 1][x].exist && !cub[y - 1][x - 1].exist) && x < get_nbxmax(map.nbcuby) && y < get_nbymax(map.nbcuby))
	{
		//printf("p.segment.exist (top) = %d\n", p.segment.exist);
		p.segment = join_segment(p.segment, cub[y][x].stop);
		p.nbwall += 1;
		{
			printf("TOP\n");
			printf("x -> %d\tet\ty -> %d\n", x, y);
			printf("p.segment.a.x = %f || p.segment.a.y = %f || p.segment.b.x = %f || top.b.y = %f\n", cub[y][x].stop.a.x, cub[y][x].stop.a.y, cub[y][x].stop.b.x, cub[y][x].stop.b.y);
			//sleep(10);
		}
	}
	if (p.segment.a.x == 0 && p.segment.a.y == 0 && p.segment.b.x == 0 && p.segment.b.y == 0)
		sleep(5);
	p.len = get_length(p.segment);
	//replace_poly(&p, player);
	//p.dodisplay = do_display_poly(&p, data);
	//p.wall = create_wall(p, player, data);
	(void)player;
	//p.wall.color = 0xFF0000;
	if (!(p.wall.img = mlx_xpm_file_to_image(data.ptr, data.texnorth, &p.wall.imgwidth, &p.wall.imgheight))) //soigner tout et mettre phrase
	{
		p.exist = false;
		ft_putstr_fd("Error\nL'image ne s'est pas charge (top)\n", 0);
		sleep(1);
		return (p);
	}
	//p.wall.imgwidth = (p.wall.imgwidth > 64) ? 64 : p.wall.imgwidth;
	//p.wall.imgheight = (p.wall.imgheight > 64) ? 64 : p.wall.imgheight;
	p.angle = 0 * (M_PI / 180);
	//printf("p.segment.exist (top) = %d\n", p.segment.exist);
	p.exist = true;
	return (p);
}

t_polygon			create_polybot(t_map map, int *coor, t_data data, t_player player)
{
	t_polygon	p;
	t_cub		**cub;
	int			x;
	int			y;

	x = coor[0];
	y = coor[1];
	cub = map.cub;
	p.segment = dup_segment(cub[y][x].sbot);
	p.normal = get_normal(cub[y][x].sbot);
	p.nbwall = 1;
	while ((cub[y][++x].exist && cub[y][x - 1].exist
		&& !cub[y + 1][x].exist && !cub[y + 1][x - 1].exist) && x < get_nbxmax(map.nbcuby) && y < get_nbymax(map.nbcuby))
	{
		//printf("p.segment.exist (bot boucle) = %d\n", p.segment.exist);
		p.segment = join_segment(p.segment, cub[y][x].sbot);
		p.nbwall += 1;
		//if (p.segment.a.x > 3000 || p.segment.a.y > 3000 || p.segment.b.x > 3000 || p.segment.b.y > 3000)
		{
			printf("BOT\n");
			printf("x -> %d\tet\ty -> %d\n", x, y);
			printf("p.segment.a.x = %f || p.segment.a.y = %f || p.segment.b.x = %f || p.segment.b.y = %f\n", cub[y][x].sright.a.x, cub[y][x].sright.a.y, cub[y][x].sright.b.x, cub[y][x].sright.b.y);
//			sleep(10);
		}
	}
	if (p.segment.a.x == 0 && p.segment.a.y == 0 && p.segment.b.x == 0 && p.segment.b.y == 0)
		sleep(5);
	p.len = get_length(p.segment);
	p.wall.color = 0x00FF00;
	if (!(p.wall.img = mlx_xpm_file_to_image(data.ptr, data.texsouth, &p.wall.imgwidth, &p.wall.imgheight))) //soigner tout et mettre phrase
	{
		p.exist = false;
		ft_putstr_fd("Error\nL'image ne s'est pas charge (bot)\n", 0);
		return (p);
	}
	(void)player;
	p.angle =  0 * (M_PI / 180);
	//printf("p.segment.exist (bot) = %d\n", p.segment.exist);
	p.exist = true;
	return (p);
}

t_polygon			create_polyright(t_map map, int *coor, t_data data, t_player player)
{
	t_polygon	p;
	t_cub		**cub;
	int			x;
	int			y;

	x = coor[0];
	y = coor[1];
	cub = map.cub;
	p.segment = dup_segment(cub[y][x].sright);
	p.normal = get_normal(cub[y][x].sright);
	p.nbwall = 1;
	while ((cub[++y][x].exist && cub[y - 1][x].exist
		&& !cub[y - 1][x + 1].exist && !cub[y][x + 1].exist) && x < get_nbxmax(map.nbcuby) && y < get_nbymax(map.nbcuby))
	{
		//printf("p.segment.exist (right boucle) = %d\n", p.segment.exist);
		p.segment = join_segment(p.segment, cub[y][x].sright);
		p.nbwall += 1;
		//if (p.segment.a.x  > 3000|| p.segment.a.y  > 3000|| p.segment.b.x  > 3000|| p.segment.b.y > 3000)
		{
			printf("RIGHT\n");
			printf("x -> %d\tet\ty -> %d\n", x, y);
			printf("p.segment.a.x = %f || p.segment.a.y = %f || p.segment.b.x = %f || right.b.y = %f\n", cub[y][x].sright.a.x, cub[y][x].sright.a.y, cub[y][x].sright.b.x, cub[y][x].sright.b.y);
//			sleep(10);
		}
	}
	if (p.segment.a.x == 0 && p.segment.a.y == 0 && p.segment.b.x == 0 && p.segment.b.y == 0)
		sleep(5);
	p.len = get_length(p.segment);
	if (!(p.wall.img = mlx_xpm_file_to_image(data.ptr, data.texeast, &p.wall.imgwidth, &p.wall.imgheight))) //soigner tout et mettre phrase
	{
		p.exist = false;
		ft_putstr_fd("Error\nL'image ne s'est pas charge (right)\n", 0);
		return (p);
	}
	(void)player;
	//printf("p.newsegment.a.y = %d\n", p.newsegment.a.y);
	p.wall.color = 0x0000FF;
	p.angle =  90 * (M_PI / 180);
	//printf("p.segment.exist (right) = %d\n", p.segment.exist);
	p.exist = true;
	return (p);
}

t_polygon			create_polyleft(t_map map, int *coor, t_data data, t_player player)
{
	t_polygon	p;
	t_cub		**cub;
	int			x;
	int			y;

	x = coor[0];
	y = coor[1];
	cub = map.cub;
	p.segment = dup_segment(cub[y][x].sleft);
	p.normal = get_normal(cub[y][x].sleft);
	p.nbwall = 1;
	while ((cub[++y][x].exist && cub[y - 1][x].exist
		&& !cub[y - 1][x - 1].exist && !cub[y][x - 1].exist) && x < get_nbxmax(map.nbcuby) && y < get_nbymax(map.nbcuby))
	{
		//printf("p.segment.exist (left boucle) = %d\n", p.segment.exist);
		p.segment = join_segment(p.segment, cub[y][x].sleft);
		p.nbwall += 1;
		//if (p.segment.a.x  > 3000|| p.segment.a.y  > 3000|| p.segment.b.x  > 3000|| p.segment.b.y > 3000)
		{
			printf("LEFT\n");
			printf("x -> %d\tet\ty -> %d\n", x, y);
			printf("p.segment.a.x = %f || p.segment.a.y = %f || p.segment.b.x = %f || left.b.y = %f\n", cub[y][x].sleft.a.x, cub[y][x].sleft.a.y, cub[y][x].sleft.b.x, cub[y][x].sleft.b.y);
//			sleep(10);
		}
	}
	if (p.segment.a.x == 0 && p.segment.a.y == 0 && p.segment.b.x == 0 && p.segment.b.y == 0)
		sleep(5);
	p.len = get_length(p.segment);
	if (!(p.wall.img = mlx_xpm_file_to_image(data.ptr, data.texwest, &p.wall.imgwidth, &p.wall.imgheight))) //soigner tout et mettre phrase
	{
		p.exist = false;
		ft_putstr_fd("Error\nL'image ne s'est pas charge (left)\n", 0);
		return (p);
	}
	(void)player;
	p.wall.color = 0xFFFFFF;
	p.angle =  90 * (M_PI / 180);
	//printf("p.segment.exist (left) = %d\n", p.segment.exist);
	p.exist = true;
	printf("p.segment.a.x = %f (left)\n", p.segment.a.x);
	return (p);
}
