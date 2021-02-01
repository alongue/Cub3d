/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:35:03 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/11 17:39:25 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

# define HEIGHTPL 32

static double	*create_ray(t_data data, int *do_exist, double dfoc)
{
	double	*angle;
	int		i;

	*do_exist = 0;
	if (!(angle = malloc(sizeof(double) * data.win_width)))
		return (ft_putstrret_fd("Error\nLe malloc n'a pas marche\n", 0, 0));
	i = -1;
	while (++i < data.win_width)
		angle[i] = atan(((data.win_width / 2) - (double)i) / dfoc);
	*do_exist = 1;
	return (angle);
}

t_player		get_player(int x, int z, int c, t_data data)
{
	t_player	player;

	player.exist = 0;
	if (c == 'N')
		player.angle = to_rad(270.);
	else if (c == 'S')
		player.angle = to_rad(90.);
	else if (c == 'E')
		player.angle = to_rad(0.);
	else if (c == 'W')
		player.angle = to_rad(180.);
	else
		return (player);
	player.x = x + HEIGHTPL;
	player.y = HEIGHTPL;
	player.z = z + HEIGHTPL;
	player.pos = set_point(x, z);
	player.speed = 200;
	player.sensi = 200;
	player.fieldvis = to_rad(90.);
	player.exist = 1;
	player.dfoc = data.win_width / 2 / tan(player.fieldvis / 2);
	//vscode printf("player.dfoc = %f\tet\tdata.win_width = %d\n", player.dfoc, data.win_width);
	////vscode sleep(10);
	player.anglerayy = atan(1 / player.dfoc);
	player.angleray = create_ray(data, &player.exist, player.dfoc);
	return (player);
}
