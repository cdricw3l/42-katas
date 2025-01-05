/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_image_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:23:15 by cb                #+#    #+#             */
/*   Updated: 2025/01/05 22:56:00 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	image_loader(char **path, t_img **img, void *mlx)
{
	int	i;

	i = 0;
	while (i < IMG_SET_SIZE)
	{
		img[i]->img = mlx_xpm_file_to_image(mlx, path[i],
					&(img[i]->width), &(img[i]->height));
		if (!img[i]->img)
			return (clean_image_memory(img, i));
		i++;
	}
	return (0);
}