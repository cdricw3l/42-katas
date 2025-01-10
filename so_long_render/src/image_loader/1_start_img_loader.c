/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_start_img_loader.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 23:56:59 by cb                #+#    #+#             */
/*   Updated: 2025/01/09 11:36:30 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// int	init_image(t_data *data)
// {
// 	int		i;
// 	t_img	*im;

// 	i = 0;
// 	if (!data->img_set || IMG_SET_SIZE <= 0)
// 		return (1);
// 	while (i < IMG_SET_SIZE)
// 	{
// 		im = malloc(sizeof(t_img));
// 		if (!im)
// 			return (clean_image_memory(data, i));
// 		im->endian = 0;
// 		im->line_length = 0;
// 		im->height = 0;
// 		im->width = 0;
// 		im->bit_per_pixel = 0;
// 		im->img = NULL;
// 		im->addr = NULL;
// 		im->position = i;
// 		data->img_set[i] = im;
// 		i++;
// 	}
// 	data->img_set[i] = NULL;
// 	return (0);
// }


int	get_images_sets(t_data *data)
{
	int			load;
	char		**path_g;
	char		**path_l;
	char		**path_r;
	
	printf("voici l'adresse de data %p\n", data);
	data->img_sets = malloc(sizeof(t_img_sets));
	if(!data->img_sets)
		return(error_layer(ERR_GET_IMGPATH));
	path_g = get_paths(1);
	path_l = get_paths(2);
	path_r = get_paths(3);
	if (!path_g || !path_l || !path_r)
	{
		free(data->img_sets);
		return (error_layer(ERR_GET_IMGPATH));
	}
	load = 0;
	load = image_loader(data, path_g, path_l, path_r);
	if (load)
		return (error_layer(ERR_IMG_LOADING));
	free_path_memory(path_g, path_l, path_r);
	return (0);
}
