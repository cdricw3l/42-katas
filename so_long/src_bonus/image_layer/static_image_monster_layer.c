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

int ft_get_offset(t_data *data, int k, int path)
{
    int check;

    check = data->img_set_global[path]->width;
    if(128 * k > check)
        return(-1);
    if(k == 0)
        return(0);
    else
        return(128 * k);
}
int ft_get_path()
{
    static int f = 0;
    
    if(f % 2 == 0)
        return(8);
    else
        return(9);
    f++;
}

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

int ft_get_image_on_frame(t_data *data, t_img *new,int path, int offset)
{
    int i;
    int j;
    char	*d;
	char	*s;

    i = 0;
    while (i < TILD_SIZE)
	{
        j = 0;
		while (j < TILD_SIZE)
		{
			s = data->img_set_global[path]->addr + (j * data->img_set_global[path]->line_length + (i + offset)
					* (data->img_set_global[path]->bit_per_pixel / 8));
			d = new->addr + (j
					* new->line_length + i
					* (new->bit_per_pixel / 8));
			*(unsigned int *)d = *(unsigned int *)s;
			j++;
		}
		i++;
	}
    return(0);
}

int	monster_draw(t_data *data)
{
	static int k = 0;
    int offset;
    t_img *new;

    if(k == 8)
        k = 0;
    new = calloc(1, sizeof(t_img));
    if(!new)
        return(1);
    new->img = mlx_new_image(data->mlx, TILD_SIZE, TILD_SIZE);
    if(!new->img)
        return(1);
    new->addr = mlx_get_data_addr(new->img,&new->bit_per_pixel, &new->line_length, &new->endian);
    if(!new->img)
        return(1);
    offset = ft_get_offset(data,k++, ft_get_path());
    if(offset == -1)
        return(1);
    ft_get_image_on_frame(data,new, ft_get_path(), offset);
    ft_put_image_on_frame(data, new);
    mlx_put_image_to_window(data->mlx,data->window,data->frame->img,0,0);
    mlx_destroy_image(data->mlx, new->img);
    free(new);
    usleep(100000);
    return(0);
}

