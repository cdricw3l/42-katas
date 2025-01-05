/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:43:22 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/04 23:55:39 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_xy	ft_s_dimention(void)
{
	t_xy	dimention;

	dimention.col = 0;
	dimention.row = 0;
	return (dimention);
}

int	load_image(t_img **img)
{

	if(!img)
		return(NULL);
	
}

t_img	**ft_init_image_set(void)
{
	t_img	**image;
	int		loading;
	image = malloc(sizeof(t_img) * IMG_SET);
	if (!image)
		return (NULL);
	loading = load_images(image);
	return (image);
}

t_data	*ft_init_game_data_s(void)
{
	t_data	*game_data;

	game_data = malloc(sizeof(t_data) * 1);
	if (!game_data)
		return (NULL);
	game_data->map_name = NULL;
	game_data->map = NULL;
	game_data->count_item = 0;
	game_data->check_item = 0;
	game_data->count_mouvement = 0;
	game_data->count_exit = 0;
	game_data->count_begin = 0;
	game_data->xy_data.exit = ft_s_dimention();
	game_data->xy_data.begin = ft_s_dimention();
	game_data->xy_data.map = ft_s_dimention();
	game_data->xy_data.screen_size = ft_s_dimention();
	return (game_data);
}

t_data	*ft_init_data_s(void)
{
	t_data	*data;
	t_img	**img_set;
	
	data = malloc(sizeof(t_data) * 1);
	if (!data)
		return (NULL);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (ft_free_memory(data,5));
	data->window = NULL;
	img_set = ft_init_image_set();
	if (!img_set)
		return (ft_free_memory(data, 6));
	ft_init_game_data_s(data);
	if (!data->game_data)
		return (ft_free_memory(data, 7));
	data->screen_size = ft_s_dimention();
	mlx_get_screen_size(data->mlx, &data->screen_size.col, &data->screen_size.row);
	return (data);
}
