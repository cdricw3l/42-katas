/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:13:54 by cb                #+#    #+#             */
/*   Updated: 2025/01/08 03:06:15 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef INITIALISATION_H
#define INITIALISATION_H

#include "so_long.h"

typedef struct s_data t_data;


char	**get_map(t_data **data);
int     check_map(t_data **data, char *path);
int     check_valide_way(t_data **data);
t_data  *initialisation_and_check(char *path);
void    print_map(t_data *data);

#endif