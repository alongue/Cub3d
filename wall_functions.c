/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:16:53 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/12 16:15:16 by alongcha         ###   ########.fr       */
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

void	clip(t_wall *wall, t_data data)
{
//	//vscode printf("--- JE SUIS DANS LE CLIP ---\n");
	wall->rightcl.a.x = min(wall->rightcl.a.x, data.win_width - 1);
	wall->rightcl.b.x = min(wall->rightcl.b.x, data.win_width - 1);
//	//vscode printf("wall.leftcl.b.y (dans le clip) = %f\n", wall->leftcl.b.y);
	wall->top = (double)wall->leftcl.a.y;
	wall->bot = (double)wall->leftcl.b.y;
	if (wall->leftcl.a.x < 0 || wall->leftcl.b.x < 0)
	{
		wall->top -= (double)(wall->leftcl.a.x * wall->deltatop);
		wall->bot -= (double)(wall->leftcl.a.x * wall->deltabot);
		wall->leftcl.a.x = 0;
		wall->leftcl.b.x = 0;
	}
//	//vscode printf("wall->top = %f\n", wall->top);
//	//vscode printf("wall->bot = %f\n", wall->bot);
}

void	set_delta(t_wall *wall)
{
	////vscode printf("wall->rightcl.a.y = %f\t\tet\t\twall->leftcl.a.y = %f\n", wall->rightcl.a.y, wall->leftcl.a.y);
	wall->deltatop = (wall->rightcl.a.y - wall->leftcl.a.y) / (wall->rightcl.a.x - wall->leftcl.a.x);
	wall->deltabot = (wall->rightcl.b.y - wall->leftcl.b.y) / (wall->rightcl.a.x - wall->leftcl.a.x);
	//wall->deltabot = (double)(wall->rightcl.b.y - wall->leftcl.b.y) / (wall->rightcl.a.x - wall->leftcl.a.x);
	////vscode printf("wall->deltatop = %f\tet\twall->deltabot = %f\n", wall->deltatop, wall->deltabot);
}

void	initbe4display(t_wall *wall, int *countcol, t_data *data)
{
	//int		maxi;

//	//vscode printf("--- JE SUIS DANS LE INIT DISPL ---\n");
	clip(wall, *data);
	//maxi = max(wall->leftcl.b.y - wall->leftcl.a.y, wall->rightcl.b.y - wall->rightcl.a.y);
//	//vscode printf("wall->rightcl.a.x = %f\tet\twall->leftcl.a.x = %f\n", wall->rightcl.a.x, wall->leftcl.a.x);
	//wall->img = mlx_new_image(data->ptr, wall->rightcl.a.x - wall->leftcl.a.x, maxi);
	wall->img_data = (int *)mlx_get_data_addr(data->img, &wall->bpp, &wall->size_line, &wall->endian);
	wall->data_file = (int *)mlx_get_data_addr(wall->img, &wall->bppimg, &wall->size_lineimg, &wall->endianimg);
	*countcol = (int)round(wall->leftcl.a.x) - 1;
}

int	can_draw(t_wall wall, t_data *data, int index)
{
	////vscode printf("wall.bot - wall.top = %f\tet\tdata->heightcol[index] = %f\n", wall.bot - wall.top, data->heightcol[index]);
	if (/*(wall.bot - wall.top >= 0) && */(!data->coldone[index] ||
		wall.bot - wall.top > data->heightcol[index]))
	{
		//data->distcol[index] = min(wall.); min poly.newseg.a.x b.x pour chaque index de ce wall puis on compare avec newpos.x de obj
		data->heightcol[index] = wall.bot - wall.top;
		if (data->coldone[index] == 0)
			data->nbcoldone++;
		return (1);
	}
	else
		return (0);
}
