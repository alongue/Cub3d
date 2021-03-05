/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isonlychar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:14:17 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/08 12:38:11 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isonlychar(const char *main_str, const char *str)
{
	int	i;

	i = -1;
	if (!main_str)
		return (0);
	while (main_str[++i])
	{
		if (ft_get_nbchar(str, main_str[i]) == 0)
			return (0);
	}
	return (1);
}
