/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_loader.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 05:12:19 by cb                #+#    #+#             */
/*   Updated: 2025/01/05 16:11:59 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef IMAGE_LOADER_H
#define IMAGE_LOADER_H

#include "so_long.h"

typedef struct s_img
{
	void				*img;
	int					*addr;
	int					bit_per_pixel;
	int					line_length;
	int					endian;
	int					width;
	int					height;
	
} t_img ;

char   **get_image_path_part3(void);
char   **get_image_path_part2(void);
char   **get_image_path(void);
int	    load_path(char **path[3]);
int	    load_images(void *mlx, t_img **img, int img_set);
int	    clean_image_memory(t_img **img, int index);

#endif
