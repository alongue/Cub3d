/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:09:03 by alongcha          #+#    #+#             */
/*   Updated: 2019/11/15 17:09:13 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*elem;
	t_list	*first;

	if (!lst || !f)
		return (NULL);
	first = ft_lstnew(f(lst));
	elem = first;
	while (lst->next != NULL)
	{
		lst = lst->next;
		elem->next = ft_lstnew(f(lst));
		if (!(elem->next))
		{
			del(elem->next);
			free(elem->next);
			return (NULL);
		}
		elem = elem->next;
	}
	return (first);
}
