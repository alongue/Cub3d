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

void	display_polygons(t_data *data, t_node node)
{
	int	counter;

	//counter = polysetlen(node.set);
	counter = -1;
	//printf("node.set[counter].exist = %d\n", node.set[counter + 1].exist);
	while (node.set[++counter].exist && node.set[counter].dodisplay)
	{
		printf("node.set[counter].wall.left.a.x = %f\ta.y = %f\nb.x = %f\tb.y = %f\n", node.set[counter].wall.left.a.x, node.set[counter].wall.left.a.y, node.set[counter].wall.left.b.x, node.set[counter].wall.left.b.y);
		display_wall(data, node.set[counter].wall);
	}
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
		display_polygons(data, current);
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
