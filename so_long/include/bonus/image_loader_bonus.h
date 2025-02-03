/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_loader_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 05:12:19 by cb                #+#    #+#             */
/*   Updated: 2025/01/17 05:56:11 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_LOADER_BONUS_H
# define IMAGE_LOADER_BONUS_H

# include "so_long_bonus.h"

typedef struct s_img	t_img;
typedef struct s_data	t_data;

int		start_images_loader(t_data *data);
int		get_image_frame_size(char *path);
char	**get_paths(void);
int		image_loader(t_data *data, char **path_g);

#endif
