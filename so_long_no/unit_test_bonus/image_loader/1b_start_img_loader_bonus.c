/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1b_start_img_loader_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 23:56:59 by cb                #+#    #+#             */
/*   Updated: 2025/01/11 17:41:35 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	get_images_sets(t_data *data)
{
	int			load;
	char		**path_g;
	char		**path_l;
	char		**path_r;
	
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
