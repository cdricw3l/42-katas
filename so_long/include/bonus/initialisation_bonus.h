/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:13:54 by cb                #+#    #+#             */
/*   Updated: 2025/01/17 05:57:24 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALISATION_BONUS_H
# define INITIALISATION_BONUS_H

# include "so_long_bonus.h"

typedef struct s_data	t_data;

t_data	*initialisation_and_check(char *path);
char	**get_map(t_data *data);
int		check_map(t_data *data);
int		check_valide_way(t_data *data);
void	process_set(t_data *data, char c, int row, int col);
int		check_dimentions(t_data *data);
int		is_close(char **map, int hauteur, int largeur);
int		ft_arr_len(char **arr);

#endif