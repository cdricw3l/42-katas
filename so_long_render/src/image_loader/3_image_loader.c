/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_image_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:23:15 by cb                #+#    #+#             */
/*   Updated: 2025/01/06 15:33:57 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	image_loader(char **path, t_data *data)
{
	int	i;
	t_img **img;

	i = 0;
	img = data->img_set;
	while (i < IMG_SET_SIZE)
	{	
		img[i]->img = mlx_xpm_file_to_image(data->mlx, path[i],
					&(img[i]->width), &(img[i]->height));
		printf("creation de la image %p\n",img[i]);
		if (!img[i]->img)
			return (1);
		img[i]->position = i;
		i++;
	}
	return (0);
}