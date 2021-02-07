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

int     set_resolution(t_data *data, char *line, char *c)
{
    int i;
    int oldi;
    int max[2];

    (void)c;
    i = get_first_char(line);
    oldi = i;
    i++;
    while (line[i] == ' ')
        i++;
    if (i == oldi + 1)
        return (ft_putstrreti_fd("Error\nMettez un espace (ID et resolution X)\n", 0, 0));
    printf("(avant) data->win_width = %d\tet\tdata->win_height = %d\n", data->win_width, data->win_height);
    max[0] = data->win_width;
    data->win_width = (ft_atoi(&line[i]) < 1) ? data->win_width : ft_atoi(&line[i]);
    data->win_width = (data->win_width < max[0]) ? data->win_width : max[0];
    i += ft_intlen(ft_atoi(&line[i]));
    while (line[i] == ' ')
        i++;
    max[1] = data->win_height;
    data->win_height = (ft_atoi(&line[i]) < 1) ? data->win_height : ft_atoi(&line[i]);
    printf("(apres) data->win_width = %d\tet\tdata->win_height = %d\n", data->win_width, data->win_height);
    data->win_height = (data->win_height < max[1]) ? data->win_height : max[1];
    printf("data->win_width = %d\tet\tdata->win_height = %d\n", data->win_width, data->win_height);
	data->img = mlx_new_image(data->ptr, data->win_width, data->win_height);
	data->img_data = (int *)mlx_get_data_addr(data->img, &data->bpp, &data->size_line, &data->endian);
    return (1);
}

int     set_texture(t_data *data, char *line, char *orientation)
{
    int i;
    int oldi;

    printf("orientation = %s\n", orientation);
    i = get_first_char(line);
    //vscode printf("line a partir du %de caractere -> %s\n", i, &line[i]);
    oldi = i;
    while (line[i] != ' ')
        i++;
    //vscode printf("line a partir du %de caractere -> %s\n", i, &line[i]);
    while (line[i] == ' ')
        i++;
    //vscode printf("line a partir du %de caractere -> %s\n", i, &line[i]);
    if (i == oldi + 1)
        return (ft_putstrreti_fd("Error\nMettez un espace (textures)\n", 0, 0));
    if (orientation[0] == 'N')
    {
        if (data->texnorth != NULL)
            return (ft_putstrreti_fd("Error\nnorth texture is written too many times\n", 0, 0));
        data->texnorth = ft_substr(line, i, INT_MAX); //renvoyer erreur si c'est n'importe quoi
        ////vscode printf("data->texnorth = %s\n", data->texnorth);
        ////vscode sleep(1);
    }
    else if (orientation[0] == 'S' && orientation[1] == 'O')
    {
        if (data->texsouth != NULL)
            return (ft_putstrreti_fd("Error\nsouth texture is written too many times\n", 0, 0));
        data->texsouth = ft_substr(line, i, INT_MAX);
        ////vscode printf("data->texsouth = %s\n", data->texsouth);
        ////vscode sleep(1);
    }
    else if (orientation[0] == 'W')
    {
        if (data->texwest != NULL)
            return (ft_putstrreti_fd("Error\nwest texture is written too many times\n", 0, 0));
        data->texwest = ft_substr(line, i, INT_MAX);
        ////vscode printf("data->texwest = %s\n", data->texwest);
        ////vscode sleep(1);
    }
    else if (orientation[0] == 'E')
    {
        if (data->texeast != NULL)
            return (ft_putstrreti_fd("Error\neast texture is written too many times\n", 0, 0));
        data->texeast = ft_substr(line, i, INT_MAX);
        ////vscode printf("data->texeast = %s\n", data->texeast);
        ////vscode sleep(1);
    }
    else if (orientation[0] == 'S')
    {
        //vscode printf("data->sprite = %s\n", data->sprite);
        //vscode sleep(1);
        if (data->sprite != NULL)
            return (ft_putstrreti_fd("Error\nsprite texture is written too many times\n", 0, 0));
        data->sprite = ft_substr(line, i, ft_strlen(line));
        ////vscode printf("data->sprite = %s\n", data->sprite);
        ////vscode sleep(1);
    }
    return (1);
}

