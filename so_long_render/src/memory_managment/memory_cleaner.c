/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_cleaner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:07:49 by cb                #+#    #+#             */
/*   Updated: 2025/01/08 03:05:36 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	*free_memory(t_data **data, int err)
{
    char **map;
    if(err != -1)
    {
        map =  (*data)->map;
        if(map)
        {
            while (*map)
            {
                free(*map);
                map++;
            }
            free((*data)->map);
        }
        clean_image_memory(data, IMG_SET_SIZE);
        free((*data)->img_set);
        if( (*data)->window)
            mlx_destroy_window((*data)->mlx, (*data)->window);
        free((*data)->mlx);
        free((*data));
    }
    error_layer(err);
	return (NULL);
}
int	clean_image_memory(t_data **data, int index)
{
	int	i;
    t_img **img;
    
	i = 0;
    img = (*data)->img_set;
	while (i < index)
	{
        free(img[i]->img);
		free(img[i]);
        printf("liberation de la memoire %p\n",img[i]);
		i++;
	}
	return (1);
}