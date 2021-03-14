/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_extremity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:08:44 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 22:33:21 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

int		get_extremity(t_segment segment, t_point *first, t_point *end)
{
	*first = dup_point(segment.a);
	*end = dup_point(segment.b);
	return (1);
}
