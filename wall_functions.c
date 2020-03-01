/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:16:53 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/01 15:03:02 by alongcha         ###   ########.fr       */
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
	wall->rightcl.a.x = min(wall->rightcl.a.x, 319);
	if (wall->leftcl.a.x < 0)
	{
		wall->leftcl.a.x = 0;
		wall->top -= (double)wall->leftcl.a.x * wall->deltatop;
		wall->bot -= (double)wall->leftcl.a.y * wall->deltabot;
	}
}

void	initbe4display(t_wall *wall, int *countcol, t_data *data)
{
	wall->img = mlx_new_image(data->mlx_ptr, wall->realside, wall->realside);
	wall->img_data = (int *)mlx_get_data_addr(wall->img, &wall->bpp, &wall->size_line, &wall->endian);
	clip(wall);
	*countcol = wall->rightcl.a.x - 1;
	wall->nbcoldone = 0;
}

void	set_delta(t_wall *wall)
{
	wall->deltatop = (wall->newright.a.y - wall->newleft.a.y) / (wall->newright.a.x - wall->newleft.a.x);
	wall->deltatop = (wall->newright.b.y - wall->newleft.b.y) / (wall->newright.a.x - wall->newleft.a.x);
}
