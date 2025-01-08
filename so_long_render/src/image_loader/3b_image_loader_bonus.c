// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   3b_image_loader_bonus.c                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/01/05 18:23:15 by cb                #+#    #+#             */
// /*   Updated: 2025/01/06 03:18:07 by cb               ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../include/so_long.h"

// int	image_loader_bonus(char **path[3], t_img **img, void *mlx)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 16;
// 	while (i < IMG_SET_SIZE)
// 	{
// 		if (i <= 16)
// 			img[i]->img = mlx_xpm_file_to_image(mlx, path[0][i],
// 					&(img[i]->width), &(img[i]->height));
// 		else if (i > 16 && i <= 32)
// 			img[i]->img = mlx_xpm_file_to_image(mlx, path[1][i - j],
// 					&(img[i]->width), &(img[i]->height));
// 		else
// 			img[i]->img = mlx_xpm_file_to_image(mlx, path[2][i - j * 2],
// 					&(img[i]->width), &(img[i]->height));
// 		if (!img[i]->img)
// 			return (clean_image_memory(img, i));
// 		i++;
// 	}
// 	return (0);
// }