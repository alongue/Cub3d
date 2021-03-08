/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appendstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:27:33 by alongcha          #+#    #+#             */
/*   Updated: 2019/12/09 22:06:22 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_appendstr(char* s, char c) {
    int len;

    if (!s)
        return (NULL);
    len = ft_strlen(s);
    s = ft_realloc(s, len + 2);
    s[len] = c;
    s[len + 1] = '\0';
    return (s);
}