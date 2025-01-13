/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_cleaner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:07:49 by cb                #+#    #+#             */
/*   Updated: 2025/01/13 01:11:58 by cb               ###   ########.fr       */
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
	free(data);
	return (1);
}

void	*exit_game(t_data **data, int err)
{
	if (err != -1)
	{
		if ((*data)->map)
		{
			while (*(*data)->map)
			{
				if (*(*data)->map)
					free(*(*data)->map);
				(*data)->map++;
			}
		}
		if ((*data)->img_set_global)
			clean_image_memory(data, (*data)->img_set_global);
	}
	mlx_destroy_display((*data)->mlx);
	error_layer(err);
	exit(0);
	return (NULL);
}
