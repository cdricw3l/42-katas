/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:59:18 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/14 01:47:02 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/hook_managment_bonus.h"

static int	ft_is_keycode_in_set(int keycode)
{
	if (keycode == 97
		|| keycode == 100
		|| keycode == 115
		|| keycode == 119
		|| keycode == 65361
		|| keycode == 65362
		|| keycode == 65363
		|| keycode == 65364)
		return (0);
	return (1);
}

static void	ft_update_mouvement(t_data **d, t_xy *begin, t_xy init)
{
	(*d)->count_mouvement++;
	if ((*d)->map[begin->row][begin->col] == 'X')
	{
		(*d)->count_item--;
		if ((*d)->count_item == 0)
			(*d)->map[(*d)->xy_data.exit.row][(*d)->xy_data.exit.col] = 'E';
		(*d)->map[begin->row][begin->col] = 'P';
		(*d)->map[init.row][init.col] = 'Z';
	}
	else
	{
		if ((*d)->map[begin->row][begin->col] == 'E')
			if ((*d)->count_item == 0)
				exit_game(*d, ERR_WIN);
		(*d)->map[begin->row][begin->col] = 'P';
		(*d)->map[init.row][init.col] = 'Z';
	}
	ft_image_drawer(*d);
	print_map(*d);
}

static int	ft_check_target(t_data **data, char c)
{
	if (c != '1' && c != 'E' && c != 'M')
		return (1);
	if (c == 'E' && (*data)->count_item == 0)
		return (1);
	return (0);
}

static void	ft_update_position(t_data **d, int key, t_xy *b)
{
	t_xy	i;

	i.row = b->row;
	i.col = b->col;

	if (key == XK_a || key == XK_Left)
		if (ft_check_target(d, (*d)->map[b->row][b->col - 1]))
			b->col -= 1;
	if (key == XK_s || key == XK_Down)
		if (ft_check_target(d, (*d)->map[b->row + 1][b->col]))
			b->row += 1;
	if (key == XK_d || key == XK_Right)
		if (ft_check_target(d, (*d)->map[b->row][b->col + 1]))
			b->col += 1;
	if (key == XK_w || key == XK_Up)
		if (ft_check_target(d, (*d)->map[b->row - 1][b->col]))
			b->row -= 1;
	if (i.row != b->row || i.col != b->col)
		ft_update_mouvement(d, b, i);
}

int	manage_keyboard(int keycode, t_data *data)
{
	t_xy	*begin;

	begin = &data->xy_data.begin;
	if (keycode == 65363)
		data->char_state = RIGHT;
	if (keycode == 65361)
		data->char_state = LEFT;
	if (!ft_is_keycode_in_set(keycode))
		ft_update_position(&data, keycode, begin);
	if (keycode == XK_Escape || keycode == 79933840)
		exit_game(data, 76);
	return (0);
}
