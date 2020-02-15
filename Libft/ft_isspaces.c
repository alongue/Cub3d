/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:11:25 by alongcha          #+#    #+#             */
/*   Updated: 2019/11/28 21:18:42 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspaces(const char *str)
{
	int	i;
	int	counter;

	i = -1;
	counter = 0;
	if (str == NULL)
		return (-1);
	while (str[++i])
	{
		if (ft_isspace(str[i]))
			counter++;
	}
	return (counter);
}
