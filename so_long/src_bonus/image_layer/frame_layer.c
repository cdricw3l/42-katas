/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_layer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:23:20 by cb                #+#    #+#             */
/*   Updated: 2025/01/17 12:00:18 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/image_layer_bonus.h"

static int	ft_put_animation_on_frame(t_img *dst, t_img *src, t_xy xyf)
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
			d = dst->addr + ((j + (xyf.row * TILD_SIZE))
					*dst->line_length + (i + (xyf.col * TILD_SIZE))
					*(dst->bit_per_pixel / 8));
			if (s && d)
				*(unsigned int *)d = *(unsigned int *)s;
			j++;
		}
		i++;
	}
	return (i * j);
}

static void	ft_extract_from_animation(t_img *dst, t_img *src, int offset)
{
	int		i;
	int		j;
	char	*d;
	char	*s;

	i = 0;
	while (i < TILD_SIZE)
	{
		j = 0;
		while (j < TILD_SIZE)
		{
			s = src->addr
				+ (j * src->line_length
					+ (i + offset)
					* (src->bit_per_pixel / 8));
			d = dst->addr + (j
					* dst->line_length + i
					* (dst->bit_per_pixel / 8));
			if (s && d)
				*(unsigned int *)d = *(unsigned int *)s;
			j++;
		}
		i++;
	}
}

static t_img	*init_tmp_img(t_data *data, int x, int y)
{
	t_img	*new;

	new = calloc(1, sizeof(t_img));
	if (!new)
		return (NULL);
	new->img = mlx_new_image(data->mlx, x, y);
	if (!new->img)
		return (NULL);
	new->addr = mlx_get_data_addr(new->img,
			&new->bit_per_pixel,
			&new->line_length, &new->endian);
	if (!new->addr)
		return (NULL);
	return (new);
}

int	frame_layer(t_data *data, t_img *frame, t_xy dest, int frame_size)
{
	t_img	*tmp;
	int		i;

	i = 0;
	tmp = init_tmp_img(data, frame->width / frame_size, frame->height);
	if (!frame || !frame->img || !tmp)
		return (1);
	while (i < frame_size)
	{
		ft_extract_from_animation(tmp, frame, ft_get_offset(i));
		ft_put_animation_on_frame(data->frame, tmp, dest);
		mlx_put_image_to_window(data->mlx, data->window,
			data->frame->img, 0, 0);
		ft_count_move(data);
		i++;
		mlx_flush_event(data->mlx);
		monster_draw(data);
	}
	mlx_destroy_image(data->mlx, tmp->img);
	free(tmp);
	return (0);
}
