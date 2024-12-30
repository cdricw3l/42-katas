/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:43:22 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/30 17:21:43 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// void ft_put_px(t_img *data, int x, int y, int color)
// {
//     char *dst;
//     dst = data->addr + (y * data->line_length + x * (data->bit_per_pixel / 8));
//     *(unsigned int *)dst = color;
// }

// int ft_init_map(void **mlx, void **new_w, t_img *img)
// {
//     int hauteur;
//     int largeur;
    
//     hauteur = 0;
//     *mlx = mlx_init();
   

//     *new_w = mlx_new_window(*mlx, 1920, 1080, "hello");
//     (*img).img = mlx_new_image(*mlx, 1920, 1080);
//     (*img).addr = mlx_get_data_addr((*img).img, &(*img).bit_per_pixel, &(*img).line_length, &(*img).endian);
//     while (hauteur < 1080)
//     {
//         largeur = 0;
//         while (largeur  < 1920)
//         {
//             //mlx_pixel_put(*mlx,*new_w,largeur, hauteur, ft_colors(largeur, hauteur));
//             ft_put_px(img, largeur, hauteur, ft_colors(largeur, hauteur));
//             largeur++;
//         }
//         hauteur++;
//     }
//     mlx_put_image_to_window(*mlx, *new_w, (*img).img, 0, 0);
//     return(1);
// }

// void ft_init_structure(t_data *data)
// {
//     data->mlx= NULL;
//     data->window = NULL;
// }



// void    start_game(t_data *data)
// {
//     data->mlx = NULL;
//     data->window = NULL;
    
//     ft_init_map(&data->mlx, &data->window, &data->img);
//     if(!data->window || !data->mlx)
//     {
//         perror(ft_error_return(4));
//         return ;
//     }
//     mlx_key_hook(data->window, ft_manage_keyboard, data);
//     printf("adresse 1: %p et adresse 2: %p\n", &data->mlx, &data->window);
//     mlx_hook(data->window, 17, 0 ,ft_close_windows, &data);
//     mlx_loop(data->mlx) ;
// }


int	main(int argc, char *argv[])
{
    
    t_data  *data;
    
    if(argc != 2)
    {
        perror(ft_error_return(1));
        return (1);
    }
    else
    {
        data = init_and_check(argv[1]);
        if(!data)
        {
            perror(ft_error_return(3)); 
            return(1);
        }
        else
        {
            printf("initialisation realiser avec succes\n");
            ft_display_data_info(data);
            ft_check_valide_way(data->game_data->map, data->game_data, data->game_data->begin);
            // start_game(&data);
            ft_free_memory(data);
        }
    }
    return(0);
}
