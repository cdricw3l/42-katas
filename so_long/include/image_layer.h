/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_layer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:04:05 by cb                #+#    #+#             */
/*   Updated: 2025/01/17 05:54:17 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_LAYER_H
# define IMAGE_LAYER_H

# include "so_long.h"

typedef struct s_data	t_data;
typedef struct s_xy		t_xy;

int		run_image_layer(t_data *data);
int		ft_image_drawer(t_data *data);

#endif