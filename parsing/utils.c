/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:59:52 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/17 16:01:25 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_map	putstrret_fd(char *str, t_map map, int fd)
{
	ft_putstr_fd(str, fd);
	return (map);
}

void	*ft_realloc(void *ptr, size_t size)
{
	void			*ptrcop;
	size_t			i;

	i = -1;
	if (size == 0)
		return (NULL);
	if (!(ptrcop = malloc(size)))
		return (NULL);
	if (ptr != NULL)
		ft_memcpy(ptrcop, ptr, size);
	return (ptrcop);
}
