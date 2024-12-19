/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:43:22 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/19 17:05:35 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void ft_put_px(t_data *data, int x, int y, int color)
{
    char *dst;
    dst = data->addr + (y * data->line_length + x * (data->bit_per_pixel / 8));
    *(unsigned int *)dst = color;
}

int ft_init_map(void **mlx, void **new_w, t_data *img)
{
    int hauteur;
    int largeur;
    
    hauteur = 0;
    *mlx = mlx_init();
    *new_w = mlx_new_window(*mlx, 1920, 1080, "hello");
    (*img).img = mlx_new_image(*mlx, 1920, 1080);
    (*img).addr = mlx_get_data_addr((*img).img, &(*img).bit_per_pixel, &(*img).line_length, &(*img).endian);
    while (hauteur < 1080)
    {
        largeur = 0;
        while (largeur  < 1920)
        {
            ft_put_px(img, largeur, hauteur, ft_colors(largeur, hauteur));
            largeur++;
        }
        hauteur++;
    }
    mlx_put_image_to_window(*mlx, *new_w, (*img).img, 0, 0);
    return(1);
}


int check_and_init(char *path, char **map, t_data *data)
{
    int fd = open(path,O_RDONLY);
    int check;
    int arr_check[5];
    
    if (fd == -1)
    {
        perror(ft_error_return(2));
        return (1);
    }
    ft_get_dimentions(fd, data);
    map = ft_parse_params(path, data->dimention.hauteur, data->dimention.largeur);
    check = ft_check_params(map, arr_check ,data->dimention.hauteur, data->dimention.largeur);
    if(check)
        return(1);
    return(check);
}


void    start_game(t_data *data)
{
    data->mlx = NULL;
    data->window = NULL;
    data->mouse_position.x = 0;
    data->mouse_position.y = 0;
    
    ft_init_map(&data->mlx, &data->window, data);
    if(!data->window|| !data->mlx)
    {
        perror(ft_error_return(4));
        return ;
    }
    mlx_key_hook(data->window, ft_manage_keyboard, data);
    printf("adresse 1: %p et adresse 2: %p\n", &data->mlx, &data->window);
    mlx_hook(data->window, 17, 0 ,ft_close_windows, &data);
    //mlx_mouse_hook(data->window,  ft_manage_mouse, data);
    mlx_loop(data->mlx);
}

int	main(int argc, char *argv[])
{
    
    t_data  data;
    char    **map;
    
    if(argc != 2)
    {
        perror(ft_error_return(1));
        return (1);
    }
    else
    {
        map = NULL;
        if(check_and_init(argv[1],map, &data))
        {
            perror(ft_error_return(3));
            return(1);
        }
        else
            start_game(&data);
    }
    return(0);
}