/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_var_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 19:42:34 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/15 19:42:37 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_segment	set_segment(int px, int py, int qx, int qy)
{
	t_segment	s;

	//peut etre faire des malloc
	s->p->x = px;
	s->p->y = py;
	s->q->x = qy;
	s->q->y = qy;
	return (s);
}

void		set_cub(t_cub ***cub)
{
	cub[i][counter]->x = i * cub[i][counter]->wall->realside; //sommet a gauche avec vue du dessus
	cub[i][counter]->y= counter * cub[i][counter]->wall->realside; //sommet en haut avec vue du dessus
	cub[i][counter]->stop = set_segment(cub[i][counter]->x,
										cub[i][counter]->y,
										cub[i][counter]->x + cub[i][counter].side,
										cub[i][counter]->y);
	cub[i][counter]->sleft = set_segment(cub[i][counter]->x,
										 cub[i][counter]->y,
										 cub[i][counter]->x,
										 cub[i][counter]->y + cub[i][counter]->side);
	cub[i][counter]->sbot = set_segment(cub[i][counter]->x + cub[i][counter]->side,
										cub[i][counter]->y + cub[i][counter]->side,
										cub[i][counter]->x,
										cub[i][counter]->y + cub[i][counter]->side);
	cub[i][counter]->sright = set_segment(cub[i][counter]->x + cub[i][counter]->side,
										  cub[i][counter]->y + cub[i][counter]->side,
										  cub[i][counter]->x + cub[i][counter]->side,
										  cub[i][counter]->y);
}
