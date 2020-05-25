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

#define NBELEM 8

int     set_resolution(t_data *data, char *line)
{
    int i;
    int oldi;

    i = get_first_char(line);
    oldi = i;
    i++;
    while (line[i] == ' ')
        i++;
    if (i == oldi + 1)
        return (ft_putstrreti_fd("Error\nMettez un espace (ID et resolution X)\n", 0, 0));
    if ((data->win_width = ft_atoi(&line[i])) > 2560)
        data->win_width = 2560;
    i++;
    while (line[i] == ' ')
        i++;
    if (i == oldi + 1)
        return (ft_putstrreti_fd("Error\nMettez un espace (resolution X et Y)\n", 0, 0));
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
    printf("line a partir du %de caractere -> %s\n", i, &line[i]);
    oldi = i;
    while (line[i] != ' ')
        i++;
    printf("line a partir du %de caractere -> %s\n", i, &line[i]);
    while (line[i] == ' ')
        i++;
    if (i == oldi + 1)
        return (ft_putstrreti_fd("Error\nMettez un espace (textures)\n", 0, 0));
    if (orientation == 'N')
    {
        if (data->texnorth != NULL)
            return (ft_putstrreti_fd("Error\nnorth texture is written too many times\n", 0, 0));
        data->texnorth = ft_substr(line, i, ft_strlen(line)); //renvoyer erreur si c'est n'importe quoi
    }
    if (orientation == 'S')
    {
        if (data->texsouth != NULL)
            return (ft_putstrreti_fd("Error\nsouth texture is written too many times\n", 0, 0));
        data->texsouth = ft_substr(line, i, ft_strlen(line));
    }
    if (orientation == 'W')
    {
        if (data->texwest != NULL)
            return (ft_putstrreti_fd("Error\nwest texture is written too many times\n", 0, 0));
        data->texwest = ft_substr(line, i, ft_strlen(line));
    }
    if (orientation == 'E')
    {
        if (data->texeast != NULL)
            return (ft_putstrreti_fd("Error\neast texture is written too many times\n", 0, 0));
        data->texeast = ft_substr(line, i, ft_strlen(line));
    }
    if (orientation == 's')
    {
        printf("data->srpie = %s\n", data->sprite);
        sleep(1);
        if (data->sprite != NULL)
            return (ft_putstrreti_fd("Error\nsprite texture is written too many times\n", 0, 0));
        data->sprite = ft_substr(line, i, ft_strlen(line));
    }
    return (1);
}

int     set_color_value(t_data *data, char *line, char letter)
{
    int i;
    int oldi;

    i = get_first_char(line);
    oldi = i;
    i++;
    while (line[i] == ' ')
        i++;
    printf("line[i] = %c\n", line[i]);
    if (i == oldi + 1)
        return (ft_putstrreti_fd("Error\nMettez un espace (sol, plafonds)\n", 0, 0));
    if (letter == 'F')
    {
        if (data->colfloor != (unsigned int)-1)
            return (ft_putstrreti_fd("Error\nLa couleur du sol a ete mise plusieurs fois\n", 0, 0));
        if ((data->colfloor = convert_color(&line[i])) == (unsigned int)-1)
            return (ft_putstrreti_fd("Error\nVerifiez les couleurs\n", 0, 0));
        printf("data->colfloor = %#x\n", data->colfloor);
    }
    else if (letter == 'C')
    {
        if (data->colceil != (unsigned int)-1)
            return (ft_putstrreti_fd("Error\nLa couleur du plafond a ete mise plusieurs fois\n", 0, 0));
        if ((data->colceil = convert_color(&line[i])) == (unsigned int)-1)
            return (ft_putstrreti_fd("Error\nVerifiez les couleurs\n", 0, 0));
        printf("data->colceil = %#x\n", data->colceil);
        //sleep(2);
    }
    return (1);
}



int     set_color(t_data *data, char *line)
{
    int i;
    int counter;

    counter = 0;
    i = get_first_char(line);
    if (line[i] == 'R' && ++counter < NBELEM) // faut pas que un de tout ca y soit 2 fois
    {
        if (!set_resolution(data, line))
            return (0);
    }
    else if (line[i] == 'N' && line[i + 1] == 'O' && ++counter < NBELEM)
    {
        if (!set_texture(data, line, 'N'))
            return (0);
    }
    else if (line[i] == 'S' && line[i + 1] == 'O' && ++counter < NBELEM)
    {
        if (!set_texture(data, line, 'S'))
            return (0);
    }
    else if (line[i] == 'W' && line[i + 1] == 'E' && ++counter < NBELEM)
    {
        if (!set_texture(data, line, 'W'))
            return (0);
    }
    else if (line[i] == 'E' && line[i + 1] == 'A' && ++counter < NBELEM)
    {
        if (!set_texture(data, line, 'E'))
            return (0);
    }
    else if (line[i] == 'S' && ++counter < NBELEM) // on a deja verifier si y avait un 'O' apres
    {
        if (!set_texture(data, line, 's'))
            return (0);
    }
    else if (line[i] == 'F' && ++counter < NBELEM)
    {
        if (!set_color_value(data, line, 'F'))
            return (0);
    }
    else if (line[i] == 'C' && ++counter < NBELEM)
    {
        if (!set_color_value(data, line, 'C'))
            return (0);
    }
    else
        return (ft_putstrreti_fd("Error\nVeuillez verifier ce que vous avez marquer\n", 0, 0));
    return (counter);
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
    int     counter[3];

    (void)map;
    newfd = open(data->filename, O_RDONLY);
    ft_memseti(counter, 0, 3);
    while ((ret = get_next_line(newfd, &line)) == 1 &&
    (ft_isalpha(line[get_first_char(line)]) || ft_strncmp(line, "", 1) == 0))
    {
        if (ft_strncmp(line, "", 1) != 0)
        {
            counter[1] = counter[0];
            counter[0] += set_color(data, line);
            if (counter[1] == counter[0])
                return(0);
            printf("counter elements = %d\n", counter[0]);
            counter[2]++;
            free(line);
        }
        else
            counter[2]++;
    }
	if (ret == -1)
		return (ft_putstrreti_fd("Error\nVeuillez verifiez le fichier\n", 0, 0));
    if (counter[0] != NBELEM)
        return (ft_putstrreti_fd("Error\nVeuillez verifier le nombre d'elements\n", 0, 0));
    while (ret != 0)
    {
        ret = get_next_line(newfd, &line);
        free(line);
    }
    while (--counter[2] >= 0)
    {
        get_next_line(fd, &line);
        printf("line -> %s\n", line);
        free(line);
    }
    printf("fd = %d et newfd = %d\n", fd, newfd);
    sleep(2);
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