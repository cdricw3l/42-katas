/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_loader.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 05:12:19 by cb                #+#    #+#             */
/*   Updated: 2025/01/09 07:22:29 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef IMAGE_LOADER_H
#define IMAGE_LOADER_H

#include "so_long.h"

typedef struct s_img t_img;
typedef struct s_data t_data;


int	    get_images_sets(t_data *data);
int	    get_image_frame_size(char *path);
char	**get_paths(int set);
int	    image_loader(t_data *data, char **path_g, char **path_l, char **path_r);

#endif
