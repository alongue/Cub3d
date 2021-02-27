/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:21:47 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/12 16:21:37 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		tosave(char **av, int ac)
{
	if (ac == 3 && ft_strncmp(av[2], "--save", ft_strlen(av[2])) == 0)
		return (1);
	return (0);
}

int		create_data(t_data *data, char **av, int ac)
{
	data->nbcoldone = 0;
	//vscode printf("(avant ptr)\n");
	if ((data->ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	data->ac = ac;
	data->tosave = tosave(av, ac);
	if (ac < 2 || ac > 3 || (ac == 3 && !data->tosave))
		return (EXIT_FAILURE);
	//vscode printf("av[1] (avant window) = %s\n", av[1]);
	mlx_get_screen_size(data->ptr, &data->win_width, &data->win_height);
	data->colceil = (unsigned int)-1; //avec les 3 valeurs max on attendra jamais unsigned int max
	data->colfloor = (unsigned int)-1;
	data->texnorth = NULL;
	data->texsouth = NULL;
	data->texeast = NULL;
	data->texwest = NULL;
	data->sprite = NULL;
	if (!(data->coldone = malloc(sizeof(int) * data->win_width)))
		return (EXIT_FAILURE);
	if (!(data->heightcol = malloc(sizeof(double) * data->win_width)))
		return (EXIT_FAILURE);
	data->filename = ft_strdup(av[1]);
	////vscode printf("data->coldone = %p\tet\tdata->heightcol = %p\n", &data->coldone, &data->heightcol);
	////vscode printf("data->win_width = %p\tet\tdata->win_height = %p\n", &data->win_width, &data->win_height);
	////vscode printf("data = %p\tet\tdata->window = %p\tet\tdata->ptr = %p\n", &data, &data->window, &data->ptr);
	data->cubside = 64;
	return (EXIT_SUCCESS);
}

void	reset_data(t_data *data)
{
	//int	x;
	//int	y;

	data->coldone = ft_memseti(data->coldone, 0, data->win_width);
	data->heightcol = ft_memseti(data->heightcol, 0, data->win_width);
	/*x = -1;
	y = -1;
	while (++y < data->win_height)
	{
		x = -1;
		while (++x < data->win_width)
			data->img_data[y * data->win_width + x] = 0x000000;
	}*/
	data->nbcoldone = 0;
	display_ceilfloor(data);
}

int		free_elements(t_data data, t_tree tree, t_map map)
{
	(void)data;
	(void)tree;
	(void)map;
	return (0);
}
