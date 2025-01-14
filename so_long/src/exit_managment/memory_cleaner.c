/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_cleaner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:07:49 by cb                #+#    #+#             */
/*   Updated: 2025/01/14 01:47:18 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	clean_image_memory(t_data **d, t_img **data)
{
	int	i;

	i = 0;
	if ((unsigned long)(*d)->img_set_global == 0xbebebebebebebebe)
		return (1);
	while (i < SET_SIZE)
	{
		mlx_destroy_image((*d)->mlx, data[i]->img);
		free(data[i]->class);
		free(data[i]);
		i++;
	}
	free(data);
	return (1);
}

void	*exit_game(t_data *data, int err)
{
	int	i;
	
	i = 0;
	if (err != -1)
	{
		if (data->map)
		{
			while (i <= data->xy_data.map.row)
			{
				if (data->map[i])
					free(data->map[i]);
				i++;
			}
			free(data->map);
		}
		if (data->img_set_global)
			clean_image_memory(&data, data->img_set_global);
	}
	if(data->window != NULL)
		mlx_destroy_window(data->mlx, data->window);
	if(data->mlx != NULL)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	error_layer(err);
	exit(0);
	return (NULL);
}
