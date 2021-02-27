/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:44:56 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/12 16:23:15 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	vertical(int fd, t_data *data)
{
	int y;
	int x;
	int hex;

	y = data->win_height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < data->win_width)
		{
			hex = data->img_data[y * data->win_width + x];
			write(fd, &hex, sizeof(int));
			x++;
		}
		y--;
	}
}

void	header_bmp(t_data *data, int fd)
{
	int header_size;
	int nb_plane;
	int i;

	i = 0;
	nb_plane = 1;
	header_size = 40;
	write(fd, &header_size, 4);
	write(fd, &data->win_width, 4);
	write(fd, &data->win_height, 4);
	write(fd, &nb_plane, 2);
	write(fd, &data->bpp, 2);
	while (i < 28)
	{
		write(fd, "\0", 1);
		i++;
	}
}

void	bitmap(t_data *data, t_map *map)
{
	int		fd;
	int		file_size;
	int		begin_file;
	char	*filename;

    (void)map;
	filename = ft_strdup("screen.bmp");
	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
	file_size = 58 + (data->win_width * data->win_height) * 4;
	begin_file = 58;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &begin_file, 4);
	header_bmp(data, fd);
	vertical(fd, data);
	close(fd);
	free(filename);
	//get_next_line(-1, NULL, 0);
	exit(0);
}