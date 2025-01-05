/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_start_img_loader.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 23:56:59 by cb                #+#    #+#             */
/*   Updated: 2025/01/05 22:54:43 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	init_image(t_img **img, int img_set)
{
	int		i;
	t_img	*im;

	i = 0;
	if (!img || img_set <= 0)
		return (1);
	while (i < img_set)
	{
		im = malloc(sizeof(t_img));
		if (!im)
			return (clean_image_memory(img, i));
		im->endian = 0;
		im->line_length = 0;
		im->height = 0;
		im->width = 0;
		im->bit_per_pixel = 0;
		im->img = NULL;
		im->addr = NULL;
		img[i] = im;
		i++;
	}
	return (0);
}

int	load_images(void *mlx, t_img **img, int img_set)
{
	int		init;
	int		load;
	char	**path;

	init = init_image(img, img_set);
	if (init)
		return (error_layer(ERR_ALLOC_IMG));
	path = load_path();
	if (!path)
		return (error_layer(ERR_GET_IMGPATH));
	load = image_loader(path, img, mlx);
	if (load)
		return (error_layer(ERR_IMG_LOADING));
	return (0);
}
