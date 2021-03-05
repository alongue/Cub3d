/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:22:34 by alongcha          #+#    #+#             */
/*   Updated: 2019/12/11 20:30:08 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void *ptr, size_t size, size_t oldsize, int dofree)
{
	void			*ptrcop;
	if (size == 0)
	{
		if (dofree)
		{
			free(ptr);
			ptr = NULL;
		}
		return (NULL);
	}
	if (!(ptrcop = malloc(size)))
	{
		if (dofree)
		{
			free(ptr);
			ptr = NULL;
		}
		return (NULL);
	}
	if (ptr != NULL)
		ft_memcpy(ptrcop, ptr, oldsize);
	else
		return (NULL);
	free(ptr);
	return (ptrcop);
}
