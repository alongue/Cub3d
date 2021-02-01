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
	//vscode printf("ESCAPEouii\n");
	ret = free_elements(*data, map->tree, *map);
	exit(ret);
	return (ret);
}

int		funt(int i, void **p)
{
	t_data		*data;
	t_map		*map;
	t_player	*player;

	//vscode printf("test\n");
	data = (t_data *)p[0];
	map = (t_map *)p[1];
	player = (t_player *)p[2];
	reset_data(data);
	////vscode printf("p[0] = %p\n", p[0]);
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
		//vscode printf("            			  ESCAPE\n");
		//vscode printf("data->window = %p\n", &data->window);
		mlx_hook(data->window, 17, 0, exit_hook, p);
	}
	////vscode printf("keycode = %d\n", i);
	renderbsp(data, *map->tree.rootnode, *player);
	//vscode printf("map->tree.rootnode->splitter.wall.color = %x\n", map->tree.rootnode->splitter.wall.color);
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

	////vscode sleep(5);
//	//vscode printf("--- JE SUIS DANS LE DISPL WALL ---\n");
	initbe4display(&wall, &i, data);
	ft_memseti(ptraddr, 0, 2);
	ft_memseti(incr, 0, 2);
	cumul = 0;
	rest = 0;
	////vscode printf("wall->leftcl.a.x = %f\t\tet\t\twall->rightcl.a.x = %f\n", wall.leftcl.a.x, wall.rightcl.a.x);
	while (++i <= (int)round(wall.rightcl.a.x))
	{
		////vscode printf("i = %d\n", i);
		if (can_draw(wall, data, i))
		{
			wall.topcl = fmax(wall.top, 0.);
			wall.botcl = fmin(wall.bot, data->win_height);
			tanindex = -polygon.newangle - to_rad(90) + player.angleray[i];
			//index = (int)((polygon.pdist * tan(tanindex) + polygon.btobp) * (wall.imgwidth / data->cubside)) - (wall.imgwidth * cumul) - rest;
			index = (int)((polygon.pdist * tan(tanindex) + polygon.btobp) * ((wall.imgwidth) / data->cubside)) % (wall.imgwidth);
			////vscode printf("index = %d\n", index);
			/*if (index > (cumul + 1) * wall.imgwidth)
			{
				rest = index % (wall.imgwidth * (cumul + 1));
				//vscode printf("rest = %d\n", rest);
				////vscode sleep(5);
				cumul++;
			}*/
			////vscode printf("wall.imgwidth / data->cubside = %i\n", wall.imgwidth / data->cubside);
			////vscode printf("index = %d\n", index);
			index = (index < 0) ? 0 : index;
			incr[0] = (wall.imgheight - 1) / (wall.bot - wall.top);
			incr[1] = (wall.topcl - wall.top) * incr[0];
			incr[1] = (incr[1] < 0) ? 0 : incr[1];
			ptraddr[0] = (int)(round(wall.topcl) * data->win_width + i);
			ptraddr[1] = (int)(round(wall.botcl) * data->win_width + i);
//			//vscode printf("topcl = %f\tet\tbotcl = %f\n", wall.topcl, wall.botcl);
//			//vscode printf("(avant la boucle) ptraddr[0] = %d\tet\tptraddr[1] = %d\n", ptraddr[0], ptraddr[1]);
			while (ptraddr[0] < ptraddr[1])
			{
				//get(index, incr[1]);
//				//vscode printf("(pdt la boucle) incr[1] = %f\tet\tindex = %d\n", incr[1], index);
				////vscode printf("wall.imgwidth = %d\tet\twall.imgheight = %d\n", wall.imgwidth, wall.imgheight);
				////vscode printf("avant\n");
				wall.img_data[ptraddr[0]] = wall.data_file[(int)(round(incr[1]) * wall.imgwidth + index)];
				//wall.img_data[ptraddr[0]] = (unsigned int)0xfff;
				//if (ptraddr[0] > ((data->win_width * data->win_height) - 1)) // 2 073 599 pour 1920 et 1080
				//	//vscode printf("ptraddr[0] = %d qui est superieur win * height (- 1) (= %d)\n", ptraddr[0], (data->win_width * data->win_height) - 1);
				////vscode printf("pdist = %f\n", polygon.pdist);
				////vscode printf("apres\n");
				incr[1] += incr[0];
				ptraddr[0] += data->win_width;
			}
			////vscode printf("(apres la boucle) ptraddr[0] = %d\tet\tptraddr[1] = %d\n", ptraddr[0], ptraddr[1]);
			data->coldone[i] = 1;
		}
		wall.top += wall.deltatop;
		wall.bot += wall.deltabot;
	}
	////vscode printf("Je suis sorti\n");
	return (EXIT_SUCCESS);
}

