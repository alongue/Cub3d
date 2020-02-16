/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 15:00:53 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/16 15:05:07 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_point		*dup_point(t_point *p)
{
	t_point *point;

	if (!p)
		return (NULL);
	point = get_point(p->x, p->y);
	return (point);
}
