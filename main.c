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
	t_map		map;
	void		*param[3];

	map = initmap(&data, &player, av, ac);
	if (!map.exist)
		return (EXIT_FAILURE);
	if (!create_tree_node(&map, data))
		return (EXIT_FAILURE);
	build_tree(map.tree.rootnode, map.tree.rootnode->set, player, data);
	renderbsp(&data, *map.tree.rootnode, player);
	renderobjects(&data, player, map);
	if (data.tosave)
		bitmap(&data, &map);
	mlx_put_image_to_window(data.ptr, data.window, data.img, 0, 0);
	param[0] = (void *)&data;
	param[1] = (void *)&map;
	param[2] = (void *)&player;
	mlx_hook(data.window, 2, (1L << 0), onkeypressed, param);
	mlx_hook(data.window, 33, (1L << 17), onexit, param);
	mlx_loop(data.ptr);
	return (EXIT_SUCCESS);
}