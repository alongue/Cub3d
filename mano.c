/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:12:43 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/10 13:18:28 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

int		main()
{
	t_point		a;
	t_point		b; //mettre les points en float a mon avis
	t_point		*acop;
	t_point		*bcop;
	t_segment	s;

	s = get_segmenti(10, 20, 30, 40);
	get_extremity(s, &a, &b);
	printf("a.y = %d\tet\ta.x =%d\nb.y = %d\tet\tb.x = %d\n", a.y, a.x, b.y, b.x);
	acop = &a;
	bcop = &b;
	if (a.y < b.y)
	{
		printf("je suis rentre\n");
		ft_swap((void *)&acop, (void *)&bcop);
		a = dup_point(*acop);
		b = dup_point(*bcop);
	}
	printf("a.y = %d\tet\ta.x =%d\nb.y = %d\tet\tb.x = %d\n", a.y, a.x, b.y, b.x);
}
