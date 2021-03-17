/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:17:08 by user42            #+#    #+#             */
/*   Updated: 2021/03/17 11:17:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		free_data(int ret, t_data *data)
{
	if (!data)
		return (ret);
	ft_free_ret(ret, (void **)&data->filename, NULL,
	(void **)&data->texeast);
	if (data->img)
	{
		mlx_destroy_image(data->ptr, data->img);
		data->img = NULL;
	}
	if (data->window && data->ptr)
	{
		mlx_destroy_window(data->ptr, data->window);
		data->window = NULL;
	}
	if (data->ptr)
		mlx_destroy_display(data->ptr);
	ft_free_ret(ret, (void **)&data->ptr, NULL, NULL);
	ft_free_ret(ret, (void **)&data->texnorth, (void **)&data->texsouth,
	(void **)&data->texwest);
	ft_free_ret(ret, (void **)&data->sprite, (void **)&data->coldone,
	(void **)&data->heightcol);
	return (ret);
}

int		free_map_objects(int ret, t_map *map, t_data *data)
{
	int		i;

	i = -1;
	if (map->objects)
	{
		while (++i < map->nbobjects)
		{
			if (map->objects[i].img)
			{
				mlx_destroy_image(data->ptr, map->objects[i].img);
				map->objects[i].img = NULL;
			}
		}
	}
	ft_free_ret(0, (void **)&map->objects, NULL, NULL);
	return (ret);
}

void	free_set(t_node **node, t_data *data)
{
	int		i;

	i = -1;
	if (*node && (*node)->set)
	{
		while ((*node)->set[++i].exist && (*node)->set[i].wall.img)
		{
			mlx_destroy_image(data->ptr, (*node)->set[i].wall.img);
			(*node)->set[i].wall.img = NULL;
		}
		free((*node)->set);
		(*node)->set = NULL;
	}
}

void	free_treenode(t_node **node, t_data *data)
{
	if (!*node)
		return ;
	if ((*node)->frontchild)
		free_treenode(&(*node)->frontchild, data);
	if ((*node)->backchild)
		free_treenode(&(*node)->backchild, data);
	if ((*node)->set)
		free((*node)->set);
	(*node)->set = NULL;
	if (*node)
		free(*node);
	*node = NULL;
	return ;
}

int		free_all_stuff(int ret, t_map *map, t_data *data, int aftercubparse)
{
	int		i;

	if (map)
	{
		i = -1;
		while (map->number && map->number[++i])
			ft_free_ret(0, (void **)&map->number[i], NULL, NULL);
		i = free_map_objects(-1, map, data);
		if (map->cub)
		{
			if (aftercubparse)
				map->cub--;
			while (map->cub[++i])
			{
				if (aftercubparse)
					map->cub[i]--;
				ft_free_ret(0, (void **)&map->cub[i], NULL, NULL);
			}
		}
		ft_free_ret(ret, (void **)&map->cub, (void **)&map->nbcuby, NULL);
		ft_free_ret(ret, (void **)&map->number, NULL, NULL);
		free_set(&map->tree.rootnode, data);
		free_treenode(&map->tree.rootnode, data);
	}
	return (free_data(ret, data));
}
