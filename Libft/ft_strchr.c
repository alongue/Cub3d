/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:55:26 by alongcha          #+#    #+#             */
/*   Updated: 2019/11/11 22:05:19 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ccop;
	char	*scop;

	ccop = (char)c;
	scop = (char *)s;
	while (*scop != ccop && *scop)
		scop++;
	if (*scop == ccop)
		return (scop);
	else
		return (0);
}