int     set_color_value(t_data *data, char *line, char *letters)
{
    int i;
    int oldi;

    i = get_first_char(line);
    oldi = i;
    i++;
    while (line[i] == ' ')
        i++;
    //vscode printf("line[i] = %c\n", line[i]);
    if (i == oldi + 1)
        return (ft_putstrreti_fd("Error\nMettez un espace (sol, plafonds)\n", 0, 0));
    if (letters[0] == 'F')
    {
        if (data->colfloor != (unsigned int)-1)
            return (ft_putstrreti_fd("Error\nLa couleur du sol a ete mise plusieurs fois\n", 0, 0));
        if ((data->colfloor = convert_color(&line[i])) == (unsigned int)-1)
            return (ft_putstrreti_fd("Error\nVerifiez les couleurs\n", 0, 0));
        //vscode printf("data->colfloor = %#x\n", data->colfloor);
    }
    else if (letters[0] == 'C')
    {
        if (data->colceil != (unsigned int)-1)
            return (ft_putstrreti_fd("Error\nLa couleur du plafond a ete mise plusieurs fois\n", 0, 0));
        if ((data->colceil = convert_color(&line[i])) == (unsigned int)-1)
            return (ft_putstrreti_fd("Error\nVerifiez les couleurs\n", 0, 0));
        //vscode printf("data->colceil = %#x\n", data->colceil);
        ////vscode sleep(2);
    }
    return (1);
}



int     set_color(t_data *data, char *line)
{
    int     counter;
    char    **parameters;
    char    begline[3];
    int     inc;
    int     (*set_data[3])(t_data *data, char *line, char *letters);
    
    parameters = (char *[9]){"R", "NO", "SO", "WE", "EA", "S", "F", "C", 0};
    set_data[0] = &set_resolution;
    set_data[1] = &set_texture;
    set_data[2] = &set_color_value;
    counter = 0;
    begline[0] = line[0];
    begline[1] = (line[1] == ' ') ? 0 : line[1];
    begline[2] = 0;
    (void)set_data;
    (void)begline;
    (void)parameters;
    inc = -1;
    while (parameters[++inc])
    {
        printf("parameters[inc] = %s\n", parameters[inc]);
        if (ft_strncmp(begline, parameters[inc], ft_strlen(parameters[inc])) == 0 && counter < NBELEM + 1)
        {
            printf("line = %s\tet\tbegline = %s\n", line, begline);
            if (inc == 0)
                return (counter = (!set_data[0](data, line, parameters[inc])) ? 0 : counter + 1);
            else if (inc < 6)
                return (counter = (!set_data[1](data, line, parameters[inc])) ? 0 : counter + 1);
            else if (inc < 9)
                return (counter = (!set_data[2](data, line, parameters[inc])) ? 0 : counter + 1);
        }
    }
    return (ft_putstrreti_fd("Error\nVeuillez verifier le premier caractere de la ligne\n", 0, 0));
    /*
    if (line[i] == 'R' && ++counter < NBELEM) // faut pas que un de tout ca y soit 2 fois
    {
        if (!set_resolution(data, line, 'R'))
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
    */
}

int     get_first_char(char *str) // cherche 1er caractere sans compter espaces
{
    int i;

    i = 0;
    while (str[i] == ' ')
        i++;
    return (i);
}

int     parse_elements(t_data *data, int fd)
{
    int     ret;
    char    *line;
    int     newfd;
    int     counter[3];

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
            //vscode printf("counter elements = %d\n", counter[0]);
            counter[2]++;
            //free(line);
        }
        else
            counter[2]++;
    }
	if (ret == -1)
		return (ft_putstrreti_fd("Error\nVeuillez verifiez le fichier\n", 0, 0));
    if (counter[0] != NBELEM)
        return (ft_putstrreti_fd("Error\nVeuillez verifier le nombre de parametres\n", 0, 0));
    while (ret != 0)
    {
        ret = get_next_line(newfd, &line);
        //free(line);
    }
    while (--counter[2] >= 0)
    {
        get_next_line(fd, &line);
        //vscode printf("line -> %s\n", line);
        //free(line);
    }
    //vscode printf("fd = %d et newfd = %d\n", fd, newfd);
    //vscode sleep(2);
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
