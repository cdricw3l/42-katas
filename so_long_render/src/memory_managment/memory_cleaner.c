/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_cleaner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:07:49 by cb                #+#    #+#             */
/*   Updated: 2025/01/09 12:05:52 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	*free_memory(t_data *data, int err)
{
    char **map;
    if(err != -1)
    {
        map =  data->map;
        if(map)
        {
            while (*map)
            {
                free(*map);
                map++;
            }
            free(data->map);
        }
        if(data->img_sets)
            clean_image_memory(data, IMG_SET_SIZE);
        if( data->window)
            mlx_destroy_window(data->mlx, data->window);
        free(data->mlx);
        free(data);
    }
    error_layer(err);
	return (NULL);
}
int	clean_image_memory(t_data *data, int index)
{
	int	i;
    (void)index;
	i = 0;
	while (i < SET_SIZE)
	{   
        free(data->img_sets->img_set_global[i]->img);
        free(data->img_sets->img_set_left[i]->img);
        free(data->img_sets->img_set_right[i]->img);
		i++;
	}
    free(data->img_sets->img_set_global);
    free(data->img_sets->img_set_left);
    free(data->img_sets->img_set_right);
    free(data->img_sets);
	return (1);
}

void	free_path_memory(char **path_g, char **path_l, char **path_r)
{
	
	free(path_g);
	free(path_l);
	free(path_r);
	
}