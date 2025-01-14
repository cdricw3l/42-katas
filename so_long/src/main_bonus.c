/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 23:44:40 by cb                #+#    #+#             */
/*   Updated: 2025/01/14 01:41:10 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

int	close_windows(t_data *data)
{
	exit_game(data, 0);
	return (0);
}

void	start_game(t_data *data)
{
	t_xy	win;

	win.col = data->xy_data.map.col;
	win.row = data->xy_data.map.row;
	if (win.col * TILD_SIZE <= 0 || win.row * TILD_SIZE <= 0)
    {
        ft_putstr_fd("Error: Invalid window size\n", 2);
        exit_game(data, ERR_ALLOC_IMG);
    }
    
	data->window = mlx_new_window(data->mlx,
			win.col * TILD_SIZE,
			win.row * TILD_SIZE, "so long");
	if (!data->window)
		exit_game(data, ERR_WIN);
	ft_image_drawer(data);
	mlx_hook(data->window, 2, 1L << 0, manage_keyboard, data);
	mlx_hook(data->window, 17, 1L << 0, close_windows, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char *argv[])
{
	t_data		*data;

	if (argc != 2)
		return (error_layer(0));
	else
	{
		data = initialisation_and_check(argv[1]);
		if (!data)
			return (1);
		ft_display_data_info(data);
		start_game(data);
	}
	return (0);
}
