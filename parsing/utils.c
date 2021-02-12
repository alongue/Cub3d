/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:59:52 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/17 16:01:25 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_map			putstrret_fd(char *str, t_map map, int fd)
{
	ft_putstr_fd(str, fd);
	return (map);
}

void			*ft_realloc(void *ptr, size_t size)
{
	void			*ptrcop;
	//size_t			i;

	//i = -1;
	if (size == 0)
		return (NULL);
	if (!(ptrcop = malloc(size)))
		return (NULL);
	if (ptr != NULL)
		ft_memcpy(ptrcop, ptr, size);
	return (ptrcop);
}

unsigned int	convert_color(char *line)
{
	unsigned int	ret;
	unsigned int	res;
	int				i;
	int				counter;

	counter = -1;
	ret = 0;
	i = 0;
	printf("&line[i] = %s\n", &line[i]);
	while (++counter < 3)
	{
		ret *= 256;
		res = (unsigned int)ft_atol_base(ft_convert_basel(&line[i], "0123456789", "0123456789abcdef"), "0123456789abcdef");
		////vscode printf("res = \"%s\"\n", ft_convert_basel(&line[i], "0123456789", "0123456789abcdef"));
		////vscode printf("res = %#x\n", res);
		i += ft_intlen(ft_atoi(&line[i]));
		////vscode printf("line[%d] = '%c'\n", i, line[i]);
		////vscode printf("res = %d\n", res);
		if ((counter < 2 && line[i++] != ',') || res > 255)
		{
			printf("counter = %d\tet\tline[%d] = %c\n", counter, i, line[i]);
			return ((unsigned int)-1);
		}
		ret = (counter == 2 && line[i] != 0) ? (unsigned int)-1 : ret + res;
		printf("line = %s\tet\ti = %d\nline[i] = %d\n", line, i, line[i]);
		////vscode sleep(2);
	}
	return (ret);
}