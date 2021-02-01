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

t_polygon	get_polygon(t_polygon polygon) //mettre peut etre le param cubside mais y aura plus de 4 param
{
	t_polygon	poly;

	poly.exist = polygon.exist; //quand on le commente ca arrete le cote aleatoire mais ca fait un mauvais bsp donc je pense que le probleme reside dans l'existence des polygones
	poly.segment = dup_segment(polygon.segment);
	//vscode printf("poly.segment.exist = %d\n", poly.segment.exist);
	//vscode printf("poly.segment.a.x = %f\t\tpoly.segment.a.y = %f\tpoly.segment.b.x = %f\t\tpoly.segment.b.y = %f\n", poly.segment.a.x, poly.segment.a.y, poly.segment.b.x, poly.segment.b.y);
	poly.len = polygon.len;
	poly.newsegment = dup_segment(polygon.newsegment);
	poly.normal = dup_normal(polygon.normal);
	poly.isused = polygon.isused;
	poly.dodisplay = polygon.dodisplay;
	poly.nbwall = polygon.nbwall;
	poly.angle = polygon.angle;
	//vscode printf("poly.wall.color = %x\tet\tpolygon.wall.color = %x\n", poly.wall.color, polygon.wall.color);//map->tree.rootnode->splitter.wall.color);
	poly.wall = dup_wall(polygon.wall);
	//vscode printf("poly.wall.color = %x\tet\tpolygon.wall.color = %x\n\n", poly.wall.color, polygon.wall.color);//map->tree.rootnode->splitter.wall.color);
	return (poly);
}

void		partition_frontset(t_polygon *frontset, t_polygon *backset,
						t_point p, t_polygon poly)
{
	t_player	player;

	player.exist = 0;
	//vscode printf("frontset\n");
	*frontset = get_polygon(poly);
	*backset = get_polygon(poly);
	frontset->isused = 0;
	backset->isused = 0;
	split_segment_inc(poly.segment, p, &(frontset->segment), &(backset->segment));
	frontset->len = get_length(frontset->segment);
	backset->len = get_length(backset->segment);
	//vscode printf("FRONT\n");
	//vscode printf("seg front a.x = %f\tb.x = %f\ta.y = %f\tb.y = %f\n", frontset->segment.a.x, frontset->segment.b.x, frontset->segment.a.y, frontset->segment.b.y);
	//vscode printf("seg back a.x = %f\tb.x = %f\ta.y = %f\tb.y = %f\n", backset->segment.a.x, backset->segment.b.x, backset->segment.a.y, backset->segment.b.y);
	////vscode sleep(3);
	//frontset->nbwall = poly.nbwall / 2; du coup faudrait mettre ca en double
	//backset->nbwall = poly.nbwall / 2;
}

void		partition_backset(t_polygon *frontset, t_polygon *backset,
						t_point p, t_polygon poly)
{
	t_player	player;

	player.exist = 0;
	//vscode printf("backset\n");
	*frontset = get_polygon(poly);
	*backset = get_polygon(poly);
	frontset->isused = 0;
	backset->isused = 0;
	split_segment_inc(poly.segment, p, &(backset->segment), &(frontset->segment));
	frontset->len = get_length(frontset->segment);
	backset->len = get_length(backset->segment);
	//vscode printf("BACK\n");
	//vscode printf("p.x = %f\tp.y = %f\n", p.x, p.y);
	//vscode printf("seg front a.x = %f\tb.x = %f\ta.y = %f\tb.y = %f\n", frontset->segment.a.x, frontset->segment.b.x, frontset->segment.a.y, frontset->segment.b.y);
	//vscode printf("seg back a.x = %f\tb.x = %f\ta.y = %f\tb.y = %f\n", backset->segment.a.x, backset->segment.b.x, backset->segment.a.y, backset->segment.b.y);
	////vscode sleep(3);
	//frontset->nbwall = poly.nbwall / 2; du coup faudrait mettre ca en double
	//backset->nbwall = poly.nbwall / 2;
}
