/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:59:18 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/14 01:47:02 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/hook_managment_bonus.h"

int ft_fight_checker(t_data *data)
{
	int col;
	int row;

	col = data->xy_data.begin.col;
	row = data->xy_data.begin.row;
	if (data->char_state == LEFT)
		if(data->map[row][col - 1] == 'M')
			return(1);
	if (data->char_state == RIGHT)
		if(data->map[row][col + 1] == 'M')
			return(1);
	if ((data->char_state == RIGHT
			&& data->map[row][col - 1] == 'M')
			|| (data->char_state == LEFT
			&& data->map[row][col + 1] == 'M'))
		ft_printf("On attack pas de dos\n");
	return(0);
}

void ft_fight(t_data *data, t_xy m)
{
	while (ft_fight_checker(data) && data->life > 0)
	{
		if(data->char_state == LEFT)
		{
			frame_layer(data,data->img_set_global[13], m, 6);
			frame_layer(data,data->img_set_global[14], data->xy_data.begin, 4);
			data->map[0][data->xy_data.map.col - data->life] = '1';

		}
		else if(data->char_state == RIGHT)
		{
			frame_layer(data,data->img_set_global[12], m, 6);
			frame_layer(data,data->img_set_global[15], data->xy_data.begin, 4);
			data->map[0][data->xy_data.map.col - data->life] = '1';
		}
		print_map(data);
        ft_decrease_counter_life(data);
		if(data->life == 0)
		{
			if(data->char_state == LEFT)
				frame_layer(data,data->img_set_global[16], data->xy_data.begin, 8);
			else
				frame_layer(data,data->img_set_global[17], data->xy_data.begin, 8);
		}
		mlx_loop(data->mlx);
	}
}

int ft_fight_layer(t_data *data)
{
	t_xy monster;
	if(data->char_state == LEFT)
	{
		monster.col = data->xy_data.begin.col - 1;
		monster.row = data->xy_data.begin.row;

	}
	else if (data->char_state == RIGHT)
	{
		monster.col = data->xy_data.begin.col + 1;
		monster.row = data->xy_data.begin.row;
	}
	
	ft_fight(data, monster);
	printf("voici TA LIFE  %d\n", data->life);
	
	return(data->life);
}
