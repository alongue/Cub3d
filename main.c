/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:05:26 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 19:56:27 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		onexit(void **p)
{
	t_data		*data;
	t_map		*map;
	t_player	*player;

	data = (t_data *)p[0];
	map = (t_map *)p[1];
	player = (t_player *)p[2];
	exit(free_all_stuff(free_player(0, player, NULL),
	map, data, 1));
}

int		onkeypressed(int key, void **p)
{
	t_data		*data;
	t_map		*map;
	t_player	*player;

	map = (t_map *)p[1];
	player = (t_player *)p[2];
	reset_data((data = (t_data *)p[0]));
	if (key == 65363)
		turn_right(player);
	else if (key == 65361)
		turn_left(player);
	if (key == 119)
		move_forward(player);
	else if (key == 115)
		move_backward(player);
	else if (key == 97)
		move_left(player);
	else if (key == 100)
		move_right(player);
	if (key == 65307)
		onexit(p);
	renderbsp(data, *map->tree.rootnode, *player);
	renderobjects(data, *player, *map);
	mlx_put_image_to_window(data->ptr, data->window, data->img, 0, 0);
	return (0);
}

void	**get_params_main(t_data *data, t_player *player, t_map *map)
{
	void	**params;

	if (!(params = malloc(sizeof(void *) * 3)))
	{
		free_all_stuff(0, map, data, 1);
		free_player(0, player, MALLOC);
		return (NULL);
	}
	params[0] = (void *)data;
	params[1] = (void *)player;
	params[2] = (void *)map;
	return (params);
}

int		main(int ac, char **av)
{
	t_data		data;
	t_player	player;
	t_map		map;
	void		*params[3];

	map = initmap(&data, &player, av, ac);
	if (!map.exist)
		return (EXIT_FAILURE);
	if (!create_tree_node(&map, data))
		return (free_player(EXIT_FAILURE, &player, NULL));
	if (!build_tree(map.tree.rootnode, map.tree.rootnode->set, player, data)
	&& free_player(1, &player, NULL))
		return (free_all_stuff(EXIT_FAILURE, &map, &data, 1));
	renderbsp(&data, *map.tree.rootnode, player);
	renderobjects(&data, player, map);
	if (data.tosave)
		return (free_all_stuff(bitmap(&data, &player), &map, &data, 1));
	mlx_put_image_to_window(data.ptr, data.window, data.img, 0, 0);
	params[0] = (void *)&data;
	params[1] = (void *)&map;
	params[2] = (void *)&player;
	mlx_hook(data.window, 2, (1L << 0), onkeypressed, params);
	mlx_hook(data.window, 33, (1L << 17), onexit, params);
	mlx_loop(data.ptr);
	return (EXIT_SUCCESS);
}
