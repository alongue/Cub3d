/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 23:34:46 by alongcha          #+#    #+#             */
/*   Updated: 2019/12/12 00:59:56 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free_ret(int myret, ...)
{
	va_list	ap;
	void	*ptr;

	va_start(ap, myret);
	while ((ptr = va_arg(ap, void *)) != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
	va_end(ap);
	return (myret);
}
