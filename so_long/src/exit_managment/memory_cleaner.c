/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_cleaner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:07:49 by cb                #+#    #+#             */
/*   Updated: 2025/01/13 04:42:56 by cb               ###   ########.fr       */
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
		if ((*d)->mlx)
			mlx_destroy_image((*d)->mlx, data[i]->img);
		else
			free(data[i]->img);
		free(data[i]->class);
		free(data[i]);
		i++;
	}
	mlx_destroy_display((*d)->mlx);
	free(data);
	return (1);
}

void	*exit_game(t_data **data, int err)
{
	int i;

	i = 0;
	if (err != -1)
	{
		if ((*data)->map)
		{
			while (i <= (*data)->xy_data.map.row)
			{
				if ((*data)->map[i])
					free((*data)->map[i]);
				i++;
			}
		}
		if ((*data)->img_set_global)
			clean_image_memory(data, (*data)->img_set_global);
	}
	free((*data)->mlx);
	error_layer(err);
	exit(0);
	return (NULL);
}
