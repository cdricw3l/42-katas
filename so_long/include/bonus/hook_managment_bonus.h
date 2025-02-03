/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_managment_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:04:05 by cb                #+#    #+#             */
/*   Updated: 2025/01/17 10:41:20 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_MANAGMENT_BONUS_H
# define HOOK_MANAGMENT_BONUS_H

# include "so_long_bonus.h"

int		manage_keyboard(int keycode, t_data *data);
int		ft_fight_checker(t_data *data);
int		ft_fight_layer(t_data *data);
void	ft_increase_counter_life(t_data *data);
void	ft_decrease_counter_life(t_data *data);
void	ft_count_move(t_data *data);
int		ft_push_object(t_data *data);
#endif