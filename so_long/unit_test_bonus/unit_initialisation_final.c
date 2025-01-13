/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_initialisation_final.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 03:12:19 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/11 15:00:46 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};


void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bit_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int ft_close_windows(int keycode, t_data **data)
{
    printf("voici le keycode %d\n", keycode);
    (void)data;
    if(keycode == 65307 || keycode == 64)
    {
        printf("voici %p \n", (*data)->img_sets);
        printf("data .mlx %p\n", (*data)->map);
        mlx_destroy_window((*data)->mlx, (*data)->window);
        free_memory(data, 42);
        return(0);
    }
    return(1);
}

int dynamique_hook(t_data *d)
{   
   
    t_img_sets *data;
    static int k = 0;
    printf("data %d\n", k);
    t_img *im1;
    t_img *im2;
    t_img *im3;
    //t_img *new;

    printf("K :  %d et ptr %p\n",k, d->img_sets->img_set_global[0]->img);
    data = d->img_sets;
    im1 = data->img_set_global[k];
    im2 = data->img_set_right[k];
    im3 = data->img_set_left[k];
    
    printf("classe image set 1 : %s", im1->class);
    printf("classe image set 2 : %s", im2->class);
    printf("classe image set 3 : %s", im3->class);
    
    if(im1 != NULL)
        mlx_put_image_to_window(d->mlx,d->window,im1->img, 10, 10);
    if(im2 != NULL)
        mlx_put_image_to_window(d->mlx,d->window,im2->img, 100, 100);
    if(im3 != NULL)
        mlx_put_image_to_window(d->mlx,d->window,im3->img, 500, 200);
    sleep(1);
    k++;
    if(k == 14)
        k = 0;
    return (0);
}


int main(void)
{
    t_data		*data;
    t_xy          map;
    
    data = initialisation_and_check("map/map2.ber");

    if (!data)
 		    return (1);
    else
        printf("INITIALISATION DES STRUCTURS REALISER AVEC SUCCES\n");
    map = data->xy_data.map;
    data->window = mlx_new_window(data->mlx, map.col * TILD_SIZE, map.row * TILD_SIZE, "so_long");
    if(!data->window)
    {
        free_memory(&data, ERR_WIN);
        return(1);
    }
    else
        printf("WINDOWS INITIALISER AVEC SUCCES %p\n", data->mlx);
    
    // mlx_loop_hook(data->mlx, &dynamique_hook, data);
    // mlx_hook(data->window, ON_KEYDOWN, 1l<<0, ft_close_windows,&data);
    // mlx_loop(data->mlx);
    
    t_img  old;
    t_img new;

    old = *data->img_sets->img_set_left[2];
    assert(&old);

    int largeur = old.width / old.frame_size;
    printf("voici la largeur %d\n", largeur);
    new.img = mlx_new_window(data->mlx, largeur , old.height, "hello");
    assert(new.img);

    new.addr = mlx_get_data_addr(&new.img, &new.bit_per_pixel, &new.line_length, &new.endian);
    assert(new.addr);
    
    //my_mlx_pixel_put(&new, 0, 128, 0xFF0000);
    
    mlx_loop(data->mlx);

    return(0);
}