/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:59:52 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 20:02:51 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_map			putstrret_fd(char *str, t_map map, int fd)
{
	ft_putstr_fd(str, fd);
	return (map);
}

unsigned int	convert_color(char *line)
{
	unsigned int	ret;
	unsigned int	res;
	int				i;
	int				counter;

	counter = -1;
	ret = 0;
	i = 0;
	while (++counter < 3)
	{
		ret *= 256;
		if (!ft_isdigit(line[i]))
			return ((unsigned int)-1);
		res = (unsigned int)ft_atoi(&line[i]);
		i += ft_intlen(ft_atoi(&line[i]));
		if ((counter < 2 && line[i++] != ',') || res > 255)
			return ((unsigned int)-1);
		ret = (counter == 2 && line[i] != 0) ? (unsigned int)-1 : ret + res;
	}
	return (ret);
}
