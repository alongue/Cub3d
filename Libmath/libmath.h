/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmath.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:21:36 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/16 15:19:48 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMATH_H
# define LIBMATH_H

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>

# define COLINEAR 0
# define COINCIDING 0
# define CLOCKWISE 1
# define COUNTERCLOCKWISE 2

struct				s_point
{
	int		x;
	int		y;
};
typedef struct s_point		t_point;

struct				s_segment
{
	t_point	p;
	t_point	q;
};
typedef struct s_segment	t_segment;

struct				s_normal
{
	int		xlen;
	int		ylen;
	int		xmin;
	int		ymin;
	int		xmax;
	int		ymax;
};
typedef struct s_normal		t_normal;

bool			do_intersect(t_segment s1, t_segment s2);
int				ft_abs(int nb);
t_normal		*get_normal(t_segment s);
bool			is_colinear(t_segment s1, t_segment s2);
int				min(int a, int b);
int				max(int a, int b);
bool			onsegment(t_point s, t_point p, t_point r);
int				orientation(t_point p, t_point q, t_point r);
t_segment		join_segment(t_segment *s1, t_segment *s2);
t_segment		*get_segment(t_point p, t_point q);
t_segment		*dup_segment(t_segment *s);
t_segment		*get_segmenti(int px, int py, int qx, int qy);
t_point			*get_point(int x, int y);
t_point			*dup_point(t_point *p);

#endif
