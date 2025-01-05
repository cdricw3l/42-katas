/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_cleaner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:07:49 by cb                #+#    #+#             */
/*   Updated: 2025/01/05 21:27:08 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	*free_memory(t_data *data, int err)
{
    char **map;
    if(err != -1)
    {
        map = data->map;
        if(map)
        {
            while (*map)
            {
                free(*map);
                map++;
            }
        }
        clean_image_memory(data->img_set,IMG_SET_SIZE);
        free(data->img_set);
        free(data->map);
        free(data);
    }
    error_layer(err);
	return (NULL);
}
int	clean_image_memory(t_img **img, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (img[i])
			free(img[i]);
		i++;
	}
    free(img);
	return (1);
}