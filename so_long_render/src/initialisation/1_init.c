/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:43:22 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/08 03:08:57 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/initialisation.h"

static int	_init(t_data **data, char *map_path)
{
	
	(*data)->map_name = map_path;
	(*data)->map = NULL;
	(*data)->count_item = 0;
	(*data)->check_item = 0;
	(*data)->count_mouvement = 0;
	(*data)->count_exit = 0;
	(*data)->count_begin = 0;
	(*data)->xy_data.exit = ft_s_dimention();
	(*data)->xy_data.begin = ft_s_dimention();
	(*data)->xy_data.map = ft_s_dimention();
	(*data)->xy_data.screen_size = ft_s_dimention();
	mlx_get_screen_size((*data)->mlx, &(*data)->xy_data.screen_size.col,
				&(*data)->xy_data.screen_size.row);
	if((*data)->xy_data.screen_size.col == 0 
			|| (*data)->xy_data.screen_size.row == 0)
		return(1);
	return(0);
}

t_data	*data_initialisation(char *map_path)
{
	t_data	*data;
	int		init_result;
	
	data = malloc(sizeof(t_data) * 1);
	if (!data)
		return (NULL);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (free_memory(&data, ERR_MLX));
	data->window = NULL;
	get_image_set(&data);
	if (data->img_set)
		return (free_memory(&data, ERR_IMG_SET));
	init_result = _init(&data, map_path);
	if (init_result)
		return (free_memory(&data, ERR_SCREEN));
	return (data);
}


t_data	*initialisation_and_check(char *path)
{
	t_data	*data;
	int		check_param;

	data = data_initialisation(path);
	if (!data)
		return (NULL);
	data->map = get_map(&data);
	if (!data->map)
		return (free_memory(&data, ERR_GET_MAP));
	check_param = check_map(&data, path);
	if (check_param || get_area(rescal(data->xy_data.map, TILD_SIZE)) > get_area(data->xy_data.screen_size))
	{
		return (free_memory(&data, check_param));
	}
	// if (check_valide_way(data) == 1)
	// 	return (free_memory(data, ERR_NO_WAY));
	printf("area %d et %d ", get_area(rescal(data->xy_data.map, TILD_SIZE)) , get_area(data->xy_data.screen_size));
	return (data);
}
