/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:16:53 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/17 15:36:12 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/* il est logiquement necessaire de mettre a jour les coordonnees verticales des extr􏰀emites du mur. Mais comme nous avons dit que nous conservions particulierement les coordonnees verticales seulement du debut du mur􏰋les coordonnees verticales des tranches suivantes etant calculees incrementalement grace aux deltas que nous avons calcul􏰀es ci􏰂dessus􏰋 nous n'aurons a nous soucier que de mettre􏰐a jour les coordonnees verticales du debut du mur */
void	clip(t_wall *wall)
{
	wall->leftcl.p.x = (wall->left.p.x > 319) ? 319 : wall->left.p.x;
	if (wall->left.p.x < 0)
	{
		wall->leftcl.p.x = 0;
		wall->top -= (double)wall->leftcl.p.x * wall->deltatop;
		wall->bot -= (double)wall->leftcl.p.y * wall->deltabot;
	}
	wall->rightcl.p.x = wall->right.p.x;
}


