/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 14:31:27 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/08 17:16:54 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libmath.h"

# include <stdio.h>

int		main()
{
	t_point		p;
	t_segment	segment;

	segment = get_segmenti(576, 255, 576, 193);
	//p.x = min(segment.a.x, segment.b.x) + 5;
	//vscode printf("segment.intercept = %f\n", segment.intercept);
	p.x = min(segment.a.x, segment.b.x);
	set_point_on_segx(segment, &p);
	//vscode printf("p.x = %d\tet\tp.y = %d\n", p.x, p.y);
	get_next_point(segment, &p);
	//vscode printf("p.x = %d\tet\tp.y = %d\n", p.x, p.y);
}
