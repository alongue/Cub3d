/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_basel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:14:53 by alongcha          #+#    #+#             */
/*   Updated: 2019/12/04 17:32:25 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_convert_basel(const char *nbr,
const char *base_from, const char *base_to)
{
	return (ft_ltoa_base(ft_atol_base(nbr, base_from), base_to));
}
