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
	p.nbwall = 1;
	while ((cub[y][++x].exist && cub[y][x - 1].exist
		&& !cub[y - 1][x].exist && !cub[y - 1][x - 1].exist)
		&& x < map->nbxmax && y < map->nbymax)
	{
		p.segment = join_segment(p.segment, cub[y][x].stop);
		p.nbwall += 1;
	}
	p.len = get_length(p.segment);
	p.wall.color = 0xFF0000;
	if (!(p.wall.img = mlx_xpm_file_to_image(data.ptr, data.texnorth,
	&p.wall.imgwidth, &p.wall.imgheight)))
	{
		p.exist = 0;
		ft_putstr_fd("Error\nL'image ne s'est pas charge (top)\n", 0);
		return (p);
	}
	p.angle = 0 * (M_PI / 180);
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
	p.nbwall = 1;
	while ((cub[y][++x].exist && cub[y][x - 1].exist
		&& !cub[y + 1][x].exist && !cub[y + 1][x - 1].exist)
		&& x < map->nbxmax && y < map->nbymax)
	{
		p.segment = join_segment(p.segment, cub[y][x].sbot);
		p.nbwall += 1;
	}
	p.len = get_length(p.segment);
	p.wall.color = 0x00FF00;
	if (!(p.wall.img = mlx_xpm_file_to_image(data.ptr, data.texsouth, &p.wall.imgwidth, &p.wall.imgheight)))
	{
		p.exist = 0;
		ft_putstr_fd("Error\nL'image ne s'est pas charge (bot)\n", 0);
		return (p);
	}
	p.angle =  0 * (M_PI / 180);
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
	p.nbwall = 1;
	while ((cub[++y][x].exist && cub[y - 1][x].exist
		&& !cub[y - 1][x + 1].exist && !cub[y][x + 1].exist)
		&& x < map->nbxmax && y < map->nbymax)
	{
		p.segment = join_segment(p.segment, cub[y][x].sright);
		p.nbwall += 1;
	}
	p.len = get_length(p.segment);
	if (!(p.wall.img = mlx_xpm_file_to_image(data.ptr, data.texeast, &p.wall.imgwidth, &p.wall.imgheight)))
	{
		p.exist = 0;
		ft_putstr_fd("Error\nL'image ne s'est pas charge (right)\n", 0);
		return (p);
	}
	p.wall.color = 0x0000FF;
	p.angle =  90 * (M_PI / 180);
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
	p.nbwall = 1;
	while ((cub[++y][x].exist && cub[y - 1][x].exist
		&& !cub[y - 1][x - 1].exist && !cub[y][x - 1].exist)
		&& x < map->nbxmax && y < map->nbymax)
	{
		p.segment = join_segment(p.segment, cub[y][x].sleft);
		p.nbwall += 1;
	}
	p.len = get_length(p.segment);
	if (!(p.wall.img = mlx_xpm_file_to_image(data.ptr,
	data.texwest, &p.wall.imgwidth, &p.wall.imgheight)))
	{
		p.exist = 0;
		ft_putstr_fd("Error\nL'image ne s'est pas charge (left)\n", 0);
		return (p);
	}
	p.wall.color = 0xFFFFFF;
	p.angle =  90 * (M_PI / 180);
	p.exist = 1;
	return (p);
}
