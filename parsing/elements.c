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

int     get_reslen(char *line)
{
    int     counter;

    counter = 1;
    while (*line != '\0' && *line != ' ')
    {
        if (counter > 7)
            return (counter);
      //vscode printf("line = %c\tet\tcounter = %d\n", *line, counter);
        line++;
        counter++;
    }
    return (counter - 1);
}

int     set_resolution(t_data *data, char *line, char *c)
{
    int i;
    int max[2];

    (void)c;
    i = 0;
    while (line[++i] == ' ')
        ;
    if (!ft_isdigit(line[i]) || i == 1)
        return (ft_putstrreti_fd("Error\nMettez au moins un espace (ID et resolution X)\n", 0, STDOUT_FILENO));
    max[0] = data->win_width;
    if (get_reslen(&line[i]) < 7)
    {
        data->win_width = (ft_atoi(&line[i]) < 1) ? data->win_width : ft_atoi(&line[i]);
        data->win_width = (data->win_width < max[0]) ? data->win_width : max[0];
    }
    while (ft_isdigit(line[i]))
        i++;
    while (line[i] == ' ')
        i++;
    if (!ft_isdigit(line[i])) // au cas ou y a une virgule ou autre entre
        return (ft_putstrreti_fd("Error\nMettez au moins un espace (resolution X et resolution Y)\n", 0, STDOUT_FILENO)); // peutetre refaire la technique du oldi
    max[1] = data->win_height;
    if (get_reslen(&line[i]) < 7)
    {
        data->win_height = (ft_atoi(&line[i]) < 1) ? data->win_height : ft_atoi(&line[i]);
        data->win_height = (data->win_height < max[1]) ? data->win_height : max[1];
    }
	if (!(data->img = mlx_new_image(data->ptr, data->win_width, data->win_height)))
        return (ft_putstrreti_fd("Error\nUn malloc n'a pas marche\n", 0, STDOUT_FILENO));
	data->img_data = (int *)mlx_get_data_addr(data->img, &data->bpp, &data->size_line, &data->endian);
    return (1);
}

int     set_texture(t_data *data, char *line, char *orientation)
{
    int i;
    int oldi;

  //vscode printf("orientation = %s\n", orientation);
    i = 0;
  //vscode printf("line a partir du %de caractere -> %s\n", i, &line[i]);
    oldi = i;
    while (line[i] != ' ')
        i++;
  //vscode printf("line a partir du %de caractere -> %s\n", i, &line[i]);
    while (line[i] == ' ')
        i++;
  //vscode printf("line a partir du %de caractere -> %s\n", i, &line[i]);
    if (i == oldi + 1)
        return (ft_putstrreti_fd("Error\nMettez un espace (textures)\n", 0, STDOUT_FILENO));
    if (orientation[0] == 'N')
    {
        if (data->texnorth != NULL)
            return (ft_putstrreti_fd("Error\nnorth texture is written too many times\n", 0, STDOUT_FILENO));
        if (!(data->texnorth = ft_substr(line, i, INT_MAX))) //renvoyer erreur si c'est n'importe quoi
            return (ft_putstrreti_fd("Error\nUn malloc n'a pas fonctionne\n", 0, STDOUT_FILENO));
        //printf("data->texnorth = %s\n", data->texnorth);
        //sleep(1);
    }
    else if (orientation[0] == 'S' && orientation[1] == 'O')
    {
        if (data->texsouth != NULL)
            return (ft_putstrreti_fd("Error\nsouth texture is written too many times\n", 0, 0));
        if (!(data->texsouth = ft_substr(line, i, INT_MAX)))
            return (ft_putstrreti_fd("Error\nUn malloc n'a pas fonctionne\n", 0, STDOUT_FILENO));
        //printf("data->texsouth = %s\n", data->texsouth);
        //sleep(1);
    }
    else if (orientation[0] == 'W')
    {
        if (data->texwest != NULL)
            return (ft_putstrreti_fd("Error\nwest texture is written too many times\n", 0, 0));
        if (!(data->texwest = ft_substr(line, i, INT_MAX)))
            return (ft_putstrreti_fd("Error\nUn malloc n'a pas fonctionne\n", 0, STDOUT_FILENO));
        //printf("data->texwest = %s\n", data->texwest);
        //sleep(1);
    }
    else if (orientation[0] == 'E')
    {
        if (data->texeast != NULL)
            return (ft_putstrreti_fd("Error\neast texture is written too many times\n", 0, 0));
        if (!(data->texeast = ft_substr(line, i, INT_MAX)))
            return (ft_putstrreti_fd("Error\nUn malloc n'a pas fonctionne\n", 0, STDOUT_FILENO));
        //printf("data->texeast = %s\n", data->texeast);
        //sleep(1);
    }
    else if (orientation[0] == 'S')
    {
      //vscode printf("data->sprite = %s\n", data->sprite);
        //sleep(1);
        if (data->sprite != NULL)
            return (ft_putstrreti_fd("Error\nsprite texture is written too many times\n", 0, 0));
        if (!(data->sprite = ft_substr(line, i, ft_strlen(line))))
            return (ft_putstrreti_fd("Error\nUn malloc n'a pas fonctionne\n", 0, STDOUT_FILENO));
        //printf("data->sprite = %s\n", data->sprite);
        //sleep(1);
    }
    return (1);
}

