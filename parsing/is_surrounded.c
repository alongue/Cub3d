/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_surrounded.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:41:07 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 20:37:00 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		get_xtreme_x(char *xtreme)
{
	int		x;
	char	*temp;

	temp = ft_strjoin_free(ft_ctos(xtreme[0]), ft_ctos(xtreme[1]));
	x = ft_atoi(temp);
	free(temp);
	return (x);
}

int		get_xtreme_y(char *xtreme)
{
	int		y;
	char	*temp;

	temp = ft_strjoin_free(ft_ctos(xtreme[2]), ft_ctos(xtreme[3]));
	y = ft_atoi(temp);
	free(temp);
	return (y);
}

char	*get_xtreme(int x, int y)
{
	char	**xtreme;
	int		boundend;
	int		i;

	xtreme = recover_xtreme(NULL, &boundend, 0);
	i = -1;
	while (++i < boundend)
	{
		if (x == get_xtreme_x(xtreme[i]) && y == get_xtreme_y(xtreme[i]))
			return (ft_strdup(xtreme[i]));
	}
	return (NULL);
}

int		get_xtreme_location(int x, int y)
{
	char	**xtreme;
	int		boundend;
	int		i;

	xtreme = recover_xtreme(NULL, &boundend, 0);
	i = -1;
	while (++i < boundend)
	{
		if (x == get_xtreme_x(xtreme[i]) && y == get_xtreme_y(xtreme[i]))
			return (ft_atoi(&xtreme[i][4]));
	}
	return (-2);
}

int		is_boundaries(int x, int y)
{
	int		boundend;
	char	**xtreme;
	int		i;

	xtreme = recover_xtreme(NULL, &boundend, 0);
	i = -1;
	while (++i < boundend)
	{
		if (x == get_xtreme_x(xtreme[i]) && y == get_xtreme_y(xtreme[i]))
			return (1);
	}
	return (0);
}

int		is_rlly_btwn(int y, char **boundx, int max)
{
	int	i[2];

	i[0] = -1;
	i[1] = -1;
	while (++i[0] < max)
	{
		while (++i[1] < max)
		{
			if (i[0] != i[1])
				if (is_btwn(y, get_xtreme_x(boundx[i[0]]),
				get_xtreme_x(boundx[i[1]])))
				{
					if ((ft_atoi(&boundx[i[0]][4]) == LEFT &&
					ft_atoi(&boundx[i[1]][4]) == RIGHT)
					|| (ft_atoi(&boundx[i[0]][4]) == RIGHT &&
					ft_atoi(&boundx[i[1]][4]) == LEFT))
						return (1);
					i[0] = i[1];
				}
		}
	}
	return (0);
}

char	**xtreme_sorted_y(int y, int *max)
{
	char	**xtreme;
	char	**boundy;
	int		boundend;
	int		i;
	int		k;

	xtreme = recover_xtreme(NULL, &boundend, 0);
	i = -1;
	k = 0;
	boundy = malloc(sizeof(char *) * (k + 1));
	while (++i < boundend)
	{
		if (y == get_xtreme_y(xtreme[i]))
		{
			if (k != 0)
				boundy = ft_realloc(boundy, sizeof(char *) * (k + 1));
			boundy[k] = ft_strdup(xtreme[i]);
			k++;
		}
	}
	*max = k;
	sort_table_y(boundy, k);
	return (boundy);
}

int		is_outside_xboundaries(int y, t_map map)
{
	int		boundend;
	int		max;
	char	**xtreme;
	char	**boundy;
	int		x;
	int		i;

	xtreme = xtreme_sorted_y(y, &boundend);
	boundy = get_all_boundy(y, &max, xtreme, boundend);
	x = 0;
	i = 0;
	while (x <= get_line_nbmax(map.number, y))
	{
		if (i < max && x == get_xtreme_x(boundy[i]))
		{
			if (ft_atoi(&boundy[i][4]) == BLOCKED)
			{
				i++;
			}
			else
			{
				if (i + 1 < max)
				{
					x = get_xtreme_x(boundy[i + 1]);
				}
				i += 2;
			}
		}
		else
		{
			if (map.number[y][x] != ' ' && !is_boundaries(x, y))
			{
				return (1);
			}
		}
		x++;
	}
	return (0);
}

void	sort_table_y(char **table, int max)
{
	int		i;
	int		j;
	int		x[2];

	ft_memseti(x, 0, 2);
	i = -1;
	while (++i < max)
	{
		j = i - 1;
		while (++j < max)
		{
			x[0] = get_xtreme_x(table[i]);
			x[1] = get_xtreme_x(table[j]);
			if (i != j)
				if (x[0] > x[1])
				{
					ft_swap((void **)&table[i], (void **)&table[j]);
					j = i - 1;
				}
		}
	}
}

