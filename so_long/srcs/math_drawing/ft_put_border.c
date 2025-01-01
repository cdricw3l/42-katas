/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_border.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:43:22 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/01 17:24:37 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_put_border(t_data *data, t_border b)
{
	int	i;
	int	j;

	i = 0;
	while (i <= b.size.col)
	{
		j = 0;
		while (j <= b.size.row)
		{
			if (i <= b.border_size
				|| (i >= b.size.col - b.border_size && i <= b.size.col))
				mlx_pixel_put(data->mlx, data->window,
				j + b.targ.col-b.size.col / 2, i + b.targ.row - b.size.row /2, b.b_color);
			else
				if(j<= b.border_size || (j >= b.size.col - b.border_size && j<= b.size.col))
					mlx_pixel_put(data->mlx, data->window,
					j + b.targ.col - b.size.col/ 2, i + b.targ.row - b.size.row/2, b.b_color);
			else
				if (b.r_color)
					mlx_pixel_put(data->mlx, data->window, 
					j + b.targ.col - b.size.col/ 2, i + b.targ.row - b.size.row/2, b.r_color);
			j++;
		}
		i++;
	}
}