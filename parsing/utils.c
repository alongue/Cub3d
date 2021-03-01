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
	char			*color;

	counter = -1;
	ret = 0;
	i = 0;
	while (++counter < 3)
	{
		ret *= 256;
		color = ft_convert_basel(&line[i], "0123456789", "0123456789abcdef");
		res = (unsigned int)ft_atol_base(color, "0123456789abcdef");
		free(color);
		i += ft_intlen(ft_atoi(&line[i]));
		if ((counter < 2 && line[i++] != ',') || res > 255)
			return ((unsigned int)-1);
		ret = (counter == 2 && line[i] != 0) ? (unsigned int)-1 : ret + res;
	}
	return (ret);
}