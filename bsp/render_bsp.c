/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bsp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:02:24 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 21:01:35 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	reset_polygons(t_polygon *polygon, t_player player, t_data data)
{
	unsigned int	color;
	int				imgwidth;
	int				imgheight;
	void			*img;

	replace_poly(polygon, player);
	color = polygon->wall.color;
	imgwidth = polygon->wall.imgwidth;
	imgheight = polygon->wall.imgheight;
	img = polygon->wall.img;
	polygon->dodisplay = do_display_poly(polygon, data, player);
	polygon->wall = create_wall(*polygon, player, data);
	polygon->wall.img = img;
	polygon->wall.imgwidth = imgwidth;
	polygon->wall.imgheight = imgheight;
	polygon->wall.color = color;
}

void	display_polygons(t_data *data, t_node node, t_player player)
{
	int	counter;

	counter = -1;
	while (node.set[++counter].exist)
	{
		reset_polygons(&node.set[counter], player, *data);
		if (node.set[counter].dodisplay)
			display_wall(data, node.set[counter].wall, node.set[counter], player);
	}
}

void	renderbsp(t_data *data, t_node current, t_player player)
{
	int		result;

	if (current.isleaf)
	{
		display_polygons(data, current, player);
		return ;
	}
	result = classify_point(current.splitter, player.pos);
	if (result == FRONT || result == COINCIDING)
	{
		renderbsp(data, *current.frontchild, player);
		renderbsp(data, *current.backchild, player);
	}
	else if (result == BACK)
	{
		renderbsp(data, *current.backchild, player);
		renderbsp(data, *current.frontchild, player);
	}
}

void	renderobjects(t_data *data, t_player player, t_map map)
{
	int	i;

	i = -1;
	while (++i < map.nbobjects)
	{
		replace_obj(&map.objects[i], player);
		if (do_display_obj(&map.objects[i], *data, player))
			display_object(data, map.objects[i], player);
	}
}
