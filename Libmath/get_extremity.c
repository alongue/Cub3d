/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_extremity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:08:44 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/10 12:35:52 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

int		get_extremity(t_segment segment, t_point *first, t_point *end)
{
	*first = dup_point(segment.a);
	*end = dup_point(segment.b); //tjrs les cas d'erreurs en mode overflow a gerer
	return (1);
}