int		getside(int y, char *xtreme, int oldside)
{
	int			x;
	static int	side = BLOCKED;
	static int	static_outside = BLOCKED;
	static int	ycop = 0;
	char		*b4_xtreme;

	if (ycop != y)
	{
		ycop = y;
		static_outside = BLOCKED;
		side = BLOCKED;
	}
	x = get_xtreme_x(xtreme);
	if (((is_boundaries(x, y - 1) && !is_boundaries(x, y + 1))
	|| (is_boundaries(x, y - 1) && is_boundaries(x, y + 1) &&
	get_xtreme_location(x, y + 1) != BLOCKED)
	|| (is_boundaries(x, y + 1) && !is_boundaries(x, y - 1))
	|| (is_boundaries(x, y + 1) && is_boundaries(x, y - 1) &&
	get_xtreme_location(x, y - 1) != BLOCKED))
	&& !(is_boundaries(x, y - 1) && get_xtreme_location(x, y - 1) != BLOCKED
	&& is_boundaries(x, y + 1) && get_xtreme_location(x, y + 1) != BLOCKED))
	{
		if (side == BOT)
		{
			if (is_boundaries(x, y + 1))
			{
				b4_xtreme = get_xtreme(x, y + 1);
				if (ft_atoi(&b4_xtreme[4]) != BLOCKED && static_outside == 0)
				{
					free(b4_xtreme);
					side = BLOCKED;
					static_outside = BLOCKED;
					return (oldside);
				}
				else if (ft_atoi(&b4_xtreme[4]) != BLOCKED &&
				static_outside == 1)
				{
					free(b4_xtreme);
					side = BLOCKED;
					static_outside = BLOCKED;
					return (!oldside);
				}
			}
			else if (is_boundaries(x, y - 1))
			{
				b4_xtreme = get_xtreme(x, y - 1);
				if (ft_atoi(&b4_xtreme[4]) != BLOCKED &&
				static_outside == 0)
				{
					free(b4_xtreme);
					side = BLOCKED;
					static_outside = BLOCKED;
					return (!oldside);
				}
				else if (ft_atoi(&b4_xtreme[4]) !=
				BLOCKED && static_outside == 1)
				{
					free(b4_xtreme);
					side = BLOCKED;
					static_outside = BLOCKED;
					return (oldside);
				}
			}
		}
		else if (side == TOP)
		{
			if (is_boundaries(x, y - 1))
			{
				b4_xtreme = get_xtreme(x, y - 1);
				if (ft_atoi(&b4_xtreme[4]) != BLOCKED
				&& static_outside == 0)
				{
					side = BLOCKED;
					static_outside = BLOCKED;
					free(b4_xtreme);
					return (oldside);
				}
				else if (ft_atoi(&b4_xtreme[4]) !=
				BLOCKED && static_outside == 1)
				{
					side = BLOCKED;
					static_outside = BLOCKED;
					free(b4_xtreme);
					return (!oldside);
				}
			}
			else if (is_boundaries(x, y + 1))
			{
				b4_xtreme = get_xtreme(x, y + 1);
				if (ft_atoi(&b4_xtreme[4]) != BLOCKED &&
				static_outside == 0)
				{
					side = BLOCKED;
					static_outside = BLOCKED;
					free(b4_xtreme);
					return (!oldside);
				}
				else if (ft_atoi(&b4_xtreme[4]) != BLOCKED &&
				static_outside == 1)
				{
					side = BLOCKED;
					static_outside = BLOCKED;
					free(b4_xtreme);
					return (oldside);
				}
			}
		}
		if (is_boundaries(x, y - 1))
		{
			b4_xtreme = get_xtreme(x, y - 1);
			if (ft_atoi(&b4_xtreme[4]) != BLOCKED)
			{
				side = TOP;
				static_outside = oldside;
				free(b4_xtreme);
				if (oldside == 1)
					return (!oldside);
				else
					return (oldside);
			}
		}
		else if (is_boundaries(x, y + 1))
		{
			b4_xtreme = get_xtreme(x, y + 1);
			if (ft_atoi(&b4_xtreme[4]) != BLOCKED)
			{
				side = BOT;
				static_outside = oldside;
				free(b4_xtreme);
				if (oldside == 1)
					return (!oldside);
				else
					return (oldside);
			}
		}
	}
	if (is_boundaries(x + 1, y))
		return (oldside);
	return (!oldside);
}

char	**get_all_boundy(int y, int *max, char **xtreme, int boundend)
{
	char	**boundy;
	int		k;
	int		i;
	int		isoutside;
	int		isoutsidecop;

	boundy = malloc(sizeof(char *) * 1);
	k = 0;
	i = -1;
	isoutside = 1;
	isoutsidecop = 1;
	i = -1;
	while (++i < boundend)
	{
		if (ft_atoi(&xtreme[i][4]) == BLOCKED || isoutside
		!= (isoutsidecop = getside(y, xtreme[i], isoutside)))
		{
			if (k != 0)
				boundy = ft_realloc(boundy, sizeof(char *) * (k + 1));
			boundy[k] = ft_strdup(xtreme[i]);
			k++;
		}
		isoutside = isoutsidecop;
	}
	sort_table_y(boundy, k);
	*max = k;
	i = -1;
	return (boundy);
}

int		check_around(t_map map)
{
	int		y;

	y = 0;
	while (y < map.nbymax)
	{
		if (is_outside_xboundaries(y, map))
			return (0);
		y++;
	}
	return (1);
}

int		is_surrounded(t_map map)
{
	int		coor[3];
	char	*strcop;

	coor[0] = -1;
	coor[1] = 0;
	while (++coor[0] < map.nbymax)
	{
		strcop = ft_strtrim(map.number[coor[0]], " ");
		coor[1] += ft_strlen(map.number[coor[0]]);
		if (strcop[0] != '1' || strcop[ft_strlen(strcop) - 1] != '1')
			return (0);
	}
	if (!(map.parsepos = malloc(sizeof(int) * coor[1])))
		return (3);
	if (!(map.backtrackpos = malloc(sizeof(int) * coor[1])))
		return (3);
	map.parsepos = ft_memseti(map.parsepos, 0, coor[1]);
	map.backtrackpos = ft_memseti(map.parsepos, 0, coor[1]);
	coor[1] = -1;
	ft_memseti(coor, 0, 3);
	coor[1] = get_line_nbmin(map.number, 0);
	if (searching_around(&map, coor, BLOCKED) == ISFINISH)
	{
		if (!check_around(map))
			return (0);
		return (1);
	}
	else
		return (0);
}
