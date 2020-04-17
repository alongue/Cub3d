/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_segment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:44:25 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/11 15:45:19 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

int	translate_segment(t_segment *segment, float x, float y) // si le point en x ou en y fais faire un overflow on renvoie un chiffre d'erreur
{
	int	ret;

	ret = 1;
	ret = translate_point(&segment->a, x, y);
	ret = translate_point(&segment->b, x, y);
	return (ret);
}
