/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 22:06:15 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 20:55:39 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int			create_tree_node(t_map *map, t_data data)
{
	if (!(map->tree.rootnode = malloc(sizeof(t_node) * 1)))
	{
		map->tree.rootnode->frontchild = NULL;
		map->tree.rootnode->backchild = NULL;
		map->tree.rootnode->set = NULL;
		return (ft_putstrreti_fd(MALLOC, 0,
		free_all_stuff(STDOUT_FILENO, map, &data, 1)));
	}
	map->tree.rootnode->frontchild = NULL;
	map->tree.rootnode->backchild = NULL;
	if (!parse_poly(map, data))
		return (free_all_stuff(0, map, &data, 1));
	return (1);
}

int			init_node(t_node *node, t_polygon *set)
{
	node->exist = 0;
	node->frontchild = NULL;
	node->backchild = NULL;
	if (!(node->frontchild = malloc(sizeof(t_node) * 1)))
		return (free_msg_once(0, MALLOC, NULL, NULL));
	node->frontchild->frontchild = NULL;
	node->frontchild->backchild = NULL;
	node->frontchild->set = NULL;
	if (!(node->backchild = malloc(sizeof(t_node) * 1)))
		return (free_msg_once(0, MALLOC, NULL, NULL));
	node->backchild->frontchild = NULL;
	node->backchild->backchild = NULL;
	node->backchild->set = NULL;
	if (is_convex_set(set, node))
		return (2);
	node->splitter = choose_div_polygon(set);
	if (!(node->frontchild->set = malloc_frontset_child(set, node->splitter)))
		return (free_msg_once(0, MALLOC, NULL, NULL));
	if (!(node->backchild->set = malloc_backset_child(set, node->splitter)))
		return (free_msg_once(0, MALLOC, NULL, NULL));
	return (1);
}

int			build_tree(t_node *node, t_polygon *set,
t_player player, t_data data)
{
	int			side;
	int			counter[3];
	int			ret;
	static int	i = 0;

	if (!(ret = init_node(node, set)) || ret == 2)
		return (ret);
	ft_memseti(counter, 0, 3);
	while (set[counter[0]].exist)
	{
		side = get_side(node->splitter, set[counter[0]]);
		if (side == FRONT || side == COINCIDING)
			node->frontchild->set[counter[1]++] = get_polygon(set[counter[0]]);
		else if (side == BACK)
			node->backchild->set[counter[2]++] = get_polygon(set[counter[0]]);
		else if (side == SPANNING)
			split_polygon(set[counter[0]], node->splitter, &node->
			frontchild->set[counter[1]++], &node->backchild->set[counter[2]++]);
		counter[0]++;
	}
	return (build_again(node, player, data, &i));
}

int			build_again(t_node *node, t_player player, t_data data, int *i)
{
	node->exist = 1;
	(*i)++;
	if (!build_tree(node->frontchild, node->frontchild->set, player, data))
		return (0);
	(*i)++;
	if (!build_tree(node->backchild, node->backchild->set, player, data))
		return (0);
	return (1);
}
