/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_polygon_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 11:41:31 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 21:02:33 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_polygon	get_polygon(t_polygon polygon)
{
	t_polygon	poly;

	poly.exist = polygon.exist;
	poly.segment = dup_segment(polygon.segment);
	poly.len = polygon.len;
	poly.newsegment = dup_segment(polygon.newsegment);
	poly.normal = dup_normal(polygon.normal);
	poly.isused = polygon.isused;
	poly.dodisplay = polygon.dodisplay;
	poly.nbwall = polygon.nbwall;
	poly.angle = polygon.angle;
	poly.wall = dup_wall(polygon.wall);
	return (poly);
}

void		partition_frontset(t_polygon *frontset, t_polygon *backset,
						t_point p, t_polygon poly)
{
	*frontset = get_polygon(poly);
	*backset = get_polygon(poly);
	frontset->isused = 0;
	backset->isused = 0;
	split_segment_inc(poly.segment, p, &(frontset->segment), &(backset->segment));
	frontset->len = get_length(frontset->segment);
	backset->len = get_length(backset->segment);
}

void		partition_backset(t_polygon *frontset, t_polygon *backset,
						t_point p, t_polygon poly)
{
	*frontset = get_polygon(poly);
	*backset = get_polygon(poly);
	frontset->isused = 0;
	backset->isused = 0;
	split_segment_inc(poly.segment, p, &(backset->segment), &(frontset->segment));
	frontset->len = get_length(frontset->segment);
	backset->len = get_length(backset->segment);
}
