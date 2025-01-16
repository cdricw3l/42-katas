/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_image_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:23:15 by cb                #+#    #+#             */
/*   Updated: 2025/01/14 00:41:13 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	clean_img_set(t_data **data, int idx, char **path)
{
	int	i;

	i = 0;
	if ((*data)->img_set_global)
	{
		while (i < idx)
		{
			if ((*data)->img_set_global[i])
			{
				if ((*data)->img_set_global[i]->img)
					mlx_destroy_image((*data)->mlx,
						(*data)->img_set_global[i]->img);
				free((*data)->img_set_global[i]);
				(*data)->img_set_global[i] = NULL;
			}
			i++;
		}
		free((*data)->img_set_global);
		(*data)->img_set_global = NULL;
	}
	if (path)
		free(path);
	return (1);
}

int	push_img_set(t_data *data, char **path)
{
	int	i;

	i = 0;
	while (i < SET_SIZE)
	{
		data->img_set_global[i] = malloc(sizeof(t_img) * 1);
		if (!data->img_set_global[i])
			return (clean_img_set(&data, i, path));
		data->img_set_global[i]->img = mlx_xpm_file_to_image(data->mlx, path[i],
				&data->img_set_global[i]->width,
				&data->img_set_global[i]->height);
		if (!data->img_set_global[i]->img)
			return (clean_img_set(&data, i, path));
		data->img_set_global[i]->addr
			= mlx_get_data_addr(data->img_set_global[i]->img,
				&data->img_set_global[i]->bit_per_pixel,
				&data->img_set_global[i]->line_length,
				&data->img_set_global[i]->endian);
		if (!data->img_set_global[i]->addr)
			return (clean_img_set(&data, i, path));
		i++;
	}
	return (0);
}

int	image_loader(t_data *data, char **path_g)
{
	int		r;
	t_img	**img_set;

	img_set = data->img_set_global;
	if (!img_set)
		return (1);
	r = push_img_set(data, path_g);
	if (r != 0)
		return (1);
	free(path_g);
	return (0);
}
