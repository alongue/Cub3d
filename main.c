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

int		exit_hook(void **p)
{
	int			ret;
	t_data		*data;
	t_map		*map;
	t_player	*player;

	data = (t_data *)p[0];
	map = (t_map *)p[1];
	player = (t_player *)p[2];
	printf("ESCAPEouii\n");
	ret = free_elements(*data, map->tree, *map);
	exit(ret);
	return (ret);
}

int		funt(int i, void **p)
{
	t_data		*data;
	t_map		*map;
	t_player	*player;

	printf("test\n");
	data = (t_data *)p[0];
	map = (t_map *)p[1];
	player = (t_player *)p[2];
	reset_data(data);
	//printf("p[0] = %p\n", p[0]);
	//*a = 1;
	if (i == 124)
		turn_right(player);
	if (i == 123)
		turn_left(player);
	if (i == 13)
		move_forward(player);
	//{
		/**wall = set_north_wall(wall->x - 5, wall->y - 5, wall->width + 10, wall->height + 10);
		display_wall(p[1], *wall);*/
		//grow_wall(data, wall);
	//}
	if (i == 1)
		move_backward(player);
	if (i == 0)
		move_left(player);
	if (i == 2)
		move_right(player);
	if (i == 53)
	{
		printf("            			  ESCAPE\n");
		printf("data->window = %p\n", &data->window);
		mlx_hook(data->window, 17, 0, exit_hook, p);
	}
	//printf("keycode = %d\n", i);
	renderbsp(data, *map->tree.rootnode, *player);
	printf("map->tree.rootnode->splitter.wall.color = %x\n", map->tree.rootnode->splitter.wall.color);
	renderobjects(data, *player, *map);
	mlx_put_image_to_window(data->ptr, data->window, data->img, 0, 0);	// max(wall.leftcl.a.x, 0), max(wall.leftcl.a.y, 0));
	return (0);
}

int				display_wall(t_data *data, t_wall wall, t_polygon polygon, t_player player)
{
	int		i;
	int		ptraddr[2];
	double	tanindex;
//	double	cumul;
//	double	anglewallpl;
	int		index;
	int		rest;
	int		cumul;
	double	incr[2];

	//sleep(5);
//	printf("--- JE SUIS DANS LE DISPL WALL ---\n");
	initbe4display(&wall, &i, data);
	ft_memseti(ptraddr, 0, 2);
	ft_memseti(incr, 0, 2);
	cumul = 0;
	rest = 0;
	//printf("wall->leftcl.a.x = %f\t\tet\t\twall->rightcl.a.x = %f\n", wall.leftcl.a.x, wall.rightcl.a.x);
	while (++i <= (int)round(wall.rightcl.a.x))
	{
		//printf("i = %d\n", i);
		if (can_draw(wall, data, i))
		{
			wall.topcl = fmax(wall.top, 0.);
			wall.botcl = fmin(wall.bot, data->win_height);
			tanindex = -polygon.newangle - to_rad(90) + player.angleray[i];
			//index = (int)((polygon.pdist * tan(tanindex) + polygon.btobp) * (wall.imgwidth / data->cubside)) - (wall.imgwidth * cumul) - rest;
			index = (int)((polygon.pdist * tan(tanindex) + polygon.btobp) * ((wall.imgwidth) / data->cubside)) % (wall.imgwidth);
			//printf("index = %d\n", index);
			/*if (index > (cumul + 1) * wall.imgwidth)
			{
				rest = index % (wall.imgwidth * (cumul + 1));
				printf("rest = %d\n", rest);
				//sleep(5);
				cumul++;
			}*/
			//printf("wall.imgwidth / data->cubside = %i\n", wall.imgwidth / data->cubside);
			//printf("index = %d\n", index);
			index = (index < 0) ? 0 : index;
			incr[0] = (wall.imgheight - 1) / (wall.bot - wall.top);
			incr[1] = (wall.topcl - wall.top) * incr[0];
			incr[1] = (incr[1] < 0) ? 0 : incr[1];
			ptraddr[0] = (int)(round(wall.topcl) * data->win_width + i);
			ptraddr[1] = (int)(round(wall.botcl) * data->win_width + i);
//			printf("topcl = %f\tet\tbotcl = %f\n", wall.topcl, wall.botcl);
//			printf("(avant la boucle) ptraddr[0] = %d\tet\tptraddr[1] = %d\n", ptraddr[0], ptraddr[1]);
			while (ptraddr[0] < ptraddr[1])
			{
				//get(index, incr[1]);
//				printf("(pdt la boucle) incr[1] = %f\tet\tindex = %d\n", incr[1], index);
				//printf("wall.imgwidth = %d\tet\twall.imgheight = %d\n", wall.imgwidth, wall.imgheight);
				//printf("avant\n");
				wall.img_data[ptraddr[0]] = wall.data_file[(int)(round(incr[1]) * wall.imgwidth + index)];
				//wall.img_data[ptraddr[0]] = (unsigned int)0xfff;
				//if (ptraddr[0] > ((data->win_width * data->win_height) - 1)) // 2 073 599 pour 1920 et 1080
				//	printf("ptraddr[0] = %d qui est superieur win * height (- 1) (= %d)\n", ptraddr[0], (data->win_width * data->win_height) - 1);
				//printf("pdist = %f\n", polygon.pdist);
				//printf("apres\n");
				incr[1] += incr[0];
				ptraddr[0] += data->win_width;
			}
			//printf("(apres la boucle) ptraddr[0] = %d\tet\tptraddr[1] = %d\n", ptraddr[0], ptraddr[1]);
			data->coldone[i] = 1;
		}
		wall.top += wall.deltatop;
		wall.bot += wall.deltabot;
	}
	//printf("Je suis sorti\n");
	return (EXIT_SUCCESS);
}