void		set_ratio(int *nb, float *relation, t_polygon currentpoly, t_polygon *set)
{
	int	i;
	int	side;

	i = -1;
	while (set[++i].exist)
		if (!is_same_segment(set[i].segment, currentpoly.segment))
		{
			side = get_side(currentpoly, set[i]);
			if (side == FRONT) // jsp ou mettre COINCIDING du coup
				nb[0] += 1;
			else if (side == BACK)
				nb[1] += 1;
			else if (side == SPANNING)
				nb[2] += 1;
			////vscode printf("nb[0] (front) = %d\tet\tnb[1] (back) = %d\tet\tnb[2] (spanning) = %d\n", nb[0], nb[1], nb[2]);
			if (nb[0] <= nb[1] && nb[1] != 0)
				*relation = (float)nb[0] / nb[1];
			else if (nb[0] >= nb[1] && nb[0] != 0)
				*relation = (float)nb[1] / nb[0];
		}
}

void	set_best_poly(t_polygon *poly, t_polygon *set,
						float minrelation, int *leastsplits)
{
	int		nb[3];
	float	bestrelation;
	float	relation;
	int		i;

	i = -1;
	bestrelation = 0.;
	relation = 0.;
	ft_memseti(nb, 0, 3);
	set_ratio(nb, &relation, poly[0], set);
	////vscode printf("relation = %f\tet\tminrelation = %f\n*leastsplits = %d\nnb[0] = %d\tet\tnb[1] = %d\tet\tnb[2] = %d\n", relation, minrelation, *leastsplits, nb[0], nb[1], nb[2]);
	////vscode printf("*leastsplits = %d\n", *leastsplits);
	if (relation >= minrelation &&
		((nb[2] < *leastsplits) || (relation > bestrelation)))
	{
		*leastsplits = nb[2];
		bestrelation = relation;
		set_used_poly(set, &poly[0]);
		poly[1] = get_polygon(poly[0]);
		////vscode printf("relation = %f\tet\tpoly[0].isused = %d\n", relation, poly[0].isused);
		////vscode printf("poly[0].isused = %d\n", poly[0].isused);
		////vscode sleep(1);
		/*while (++i[1] != i[0])
			set[i[1]].isused = 0;
		set[i[0]].isused = 1;*/
	}
}

t_polygon	choose_div_polygon(t_polygon *set)
{
	t_polygon	poly[2]; //poly[0] --> currentpoly et poly[1] --> bestpoly
	int			i;
	float		minrelation;
	int			leastsplits;
	int			counter;


	counter = 0;
	poly[1].isused = 0;
	////vscode printf("polysetlen(set) = %d\n", polysetlen(set));
	////vscode sleep(3);
	minrelation = (is_pair(polysetlen(set))) ? (float)(polysetlen(set) / 2 - 1) / (polysetlen(set) / 2 + 1) : 1.;
	leastsplits = INT_MAX;
	if (is_convex_set(set, NULL))
		return (set[0]);
	//vscode printf("ma grosse bite\n");
	i = -1;
	while (!poly[1].isused) // a cause des isused
	{
		i = -1;
		while (set[++i].exist)
		{
			////vscode printf("test\n");
			////vscode sleep(1);
			if (!set[i].isused)
			{
			////vscode printf("test2\n");
			////vscode sleep(1);
				poly[0] = get_polygon(set[i]);
				set_best_poly(poly, set, minrelation, &leastsplits);
//				//vscode printf("bestpoly is used ? %d, cuz set[%d].isused = %d\tet\tset de len = %d\n", poly[1].isused, i, set[i].isused, polysetlen(set));
				//if (minrelation == 0.)
				//{
					//vscode printf("minrelation = 0000000000\n");
					////vscode sleep(1);
				//}
			}
		}
		////vscode printf("TOUR SUIVANT\n");
		minrelation = (minrelation < 0.0000000000001) ? 0. : (float)minrelation / 2;
	}
	//counter = -1;
	//i = -1;
	//while (set[++i].exist)
	//	if (set[i].isused)
	//		counter = i;
	////vscode printf("best polygon is set[%d]\n", counter);
	return (poly[1]);
}

