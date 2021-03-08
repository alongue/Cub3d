/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:01:29 by user42            #+#    #+#             */
/*   Updated: 2021/03/08 19:51:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_map   initmap(t_data *data, t_player *player, char **av, int ac)
{
    t_map   map;

    map.exist = 0;
    if (create_data(data, av, ac) == EXIT_FAILURE)
		return (map);
	map = create_map(data, player);
	if (!map.exist)
		return (map);
	reset_data(data);
    return (map);
}
