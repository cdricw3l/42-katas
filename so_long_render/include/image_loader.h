/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_loader.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 05:12:19 by cb                #+#    #+#             */
/*   Updated: 2025/01/08 03:05:59 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef IMAGE_LOADER_H
#define IMAGE_LOADER_H

#include "so_long.h"

typedef struct s_img t_img;
typedef struct s_data t_data;

char   **get_image_path_part3(void);
char   **get_image_path_part2(void);
char   **get_image_path(void);
char	**load_path(void);
int	    get_image_set(t_data **data);
int	    image_loader(char **path, t_data **data);

#endif
