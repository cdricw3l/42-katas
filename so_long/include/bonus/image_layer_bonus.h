/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_layer_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:04:05 by cb                #+#    #+#             */
/*   Updated: 2025/01/17 11:45:26 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_LAYER_BONUS_H
# define IMAGE_LAYER_BONUS_H

# include "so_long_bonus.h"

typedef struct s_data	t_data;
typedef struct s_xy		t_xy;

int		run_image_layer(t_data *data);
int		ft_image_drawer(t_data *data);
int		monster_draw(t_data *data);
int		frame_layer(t_data *data, t_img *frame, t_xy dest, int frame_size);
int		ft_get_offset(int k);
int		ft_get_path(int k);

#endif