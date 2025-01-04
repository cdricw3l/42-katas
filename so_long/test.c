/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 02:52:17 by cb                #+#    #+#             */
/*   Updated: 2025/01/04 04:06:48 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <unistd.h>

void    ft_cligniote(int **image, int len)
{
    static int swap = 0;
    int colors;
    int *img;
    int i;

    img = *image;
    if(swap == 0)
        colors = 0xD840FB;
    else
        colors = 0x780BF7;
    i = 0;
    while (i < len)
    {
        img[i] = colors;
        i++;
    }
    if(swap == 0)
        swap = 1;
    else
        swap = 0;
    sleep(1);
    
}

int main(void)
{
    void *mlx;
    void *windows;
    t_img image;
    
    image.width = 640;
    image.height = 320;
   
    mlx = mlx_init();
    if(!mlx)
        return(1);
    windows = mlx_new_window(mlx,640,320,"hello");
    if(!windows)
        return(1);
    int j = 0;
    while (j < 3)
    {
        image.img = mlx_new_image(mlx,image.width, image.height);
        if(!image.img)
            return(1);
        int i = 0;
        int len = image.height * image.width;
        int *addr = (int *)mlx_get_data_addr(image.img,&image.bit_per_pixel,&image.line_length,&image.endian);
        if(!addr)
            return(1);
        ft_cligniote(&addr, len);
        mlx_put_image_to_window(mlx,windows,image.img,0,0);
        free(image.img);
    }
    
    mlx_loop(mlx);
    return(0);
}