/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:44:25 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/29 16:24:51 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

int	translate(t_segment *segment, int x, int y) // si le point en x ou en y fais faire un overflow on renvoie un chiffre d'erreur
{
	segment->a.x += x;
	segment->a.y += y;
	segment->b.x += x;
	segment->b.y += y;
}
