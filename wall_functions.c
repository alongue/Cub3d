/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:16:53 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/10 13:45:22 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/* il est logiquement necessaire de mettre a jour les coordonnees verticales des extr􏰀emites du mur. Mais comme nous avons dit que nous conservions particulierement les coordonnees verticales seulement du debut du mur􏰋les coordonnees verticales des tranches suivantes etant calculees incrementalement grace aux deltas que nous avons calcul􏰀es ci􏰂dessus􏰋 nous n'aurons a nous soucier que de mettre􏰐a jour les coordonnees verticales du debut du mur */


/*void			set_dim_north_wall(t_wall *wall, int width, int height) //la valeur x et y du wall precise l'endroit du coin en haut a gauche du wall
{
	//t_wall	wall;

	wall->width = width;
	wall->height = height;
	wall->color = 0xCECECE; //gris
	//return (wall);
}*/


// ------- !!! DEPRECATED !!! ------- 

/*void			set_north_wall(t_wall *wall, t_segment left, t_segment right, unsigned int color) //la valeur x et y du wall precise l'endroit du coin en haut a gauche du wall
{
	//t_wall	wall;

	wall->left = dup_segment(left);
	wall->right = dup_segment(right);
	wall->color = color; //gris
	//return (wall);
}*/

void	clip(t_wall *wall)
{
	printf("--- JE SUIS DANS LE CLIP ---\n");
	wall->rightcl = dup_segment(wall->right);
	wall->rightcl.a.x = min(wall->right.a.x, 319);
	wall->rightcl.b.x = min(wall->right.b.x, 319);
	wall->leftcl = dup_segment(wall->left);
	printf("wall.leftcl.b.y (dans le clip) = %d\n", wall->left.b.y);
	if (wall->leftcl.a.x < 0 || wall->leftcl.b.x < 0)
	{
		wall->top -= (double)wall->leftcl.a.x * wall->deltatop;
		wall->bot -= (double)wall->leftcl.a.x * wall->deltabot;
		wall->leftcl.a.x = 0;
		wall->leftcl.b.x = 0;
	}
}

void	set_delta(t_wall *wall)
{
	//printf("wall->right.a.x = %d\n", wall->right.a.x);
	wall->deltatop = (double)(wall->right.a.y - wall->left.a.y) / (wall->right.a.x - wall->left.a.x);
	wall->deltabot = (double)(wall->right.b.y - wall->left.b.y) / (wall->right.a.x - wall->left.a.x);
	printf("wall->deltatop = %f\tet\twall->deltabot = %f\n", wall->deltatop, wall->deltabot);
}

void	initbe4display(t_wall *wall, int *countcol, t_data *data)
{
	printf("--- JE SUIS DANS LE INIT DISPL ---\n");
	wall->img = mlx_new_image(data->mlx_ptr, wall->realside, wall->realside);
	wall->img_data = (int *)mlx_get_data_addr(wall->img, &wall->bpp, &wall->size_line, &wall->endian);
	clip(wall);
	*countcol = wall->rightcl.a.x - 1;
	wall->nbcoldone = 0;
}
