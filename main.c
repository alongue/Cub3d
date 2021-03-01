/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:05:26 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/12 16:20:34 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		onexit(void **p)
{
	int			ret;
	t_data		*data;
	t_map		*map;
	t_player	*player;

	//vscode printf("ESCAPEouii\n");
	data = (t_data *)p[0];
	map = (t_map *)p[1];
	player = (t_player *)p[2];
	(void)player;
	//ret = free_elements(data, map);
	ret = 0;
	(void)data;
	(void)map;
	exit(ret);
	return (ret);
}

int		onkeypressed(int key, void **p)
{
	t_data		*data;
	t_map		*map;
	t_player	*player;

	//vscode printf("test\n");
	//vscode printf("keycode = %d\n", key);
	data = (t_data *)p[0];
	map = (t_map *)p[1];
	player = (t_player *)p[2];
	reset_data(data);
	////vscode printf("p[0] = %p\n", p[0]);
	//*a = 1;
	if (key == 65363)
		turn_right(player);
	else if (key == 65361)
		turn_left(player);
	if (key == 119)
		move_forward(player);
	//{
		/**wall = set_north_wall(wall->x - 5, wall->y - 5, wall->width + 10, wall->height + 10);
		display_wall(p[1], *wall);*/
		//grow_wall(data, wall);
	//}
	if (key == 115)
		move_backward(player);
	else if (key == 97)
		move_left(player);
	else if (key == 100)
		move_right(player);
	if (key == 65307)
	{
		//vscode printf("            			  ESCAPE\n");
		//vscode printf("data->window = %p\n", &data->window);
		onexit(p);
	}
	////vscode printf("keycode = %d\n", i);
	renderbsp(data, *map->tree.rootnode, *player);
	//vscode printf("map->tree.rootnode->splitter.wall.color = %x\n", map->tree.rootnode->splitter.wall.color);
	renderobjects(data, *player, *map);
	mlx_put_image_to_window(data->ptr, data->window, data->img, 0, 0);	// max(wall.leftcl.a.x, 0), max(wall.leftcl.a.y, 0));
	return (0);
}

int		main(int ac, char **av)
{
	t_data		data;
	t_player	player;
	//t_map		*map;
	t_map		map;
	void		*param[3];

	if (create_data(&data, av, ac) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	map = create_map(&data, &player);
	if (!map.exist)
		return (EXIT_FAILURE);
	reset_data(&data);
	if (!create_tree_node(&map, data))
		return (4);
	build_tree(map.tree.rootnode, map.tree.rootnode->set, player, data);
	////vscode printf("map.tree.rootnode->splitter.wall.color (main) = %x\n", map.tree.rootnode->splitter.wall.color);
	//vscode printf("map.tree.rootnode.exist : %d\n", map.tree.rootnode->exist);

	//ft_memseti(data.coldone, 0, data.win_width);
	//wall = set_north_wall(0, 0, 100, 100);
	//set_dim_north_wall(&wall, 100, 100);
	//coor[0] = ft_memseti(coor[0], 50, 2);
	//wall.color = 0xffffff;
	////vscode printf("wall = %p\n", wall);
	//display_ceilfloor(data);
	
	renderbsp(&data, *map.tree.rootnode, player);
	//vscode printf("After rendering bsp\n");
	renderobjects(&data, player, map);
	if (data.tosave)
		bitmap(&data, &map);
	mlx_put_image_to_window(data.ptr, data.window, data.img, 0, 0);	// max(wall.leftcl.a.x, 0), max(wall.leftcl.a.y, 0)); // y a des problemes de malloc a l'interieur de mlx_put_image_to_window()
	//vscode printf("salut c'est moi\n");
	param[0] = (void *)&data;
	//vscode printf("param[0]\n");
	param[1] = (void *)&map;
	//vscode printf("param[1]\n");
	param[2] = (void *)&player;
	//vscode printf("param[2]\n");
	mlx_hook(data.window, 2, (1L << 0), onkeypressed, param); //2 -> keypress, 4 -> mousepress, 6 -> mousemotion
	mlx_hook(data.window, 33, (1L << 17), onexit, param);
//	renderbsp(&data, *map.tree.rootnode, player);
	mlx_loop(data.ptr);
	return (EXIT_SUCCESS);
}
