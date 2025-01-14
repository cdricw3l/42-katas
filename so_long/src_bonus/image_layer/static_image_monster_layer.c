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

// static int	ft_get_first_frame_idx(t_data *data, char c)
// {
// 	if (c == '1')
// 		return (5);
// 	else if (c == 'X')
// 		return (4);
// 	if (c == 'P' && data->char_state == LEFT)
// 		return (0);
// 	else if (c == 'P' && data->char_state == RIGHT)
// 		return (1);
// 	else if (c == 'E')
// 		return (2);
// 	return (99);
// }

// static int	ft_get_frame_idx(t_data *data, char c)
// {
	
// 	if (c == 'P' && data->char_state == LEFT)
// 		return (0);
// 	if (c == 'P' && data->char_state == RIGHT)
// 		return (1);
// 	if (c == 'Z')
// 		return (7);
// 	if (c == 'E')
// 	{
// 		if (data->count_item == 0)
// 			return (6);
// 	}
// 	return (99);
// }

static void	my_mlx_pixel_put(t_img *dst, t_img *src, t_xy xyf, int offset)
{
	char	*d;
	char	*s;
	int		i;
	int		j;
    (void)offset;
	i = 0;
	while (i < TILD_SIZE)
	{
		j = 0;
		while (j < TILD_SIZE)
		{
			s = src->addr + ((j) * src->line_length + i
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

int	monster_draw(t_data *data)
{
	int		i;
	int		j;
	int     path;
	t_xy	dest;

	i = 0;
    int o = 0;
    while (o < 8)
    {
        while (i < data->xy_data.map.row)
        {
            j = 0;
            while (j < data->xy_data.map.col)
            {
                if(data->map[i][j] == 'M')
                {
                    dest.row = i * TILD_SIZE;
                    dest.col = j * TILD_SIZE;

                }
                if(data->char_state == LEFT)
                    path = 9;
                else if(data->state_game == 1)
                    path = 10;
                my_mlx_pixel_put(data->frame, data->img_set_global[path], dest, o++);
                j++;
            }
            i++;
        }
        mlx_put_image_to_window(data->mlx, data->window, data->frame->img, 0, 0);
        o++;
    }
	return (0);
}

