/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:22:34 by alongcha          #+#    #+#             */
/*   Updated: 2019/12/11 20:30:08 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ctos(char c)
{
	char	*temp;

	temp = malloc(sizeof(char) * (1 + 1));
	temp[0] = c;
	temp[1] = 0;
	return (temp);
}