int     set_color_value(t_data *data, char *line, char *letters)
{
    int i;

    i = 0;
    while (line[++i] == ' ')
        ;
    if (!ft_isdigit(line[i]) || i == 1)
        return (ft_putstrreti_fd("Error\nMettez au moins un espace (sol ou plafond)\n", 0, 0));
    if (letters[0] == 'F')
    {
        if (data->colfloor != (unsigned int)-1)
            return (ft_putstrreti_fd("Error\nLa couleur du sol a ete mise plusieurs fois\n", 0, 0));
        if ((data->colfloor = convert_color(&line[i])) == (unsigned int)-1)
            return (ft_putstrreti_fd("Error\nVerifiez les couleurs du floor, bon format : 255,255,255\n", 0, 0));
      //vscode printf("data->colfloor = %#x\n", data->colfloor);
    }
    else if (letters[0] == 'C')
    {
        if (data->colceil != (unsigned int)-1)
            return (ft_putstrreti_fd("Error\nLa couleur du plafond a ete mise plusieurs fois\n", 0, 0));
        if ((data->colceil = convert_color(&line[i])) == (unsigned int)-1)
            return (ft_putstrreti_fd("Error\nVerifiez les couleurs du ceil, bon format : 255,255,255\n", 0, 0));
      //vscode printf("data->colceil = %#x\n", data->colceil);
        //sleep(2);
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
    while (parameters[++inc] && (ft_isalpha(line[0]) || ft_strncmp(line, "", 1) == 0))
    {
        //printf("parameters[inc] = %s\tline[0] = %c\n", parameters[inc], line[0]);
        if (ft_strncmp(begline, parameters[inc], ft_strlen(parameters[inc])) == 0)// && counter < NBELEM + 1)
        {
          //vscode printf("line = %s\tet\tbegline = %s\n", line, begline);
            if (inc == 0)
                return (counter = (!set_data[0](data, line, parameters[inc])) ? 0 : 1);
            else if (inc < 6)
                return (counter = (!set_data[1](data, line, parameters[inc])) ? 0 : 1);
            else if (inc < 9)
                return (counter = (!set_data[2](data, line, parameters[inc])) ? 0 : 1);
        }
    }
    return (ft_putstrreti_fd("Error\nVeuillez verifier la ligne\n", 0, 0));
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

int     get_next_free(char *line, t_data *data, char *msg, int *ret)
{
    if (line)
        free(line);
    get_next_line(-1, NULL);
    printf("fd = %d\tet\tnewfd = %d dans gnf\n", ret[2], ret[1]);
    close(ret[1]);
    if (data != NULL)
        close(ret[2]);
    printf("apres 2e close\n");
    ret[0] = 0;
    printf("ret[0] = %d\tet\t", ret[0]);
    printf("msg = %s\n", msg);
    if (msg)
        return (ft_putstrreti_fd(msg, ret[0],
        free_data_stuff(STDOUT_FILENO, data))); // return 0 par defaut
    else
        return (free_data_stuff(ret[0], data)); // return 0 par defaut
}

int     parse_elements(t_data *data, int fd)
{
    int     ret[3];
    char    *line;
    int     counter[3];

    ret[2] = fd;
	if ((ret[1] = open(data->filename, O_RDONLY)) == -1 && close(ret[1]) == -1)
		return (ft_putstrreti_fd("Error\nLe fichier ne peut pas s'ouvrir\n", 0,
		free_data_stuff(STDOUT_FILENO, data)));
    printf("fd = %d\tet\tnewfd = %d\n", fd, ret[1]);
    ft_memseti(counter, 0, 3);
    while ((ret[0] = get_next_line(ret[1], &line)) == 1 && (counter[0] < NBELEM || ft_strncmp(line, "", 1) == 0))
    {
        if (ft_strncmp(line, "", 1) != 0)
        {
            counter[1] = counter[0];
            counter[0] += set_color(data, line);
            if (counter[1] == counter[0])
                return (get_next_free(line, data, NULL, ret));
        }
        free(line);
        counter[2]++;
      //vscode printf("counter[2] = %d\n", counter[2]);
    }
	if (ret[0] == -1)
        return (get_next_free(line, data, "Error\nVeuillez verifier le fichier\n", ret));
    if (counter[0] != NBELEM)
        return (get_next_free(line, data, "Error\nVeuillez verifier le nombre de parametres\n", ret));
    get_next_free(line, NULL, NULL, ret);
    while (--counter[2] >= 0)
        get_next_line(fd, &line);
    return (1);
}

int     verify_end(int fd, t_data *data, t_map *map)
{
    char    *line;
    int     ret[3];

    ft_memseti(ret, 0, 3);
    ret[1] = fd;
    printf("ret[1] = %d\n", ret[1]);
    while ((ret[2] = get_next_line(fd, &line)) != -1)
    {
        //line[0] = 'c';
        if (!ft_isonlychar(line, " "))
        {
            printf("line = %s\n", line);
            free_all_stuff(0, map, data);
            return (get_next_free(line, NULL, "Error\nLa map doit etre le dernier element\n", ret));
        }
        free(line);
        printf("ret[2] = %d\n", ret[2]);
        if (ret[2] == 0)
        {
            printf("ret[2] = %d\n", ret[2]);
            return (1);
        }
    }
    return (get_next_free(line, data, "Error\nVeuillez verifier le fichier\n", ret));
}
