/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 02:52:17 by cb                #+#    #+#             */
/*   Updated: 2025/01/04 16:39:04 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"
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

int ft_image_layer(void *mlx, void *win, t_img *im, int nb)
{
    t_img image;
    int *addr;
    int *old_im;
    int   i;
    (void)nb;
    i = 0;
    //mlx_put_image_to_window(mlx,win,im->img,10,10);
    image.img = mlx_new_image(mlx, (im->width / 8) ,im->height);
    if (!image.img)
        return(1);
    //printf("old w %d new w: %d, old h %d new h %d",im->width,im->height, image.width  , image.height);
    image.addr = (int *)mlx_get_data_addr(image.img,&image.bit_per_pixel,&image.line_length,&image.endian);
    if(!image.addr)
        printf("erruer\n");
    old_im = im->addr;
    while (i < ((im->width / 8) * im->height))
    {
        printf("START... %d, i %d \n", old_im[i] , i);
        image.addr[i] = old_im[i];
        i++;
    }
    mlx_put_image_to_window(mlx,win,image.img,0,0);
    return(0);
}

int main(void)
{
    void *mlx;
    void *windows;
    t_img image;
    
    image.width = 0;
    image.height = 0;
   
    printf("voici la taille h :%d et w :%d\n", image.width, image.height);
    mlx = mlx_init();
    if(!mlx)
        return(1);
    else
        printf("voici la taille h :%d et w :%d\n", image.width, image.height);
    image.img = mlx_xpm_file_to_image(mlx,"items/monster/monter.xpm",&image.width, &image.height);
    if(!image.img)
    {
        printf("erruer\n");
        return(1);
    }
    windows = mlx_new_window(mlx, image.width, image.height,"hefllo");
    if(!windows)
        return(1);
    //mlx_put_image_to_window(mlx,windows,image.img,10,10);
    image.addr = (int *)mlx_get_data_addr(image.img,&image.bit_per_pixel,&image.line_length,&image.endian);
    ft_image_layer(mlx,windows,&image,8);
    mlx_loop(mlx);
    return(0);
}