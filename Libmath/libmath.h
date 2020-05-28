/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmath.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:21:36 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/10 12:23:31 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMATH_H
# define LIBMATH_H

# include <math.h>
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>

# define COLINEAR 0
# define COINCIDING 0
# define CLOCKWISE 1
# define COUNTERCLOCKWISE 2

struct						s_point
{
	double	x;
	double	y;
};
typedef struct s_point		t_point;

struct						s_segment
{
	int	exist;
	t_point	a;
	t_point	b;
	double	coeff;
	double	intercept;
};
typedef struct s_segment	t_segment;

struct						s_normal
{
	double	xlen;
	double	ylen;
};
typedef struct s_normal		t_normal;

int						do_intersect(t_segment s1, t_segment s2);
t_normal					dup_normal(t_normal normal);
t_point						dup_point(t_point p);
t_segment					dup_segment(t_segment s);
int							ft_abs(int nb);
int							get_extremity(t_segment segment, t_point *first, t_point *end);
double						get_length(t_segment segment);
double						get_lengthp(t_point a, t_point b);
void						get_next_point(t_segment segment, t_point *point, double iterator);
void						get_prev_point(t_segment segment, t_point *point, double iterator);
t_normal					get_normal(t_segment s);
t_point						get_point(double x, double y);
t_segment					get_segment(t_point p, t_point q);
t_segment					get_segmenti(double px, double py, double qx, double qy);
int						is_colinear(t_segment s1, t_segment s2);
int						is_pair(int a);
int						is_same_segment(t_segment s1, t_segment s2);
t_segment					join_segment(t_segment s1, t_segment s2);
int							min(int a, int b);
int							max(int a, int b);
int						onsegment(t_point s, t_point p, t_point r);
int							orientation(t_point p, t_point q, t_point r);
void						set_btwn_zero_twopi(double *angle);
void						set_btwn_minpi_pi(double *angle);
void						set_point_on_segx(t_segment segment, t_point *p);
void						set_point_on_segy(t_segment segment, t_point *p);
void						split_segment_inc(t_segment segment, t_point point,
t_segment *s1, t_segment *s2);
void						split_segment_exc(t_segment segment, t_point point,
t_segment *s1, t_segment *s2);
double						to_rad(double angle);
double						to_deg(double angle);
int							translate_point(t_point *point, double x, double y);
int							translate_segment(t_segment *segment, double x, double y);

#endif
