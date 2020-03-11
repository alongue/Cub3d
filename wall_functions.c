/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:16:53 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/11 18:31:02 by alongcha         ###   ########.fr       */
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
	wall->rightcl.a.x = min(wall->rightcl.a.x, 319);
	wall->rightcl.b.x = min(wall->rightcl.b.x, 319);
	printf("wall.leftcl.b.y (dans le clip) = %d\n", wall->leftcl.b.y);
	if (wall->leftcl.a.x < 0 || wall->leftcl.b.x < 0)
	{
		wall->leftcl.a.x = 0;
		wall->leftcl.b.x = 0;
	}
	wall->top = (double)wall->leftcl.a.y;
	wall->bot = (double)wall->leftcl.b.y;
	printf("wall->top = %f\n", wall->top);
	printf("wall->bot = %f\n", wall->bot);
}

void	set_delta(t_wall *wall)
{
	printf("wall->rightcl.a.y = %d\t\tet\t\twall->leftcl.a.y = %d\n", wall->rightcl.a.y, wall->leftcl.a.y);
	wall->deltatop = (double)(wall->rightcl.a.y - wall->leftcl.a.y) / (wall->rightcl.a.x - wall->leftcl.a.x);
	wall->deltabot = (double)(wall->rightcl.b.y - wall->leftcl.b.y) / (wall->rightcl.a.x - wall->leftcl.a.x);
	printf("wall->deltatop = %f\tet\twall->deltabot = %f\n", wall->deltatop, wall->deltabot);
}

void	initbe4display(t_wall *wall, int *countcol, t_data *data)
{
	int		maxi;

	printf("--- JE SUIS DANS LE INIT DISPL ---\n");
	clip(wall);
	maxi = max(wall->leftcl.b.y - wall->leftcl.a.y, wall->rightcl.b.y - wall->rightcl.a.y);
	printf("wall->rightcl.a.x = %d\tet\twall->leftcl.a.x = %d\n", wall->rightcl.a.x, wall->leftcl.a.x);
	printf("fmin(wall->bot, 200) - fmax(wall->top, 0) = %f\n", fmin(wall->bot, 200) - fmax(wall->top, 0));
	wall->img = mlx_new_image(data->mlx_ptr, wall->rightcl.a.x - wall->leftcl.a.x, fmin(wall->bot, 200) - fmax(wall->top, 0));
	wall->img_data = (int *)mlx_get_data_addr(wall->img, &wall->bpp, &wall->size_line, &wall->endian);
	*countcol = wall->leftcl.a.x - 1;
	wall->nbcoldone = 0;
}
