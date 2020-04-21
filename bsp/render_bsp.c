/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bsp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:02:24 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/12 13:13:33 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	reset_polygons(t_polygon *polygon, t_player player, t_data data)
{
	replace_poly(polygon, player);
	polygon->dodisplay = do_display_poly(polygon, data);
	polygon->wall = create_wall(*polygon, player, data);
	polygon->wall.color = 0xff00ff;
}

void	display_polygons(t_data *data, t_node node, t_player player)
{
	int	counter;

	//printf("!!! DISPL POLY !!!\n");
	//sleep(3);
	//counter = polysetlen(node.set);
	counter = -1;
	//printf("node.set[counter].exist = %d\n", node.set[counter + 1].exist);
	//(void)player;
	while (node.set[++counter].exist)
	{
		reset_polygons(&node.set[counter], player, *data);
//		printf("node.set[counter].wall.leftcl.a.x = %f\ta.y = %f\nrightcl.b.x = %f\tb.y = %f\n", node.set[counter].wall.leftcl.a.x, node.set[counter].wall.leftcl.a.y, node.set[counter].wall.rightcl.b.x, node.set[counter].wall.rightcl.b.y);
		printf("node.set[counter].dodisplay = %d\n", node.set[counter].dodisplay);
		if (node.set[counter].dodisplay)
			display_wall(data, node.set[counter].wall);
	}
//	printf("\nLes poly du node sont passes\n");
	//sleep(4);
}

/*void	display_polygons(t_data *data, t_node node)
{
	int	side;
	int	i;
	int	j;

	i = -1;
	j = -1;
	side = 0;
	while (set[++i].exist)
	{
		j = -1;
		while (set[++j].exist)
			if (i != j && (side = get_side(set[i], set[j])) != FRONT)
				display_wall(data, node.set[counter].wall);
	}
}*/

void	renderbsp(t_data *data, t_node current, t_player player)
{
	int		result;

	printf("HOLA !!\n");
	//if (!current.backchild->exist && !current.frontchild->exist)
	if (current.isleaf)
	{
		display_polygons(data, current, player);
		return ;
	}
	result = classify_point(current.splitter, player.pos);
	if (result == FRONT || result == COINCIDING)
	{
		//if (current.backchild->exist)
			renderbsp(data, *current.backchild, player);
		//if (current.frontchild->exist)
			renderbsp(data, *current.frontchild, player);
	}
	else if (result == BACK)
	{
		//if (current.frontchild->exist)
			renderbsp(data, *current.frontchild, player);
		//if (current.backchild->exist)
			renderbsp(data, *current.backchild, player);
	}
}
