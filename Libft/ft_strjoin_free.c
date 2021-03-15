/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:47:04 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 20:39:15 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *pre, char *suf)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(pre, suf)))
	{
		if (pre == suf)
			free(pre);
		else
		{
			free(pre);
			free(suf);
		}
		return (NULL);
	}
	if (pre == suf)
		free(pre);
	else
	{
		free(pre);
		free(suf);
	}
	return (tmp);
}
