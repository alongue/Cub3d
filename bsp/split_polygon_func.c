/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_polygon_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 11:41:31 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/11 11:49:07 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_polygon	dup_polygon(t_polygon polygon) //mettre peut etre le param cubside mais y aura plus de 4 param
{
	t_polygon	poly;

	poly.exist = polygon.exist; //quand on le commente ca arrete le cote aleatoire mais ca fait un mauvais bsp donc je pense que le probleme reside dans l'existence des polygones
	poly.segment = dup_segment(polygon.segment);
	poly.newsegment = dup_segment(polygon.newsegment);
	poly.normal = dup_normal(polygon.normal);
	poly.isused = polygon.isused;
	poly.dodisplay = polygon.dodisplay;
	poly.nbwall = polygon.nbwall;
	poly.wall = polygon.wall;
	if (polygon.segment.a.x  > 3000|| polygon.segment.a.y  > 3000|| polygon.segment.b.x  > 3000|| polygon.segment.b.y > 3000)
		{
			printf("p.segment.a.x = %f || p.segment.a.y = %f || p.segment.b.x = %f || polygon.b.y = %f\n", polygon.segment.a.x, polygon.segment.a.y, polygon.segment.b.x, polygon.segment.b.y);
			sleep(10);
		}

	return (poly);
}

void		partition_frontset(t_polygon *frontset, t_polygon *backset,
						t_point p, t_polygon poly)
{
	t_player	player;

	player.exist = false;
	*frontset = dup_polygon(poly);
	*backset = dup_polygon(poly);
	frontset->isused = false;
	backset->isused = false;
	split_segment_inc(poly.segment, p, &(frontset->segment), &(backset->segment));
	printf("FRONT\n");
	printf("seg front a.x = %f\tb.x = %f\ta.y = %f\tb.y = %f\n", frontset->segment.a.x, frontset->segment.b.x, frontset->segment.a.y, frontset->segment.b.y);
	printf("seg back a.x = %f\tb.x = %f\ta.y = %f\tb.y = %f\n", backset->segment.a.x, backset->segment.b.x, backset->segment.a.y, backset->segment.b.y);
	//sleep(3);
	//frontset->nbwall = poly.nbwall / 2; du coup faudrait mettre ca en double
	//backset->nbwall = poly.nbwall / 2;
}

void		partition_backset(t_polygon *frontset, t_polygon *backset,
						t_point p, t_polygon poly)
{
	t_player	player;

	player.exist = false;
	*frontset = dup_polygon(poly);
	*backset = dup_polygon(poly);
	frontset->isused = false;
	backset->isused = false;
	split_segment_inc(poly.segment, p, &(backset->segment), &(frontset->segment));
	printf("BACK\n");
	printf("p.x = %f\tp.y = %f\n", p.x, p.y);
	printf("seg front a.x = %f\tb.x = %f\ta.y = %f\tb.y = %f\n", frontset->segment.a.x, frontset->segment.b.x, frontset->segment.a.y, frontset->segment.b.y);
	printf("seg back a.x = %f\tb.x = %f\ta.y = %f\tb.y = %f\n", backset->segment.a.x, backset->segment.b.x, backset->segment.a.y, backset->segment.b.y);
	//sleep(3);
	//frontset->nbwall = poly.nbwall / 2; du coup faudrait mettre ca en double
	//backset->nbwall = poly.nbwall / 2;
}
