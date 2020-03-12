/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:05:26 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/12 13:13:51 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdio.h>

/*int		escape(t_data *data)
{
	exit(0);
	return (0);
}*/

int		funt(int i, void **p)
{
	t_data	*data;

	data = (t_data *)p[0];
	//printf("p[0] = %p\n", p[0]);
	//*a = 1;
	if (i == 13)
		;
	//{
		/**wall = set_north_wall(wall->x - 5, wall->y - 5, wall->width + 10, wall->height + 10);
		display_wall(p[1], *wall);*/
		//grow_wall(data, wall);
	//}
	if (i == 1)
		;
	//if (i == 53)
	//	mlx_hook(data->mlx_win, 17, 0, escape, data);
	printf("i = %d\n", i);
	return (0);
}

int		main(int ac, char **av)
{
	t_data		data;
	t_player	player;
	t_map		*map;
	//t_map		map;

	(void)ac;
	map = malloc(sizeof(t_map) * 1);
	if ((data.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	data.win_width = WIDTH;
	data.win_height = HEIGHT;
	if (create_data(&data, av) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	/*if ((data.mlx_win = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "Hello World")) == NULL)
		return (EXIT_FAILURE);*/
	*map = get_coor(data, &player, 64);
	if (!map->exist)
		return (3);
	create_tree_node(map, player);
	build_tree(map->tree.rootnode, map->tree.rootnode->set, player);
	printf("map.tree.rootnode.exist : %d\n", map->tree.rootnode->exist);
	renderbsp(&data, *map->tree.rootnode, player);
	//wall = set_north_wall(0, 0, 100, 100);
	//set_dim_north_wall(&wall, 100, 100);
	//coor[0] = ft_memseti(coor[0], 50, 2);
	//wall.color = 0xffffff;
	//printf("wall = %p\n", wall);
	//param[0] = (void *)&data;
	//mlx_hook(data.mlx_win, 2, 0, funt, param); //2 -> keypress, 4 -> mousepress, 6 -> mousemotion
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
