/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_polygon_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 11:41:31 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/10 15:38:20 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_polygon	dup_polygon(t_polygon polygon)
{
	t_polygon	poly;

	poly.exist = polygon.exist; //quand on le commente ca arrete le cote aleatoire mais ca fait un mauvais bsp donc je pense que le probleme reside dans l'existence des polygones
	poly.segment = dup_segment(polygon.segment);
	poly.newsegment = dup_segment(polygon.newsegment);
	poly.normal = dup_normal(polygon.normal);
	poly.isused = polygon.isused;
	poly.dodisplay = polygon.dodisplay;
	poly.nbwall = polygon.nbwall;
	if (polygon.segment.a.x  > 3000|| polygon.segment.a.y  > 3000|| polygon.segment.b.x  > 3000|| polygon.segment.b.y > 3000)
		{
			printf("p.segment.a.x = %d || p.segment.a.y = %d || p.segment.b.x = %d || polygon.b.y = %d\n", polygon.segment.a.x, polygon.segment.a.y, polygon.segment.b.x, polygon.segment.b.y);
			sleep(10);
		}

	return (poly);
}

void		partition_frontset(t_polygon *frontset, t_polygon *backset,
						t_point p, t_polygon poly)
{
	*frontset = dup_polygon(poly);
	*backset = dup_polygon(poly);
	frontset->isused = false;
	backset->isused = false;
	split_segment_exc(poly.segment, p, &(frontset->segment), &(backset->segment));
	//frontset->nbwall = poly.nbwall / 2; du coup faudrait mettre ca en double
	//backset->nbwall = poly.nbwall / 2;
}

void		partition_backset(t_polygon *frontset, t_polygon *backset,
						t_point p, t_polygon poly)
{
	*frontset = dup_polygon(poly);
	*backset = dup_polygon(poly);
	frontset->isused = false;
	backset->isused = false;
	split_segment_exc(poly.segment, p, &(backset->segment), &(frontset->segment));
	//frontset->nbwall = poly.nbwall / 2; du coup faudrait mettre ca en double
	//backset->nbwall = poly.nbwall / 2;
}
