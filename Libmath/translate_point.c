/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:22:54 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/10 11:24:09 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

int	translate_point(t_point *point, int x, int y) // si le point en x ou en y fais faire un overflow on renvoie un chiffre d'erreur
{
	point->x += x;
	point->y += y;
	return (1);
}
