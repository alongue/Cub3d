/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:44:34 by alongcha          #+#    #+#             */
/*   Updated: 2019/11/11 22:13:43 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int	ncop;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ncop = -n;
	}
	else
		ncop = n;
	if (ncop <= 9)
	{
		ft_putchar_fd(ncop + '0', fd);
	}
	if (ncop > 9)
	{
		ft_putnbr_fd(ncop / 10, fd);
		ft_putchar_fd((ncop % 10) + '0', fd);
	}
}
