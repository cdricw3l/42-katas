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

#include "../../include/bonus/so_long_bonus.h"

static int	clean_image_memory(t_data **d, t_img **data)
{
	int	i;

	i = 0;
	while (i < SET_SIZE)
	{
		if (data != NULL && data[i] != NULL)
		{
			mlx_destroy_image((*d)->mlx, data[i]->img);
			free(data[i]);
		}
		i++;
	}
	free(data);
	if ((*d)->frame && (*d)->frame->img)
		mlx_destroy_image((*d)->mlx, (*d)->frame->img);
	if ((*d)->frame && (*d)->frame)
		free((*d)->frame);
	return (1);
}

void	*exit_game(t_data *data, int err)
{
	int	i;

	i = 0;
	while (i <= data->xy_data.map.row)
	{
		if (data->map && data->map[i])
			free(data->map[i]);
		i++;
	}
	if (data->map)
		free(data->map);
	if (data->img_set_global)
		clean_image_memory(&data, data->img_set_global);
	if (data->window != NULL)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx != NULL)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	error_layer(err);
	exit(0);
}
