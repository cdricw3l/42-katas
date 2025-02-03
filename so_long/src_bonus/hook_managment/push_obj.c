/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:59:18 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/17 12:00:03 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/hook_managment_bonus.h"

static void	ft_push_object_right(t_data *data)
{
	t_xy	dest_block;
	t_xy	dest_hero;
	t_xy	dest_mask;

	data->map[data->xy_data.begin.row][data->xy_data.begin.col + 2] = '1';
	data->map[data->xy_data.begin.row][data->xy_data.begin.col + 1] = 'P';
	data->map[data->xy_data.begin.row][data->xy_data.begin.col] = '0';
	dest_block.col = data->xy_data.begin.col + 2;
	dest_block.row = data->xy_data.begin.row;
	dest_hero.col = data->xy_data.begin.col + 1;
	dest_hero.row = data->xy_data.begin.row;
	dest_mask.col = data->xy_data.begin.col;
	dest_mask.row = data->xy_data.begin.row;
	frame_layer(data, data->img_set_global[5], dest_block, 1);
	frame_layer(data, data->img_set_global[11], dest_hero, 2);
	frame_layer(data, data->img_set_global[7], dest_mask, 1);
	data->count_mouvement++;
	data->xy_data.begin.col = data->xy_data.begin.col + 1;
	print_map(data);
}

static void	ft_push_object_left(t_data *data)
{
	t_xy	dest_block;
	t_xy	dest_hero;
	t_xy	dest_mask;

	data->map[data->xy_data.begin.row][data->xy_data.begin.col - 2] = '1';
	data->map[data->xy_data.begin.row][data->xy_data.begin.col - 1] = 'P';
	data->map[data->xy_data.begin.row][data->xy_data.begin.col] = '0';
	dest_block.col = data->xy_data.begin.col - 2;
	dest_block.row = data->xy_data.begin.row;
	dest_hero.col = data->xy_data.begin.col - 1;
	dest_hero.row = data->xy_data.begin.row;
	dest_mask.col = data->xy_data.begin.col;
	dest_mask.row = data->xy_data.begin.row;
	frame_layer(data, data->img_set_global[5], dest_block, 1);
	frame_layer(data, data->img_set_global[10], dest_hero, 2);
	frame_layer(data, data->img_set_global[7], dest_mask, 1);
	data->count_mouvement++;
	data->xy_data.begin.col = data->xy_data.begin.col - 1;
	print_map(data);
}

int	ft_push_object(t_data *data)
{
	int	col;
	int	row;

	col = data->xy_data.begin.col;
	row = data->xy_data.begin.row;
	if (data->char_state == LEFT)
	{
		if (data->map[row][col - 2] != '1'
				&& data->map[row][col - 1] == '1'
				&& data->xy_data.begin.col - 1 > 1)
			ft_push_object_left(data);
		else
			frame_layer(data, data->img_set_global[10], data->xy_data.begin, 6);
	}
	else if (data->char_state == RIGHT)
	{
		if (data->map[row][col + 2] != '1'
				&& data->map[row][col + 1] == '1'
				&& data->xy_data.begin.col + 1 < data->xy_data.map.col - 1)
			ft_push_object_right(data);
		else
			frame_layer(data, data->img_set_global[11], data->xy_data.begin, 6);
	}
	return (0);
}
