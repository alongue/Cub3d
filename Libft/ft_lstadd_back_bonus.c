/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:16:41 by alongcha          #+#    #+#             */
/*   Updated: 2019/11/13 19:09:32 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	new->next = NULL;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	while ((*alst)->next != NULL)
	{
		*alst = (*alst)->next;
	}
	(*alst)->next = new;
}
