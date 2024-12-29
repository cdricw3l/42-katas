/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:43:22 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/29 19:24:15 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_dimention	ft_s_dimention(void)
{
	t_dimention	dimention;

	dimention.col = 0;
	dimention.row = 0;
	return (dimention);
}

int	*ft_init_check_list_arr(void)
{
	int	*check_lst;

	check_lst = malloc(sizeof(int) * CHECK_LIST_SIZE);
	if (!check_lst)
		return (NULL);
	ft_bzero(check_lst, sizeof(int) * CHECK_LIST_SIZE);
	return (check_lst);
}

t_img	*ft_init_image_s(void)
{
	t_img	*image;

	image = malloc(sizeof(t_img) * 1);
	if (!image)
		return (NULL);
	image->img = NULL;
	image->addr = NULL;
	image->bit_per_pixel = 0;
	image->line_length = 0;
	image->endian = 0;
	return (image);
}

t_game_data	*ft_init_game_data_s(void)
{
	t_game_data	*game_data;

	game_data = malloc(sizeof(t_game_data) * 1);
	if (!game_data)
		return (NULL);
	game_data->map_name = NULL;
	game_data->map = NULL;
	game_data->count_item = 0;
	game_data->count_mouvement = 0;
	game_data->begin = ft_s_dimention();
	game_data->dimention = ft_s_dimention();
	game_data->exit_position = ft_s_dimention();
	return (game_data);
}

t_data	*ft_init_data_s(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data) * 1);
	if (!data)
		return (NULL);
	data->mlx = NULL;
	data->window = NULL;
	data->img = ft_init_image_s();
	if (!data->img)
		return (ft_free_memory(data));
	data->check_list = ft_init_check_list_arr();
	if (!data->check_list)
		return (ft_free_memory(data));
	data->game_data = ft_init_game_data_s();
	if (!data->game_data)
		return (ft_free_memory(data));
	return (data);
}
