/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_poly.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 13:37:02 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 20:57:55 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_polygon			stop_fctn(t_polygon *p, char *msg)
{
	p->exist = 0;
	ft_putstr_fd(msg, STDOUT_FILENO);
	return (*p);
}

t_polygon			create_polytop(t_map *map, int *coor, t_data data)
{
	t_polygon	p;
	t_cub		**cub;
	int			x;
	int			y;

	x = coor[0];
	y = coor[1];
	cub = map->cub;
	p.segment = dup_segment(cub[y][x].stop);
	p.normal = get_normal(cub[y][x].stop);
	while ((cub[y][++x].exist && cub[y][x - 1].exist
		&& !cub[y - 1][x].exist && !cub[y - 1][x - 1].exist)
		&& x < map->nbxcharmax && y < map->nbymax)
		p.segment = join_segment(p.segment, cub[y][x].stop);
	p.len = get_length(p.segment);
	p.wall.color = 0xFF0000;
	if (!(p.wall.img = mlx_xpm_file_to_image(data.ptr, data.texnorth,
	&p.wall.imgwidth, &p.wall.imgheight)))
		return (stop_fctn(&p, "Error\nL'image ne s'est pas charge (top)\n"));
	p.angle = to_rad(0);
	p.exist = 1;
	return (p);
}

t_polygon			create_polybot(t_map *map, int *coor, t_data data)
{
	t_polygon	p;
	t_cub		**cub;
	int			x;
	int			y;

	x = coor[0];
	y = coor[1];
	cub = map->cub;
	p.segment = dup_segment(cub[y][x].sbot);
	p.normal = get_normal(cub[y][x].sbot);
	while ((cub[y][++x].exist && cub[y][x - 1].exist
		&& !cub[y + 1][x].exist && !cub[y + 1][x - 1].exist)
		&& x < map->nbxcharmax && y < map->nbymax)
		p.segment = join_segment(p.segment, cub[y][x].sbot);
	p.len = get_length(p.segment);
	p.wall.color = 0x00FF00;
	(void)data;
	if (!(p.wall.img = mlx_xpm_file_to_image(data.ptr, data.texsouth,
	&p.wall.imgwidth, &p.wall.imgheight)))
		return (stop_fctn(&p, "Error\nL'image ne s'est pas charge (bot)\n"));
	p.angle = to_rad(0);
	p.exist = 1;
	return (p);
}

t_polygon			create_polyright(t_map *map, int *coor, t_data data)
{
	t_polygon	p;
	t_cub		**cub;
	int			x;
	int			y;

	x = coor[0];
	y = coor[1];
	cub = map->cub;
	p.segment = dup_segment(cub[y][x].sright);
	p.normal = get_normal(cub[y][x].sright);
	while ((cub[++y][x].exist && cub[y - 1][x].exist
		&& !cub[y - 1][x + 1].exist && !cub[y][x + 1].exist)
		&& x < map->nbxcharmax && y < map->nbymax)
		p.segment = join_segment(p.segment, cub[y][x].sright);
	p.len = get_length(p.segment);
	if (!(p.wall.img = mlx_xpm_file_to_image(data.ptr, data.texeast,
	&p.wall.imgwidth, &p.wall.imgheight)))
		return (stop_fctn(&p, "Error\nL'image ne s'est pas charge (right)\n"));
	p.wall.color = 0x0000FF;
	p.angle = to_rad(90);
	p.exist = 1;
	return (p);
}

t_polygon			create_polyleft(t_map *map, int *coor, t_data data)
{
	t_polygon	p;
	t_cub		**cub;
	int			x;
	int			y;

	x = coor[0];
	y = coor[1];
	cub = map->cub;
	p.segment = dup_segment(cub[y][x].sleft);
	p.normal = get_normal(cub[y][x].sleft);
	while ((cub[++y][x].exist && cub[y - 1][x].exist
		&& !cub[y - 1][x - 1].exist && !cub[y][x - 1].exist)
		&& x < map->nbxcharmax && y < map->nbymax)
		p.segment = join_segment(p.segment, cub[y][x].sleft);
	p.len = get_length(p.segment);
	if (!(p.wall.img = mlx_xpm_file_to_image(data.ptr,
	data.texwest, &p.wall.imgwidth, &p.wall.imgheight)))
		return (stop_fctn(&p, "Error\nL'image ne s'est pas charge (left)\n"));
	p.wall.color = 0xFFFFFF;
	p.angle = to_rad(90);
	p.exist = 1;
	return (p);
}
