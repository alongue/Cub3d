/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_var_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 19:42:34 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/04 12:11:05 by alongcha         ###   ########.fr       */
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
							cub->x + cub->side,
							cub->y);
	cub->sleft = get_segmenti(cub->x,
							cub->y,
							cub->x,
							cub->y + cub->side);
	cub->sbot = get_segmenti(cub->x + cub->side,
							cub->y + cub->side,
							cub->x,
							cub->y + cub->side);
	cub->sright = get_segmenti(cub->x + cub->side,
								cub->y + cub->side,
								cub->x + cub->side,
								cub->y);
}
