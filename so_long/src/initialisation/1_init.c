 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:43:22 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/14 01:37:00 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/initialisation.h"

static int	_init(t_data *data, char *map_path)
{
	data->map_name = map_path;
	data->map = NULL;
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_game(data, ERR_MLX);
	data->window = NULL;
	data->img_set_global = NULL;
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
	if (data->xy_data.screen_size.col == 0
		|| data->xy_data.screen_size.row == 0)
		return (1);
	return (0);
}

t_data	*initialisation_and_check(char *path)
{
	t_data	*data;
	int		check_param;

	data = calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	if (_init(data, path) == 1)
		exit_game(data, ERR_SCREEN);
	data->map = get_map(data);
	if (!data->map)
		exit_game(data, ERR_GET_MAP);
	check_param = check_map(data);
	if (check_param
		|| get_area(rescal(data->xy_data.map, TILD_SIZE))
		> get_area(data->xy_data.screen_size))
		exit_game(data, check_param);
	if (check_valide_way(data) != 0)
		exit_game(data, ERR_NO_WAY);
	if (start_images_loader(data))
		exit_game(data, ERR_IMG_SET);
	data->frame = calloc(1,sizeof(t_img));
	if(data->frame == NULL)
		exit_game(data, ERR_FRAME);
	return (data);
}
