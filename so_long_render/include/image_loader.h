/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_loader.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 05:12:19 by cb                #+#    #+#             */
/*   Updated: 2025/01/05 23:01:42 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef IMAGE_LOADER_H
#define IMAGE_LOADER_H

#include "so_long.h"

typedef struct s_img t_img;

char   **get_image_path_part3(void);
char   **get_image_path_part2(void);
char   **get_image_path(void);
char	**load_path(void);
int	    load_images(void *mlx, t_img **img, int img_set);
int	    clean_image_memory(t_img **img, int index);
int		image_loader(char **path, t_img **img, void *mlx);

#endif
