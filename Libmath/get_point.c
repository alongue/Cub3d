/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 11:46:24 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/16 15:04:00 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_point		*get_point(int x, int y)
{
	t_point *p;

	if (!(p = malloc(sizeof(t_point))))
		return (NULL);
	p.x = x;
	p.y = y;
	return (p);
}