int		main(int ac, char **av)
{
	t_data		data;
	t_player	player;
	//t_map		*map;
	t_map		map;
	void		*param[3];

	//map = malloc(sizeof(t_map) * 1);
	if (create_data(&data, av) == EXIT_FAILURE)
		return (ft_putstrreti_fd("Error\nLa window n'a pas pu etre cree\n", 0, EXIT_FAILURE));
	/*if ((data.window = mlx_new_window(data.ptr, WIDTH, HEIGHT, "Hello World")) == NULL)
		return (EXIT_FAILURE);*/
	printf("data.window (main) = %p\n", &data.window);

	//TO REMOVE
	data.img = mlx_new_image(data.ptr, data.win_width, data.win_height);
	data.img_data = (int *)mlx_get_data_addr(data.img, &data.bpp, &data.size_line, &data.endian);

	map = create_map(&data, &player);
	//int a = 3000;
	//printf("Sieste de %dsec\n", a / 1000);
	//sleep(a);
	reset_data(&data);
	if (!map.exist)
		return (3);
	if (!create_tree_node(&map, player, data))
		return (4);
	build_tree(map.tree.rootnode, map.tree.rootnode->set, player, data);
	//printf("map.tree.rootnode->splitter.wall.color (main) = %x\n", map.tree.rootnode->splitter.wall.color);
	printf("map.tree.rootnode.exist : %d\n", map.tree.rootnode->exist);

	//ft_memseti(data.coldone, 0, data.win_width);
	//wall = set_north_wall(0, 0, 100, 100);
	//set_dim_north_wall(&wall, 100, 100);
	//coor[0] = ft_memseti(coor[0], 50, 2);
	//wall.color = 0xffffff;
	//printf("wall = %p\n", wall);
	//display_ceilfloor(data);
	
	renderbsp(&data, *map.tree.rootnode, player);
	printf("After rendering bsp\n");
	renderobjects(&data, player, map);
	mlx_put_image_to_window(data.ptr, data.window, data.img, 0, 0);	// max(wall.leftcl.a.x, 0), max(wall.leftcl.a.y, 0)); // y a des problemes de malloc a l'interieur de mlx_put_image_to_window()
	
	printf("salut c'est moi\n");
	param[0] = (void *)&data;
	printf("param[0]\n");
	param[1] = (void *)&map;
	printf("param[1]\n");
	param[2] = (void *)&player;
	printf("param[2]\n");
	(void)ac;
	mlx_hook(data.window, 2, 0, funt, param); //2 -> keypress, 4 -> mousepress, 6 -> mousemotion
//	renderbsp(&data, *map.tree.rootnode, player);
	mlx_loop(data.ptr);
	return (EXIT_SUCCESS);
}
