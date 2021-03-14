/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:22:34 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 21:17:28 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void *ptr, size_t size)
{
	void	*ptrcop;

	if (size == 0)
		return (NULL);
	if (!(ptrcop = malloc(size)))
		return (NULL);
	if (ptr != NULL)
		ft_memcpy(ptrcop, ptr, size);
	free(ptr);
	return (ptrcop);
}
