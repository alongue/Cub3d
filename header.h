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
# include <mlx.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>

# define DEFX 100
# define DEFY 200
# define WIDTH 1920
# define HEIGHT 1080
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

struct				s_data
{
	bool			exist;
	void			*ptr;
	void			*window;
	void			*img;
	int				*img_data; // les infos du mur de l'image
	int				bpp; // blk
	int				size_line; // blk
	int				endian; // blk
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
	int				currentCubIndex[2]; // sert uniquement a parse_poly
	char			*filename;
	int				nbcoldone;
	int				*coldone; // --> a free //booleen pour chaque colonne d'un mur qui a savoir si la colonne a déjà été dessiné
};
typedef struct s_data		t_data;

struct				s_wall //ca concerne les polygones en vue fps uniquement
{
	bool			exist; //check si il existe
	int				bpp; // blk
	int				size_line; // blk
	int				endian; // blk
	int				bppimg; // blk
	int				size_lineimg; // blk
	int				endianimg; // blk
	double			top; //position du sommet haut du segment actuel en y
	double			topcl; //position du sommet haut clipé du segment actuel en y
	double			bot; //position du sommet bas du segment actuel en y
	double			botcl; //position du sommet bas clipé du segment actuel en y
	t_segment		left; // reel segment vertical gauche
	t_segment		leftcl; // reel segment vertical gauche
	t_segment		right; // reel segment vertical droite
	t_segment		rightcl; // reel segment vertical droite
	double			deltatop; // le delta entre le sommet haut du segment gauche et sommet haut du segment droit
	double			deltabot; // le delta entre le sommet bas du segment gauche et sommet bas du segment droit
//	double			pdist;
//	double			btobp;
	unsigned int	color; // la couleur
	void			*img; // l'image du mur
	int				imgwidth;
	int				imgheight;
	int				*img_data; // les infos du mur de l'image
	int				*data_file;
};
typedef struct s_wall		t_wall;

struct				s_cub //ils seront tjrs visualiser du dessus
{
	bool		exist;
	int			x;
	int			y;
	t_segment	stop;
	t_segment	sleft;
	t_segment	sbot;
	t_segment	sright;
	t_wall		wall;
};
typedef struct s_cub		t_cub;

struct				s_polygon // ils seront tjrs visualiser du dessus aussi
{
	bool		exist;
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
	bool		isused;
	bool		dodisplay;
	int			nbwall; //je pense que ce sera utile pour les textures (je pense a redessiner plusieurs fois la texture)
};
typedef struct s_polygon	t_polygon;

struct				s_object
{
	bool		exist;
	int			bpp; // blk
	int			size_line; // blk
	int			endian; // blk
	int			bppimg; // blk
	int			size_lineimg; // blk
	int			endianimg; // blk
	t_point		pos;
	t_point		newpos;
	bool		dodisplay;
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
//	double		depth;
	void		*img;
	int			*img_data;
	int			*data_file;
};
typedef struct s_object		t_object;

struct				s_player
{
	bool	exist;
	t_point	pos;
	int		x;
	int		y;
	int		z;
	float	speed;
	double	sensi;
	double	dfoc;
	double	*angleray;
	double	anglerayy;
	//int		height;
	double	fieldvis; //le champ de vision en radian
	double	angle; //l'angle en radian par rapport a l'axe des abscisses
};
typedef struct s_player		t_player;

struct				s_tree
{
	struct s_node		*rootnode;
};
typedef struct s_tree		t_tree;

struct				s_node
{
	bool			exist;
	t_tree			tree;
	t_polygon		splitter; //a polygon and a splitter at the same time
	t_polygon		*set;
	bool			isleaf;
	struct s_node	*frontchild;
	struct s_node	*backchild;
};
typedef struct s_node		t_node;

struct				s_map
{
	bool		exist;
	int			*nbcuby; //tableau qui indique le nombre de caractere qui a dans une colonne (dernier nb = -1) sans compter les espaces au debut et a la fin
	char		**number; //tous les caracteres de la map
	int			nbobjects; // le nombre d'objets
	//t_polygon	*set;
	int			height;
	int			*parsepos;
	int			*backtrackpos;
	t_cub		**cub; // tous les cub de la map
	int			*lastchar;
	t_object	*objects; // tous les objets de la map
	//int		nbobjects;
	t_tree		tree; // l'arbre de la map
};
typedef struct s_map		t_map;

