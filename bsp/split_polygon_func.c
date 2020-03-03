/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_polygon_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 11:41:31 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/02 17:45:04 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void		partition_frontset(t_polygon *frontset, t_polygon *backset,
						t_point p, t_polygon poly)
{
	split_segment_exc(poly.segment, p, &frontset->segment, &backset->segment);
	frontset->normal = dup_normal(poly.normal);
	//frontset->nbwall = poly.nbwall / 2; du coup faudrait mettre ca en double
	frontset->exist = true;
	backset->normal = dup_normal(poly.normal);
	//backset->nbwall = poly.nbwall / 2;
	backset->exist = true;
}

void		partition_backset(t_polygon *frontset, t_polygon *backset,
						t_point p, t_polygon poly)
{
	split_segment_exc(poly.segment, p, &backset->segment, &frontset->segment);
	frontset->normal = dup_normal(poly.normal);
	//frontset->nbwall = poly.nbwall / 2; du coup faudrait mettre ca en double
	frontset->exist = true;
	backset->normal = dup_normal(poly.normal);
	//backset->nbwall = poly.nbwall / 2;
	backset->exist = true;
}