void		build_tree(t_node *node, t_polygon *set, t_player player, t_data data) //je laisse ces fonctions en suspens
{
	int			side;
	int			counter[3];
	static int	i = 0;

//	//vscode printf("------ !!!!! JE RENTRE DANS LE BUILD TREE !!!!! ------\n");
	node->exist = 0;
	node->frontchild = malloc(sizeof(t_node) * 1);
	node->backchild = malloc(sizeof(t_node) * 1);
	//int	a;
	//a = -1;
	//while (set[++a].exist) //afficher tous les segments 1 par 1 avec un sleep 
	//{
		//vscode printf("set[%d].segment.a.x = %f\tset[%d].segment.a.y = %f\tset[%d].segment.b.x = %f\tset[%d].segment.b.y = %f\n", a, set[a].segment.a.x, a, set[a].segment.a.y, a, set[a].segment.b.x, a, set[a].segment.b.y);
		////vscode sleep(2);
	//	if (set[a].segment.a.x == 0 && set[a].segment.a.y == 0 && set[a].segment.b.x == 0 && set[a].segment.b.y == 0)
	//	{
			//vscode printf("Oh la vous la arretez vous svp !\n");
			//vscode sleep(5);
	//	}
	//}
	if (is_convex_set(set, node))
	{
		//vscode printf("The set is convex\n");
		return ;
	}
	ft_memseti(counter, 0, 3);
	////vscode printf("set len = %d\n", polysetlen(set));
	node->splitter = choose_div_polygon(set);
	//vscode printf("set[counter[0]].exist = %d\n", set[counter[0]].exist);
	node->frontchild->set = malloc_frontset_child(set, node->splitter);
	node->backchild->set = malloc_backset_child(set, node->splitter);
	while (set[counter[0]].exist/* && set[counter[0]].segment.exist*/)
	{
		side = get_side(node->splitter, set[counter[0]]);	/*																										*/
		//vscode printf("set[counter[0]].normal.xlen = %f\tet\tset[counter[0]].ylen = %f\n", set[counter[0]].normal.xlen, set[counter[0]].normal.ylen);
		//vscode printf("set[%d].segment.a.x = %f\tset[%d].segment.a.y = %f\tset[%d].segment.b.x = %f\tset[%d].segment.b.y = %f\n", counter[0], set[counter[0]].segment.a.x, counter[0], set[counter[0]].segment.a.y, counter[0], set[counter[0]].segment.b.x, counter[0], set[counter[0]].segment.b.y);
		if (side == FRONT || side == COINCIDING)									/*																										*/
		{
			node->frontchild->set[counter[1]] = get_polygon(set[counter[0]]);	/*										Peut-etre mettre												*/
			//node->frontchild->set[counter[1]].wall = create_wall(node->frontchild->set[counter[1]], player, data); //trouver un moyen de recuperer la valeur
			//frontpolyset[counter[1]].isused = 0;
			counter[1]++;
			////vscode printf("set[%d] se trouve devant\n", counter[0]);
		}
		else if (side == BACK)								/*										tout ca dans une												*/
		{
			node->backchild->set[counter[2]] = get_polygon(set[counter[0]]);	/*											fonction													*/
			//node->frontchild->set[counter[2]].wall = create_wall(node->frontchild->set[counter[2]], player, data); //trouver un moyen de recuperer la valeur
			//backpolyset[counter[2]].isused = 0;
			counter[2]++;
			////vscode printf("set[%d] se trouve derriere\n", counter[0]);
		}
		else if (side == SPANNING)							/*																										*/
		{
//			//vscode printf(" !!!!!!!!! JE VAIS SPLIT !!!!!!!!! \n");
			split_polygon(set[counter[0]], node->splitter, &node->frontchild->set[counter[1]], &node->backchild->set[counter[2]]);/*													*/
			//node->frontchild->set[counter[1]].wall = create_wall(node->frontchild->set[counter[1]], player, data); //trouver un moyen de recuperer la valeur
			//node->frontchild->set[counter[2]].wall = create_wall(node->frontchild->set[counter[2]], player, data); //trouver un moyen de recuperer la valeur
			////vscode printf("set[%d] se trouve devant et derriere\n", counter[0]);
			counter[1]++;
			counter[2]++;
		}
		////vscode printf("frontsetlen = %d\tet\tbacksetlen = %d\n", polysetlen(frontpolyset), polysetlen(backpolyset));
		counter[0]++;
	}
	node->exist = 1;
	i++;
	//vscode printf("ca fait la %de boucle\n", i);
	////vscode sleep(1);
	////free(set);
	build_tree(node->frontchild, node->frontchild->set, player, data);
	////free(frontpolyset);
	i++;
	//vscode printf("ca fait la %deme boucle\n", i);
	////vscode sleep(1);
	build_tree(node->backchild, node->backchild->set, player, data);
	////free(backpolyset);
}

