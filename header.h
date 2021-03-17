/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:07:43 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/12 16:22:31 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "Libft/libft.h"
# include "Libmath/libmath.h"
# include "get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>

# define FPS 60
# define DEFX 100
# define DEFY 200
# define FRONT 1
# define BACK 2
# define SPANNING 3
# define ISFINISH 5
# define MOVING 7
# define STOP 8
# define TOP 0
# define BOT 1
# define RIGHT 2
# define LEFT 3
# define BLOCKED -1
# define ZMIN 1
# define ARGUMENTS "Error\nArguments valables : \"map\".cub [--save]\n"
# define MALLOC "Error\nUn malloc n'a pas fonctionne\n"
# define WALL "Error\nLa map n'est pas entoure de murs\n"
# define MAP "Error\nVeuillez verifier la map\n"
# define PLAYER "Error\nLe joueur n'a pas ete mis sur la map.\n"
# define PLAYERS "Error\nUn seul joueur est accepte sur la map.\n"
# define ERRFILE "Error\nUne erreur est survenue lors de la lecture du file\n"
# define CHAR "Error\nUn des caracteres n'est pas valide\n"
# define LASTELEM "Error\nLa map doit etre le dernier element\n"

struct				s_data
{
	int				exist;
	int				ac;
	void			*ptr;
	void			*window;
	void			*img;
	int				*img_data;
	int				tosave;
	int				bpp;
	int				size_line;
	int				endian;
	int				win_width;
	int				win_height;
	int				cubside;
	unsigned int	colceil;
	unsigned int	colfloor;
	float			*heightcol;
	char			*texnorth;
	char			*texsouth;
	char			*texeast;
	char			*texwest;
	char			*sprite;
	int				currentcubindex[2];
	char			*filename;
	int				nbcoldone;
	int				*coldone;
};
typedef struct s_data		t_data;

struct				s_wall
{
	int				exist;
	int				bpp;
	int				size_line;
	int				endian;
	int				bppimg;
	int				size_lineimg;
	int				endianimg;
	double			top;
	double			topcl;
	double			bot;
	double			botcl;
	t_segment		left;
	t_segment		leftcl;
	t_segment		right;
	t_segment		rightcl;
	double			deltatop;
	double			deltabot;
	int				ptraddr[2];
	double			incr[2];
	unsigned int	color;
	void			*img;
	int				imgwidth;
	int				imgheight;
	int				*img_data;
	int				*data_file;
};
typedef struct s_wall		t_wall;

struct				s_cub
{
	int			exist;
	int			x;
	int			y;
	t_segment	stop;
	t_segment	sleft;
	t_segment	sbot;
	t_segment	sright;
	t_wall		wall;
};
typedef struct s_cub		t_cub;

struct				s_polygon
{
	int			exist;
	t_segment	segment;
	t_segment	newsegment;
	t_normal	normal;
	t_wall		wall;
	double		r;
	double		angle;
	double		newangle;
	double		len;
	double		btobp;
	double		pdist;
	int			isused;
	int			dodisplay;
};
typedef struct s_polygon	t_polygon;

struct				s_object
{
	int			exist;
	int			bpp;
	int			size_line;
	int			endian;
	int			bppimg;
	int			size_lineimg;
	int			endianimg;
	t_point		pos;
	t_point		newpos;
	int			dodisplay;
	int			height;
	int			width;
	double		top;
	double		bot;
	double		topcl;
	double		botcl;
	double		faketop;
	double		fakebot;
	double		xstart;
	double		xstartcl;
	double		xmiddlecl;
	double		xendcl;
	t_point		posfps;
	double		xiter;
	double		yiter;
	void		*img;
	int			*img_data;
	int			*data_file;
};
typedef struct s_object		t_object;

struct				s_player
{
	int		exist;
	t_point	pos;
	double	x;
	int		y;
	double	z;
	float	speed;
	double	sensi;
	double	dfoc;
	double	*angleray;
	double	fieldvis;
	double	angle;
};
typedef struct s_player		t_player;

struct				s_tree
{
	struct s_node	*rootnode;
};
typedef struct s_tree		t_tree;

struct				s_node
{
	int				exist;
	t_tree			tree;
	t_polygon		splitter;
	t_polygon		*set;
	int				isleaf;
	struct s_node	*frontchild;
	struct s_node	*backchild;
};
typedef struct s_node		t_node;

