/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_layer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:04:05 by cb                #+#    #+#             */
/*   Updated: 2025/01/12 12:43:21 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef IMAGE_LAYER_H
#define IMAGE_LAYER_H

#include "so_long.h"

typedef struct s_img t_img;
typedef struct s_data t_data;
typedef struct s_xy t_xy;
int    run_image_layer(t_data *data);
void	my_mlx_pixel_put(t_img *new, t_img *frame,t_xy xyf);
t_img *ft_image_drawer(t_data *data);
int		ft_get_img_idx(t_data *data,char c);

#endif