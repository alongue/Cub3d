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

int     set_resolution(t_data *data, char *line)
{
    int i;
    int oldi;

    i = get_first_char(line);
    oldi = i;
    i++;
    while (line[i] != ' ')
        i++;
    if (i == oldi + 1)
        return (ft_putstrreti_fd("Error\nMettez un espace\n", 0, 0));
    if ((data->win_width = ft_atoi(&line[i])) > 2560)
        data->win_width = 2560;
    i++;
    while (line[i] != ' ')
        i++;
    if (i == oldi + 1)
        return (ft_putstrreti_fd("Error\nMettez un espace\n", 0, 0));
    if ((data->win_height = ft_atoi(&line[i])) > 1440)
        data->win_height = 1440;
    if (data->win_width < 1 || data->win_height < 1)
        return (ft_putstrreti_fd("Error\nVerifiez la taille de l'ecran\n", 0, 0));
    return (1);
}

int     set_texture(t_data *data, char *line, char orientation)
{
    int i;
    int oldi;

    i = get_first_char(line);
    oldi = i;
    i++;
    while (line[i] != ' ')
        i++;
    if (i == oldi + 1)
        return (ft_putstrreti_fd("Error\nMettez un espace\n", 0, 0));
    if (orientation == 'N')
        data->texnorth = ft_substr(line, i, ft_strlen(line)); //renvoyer erreur si c'est n'importe quoi
    if (orientation == 'S')
        data->texnorth = ft_substr(line, i, ft_strlen(line));
    if (orientation == 'W')
        data->texnorth = ft_substr(line, i, ft_strlen(line));
    if (orientation == 'E')
        data->texnorth = ft_substr(line, i, ft_strlen(line));
    if (orientation == 's')
        data->sprite = ft_substr(line, i, ft_strlen(line));
    return (1);
}

int     set_color_value(t_data *data, char *line, char letter)
{
    int i;
    int oldi;

    i = get_first_char(line);
    oldi = i;
    i++;
    while (line[i] != ' ')
        i++;
    if (i == oldi + 1)
        return (ft_putstrreti_fd("Error\nMettez un espace\n", 0, 0));
    if (letter == 'F')
    {
        if ((data->colfloor = convert_color(&line[i])) == (unsigned int)-1)
            return (ft_putstrreti_fd("Error\nVerifiez les couleurs\n", 0, 0));
    }
    else if (letter == 'C')
    {
        if ((data->colceil = convert_color(&line[i])) == (unsigned int)-1)
            return (ft_putstrreti_fd("Error\nVerifiez les couleurs\n", 0, 0));
    }
    return (1);
}



int     set_color(t_data *data, char *line)
{
    int i;

    i = get_first_char(line);
    if (line[i] == 'R') // faut pas que un de tout ca y soit 2 fois
    {
        if (!set_resolution(data, line))
            return (0);
    }
    else if (line[i] == 'N' && line[i] == 'O')
    {
        if (!set_texture(data, line, 'N'))
            return (0);
    }
    else if (line[i] == 'S' && line[i] == 'O')
    {
        if (!set_texture(data, line, 'S'))
            return (0);
    }
    else if (line[i] == 'W' && line[i] == 'E')
    {
        if (!set_texture(data, line, 'W'))
            return (0);
    }
    else if (line[i] == 'E' && line[i] == 'A')
    {
        if (!set_texture(data, line, 'E'))
            return (0);
    }
    else if (line[i] == 'S') // on a deja verifier si y avait un 'O' apres
    {
        if (!set_texture(data, line, 's'))
            return (0);
    }
    else if (line[i] == 'F')
    {
        if (!set_color_value(data, line, 'F'))
            return (0);
    }
    else if (line[i] == 'C')
    {
        if (!set_color_value(data, line, 'C'))
            return (0);
    }
    else
        return (ft_putstrreti_fd("Error\nVeuillez verifier ce que vous avez marquer\n", 0, 0));
    return (1);
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

    (void)map;
    (void)fd;
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
    return (1);
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