int			get_cub(t_map *map, t_player *player, t_data data, int i)
{
	int			counter;

	counter = -1;
	player->exist = 0;
	while (map->number[i][++counter])
	{
		if (map->number[i][counter] == '1')
			set_cub(data, &map->cub[i][counter], i, counter);
		else if (map->number[i][counter] == '2') //s'occuper des malloc des objets
			set_obj(data, map, i, counter);
		else if (ft_get_nbchar("SNEW", map->number[i][counter]) == 1)
		{
			if (player->exist)
				ft_putstrreti_fd("Error\nUn seul joueur est accepte sur la map.\n", 0, 0);
			*player = get_player(counter * data.cubside, i * data.cubside, map->number[i][counter], data);
			map->cub[i][counter].exist = 0;
		}
		else
			map->cub[i][counter].exist = 0;
		//vscode printf("map->cub[0][2].sbot.a.x = %f\n", map->cub[0][2].sbot.a.x);
	}
	return (1);
}

int			get_nbcuby(t_map *map, int xmax, int nblin)
{
	int		x;
	int		y[2];

	x = -1;
	//vscode printf("xmax = %d\n", xmax);
	if (!(map->nbcuby = malloc(sizeof(int) * xmax + 1)))
		return (0);
	while (++x < xmax)
	{
		y[0] = 0;
		while (map->number[y[0]][x] == ' ')
			y[0]++;
		y[1] = nblin - 1;
		while (map->number[y[1]][x] == ' ')
			y[1]--;
		map->nbcuby[x] = y[1] - y[0] + 1;
	}
	map->nbcuby[xmax] = -1;
	map->nbxmax = get_nbxmax(map->nbcuby);
	map->nbymax = get_nbymax(map->nbcuby);
	return (1);
}

