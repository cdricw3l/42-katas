/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_layer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:23:20 by cb                #+#    #+#             */
/*   Updated: 2025/01/13 12:11:35 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/image_layer.h"

static int	ft_get_img_idx(t_data *data, char c)
{
	if (c == '1')
		return (5);
	else if (c == 'X')
		return (4);
	if (c == 'P' && data->char_state == LEFT)
		return (0);
	else if (c == 'P' && data->char_state == RIGHT)
		return (1);
	else if (c == 'E')
	{
		if(data->count_item > 0)
			return (2);
		else
			return(6);
	}
	return (99);
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

static t_img	*initial_draw(t_data *data, t_img *new)
{
	int		i;
	int		j;
	int		path;
	t_xy	dest;

	i = 0;
	while (i < data->xy_data.map.row)
	{
		j = 0;
		while (j < data->xy_data.map.col)
		{
			dest.row = i * TILD_SIZE;
			dest.col = j * TILD_SIZE;
			path = ft_get_img_idx(data, data->map[i][j]);
			if (path > -1 && path < SET_SIZE)
				my_mlx_pixel_put(new, data->img_set_global[path], dest);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->window, new->img, 0, 0);
	mlx_destroy_image(data->mlx, new->img);
	return (NULL);
}

t_img	*ft_image_drawer(t_data *data)
{
	t_img	new;
	t_xy	size;

	size = data->xy_data.map;
	new.img = mlx_new_image(data->mlx, (size.col * TILD_SIZE),
			(size.row * TILD_SIZE));
	if (!new.img)
		return (NULL);
	new.addr = mlx_get_data_addr(new.img,
			&new.bit_per_pixel, &new.line_length,
			&new.endian);
	if (!new.addr)
		return (NULL);
	initial_draw(data, &new);
	return (NULL);
}
