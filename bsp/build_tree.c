/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 22:06:15 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/11 11:20:24 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

# define MINSCALE 2 //2 car on parle ici du scale minimum donc le minimum pour n - 1 c 2 donc lorsqu'il y a n = 3 polygons (le pire cas combine au cas minimum)



int		create_tree_node(t_map *map, t_player player, t_data data)
{
	if (!(map->tree.rootnode = malloc(sizeof(t_node) * 1)))
		return (ft_putstrreti_fd("Error\nCa veut pas malloc (map->tree.rootnode (build_tree.c))\n", 0, 0));
	return (parse_poly(map, player, data));
	/*while (map->tree.rootnode->set[++a].exist)
	if (map->tree.rootnode->set->segment.a.x == 0 && map->tree.rootnode->set->segment.a.y == 0 && map->tree.rootnode->set->segment.b.x == 0 && map->tree.rootnode->set->segment.b.y == 0)
	{
		//vscode printf("set[%d] = WOUAW\n", a);
		//vscode sleep(5);
	}*/
	////vscode printf("polysetlen(set de tree) = %d\n", polysetlen(map->tree.rootnode->set));
}

