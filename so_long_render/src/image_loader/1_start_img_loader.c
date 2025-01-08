/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_start_img_loader.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 23:56:59 by cb                #+#    #+#             */
/*   Updated: 2025/01/08 03:16:25 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	init_image(t_data **data)
{
	int		i;
	t_img	*im;

	i = 0;
	if (!(*data)->img_set || IMG_SET_SIZE <= 0)
		return (1);
	while (i < IMG_SET_SIZE)
	{
		im = malloc(sizeof(t_img));
		if (!im)
			return (clean_image_memory(data, i));
		im->endian = 0;
		im->line_length = 0;
		im->height = 0;
		im->width = 0;
		im->bit_per_pixel = 0;
		im->img = NULL;
		im->addr = NULL;
		(*data)->img_set[i] = im;
		i++;
	}
	return (0);
}

int	get_image_set(t_data **data)
{
	int		init;
	int		load;
	char	**path;
	t_img	**image_set;

	image_set = malloc(sizeof(t_img *) * IMG_SET_SIZE);
	if (!image_set)
		return (1);
	(*data)->img_set = image_set;
	init = init_image(data);
	if (init)
		return (error_layer(ERR_ALLOC_IMG));
	path = load_path();
	if (!path)
		return (error_layer(ERR_GET_IMGPATH));
	load = image_loader(path, data);
	free(path);
	if (load)
		return (error_layer(ERR_IMG_LOADING));
	return (0);
}
