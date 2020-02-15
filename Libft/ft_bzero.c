/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:19:19 by alongcha          #+#    #+#             */
/*   Updated: 2019/11/11 22:00:13 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*scop;
	size_t	counter;

	counter = 0;
	scop = (char *)s;
	while (counter != n)
	{
		*scop = 0;
		scop++;
		counter++;
	}
}
