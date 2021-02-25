/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:36:24 by alongcha          #+#    #+#             */
/*   Updated: 2019/11/29 15:52:27 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		strjoin_free(char **str, char *pre, char *suf, int setnulbyte)
{
	char	*tmp;

	if (setnulbyte != -1)
		suf[setnulbyte] = 0;
	if (!(tmp = ft_strjoin(pre, suf)))
		return (-1);
	free(*str);
	*str = tmp;
	return (1);
}

int		ft_free(char *str, char *str1, char *str2)
{
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	if (str1 != NULL)
	{
		free(str1);
		str1 = NULL;
	}
	if (str2 != NULL)
	{
		free(str2);
		str2 = NULL;
	}
	return (-1);
}

int		ft_read(int fd, char **next, char *buff, unsigned int *c)
{
	char	*bf;
	int		valret;
	int		counter;

	if (ft_ischar(*next, '\n'))
		return (BUFFER_SIZE);
	valret = 0;
	if (!(bf = strdupli("")))
		return (ft_free(*next, bf, NULL));
	counter = -1;
	while (++counter < BUFFER_SIZE + 1)
		buff[counter] = '\0';
	while (!ft_ischar(buff, '\n') &&
	(valret = read(fd, buff, BUFFER_SIZE)) != 0)
	{
		if (valret == -1)
			return (ft_free(*next, bf, NULL));
		if (strjoin_free(&bf, bf, buff, valret) == -1)
			return (ft_free(*next, bf, NULL));
		(*c)++;
	}
	(*c)--;
	free(*next);
	*next = bf;
	return (valret);
}

int		set_line(int fd, char **str, char **n, unsigned int *i)
{
	int				valret;
	char			buff[BUFFER_SIZE + 1];
	char			*restofn;
	char			*tmp[2];
	unsigned int	counter;

	counter = 1;
	if (!(restofn = strdupli(*n)))
		if (!(restofn = strdupli("")))
			return (ft_free(restofn, *n, restofn));
	if ((valret = ft_read(fd, n, buff, &counter)) == -1)
		return (ft_free(restofn, NULL, *n));
	tmp[1] = *n;
	while (tmp[1][i[0]] != '\n' && tmp[1][i[0]] != '\0')
		i[0]++;
	*str = ft_substr(*n, i[1], i[0] - i[1]);
	if (!ft_ischar(restofn, '\n'))
		strjoin_free(str, restofn, *str, -1);
	i[0]++;
	tmp[0] = ft_substr(*n, i[0], BUFFER_SIZE * counter - i[0]);
	free(*n);
	*n = tmp[0];
	free(restofn);
	return (valret != 0);
}

int		get_next_line(int fd, char **line)
{
	static char		*next = NULL;
	int				valret;
	unsigned int	i[2];

	i[0] = 0;
	i[1] = 0;
	valret = 0;
	if (!line || fd <= -1)
		return (-1);
	if (BUFFER_SIZE > 0)
		valret = set_line(fd, line, &next, i);
	else
		valret = -1;
	if (next != NULL && valret == 0)
	{
		free(next);
		next = NULL;
	}
	return (valret);
}
