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

#include "header.h"

t_map	putstrret_fd(char *str, t_map map, int fd)
{
	ft_putstr_fd(str, fd);
	return (map);
}

int		get_nbxmax(int *nbcuby)
{
	int	counter;

	counter = 0;
	while (nbcuby[counter] != -1)
		counter++;
	return (counter);
}

int		get_nbymax(int *nbcuby)
{
	int	max;
	int	counter;

	max = 0;
	counter = -1;
	while (nbcuby[++counter] != -1)
		max = nbcuby[counter] > max ? nbcuby[counter] : max;
	return (max);
}

void	*ft_realloc(void *ptr, size_t size)
{
	void			*ptrcop;
	size_t			i;

	i = -1;
	if (!ptr || size == 0)
		return (NULL);
	if (!(ptrcop = malloc(size)))
		return (NULL);
	ft_memcpy(ptrcop, ptr, size);
	return (ptrcop);
}
