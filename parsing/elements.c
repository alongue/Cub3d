/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:44:56 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/12 16:23:15 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void    set_resolution(t_data *data)
{
    int i;
    int oldi;

    i = get_first_char(line);
    oldi = i;
    i++;
    while (line[i] != ' ')
        i++;
    if (i == oldi + 1)
        ft_putstrreti_fd("Error\nMettez un espace\n", 0, 0);
    if ((data->win_width = ft_atoi(&line[i])) > 2560)
        data->win_width = 2560;
    i++;
    while (line[i] != ' ')
        i++;
    if (i == oldi + 1)
        ft_putstrreti_fd("Error\nMettez un espace\n", 0, 0);
    if ((data->win_height = ft_atoi(&line[i])) > 1440)
        data->win_height = 1440;
}

void    set_texture(t_data *data, char orientation)
{
    int i;
    int oldi;

    i = get_first_char(line);
    oldi = i;
    i++;
    while (line[i] != ' ')
        i++;
    if (i == oldi + 1)
        ft_putstrreti_fd("Error\nMettez un espace\n", 0, 0);
    if (orientation == 'N')
        data->texnorth = ft_substr(line, i, ft_strlen(line)); //renvoyer erreur si c'est n'importe quoi
    if (orientation == 'S')
        data->texnorth = ft_substr(line, i, ft_strlen(line));
    if (orientation == 'W')
        data->texnorth = ft_substr(line, i, ft_strlen(line));
    if (orientation == 'E')
        data->texnorth = ft_substr(line, i, ft_strlen(line));
}





int     set_color(t_data *data, char *line)
{
    int i;

    i = get_first_char(line);
    if (line[i] == 'R') // faut pas que tout ca y soit 2 fois
        set_resolution(data);
    else if (line[i] == 'N' && line[i] == 'O')
        set_texture(data, 'N');
    else if (line[i] == 'S' && line[i] == 'O')
        set_texture(data, 'S');
    else if (line[i] == 'W' && line[i] == 'E')
        set_texture(data, 'W');
    else if (line[i] == 'E' && line[i] == 'A')
        set_texture(data, 'E');
}

int     get_first_char(char *str) // cherche 1er caractere sans compter espaces
{
    int i;

    i = 0;
    while (str[i] == ' ')
        i++;
    return (i);
}

int     parse_elements(t_map *map, t_data *data, int fd)
{
    int     ret;
    char    *line;
    int     newfd;
    int     counter;

    newfd = open(data->filename, O_RDONLY);
    counter = 0;
    while ((ret = get_next_line(newfd, &line)) == 1 &&
    (ft_isalpha(line[get_first_char(line)]) || ft_strncmp(line, "", 1) != 0))
    {
        set_color(data, line);
        counter++;
        free(line);
    }
	if (ret == -1)
		return (ft_putstrreti_fd("Error\nVeuillez verifiez le fichier\n", 0, 0));
}

int     verify_end(int fd)
{
    char    *line;
    int     ret;

    while ((ret = get_next_line(fd, &line)) != -1)
    {
        if (!ft_isonlychar(line, " "))
            return (0);
        if (ret == 0)
            return (1);
    }
    return (0);
}