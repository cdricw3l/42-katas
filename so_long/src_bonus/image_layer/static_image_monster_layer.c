/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_layer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:23:20 by cb                #+#    #+#             */
/*   Updated: 2025/01/14 00:39:38 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/image_layer_bonus.h"
#include <assert.h>

static void	my_mlx_pixel_put(t_img *dst, t_img *src, t_xy xyf)
{
	char	*d;
	char	*s;
	int		i;
	int		j;

	i = 0;
	while (i < TILD_SIZE)
	{
		j = 0;
		while (j < TILD_SIZE)
		{
			s = src->addr + (j * src->line_length + i
					*(src->bit_per_pixel / 8));
			d = dst->addr + ((j + (xyf.row))
					*dst->line_length + (i + (xyf.col))
					*(dst->bit_per_pixel / 8));
			*(unsigned int *)d = *(unsigned int *)s;
			j++;
		}
		i++;
	}

}

int ft_put_image_on_frame(t_data *data, t_img *im)
{
    int i;
    int j;
    t_xy	dest;

    i = 0;
    while (i < data->xy_data.map.row)
	{
		j = 0;
		while (j < data->xy_data.map.col)
		{
            dest.row = i * TILD_SIZE;
			dest.col = j * TILD_SIZE;
			if(data->map[i][j] == 'M')
                my_mlx_pixel_put(data->frame, im, dest);
			j++;
		}
		i++;
	}
    

    return(0);
}

int	monster_draw(t_data *data)
{
	static int k = 0;
    static int f = 0;
    int path;
    t_img *new;
    char	*d;
	char	*s;
    int i;
    int j;
    if(k == 10)
    {
        k = 0;
        f++;
    }
    new = calloc(1, sizeof(t_img));
	assert(new);
    new->img = mlx_new_image(data->mlx, 128, 128);
    new->addr = mlx_get_data_addr(new->img,&new->bit_per_pixel, &new->line_length, &new->endian);
    i = 0;
    int v;
    if(k == 0)
        v = 0;
    else
        v = 128 * k;
    if(f % 2 == 0)
        path = 8;
    else
        path = 9;
    while (i < 128)
	{
        j = 0;
		while (j < 128)
		{
			s = data->img_set_global[path]->addr + (j * data->img_set_global[path]->line_length + (i + v)
					* (data->img_set_global[path]->bit_per_pixel / 8));
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
    ft_put_image_on_frame(data, new);
    mlx_put_image_to_window(data->mlx,data->window,data->frame->img,0,0);
    free(new->img);
    free(new);
    return(0);
}

