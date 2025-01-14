/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xy_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:12:48 by cb                #+#    #+#             */
/*   Updated: 2025/01/14 01:25:16 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/so_long_bonus.h"

void	print_dimention(t_xy_data xy_arr, int c)
{
	t_xy	xy;

	if (c == 1)
		xy = xy_arr.begin;
	else if (c == 2)
		xy = xy_arr.exit;
	else if (c == 3)
		xy = xy_arr.map;
	else if (c == 4)
		xy = xy_arr.screen_size;
	ft_printf(" ==> [ data ] xy: row: %d col: %d\n",
		xy.row, xy.col);
}

t_xy	rescal(t_xy xy, int scal_factor)
{
	t_xy	new_xy;

	new_xy.col = xy.col * scal_factor;
	new_xy.row = xy.row * scal_factor;
	return (new_xy);
}

int	get_area(t_xy xy)
{
	return (xy.col * xy.row);
}

t_xy	ft_s_dimention(void)
{
	t_xy	dimention;

	dimention.col = 0;
	dimention.row = 0;
	return (dimention);
}
