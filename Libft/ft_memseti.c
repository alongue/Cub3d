/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memseti.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:04:45 by alongcha          #+#    #+#             */
/*   Updated: 2019/12/12 03:15:47 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memseti(void *b, int c, size_t len)
{
	size_t	counter;
	int		*bcop;

	counter = 0;
	bcop = (int *)b;
	while (counter != len)
	{
		*bcop = c;
		bcop++;
		counter++;
	}
	return (b);
}
