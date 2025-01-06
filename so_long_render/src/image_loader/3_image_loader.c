/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_image_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:23:15 by cb                #+#    #+#             */
/*   Updated: 2025/01/05 23:32:04 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	image_loader(char **path, t_img **img, void *mlx)
{
	int	i;

	i = 0;
	while (i < IMG_SET_SIZE - 1)
	{	
		img[i]->img = mlx_xpm_file_to_image(mlx, path[i],
					&(img[i]->width), &(img[i]->height));
		if (!img[i]->img)
		{

			printf("pafafaazea %s et %d\n", path[i], i);
			return (clean_image_memory(img, i));
		}
		i++;
	}
	return (0);
}