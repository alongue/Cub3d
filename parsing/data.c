/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:21:47 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 20:12:13 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		create_data(t_data *data, char **av, int ac)
{
	data->ptr = NULL;
	data->nbcoldone = 0;
	data->ac = ac;
	data->tosave = (ac == 3 && ft_strncmp(av[2], "--save",
	ft_strlen(av[2])) == 0) ? 1 : 0;
	if (ac < 2 || ac > 3 || (ac == 3 && !data->tosave))
		return (ft_putstrreti_fd(ARGUMENTS, EXIT_FAILURE, STDOUT_FILENO));
	if (!(data->ptr = mlx_init()))
		return (ft_putstrreti_fd(MALLOC, EXIT_FAILURE, STDOUT_FILENO));
	mlx_get_screen_size(data->ptr, &data->win_width, &data->win_height);
	data->window = NULL;
	data->img = NULL;
	data->img_data = NULL;
	data->colceil = (unsigned int)-1;
	data->colfloor = (unsigned int)-1;
	data->texnorth = NULL;
	data->texsouth = NULL;
	data->texeast = NULL;
	data->texwest = NULL;
	data->sprite = NULL;
	if (data_malloc(data, av) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	data->cubside = 64;
	return (EXIT_SUCCESS);
}

int		data_malloc(t_data *data, char **av)
{
	data->coldone = NULL;
	data->heightcol = NULL;
	data->filename = NULL;
	if (!(data->coldone = malloc(sizeof(int) * data->win_width)))
	{
		return (free_data(ft_putstrreti_fd(MALLOC, EXIT_FAILURE,
		STDOUT_FILENO), data));
	}
	if (!(data->heightcol = malloc(sizeof(double) * data->win_width)))
	{
		return (free_data(ft_putstrreti_fd(MALLOC, EXIT_FAILURE,
		STDOUT_FILENO), data));
	}
	if (!(data->filename = ft_strdup(av[1])))
	{
		return (free_data(ft_putstrreti_fd(MALLOC,
		EXIT_FAILURE, STDOUT_FILENO), data));
	}
	return (EXIT_SUCCESS);
}

void	reset_data(t_data *data)
{
	data->coldone = ft_memseti(data->coldone, 0, data->win_width);
	data->heightcol = ft_memseti(data->heightcol, 0, data->win_width);
	data->nbcoldone = 0;
	display_ceilfloor(data);
}
