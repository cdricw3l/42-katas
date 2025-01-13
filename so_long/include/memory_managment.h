/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_managment.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 01:17:28 by cb                #+#    #+#             */
/*   Updated: 2025/01/13 01:18:06 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_MANAGMENT_H
# define MEMORY_MANAGMENT_H

# include "so_long.h"
# include "memory_managment.h"

typedef struct s_data	t_data;
typedef struct s_img	t_img;

void	*exit_game(t_data **data, int err);
void	free_path_memory(char **path_g, char **path_l, char **path_r);
int		error_layer(int err);

#endif