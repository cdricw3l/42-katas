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

#include "../include/bonus/so_long_bonus.h"
#include <signal.h>
#include <assert.h>
# include <stdlib.h>
# include <signal.h>

typedef struct s_frame
{
    void    *mlx;
    void    *win;
    t_img   *im;
    int     frame_size;

} t_frame ;


// static void	my_mlx_pixel_put(t_img *dst, t_img *src, t_xy xyf)
// {
// 	char	*d;
// 	char	*s;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	while (i < TILD_SIZE)
// 	{
// 		j = 0;
// 		while (j < TILD_SIZE)
// 		{
// 			s = src->addr + (j * src->line_length + i
// 					*(src->bit_per_pixel / 8));
// 			d = dst->addr + ((j + (xyf.row))
// 					*dst->line_length + (i + (xyf.col))
// 					*(dst->bit_per_pixel / 8));
// 			*(unsigned int *)d = *(unsigned int *)s;
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	display_image_data(t_img *im)
{
	ft_printf("Voici les informations concernant l'image:");
	ft_printf("Dimentions de l'image ... hauteur: %d largeur : %d",
		im->height, im->width);
	ft_printf("voici la taile de la frame %d et la classe : %s",
		im->frame_size, im->class);
}



int ft_print_frame(t_frame *frame)
{
    static int k = 0;
    t_img *new;
    char	*d;
	char	*s;
    int i;
    int j;

    if(k == 8)
    {
        k = 0;
    }
    new = calloc(1, sizeof(t_img));
	assert(new);
    new->img = mlx_new_image(frame->mlx, 128, 128);
    new->addr = mlx_get_data_addr(new->img,&new->bit_per_pixel, &new->line_length, &new->endian);
    i = 0;
    int v;
    if(k == 0)
        v = 0;
    else
        v = 128 * k;
    
    while (i < 128)
	{
        j = 0;
		while (j < 128)
		{
			s = frame->im->addr + (j * frame->im->line_length + (i + v)
					* (frame->im->bit_per_pixel / 8));
			d = new->addr + (j
					* new->line_length + i
					* (new->bit_per_pixel / 8));
			*(unsigned int *)d = *(unsigned int *)s;
			j++;
		}
		i++;
	}
    k++;
    usleep(100000);
    mlx_put_image_to_window(frame->mlx,frame->win,new->img,0,0);
    return(0);
}

int	main(void)
{

    t_frame *frame;

    frame = calloc(1, sizeof(t_frame));
	assert(frame);

    frame->mlx = mlx_init();
    frame->im = calloc(1, sizeof(t_img));
    frame->im->img = mlx_xpm_file_to_image( frame->mlx, "tildset/monster/43_Dude_Monster_Jump_8_right.xpm",&frame->im->width, &frame->im->height);
    if(!frame->im->img)
        return(1);
    frame->im->addr = mlx_get_data_addr(frame->im->img,&frame->im->bit_per_pixel, &frame->im->line_length, &frame->im->endian);
    frame->frame_size = 8;
    frame->win = mlx_new_window(frame->mlx,frame->im->width,frame->im->height, "hello");
    mlx_string_put(frame->mlx,frame->win,100,100,0xFFFFFF,"couter 10");
    
    // mlx_put_image_to_window(frame->mlx ,frame->win,frame->im->img,0, 0);
    // mlx_loop_hook(frame->mlx, ft_print_frame, frame);
    mlx_loop(frame->mlx);
	return (0);
}
