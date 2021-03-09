/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:14:00 by user42            #+#    #+#             */
/*   Updated: 2021/03/09 20:14:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

#define SPACE_CEIL_FLOOR "Error\nMettez au moins un espace (sol ou plafond)\n"
#define COLOR_FLOOR "Error\nVerifiez le sol, bon format : 255,255,255\n"
#define COLOR_CEIL "Error\nVerifiez le plafond, bon format : 255,255,255\n"
#define TOO_TIMES_FLOOR "Error\nLa couleur du sol a ete mise plusieurs fois\n"
#define TOO_TIMES_CEIL "Error\nLe plafond a ete mise plusieurs fois\n"

int		set_color_value(t_data *data, char *line, char *letters)
{
	int i;

	i = 0;
	while (line[++i] == ' ')
		;
	if (!ft_isdigit(line[i]) || i == 1)
		return (ft_putstrreti_fd(SPACE_CEIL_FLOOR, 0, 0));
	if (letters[0] == 'F')
	{
		if (data->colfloor != (unsigned int)-1)
			return (ft_putstrreti_fd(TOO_TIMES_FLOOR, 0, 0));
		if ((data->colfloor = convert_color(&line[i])) == (unsigned int)-1)
			return (ft_putstrreti_fd(COLOR_FLOOR, 0, 0));
	}
	else if (letters[0] == 'C')
	{
		if (data->colceil != (unsigned int)-1)
			return (ft_putstrreti_fd(TOO_TIMES_CEIL, 0, 0));
		if ((data->colceil = convert_color(&line[i])) == (unsigned int)-1)
			return (ft_putstrreti_fd(COLOR_CEIL, 0, 0));
	}
	return (1);
}