struct				s_map
{
	int			exist;
	int			*nbcuby;
	char		**number;
	char		**testnumber;
	int			nbobjects;
	int			nbxcharmax;
	int			nbxmax;
	int			nbymax;
	int			height;
	t_cub		**cub;
	t_object	*objects;
	t_tree		tree;
};
typedef struct s_map		t_map;

int					bitmap(t_data *data, t_player *player);
int					build_again(t_node *node,
t_player player, t_data data, int *i);
int					build_tree(t_node *node,
t_polygon *set, t_player player, t_data data);
int					can_draw(t_wall wall, t_data *data, int index);
int					can_draw_obj(t_object *object, t_data *data, int index);
void				cannot_see_first_part(double *tanpoly, t_polygon *polygon);
void				cannot_see_last_part(double *tanpoly, t_polygon *polygon);
int					check_first_part(char *line, int *i, t_data *data);
int					check_outside(int *x, int y, int *i, char *map_number);
t_polygon			choose_div_polygon(t_polygon *set);
int					classify_point(t_polygon polygon, t_point point);
void				clip(t_wall *wall, t_data data);
int					cond_bot(t_map *map, int x, int y);
int					cond_left(t_map *map, int x, int y);
int					cond_right(t_map *map, int x, int y);
int					cond_top(t_map *map, int x, int y);
unsigned int		convert_color(char *line);
int					create_data(t_data *data, char **av, int ac);
t_map				create_map(t_data *data, t_player *player);
int					create_mlx_img(t_data *data, char *line, int end);
t_polygon			create_polybot(t_map *map, int *coor, t_data data);
t_polygon			create_polyleft(t_map *map, int *coor, t_data data);
t_polygon			create_polyright(t_map *map, int *coor, t_data data);
t_polygon			create_polytop(t_map *map, int *coor, t_data data);
int					create_tree_node(t_map *map, t_data data);
t_wall				create_wall(t_polygon poly, t_player player, t_data data);
int					data_malloc(t_data *data, char **av);
t_map				*deref_params(void **params, int **location,
int **oldlocation, int **moving_side);
int					display_ceilfloor(t_data *data);
int					display_object(t_data *data, t_object object);
int					display_wall(t_data *data, t_polygon polygon,
t_player player);
int					do_cond_top(t_map *map, int i, t_data *data);
int					do_cond_bot(t_map *map, int i, t_data *data);
int					do_cond_left(t_map *map, int i, t_data *data);
int					do_cond_right(t_map *map, int i, t_data *data);
int					do_display_poly(t_polygon *polygon, t_data data,
t_player player);
int					do_display_obj(t_object *object, t_data data,
t_player player);
int					do_location_bot(void **params, int *fakecoor,
int *coor, int *ret);
int					do_location_left(void **params, int *fakecoor,
int *coor, int *ret);
int					do_location_right(void **params, int *fakecoor,
int *coor, int *ret);
int					do_location_top(void **params, int *fakecoor,
int *coor, int *ret);
int					do_moving_bot(t_map *map, int *fakecoor,
int moving_result, int *ret);
int					do_moving_left(t_map *map, int *fakecoor,
int moving_result, int *ret);
int					do_moving_right(t_map *map, int *fakecoor,
int moving_result, int *ret);
int					do_moving_top(t_map *map, int *fakecoor,
int moving_result, int *ret);
t_wall				dup_wall(t_wall wall);
int					finish_recover(int location, char ***xtreme,
char **temp, int i);
int					free_all_stuff(int ret, t_map *map, t_data *data,
int aftercubparse);
int					free_boundy(int ret, char **boundy, int max, char *msg);
int					free_data(int ret, t_data *data);
int					free_msg_once(int ret, char *msg, void **to_free,
void **to_free2);
void				*free_msg_nl(void *ret, char *msg, void **to_free,
void **to_free2);
int					free_player(int ret, t_player *player, char *msg);
void				free_treenode(t_node **node, t_data *data);
void				*free_xtreme(void *ret, char *msg, int can_do);
char				**get_all_boundy(int y, int *max,
char **xtreme, int boundend);
int					get_col_nbmax(char **number, int lin, int *nbcuby);
int					get_col_nbmin(char **number, int lin, int *nbcuby);
int					get_cub(t_map *map, t_player *player, t_data data, int i);
int					get_line_nbmax(char **number, int col);
int					get_line_nbmin(char **number, int col);
int					get_location(int moving_side);
int					get_nbcuby(t_map *map, int xmax, int nblin);
int					get_next_free(char *line, t_data *data, char *msg, int ret);
t_polygon			get_polygon(t_polygon polygon);
int					get_reslen(char *line);
char				*get_xtreme(int x, int y);
int					get_xtreme_location(int x, int y);
int					get_xtreme_x(char *xtreme);
int					get_xtreme_y(char *xtreme);
int					get_nbxcharmax(int *nbcuby);
int					get_nbxmax(char **number);
int					get_nbymax(int *nbcuby);
t_player			get_player(int x, int z, int c, t_data data);
int					get_side(t_polygon poly1, t_polygon poly2);
void				grow_wall(t_data *data, t_wall *wall);
int					getside(int y, char *xtreme, int oldside);
int					init4drawing(t_data *data, t_player player,
t_polygon *polygon, int i);
void				initbe4display(t_wall *wall, int *countcol,
t_data *data);
t_map				initmap(t_data *data, t_player *player,
char **av, int ac);
void				init_getside(int *coor, int *ycop, int *side,
int *static_outside);
int					init_recover_xtreme(char ***xtreme, int *icop,
int *coor, int location);
int					is_boundaries(int x, int y);
int					is_convex_set(t_polygon *set, t_node *node);
int					is_outside_xboundaries(int y, t_map map);
int					is_rlly_btwn(int y, char **boundx, int max);
int					is_surrounded(t_map map);
int					iserror(t_polygon *polygon, int counter);
t_polygon			*malloc_backset_child(t_polygon *nodeset,
t_polygon splitter);
t_polygon			*malloc_frontset_child(t_polygon *nodeset,
t_polygon splitter);
void				move_backward(t_player *player);
void				move_forward(t_player *player);
void				move_left(t_player *player);
void				move_right(t_player *player);
int					moving_top(char **number, int *coor,
int *fakecoor, int *nbcuby);
int					moving_right(char **number, int *coor, int *fakecoor);
int					moving_bot(char **number, int *coor,
int *fakecoor, int *nbcuby);
int					moving_left(char **number, int *coor, int *fakecoor);
int					offset_ptrcub(t_map *map, int nblin, int xmax);
int					parse_elements(t_data *data, int fd);
int					parse_poly(t_map *map, t_data data);
void				partition_backset(t_polygon *frontset, t_polygon *backset,
t_point p, t_polygon poly);
void				partition_frontset(t_polygon *frontset, t_polygon *backset,
t_point p, t_polygon poly);
int					polysetlen(t_polygon *set);
t_map				putstrret_fd(char *str, t_map map, int fd);
int					raycastfps(t_wall *wall, t_player player,
t_polygon polygon, t_data data);
int					raycastfpsobj(t_object *object,
t_player player, t_data data);
int					raycastx(t_wall *wall, t_polygon *polygon,
t_data data, t_segment *segment);
int					raycastx_img(t_player player, t_polygon *polygon,
t_segment segment);
int					raycastxobj(t_object *object, t_data data, t_player player);
char				**recover_xtreme(int *coor, int *end, int location);
int					remind(int x, int y);
void				renderbsp(t_data *data, t_node current, t_player player);
void				renderobjects(t_data *data, t_player player, t_map map);
void				replace_poly(t_polygon *polygon, t_player player);
void				replace_obj(t_object *object, t_player player);
void				reset_data(t_data *data);
int					searching_around(t_map *map, int *coor, int moving_side);
char				**set_boundy(char **boundy, int *k, char **xtreme, int i);
int					set_color_value(t_data *data, char *line, char *letters);
void				set_cub(t_data data, t_cub *cub, int i, int counter);
int					set_obj(t_data data, t_map *map, int i, int counter);
int					set_oldlocation(int *oldlocation, int location,
int condition);
void				set_delta(t_wall *wall);
void				set_north_wall(t_wall *wall, t_segment left,
t_segment right);
void				set_player_angle(t_player *player, double angle);
void				set_player_pos(t_player *player, double x, double z);
int					set_resolution(t_data *data, char *line, char *c);
int					set_texture(t_data *data, char *line, char *orientation);
void				set_used_poly(t_polygon *set, t_polygon *current);
int					start_from_down(int *coor, int *side,
int *static_outside, int oldside);
int					start_from_up(int *coor, int *side,
int *static_outside, int oldside);
void				sort_table_y(char **table, int max);
void				split_polygon(t_polygon poly, t_polygon splitter,
t_polygon *frontset, t_polygon *backset);
int					try_moving_top(char **number, int *nbcuby,
int *col, int *lin);
void				turn_left(t_player *player);
void				turn_right(t_player *player);
int					verify_end(int fd);
char				***xtreme_addr(char ***xtreme, int *end);
char				**xtreme_sorted_y(int y, int *max);

#endif
