/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 17:03:17 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/09 17:03:20 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

#define SPACE_TEX "Error\nMettez un espace (textures)\n"
#define TOO_TIMES "Error\nTexture ecrit trop de fois\n"

int		set_chartex(char **str, char *line, int i)
{
	if (*str != NULL)
		return (ft_putstrreti_fd(TOO_TIMES, 0, STDOUT_FILENO));
	if (!(*str = ft_substr(line, i, INT_MAX)))
		return (ft_putstrreti_fd(MALLOC, 0, STDOUT_FILENO));
	return (1);
}

int		set_texture(t_data *data, char *line, char *orientation)
{
	int i;
	int oldi;

	i = 0;
	oldi = i;
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	if (i == oldi + 1)
		return (ft_putstrreti_fd(SPACE_TEX, 0, STDOUT_FILENO));
	if (orientation[0] == 'N' && set_chartex(&data->texnorth, line, i))
		return (1);
	else if (orientation[0] == 'S' && orientation[1] == 'O'
	&& set_chartex(&data->texsouth, line, i))
		return (1);
	else if (orientation[0] == 'W' && set_chartex(&data->texwest, line, i))
		return (1);
	else if (orientation[0] == 'E' && set_chartex(&data->texeast, line, i))
		return (1);
	else if (orientation[0] == 'S' && orientation[1] == 0 && line[1] == ' '
	&& set_chartex(&data->sprite, line, i))
		return (1);
	return (ft_putstrreti_fd("Error\nVeuillez verifier la ligne des textures\n",
	0, STDOUT_FILENO));
}
