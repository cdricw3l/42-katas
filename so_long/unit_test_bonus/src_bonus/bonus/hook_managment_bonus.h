/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_managment.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:04:05 by cb                #+#    #+#             */
/*   Updated: 2025/01/08 22:53:16 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HOOK_MANAGER_H
#define HOOK_MANAGER_H

#include "so_long.h"


int	manage_keyboard(int keycode, t_data *data);
int close_windows(int keycode, t_data *data);


#endif