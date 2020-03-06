/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_var_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 19:42:34 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/06 11:15:56 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void		set_cub(t_cub *cub, int i, int counter)
{
	cub->exist = true;
	cub->x = counter * cub->side; //sommet a gauche avec vue du dessus
	cub->y = i * cub->side; //sommet en haut avec vue du dessus
	cub->stop = get_segmenti(cub->x,
							cub->y,
							cub->x + cub->side - 1,
							cub->y);
	cub->sright = get_segmenti(cub->x + cub->side - 1,
							cub->y,
							cub->x + cub->side - 1,
							cub->y + cub->side - 1);
	cub->sbot = get_segmenti(cub->x + cub->side - 1,
							cub->y + cub->side - 1,
							cub->x,
							cub->y + cub->side - 1);
	cub->sleft = get_segmenti(cub->x,
							cub->y + cub->side - 1,
							cub->x,
							cub->y);
}
