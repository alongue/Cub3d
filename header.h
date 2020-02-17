/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:07:43 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/17 15:11:09 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "Libft/libft.h"
# include "Libmath/libmath.h"
# include "get_next_line/get_next_line.h"
# include <mlx.h>
# include <fcntl.h>
# include <limits.h>

# define DEFX 320
# define DEFY 200
# define WIDTH 1920
# define HEIGHT 1080
# define FRONT 1
# define BACK 2
# define SPANNING 0

struct				s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		win_width;
	int		win_height;
	char	*file;
};
typedef struct s_data		t_data;

struct				s_wall
{
	int			realside;
	int			bpp;
	int			size_line;
	int			endian;
	t_point		point;
	t_segment	left;
	t_segment	leftcl;
	t_segment	right;
	t_segment	rightcl;
	double		top;
	double		realtop;
	double		bot;
	double		realbot;
	int			deltatop;
	int			deltabot;
	int			color;
	bool		*coldone;
	int			nbcoldone;
	void		*img;
	int			*img_data;
};
typedef struct s_wall		t_wall;

struct				s_cub //ils seront tjrs visualiser du dessus
{
	bool		exist;
	int			x;
	int			y;
	int			side;
	t_segment	stop;
	t_segment	sleft;
	t_segment	sbot;
	t_segment	sright;
	t_wall		wall;
};
typedef struct s_cub		t_cub;

struct				s_polygon // ils seront tjrs visualiser du dessus aussi
{
	t_segment	segment;
	t_normal	normal;
	t_wall		wall;
	bool		isused;
	int			nbwall; //je pense que ce sera utile pour les textures (je pense a redessiner plusieurs fois la texture)
};
typedef struct s_polygon	t_polygon;

struct				s_player
{
	int		x;
	int		y;
	int		z;
	int		fieldvis;
	int		angle;
};
typedef struct s_player		t_player;

struct				s_map
{
	int			nbcubx;
	int			nbcuby;
	//t_polygon	*set;
	t_cub		**cub;
};
typedef struct s_map		t_map;

struct				s_tree
{
	struct s_node		*rootnode;
};
typedef struct s_tree		t_tree;

struct				s_node
{
	t_tree			tree;
	t_polygon		splitter; //a polygon and a splitter at the same time
	struct s_node	*frontchild;
	struct s_node	*backchild;
};
typedef struct s_node		t_node;

int					classify_point(t_polygon polygon, t_point point);
bool				cond_bot(t_map map, int x, int y);
bool				cond_left(t_map map, int x, int y);
bool				cond_right(t_map map, int x, int y);
bool				cond_top(t_map map, int x, int y);
t_polygon			create_polytop(t_cub *main, t_cub *top, t_cub *topleft, t_cub *left);
t_polygon			create_polybot(t_map map, int x, int y);
t_polygon			create_polyleft(t_map map, int x, int y);
t_polygon			create_polyright(t_map map, int x, int y);
t_polygon			create_polytop(t_map map, int x, int y);
int					create_win(t_data *data);
int					display_wall(t_data *data, t_wall wall, t_player *player);
//int					get_width(t_wall wall);
t_map				get_coor(t_data data, t_wall wall);
int					get_side(t_polygon poly1, t_polygon poly2);
void				grow_wall(t_data *data, t_wall *wall);
void				init(t_player *player, t_wall *wall, t_data *data, char **av);
void				initcub(t_cub **cub, t_wall wall);
bool				is_convex_set(t_polygon *set);
int					polysetlen(t_polygon *set);
void				raycast(t_player *player);
void				renderbsp(t_data *data, t_node *current, t_player *player);
void				set_cub(t_cub **cub);
void				set_north_wall(t_wall *wall, int heightleft, int heightright, int x);
void				set_player(t_player *player, int x, int z, int angle);

#endif
