/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_start_img_loader.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 23:56:59 by cb                #+#    #+#             */
/*   Updated: 2025/01/17 10:33:53 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	start_images_loader(t_data *data)
{
	int			load;
	char		**path_g;

	data->img_set_global = calloc(SET_SIZE, sizeof(t_img *));
	if (!data->img_set_global)
		return (error_layer(ERR_GET_IMGPATH));
	path_g = get_paths();
	if (!path_g)
		return (error_layer(ERR_GET_IMGPATH));
	load = image_loader(data, path_g);
	if (load)
		return (error_layer(ERR_IMG_LOADING));
	return (0);
}
