/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:43:22 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/01 13:16:59 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int ft_put_img(void **mlx, void **new_w, t_data *data)
{
    int hauteur;
    int largeur;
	int i;
	int j;
    
    hauteur = 0;
	largeur = 0;
	i = 0;
	data->img->img  = mlx_xpm_file_to_image(*mlx, "items/door.xpm",&hauteur,&largeur);
    while (i < data->screen_size.row - 1 * TILD_SIZE)
    {
		j = 0;
        while (j  < data->screen_size.col- 1 * TILD_SIZE)
        {
    		mlx_put_image_to_window(*mlx, *new_w, data->img->img, j, i);
            j += largeur;
        }
        i += hauteur;
    }
    return(1);
}

void    start_game(t_data **data)
{

	(*data)->mlx = mlx_init();
	mlx_get_screen_size((*data)->mlx, &(*data)->screen_size.col, &(*data)->screen_size.row);
    printf("Dimention de l'ecran : x_screen: %d et y_screen: %d\n",(*data)->screen_size.col,(*data)->screen_size.row);
    (*data)->window = mlx_new_window((*data)->mlx, TILD_SIZE * (*data)->game_data->dimention.col, TILD_SIZE * (*data)->game_data->dimention.row, "hello");
    if(!(*data)->window || !(*data)->mlx)
    {
        perror(ft_error_return(4));
        return ;
    }
    ft_put_img(&(*data)->mlx, &(*data)->window, *data);
    mlx_hook((*data)->window, 2, 1L<<0 ,ft_manage_keyboard, (*data));
    printf("adresse 1: %p et adresse 2: %p\n", (*data)->mlx, (*data)->window);
   	mlx_hook((*data)->window, 17, 1L<<0 ,ft_close_windows, (*data));
    mlx_loop((*data)->mlx) ;
}

// int	main(int argc, char *argv[])
// {
// 	t_data		*data;

// 	if (argc != 2)
// 	{
// 		perror(ft_error_return(1));
// 		return (1);
// 	}
// 	else
// 	{
// 		data = init_and_check(argv[1]);
// 		if (data)
// 		{		
// 			ft_display_data_info(data);
// 			start_game(&data);
// 			ft_free_memory(data);
// 		}
// 		else
// 		{
// 			perror(ft_error_return(3));
// 			return (1);
// 		}
// 	}
// 	return (0);
// }