void				build_tree(t_node *node, t_polygon *set, t_player player, t_data data);
bool				can_draw(t_wall wall, t_data *data, int index);
bool				can_draw_obj(t_object *object, t_data *data, int index);
int					classify_point(t_polygon polygon, t_point point);
void				clip(t_wall *wall, t_data data);
bool				cond_bot(t_map map, int x, int y);
bool				cond_left(t_map map, int x, int y);
bool				cond_right(t_map map, int x, int y);
bool				cond_top(t_map map, int x, int y);
int					create_data(t_data *data, char **av);
t_map				create_map(t_data *data, t_player *player);
t_polygon			create_polybot(t_map map, int *coor, t_data, t_player player);
t_polygon			create_polyleft(t_map map, int *coor, t_data, t_player player);
t_polygon			create_polyright(t_map map, int *coor, t_data, t_player player);
t_polygon			create_polytop(t_map map, int *coor, t_data, t_player player);
int					create_tree_node(t_map *map, t_player player, t_data data);
t_wall				create_wall(t_polygon poly, t_player player, t_data data);
int					display_ceilfloor(t_data data);
int					display_object(t_data *data, t_object object, t_player player);
int					display_wall(t_data *data, t_wall wall, t_polygon polygon, t_player player);
bool				do_display_poly(t_polygon *polygon, t_data data, t_player player);
bool				do_display_obj(t_object *object, t_data data, t_player player);
t_polygon			dup_polygon(t_polygon polygon);
t_wall				dup_wall(t_wall wall);
int					free_elements(t_data data, t_tree tree, t_map map);
void				*ft_realloc(void *ptr, size_t size);
int					get_col_nbmax(char **number, int col, int *nbcuby);
int					get_col_nbmin(char **number, int col);
int					get_line_nbmax(char **number, int lin);
int					get_line_nbmin(char **number, int lin);
int					get_nbxmax(int *nbcuby);
int					get_nbymax(int *nbcuby);
t_player			get_player(int x, int z, int c, t_data data);
int					get_side(t_polygon poly1, t_polygon poly2);
void				grow_wall(t_data *data, t_wall *wall);
void				initbe4display(t_wall *wall, int *countcol, t_data *data);
//void				initcub(t_map *map, int side);
//void				initobj(t_map *map, int side);
bool				is_convex_set(t_polygon *set, t_node *node);
int					is_surrounded(t_map map);
t_polygon			*malloc_backset_child(t_polygon *nodeset, t_polygon splitter);
t_polygon			*malloc_frontset_child(t_polygon *nodeset, t_polygon splitter);
void				move_backward(t_player *player);
void				move_forward(t_player *player);
void				move_left(t_player *player);
void				move_right(t_player *player);
int					moving_top(char **number, int *coor, int *fakecoor);
int					moving_right(char **number, int *coor, int *fakecoor);
int					moving_bot(char **number, int *coor, int *fakecoor, int *nbcuby);
int					moving_left(char **number, int *coor, int *fakecoor);
int					offset_ptrcub(t_map *map, int nblin, int xmax);
int					parse_elements(t_map *map, t_data *data, int fd);
int					parse_poly(t_map *map, t_player player, t_data data);
void				partition_backset(t_polygon *frontset, t_polygon *backset,
t_point p, t_polygon poly);
void				partition_frontset(t_polygon *frontset, t_polygon *backset,
t_point p, t_polygon poly);
int					polysetlen(t_polygon *set);
t_map				putstrret_fd(char *str, t_map map, int fd);
int					raycastfps(t_wall *wall, t_player player, t_polygon polygon, t_data data);
int					raycastfpsobj(t_object *object, t_player player, t_data data);
bool				raycastx(t_wall *wall, t_polygon *polygon, t_data data, t_segment *segment);
bool				raycastxobj(t_object *object, t_data data);//, t_segment *segment);
bool				raycastx_img(t_player player, t_polygon *polygon, t_segment segment);
void				renderbsp(t_data *data, t_node current, t_player player);
void				renderobjects(t_data *data, t_player player, t_map map);
void				replace_poly(t_polygon *polygon, t_player player);
void				replace_obj(t_object *object, t_player player);
void				reset_data(t_data *data);
int					searching_around(t_map *map, int *coor, int moving_side);
void				set_cub(t_data data, t_cub *cub, int i, int counter);
void				set_obj(t_data data, t_map *map, int i, int counter);
void				set_delta(t_wall *wall);
void				set_used_poly(t_polygon *set, t_polygon *current);
void				set_player_angle(t_player *player, double angle);
void				set_player_pos(t_player *player, double x, double z);
void				set_north_wall(t_wall *wall, t_segment left, t_segment right);
void				split_polygon(t_polygon poly, t_polygon splitter,
t_polygon *frontset, t_polygon *backset);
int					try_moving_top(char **number, int *nbcuby, int *col, int *lin);
void				turn_left(t_player *player);
void				turn_right(t_player *player);
int					verify_end(int fd);

#endif
