/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:43:22 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/05 21:34:31 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/initialisation.h"

t_xy	ft_s_dimention(void)
{
	t_xy	dimention;

	dimention.col = 0;
	dimention.row = 0;
	return (dimention);
}

int	ft_init_game_data_s(t_data *data, t_img ** img_set, char *map_path)
{
	
	data->map_name = map_path;
	data->map = NULL;
	data->count_item = 0;
	data->check_item = 0;
	data->count_mouvement = 0;
	data->count_exit = 0;
	data->count_begin = 0;
	data->xy_data.exit = ft_s_dimention();
	data->xy_data.begin = ft_s_dimention();
	data->xy_data.map = ft_s_dimention();
	data->xy_data.screen_size = ft_s_dimention();
	mlx_get_screen_size(data->mlx, &data->xy_data.screen_size.col,
				&data->xy_data.screen_size.row);
	if(data->xy_data.screen_size.col == 0 
			|| data->xy_data.screen_size.row == 0)
		return(1);
	data->img_set = img_set;
	return(0);
}

t_img	**get_image_set(void *mlx)
{
	t_img	**image;
	int		loading;
	image = malloc(sizeof(t_img) * IMG_SET_SIZE);
	if (!image)
		return (NULL);
	loading = load_images(mlx, image, IMG_SET_SIZE);
	if (loading)
		return (NULL);
	return (image);
}

t_data	*data_initialisation(char *map_path)
{
	t_data	*data;
	t_img	**img_set;
	int		init_result;
	
	data = malloc(sizeof(t_data) * 1);
	if (!data)
		return (NULL);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (free_memory(data, ERR_MLX));
	data->window = NULL;
	img_set = get_image_set(data->mlx);
	if (!img_set)
		return (free_memory(data, ERR_IMG_SET));
	init_result = ft_init_game_data_s(data, img_set, map_path);
	if (init_result)
		return (free_memory(data, ERR_SCREEN));
	return (data);
}

t_data	*initialisation_and_check(char *path)
{
	t_data	*data;
	int		check_param;

	data = data_initialisation(path);
	if (!data)
		return (free_memory(data,ERR_STRUC_INIT));
	data->map = get_map(path);
	if (!data->map)
		return (free_memory(data, ERR_GET_MAP));
	check_param = check_map(data, path);
	if (check_param)
		return (free_memory(data, ERR_CHECK_MAP));
	if (check_valide_way(data) == 1)
		return (free_memory(data, ERR_NO_WAY));
	return (data);
}
