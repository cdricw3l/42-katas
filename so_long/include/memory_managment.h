/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_managment.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 00:45:09 by cb                #+#    #+#             */
/*   Updated: 2025/01/17 05:54:55 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_MANAGMENT_H
# define MEMORY_MANAGMENT_H

# include "so_long.h"

typedef struct s_data	t_data;
typedef struct s_img	t_img;

void	*exit_game(t_data *data, int err);
void	free_path_memory(char **path_g, char **path_l, char **path_r);
int		error_layer(int err);

#endif