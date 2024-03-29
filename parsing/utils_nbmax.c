/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:59:52 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/17 16:01:25 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		get_nbxcharmax(int *nbcuby)
{
	int	counter;

	counter = 0;
	while (nbcuby[counter] != -1)
		counter++;
	return (counter);
}

int		get_nbxmax(char **number)
{
	unsigned int	max;
	int				y;
	char			*str;

	y = -1;
	max = 0;
	while (number[++y])
	{
		str = ft_strtrim(number[y], " ");
		if (max < ft_strlen(str))
			max = ft_strlen(str);
		free(str);
	}
	return (max);
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
