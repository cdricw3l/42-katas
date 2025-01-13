/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_start_img_loader.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 23:56:59 by cb                #+#    #+#             */
/*   Updated: 2025/01/12 11:17:21 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	get_images_sets(t_data *data)
{
	int			load;
	char		**path_g;

	data->img_set_global = malloc(sizeof(t_img *) * (SET_SIZE + 1)) ;
	if(!data->img_set_global)
		return(error_layer(ERR_GET_IMGPATH));
	path_g = get_paths();
	if (!path_g)
	{
		free(data->img_set_global);
		return (error_layer(ERR_GET_IMGPATH));
	}
	load = 0;
	load = image_loader(data, path_g);
	if (load)
		return (error_layer(ERR_IMG_LOADING));
	free(path_g);
	return (0);
}
