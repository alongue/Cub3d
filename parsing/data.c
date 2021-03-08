/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:21:47 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 20:12:13 by erlajoua         ###   ########.fr       */
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
		return (EXIT_FAILURE);
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
	if (!(data->coldone = malloc(sizeof(int) * data->win_width)))
	{
		mlx_destroy_display(data->ptr);
		return (free_data_stuff(ft_putstrreti_fd(MALLOC, EXIT_FAILURE,
		STDOUT_FILENO), data));
	}
	if (!(data->heightcol = malloc(sizeof(double) * data->win_width)))
	{
		mlx_destroy_display(data->ptr);
		return (ft_free_ret(ft_putstrreti_fd(MALLOC, EXIT_FAILURE,
		STDOUT_FILENO), (void **)&data->ptr, (void **)&data->coldone, NULL));
	}
	if (!(data->filename = ft_strdup(av[1])))
	{
		mlx_destroy_display(data->ptr);
		return (ft_free_ret(ft_putstrreti_fd(MALLOC,
		EXIT_FAILURE, STDOUT_FILENO),
		(void **)&data->ptr, (void **)&data->coldone,
		(void **)&data->heightcol));
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

int		free_data_stuff(int ret, t_data *data)
{
	if (!data)
		return (ret);
	ft_free_ret(ret, (void **)&data->filename,
	(void **)&data->window, (void **)&data->texeast);
	if (data->img)
	{
		mlx_destroy_image(data->ptr, data->img);
		data->img = NULL;
	}
	if (data->ptr)
	{
		mlx_destroy_display(data->ptr);
		data->ptr = NULL;
	}
	ft_free_ret(ret, (void **)&data->texnorth, (void **)&data->texsouth,
	(void **)&data->texwest);
	ft_free_ret(ret, (void **)&data->sprite, (void **)&data->coldone,
	(void **)&data->heightcol);
	return (ret);
}

int		free_all_stuff(int ret, t_map *map, t_data *data, int aftercubparse)
{
	int		i;

	if (map)
	{
		i = -1;
		if (map->number)
			while (map->number[++i])
				ft_free_ret(0, (void **)&map->number[i], NULL, NULL);
		i = (aftercubparse) ? -2 : -1;
		if (map->cub)
			while (map->cub[++i])
				ft_free_ret(0, (void **)&map->cub[i], NULL, NULL);
		printf("i = %d\n", i);
		ft_free_ret(ret, (void **)&map->cub, (void **)&map->nbcuby,
		(void **)&map->objects);
		ft_free_ret(ret, (void **)&map->number, NULL, NULL);
	}
	free_data_stuff(ret, data);
	return (ret);
}