int			get_number(t_map *map, int fd, int *nblin, int *xmax)
{
	int		ret;
	int		i;
	int		max;
	int		max1;

	i = 0;
	max = 0;
	map->nbobjects = 0;
	if (!(map->number = malloc(sizeof(char *) * (i + 1))))
		return (0);
	while ((ret = get_next_line(fd, &map->number[i])) != -1 &&
	!ft_isonlychar(map->number[i], " "))
	{
		if (!ft_isonlychar(map->number[i], "012SNEW "))
		{
			//vscode printf("map->number[%d] = %s\n", i, map->number[i]);
			return (ft_putstrreti_fd("Error\nUn des caracteres n'est pas valide\n", 0, 0)); // mettre ces 2 if dans une fonction d'erreur
		}
		//vscode printf("map->number[i] = %s\n", map->number[i]);
		//vscode printf("i = %d\n", i);
		max = ((int)ft_strlen(map->number[i])) > max ? (int)ft_strlen(map->number[i]) : max;
		i++;
		//vscode printf("je m'apprete a realloc\n");
		if (!(map->number = ft_realloc(map->number, sizeof(char *) * (i + 1))))
			return (0); // regrouper ces malloc peut etre
	}
	if (ret == -1)
		return (ft_putstrreti_fd("Error\nVeuillez verifiez le fichier\n", 0, 0));
	if (!verify_end(fd))
		return (ft_putstrreti_fd("Error\nLa map doit etre le dernier element\n", 0, 0));
	*nblin = i;
	*xmax = max;
	//vscode printf("max = %d\n", max);
	//vscode printf("nblin = %d\n", *nblin);
	//vscode sleep(1);
	i = -1;
	while (++i < *nblin)
	{
		////vscode printf("map->number[%d] = %s\n", i, map->number[i]);
		max1 = ft_strlen(map->number[i]) - 1;
		//vscode printf("ligne -> %d\tmax1 = %d\tet\t*xmax = %d\n", i, max1, *xmax);
		if (!(map->number[i] = ft_realloc(map->number[i], sizeof(char) * *xmax + 1)))
			return (0);
		while (++max1 < *xmax)
			map->number[i][max1] = ' ';
		map->number[i][*xmax] = '\0';
	}
	return (1);
}

t_map		create_map(t_data *data, t_player *player)
{
	t_map	map;
	int		fd;
	int		xmax;
	int		nblin;
	int		i;

	map.exist = 0;
	map.objects = NULL;
	xmax = 0;
	nblin = 0;
	//vscode printf("test a\n");
	if (!data->filename || !ft_strstrpart(data->filename, ft_strlen(data->filename) - 4,
									".cub"))
		return (putstrret_fd("Error\nVeuillez mettre une map\n", map, 0));
	//vscode printf("Test 1\n");
	fd = open(data->filename, O_RDONLY);
	if (!parse_elements(&map, data, fd))
		return (map);
	if (!get_number(&map, fd, &nblin, &xmax) || !get_nbcuby(&map, xmax, nblin)
		|| !offset_ptrcub(&map, nblin, xmax)) // on lui passe le fd car gnl va etre utilise pour arriver jusqu'a la map
		return (map);
	i = -1;
	if (!is_surrounded(map))
		return (putstrret_fd("Error\nLa map n'est pas entoure de murs\n", map, 0));
	while (++i < nblin)
		if (!get_cub(&map, player, *data, i))
			return (map);
	if ((data->window = mlx_new_window(data->ptr, data->win_width, data->win_height, "Cub3d")) == NULL)
		return (map);
	map.exist = 1;
	return (map);
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
	//vscode printf("data.window (main) = %p\n", &data.window);

	//TO REMOVE
	data.img = mlx_new_image(data.ptr, data.win_width, data.win_height);
	data.img_data = (int *)mlx_get_data_addr(data.img, &data.bpp, &data.size_line, &data.endian);

	map = create_map(&data, &player);
	//int a = 3000;
	////vscode printf("Sieste de %dsec\n", a / 1000);
	////vscode sleep(a);
	reset_data(&data);
	if (!map.exist)
		return (3);
	if (!create_tree_node(&map, player, data))
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
	mlx_put_image_to_window(data.ptr, data.window, data.img, 0, 0);	// max(wall.leftcl.a.x, 0), max(wall.leftcl.a.y, 0)); // y a des problemes de malloc a l'interieur de mlx_put_image_to_window()
	
	//vscode printf("salut c'est moi\n");
	param[0] = (void *)&data;
	//vscode printf("param[0]\n");
	param[1] = (void *)&map;
	//vscode printf("param[1]\n");
	param[2] = (void *)&player;
	//vscode printf("param[2]\n");
	(void)ac;
	mlx_hook(data.window, 2, 0, funt, param); //2 -> keypress, 4 -> mousepress, 6 -> mousemotion
//	renderbsp(&data, *map.tree.rootnode, player);
	mlx_loop(data.ptr);
	return (EXIT_SUCCESS);
}
