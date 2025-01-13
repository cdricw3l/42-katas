/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_cleaner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:07:49 by cb                #+#    #+#             */
/*   Updated: 2025/01/12 20:06:43 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	*free_memory(t_data **data, int err)
{
    char **map;

    map =  (*data)->map;
    if(err != -1)
    {
        if(map)
        {
            while (*map)
            {
                free(*map);
                map++;
            }
        }
        if((*data)->img_sets)
            clean_image_memory(data, &(*data)->img_sets, SET_SIZE);

    }
    if((unsigned long)(*data)->mlx !=  0xbebebebebebebebe)
    {
        printf("MEMORYYYYYYYY%p\n", (*data)->mlx);
        mlx_destroy_display((*data)->mlx);
        free((*data)->mlx);
    }
    free((*data));
    error_layer(err);
    exit(0);
	return (NULL);
}
int	clean_image_memory(t_data **d, t_img_sets **data, int index)
{
	int	i;
 
	(void)index;
    i = 0;
    if((unsigned long)(*d)->img_sets == 0xbebebebebebebebe)
        return(1);
	
    while (i < SET_SIZE)
	{   
        mlx_destroy_image((*d)->mlx,(*data)->img_set_global[i]->img);
        mlx_destroy_image((*d)->mlx,(*data)->img_set_left[i]->img);
        mlx_destroy_image((*d)->mlx,(*data)->img_set_right[i]->img);
        free((*data)->img_set_global[i]->class);
        free((*data)->img_set_left[i]->class);
        free((*data)->img_set_right[i]->class);
        free((*data)->img_set_global[i]);
        free((*data)->img_set_left[i]);
        free((*data)->img_set_right[i]);
		i++;
	}
    free((*data)->img_set_global);
    free((*data)->img_set_left);
    free((*data)->img_set_right);
    free((*data));
	return (1);
}


