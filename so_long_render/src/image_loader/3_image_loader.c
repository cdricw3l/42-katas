/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_image_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:23:15 by cb                #+#    #+#             */
/*   Updated: 2025/01/08 03:38:07 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	image_loader(char **path, t_data **data)
{
	int	i;
	t_img **img;

	i = 0;
	img = (*data)->img_set;
	if(!(*data)->img_set)
		return(1);
	while (i < IMG_SET_SIZE)
	{	
		printf("voici path i %s et les dim %d et %d ", path[i], img[i]->width ,img[i]->height);
		img[i]->img = mlx_xpm_file_to_image( (*data)->mlx, path[i],
				&(img[i]->width), &(img[i]->height));
		printf("creation de la image %p\n",img[i]);
		if (!img[i]->img)
			return (1);
		img[i]->position = i;
		i++;
	}
	return (0);
}