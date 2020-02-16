/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_var_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 19:42:34 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/16 16:05:54 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		set_cub(t_cub **cub)
{
	cub[i][counter].exist = 1;
	cub[i][counter].x = i * cub[i][counter].wall.realside; //sommet a gauche avec vue du dessus
	cub[i][counter].y = counter * cub[i][counter].wall.realside; //sommet en haut avec vue du dessus
	cub[i][counter].stop = get_segment(cub[i][counter].x,
										cub[i][counter].y,
										cub[i][counter].x + cub[i][counter].side,
										cub[i][counter].y);
	cub[i][counter].sleft = get_segment(cub[i][counter].x,
										 cub[i][counter].y,
										 cub[i][counter]->x,
										 cub[i][counter].y + cub[i][counter].side);
	cub[i][counter].sbot = get_segment(cub[i][counter].x + cub[i][counter].side,
										cub[i][counter].y + cub[i][counter].side,
										cub[i][counter].x,
										cub[i][counter].y + cub[i][counter].side);
	cub[i][counter].sright = get_segment(cub[i][counter].x + cub[i][counter].side,
										  cub[i][counter].y + cub[i][counter].side,
										  cub[i][counter].x + cub[i][counter].side,
										  cub[i][counter].y);
}
