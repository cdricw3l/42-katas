/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:59:18 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/17 05:38:45 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/hook_managment_bonus.h"

void	ft_decrease_counter_life(t_data *data)
{
	t_xy	dest;

	dest.row = 0;
	if (data->life > 0)
	{
		dest.col = data->xy_data.map.col - data->life;
		frame_layer(data, data->img_set_global[5], dest, 1);
		data->life--;
	}
}

void	ft_increase_counter_life(t_data *data)
{
	t_xy	dest;

	dest.row = 0;
	if (data->life < LIFE)
	{
		dest.col = data->xy_data.map.col - (data->life + 1);
		frame_layer(data, data->img_set_global[18], dest, 1);
		data->life++;
	}
}
