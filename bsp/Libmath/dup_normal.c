/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:51:54 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/02 16:53:52 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_normal	dup_normal(t_normal normal)
{
	t_normal	n;

	n.xlen = normal.xlen;
	n.ylen = normal.ylen;
	return (n);
}
