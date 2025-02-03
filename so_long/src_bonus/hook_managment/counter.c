/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:59:18 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/17 11:23:26 by cbouhadr         ###   ########.fr       */
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

void	ft_count_move(t_data *data)
{
	char	*move;
	char	*str;

	move = ft_itoa(data->count_mouvement);
	str = ft_strjoin("Number of steps: ", move);
	mlx_string_put(data->mlx, data->window,
		data->xy_data.map.col / 2,
		128 / 2,
		0xFFFFFF,
		str);
	free(move);
	free(str);
}
