/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:11:25 by alongcha          #+#    #+#             */
/*   Updated: 2019/12/03 13:29:44 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_get_nbspace(const char *str)
{
	int	i;
	int	counter;

	i = -1;
	counter = 0;
	while (str[++i])
	{
		if (ft_isspace(str[i]))
			counter++;
	}
	return (counter);
}
