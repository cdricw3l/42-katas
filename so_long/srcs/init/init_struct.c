/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:43:22 by cbouhadr          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/01/05 06:04:26 by cb               ###   ########.fr       */
=======
/*   Updated: 2025/01/04 22:12:11 by cb               ###   ########.fr       */
>>>>>>> main
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

t_img	**ft_init_image_set(void *mlx)
{
	t_img	**image;
	int		loading;
	image = malloc(sizeof(t_img) * IMG_SET);
	if (!image)
		return (NULL);
	loading = load_images(mlx, image, IMG_SET);
	return (image);
}

t_data	*ft_init_game_data_s(t_data *data, t_img ** img_set, char map_path)
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
		return(NULL);
	data->img_set = img_set;
	return(data);
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
<<<<<<< HEAD
		return (ft_free_memory(data,5)); // error 5
	data->window = NULL;
	img_set = ft_init_image_set(data->mlx);
	if (!img_set)
		return (ft_free_memory(data, 6)); // error 6
	ft_init_game_data_s(data, img_set, map_path);
	if (!init_result)
		return (ft_free_memory(data, 7)); // error 7
=======
		return (ft_free_memory(data,5));
	data->window = NULL;
	data->img = ft_init_image_s();
	if (!data->img)
		return (ft_free_memory(data, 6));
	data->game_data = ft_init_game_data_s();
	if (!data->game_data)
		return (ft_free_memory(data, 7));
	data->screen_size = ft_s_dimention();
	mlx_get_screen_size(data->mlx, &data->screen_size.col, &data->screen_size.row);
>>>>>>> main
	return (data);
}
