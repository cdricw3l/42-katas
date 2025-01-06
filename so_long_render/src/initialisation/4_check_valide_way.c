/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_check_valide_way.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:18:35 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/06 00:50:14 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/initialisation.h"

void	fill_arr2(int target, t_data *data, int col, int row)
{
	int		h;
	int		w;
	char	**tab;
	char	c;

	tab = data->map;
	h = data->xy_data.exit.row;
	w = data->xy_data.exit.col;
	c = tab[row][col];
	if (tab[row][col] == 'C')
	{
		data->check_item++;
		tab[row][col] = 'X';
	}
	else if (tab[row][col] == '0'|| tab[row][col] == 'E')
		tab[row][col] = ' ';
	if(!ft_isset(c," 1X"))
	{
		if (col > 1 || row < h || row > 1 || col < w)
		{
			if(data->count_item > data->check_item)
			{
				fill_arr2(target, data, col, row - 1);
				fill_arr2(target, data, col, row + 1);
				fill_arr2(target, data, col - 1, row);
				fill_arr2(target, data, col + 1, row);
			}
		}
	}
	print_map(data);
}

int	check_valide_way(t_data *data)
{
	char		**tab;
	int			target;
	t_xy		begin;

	if (!data)
		return(1);
	tab = data->map;
	begin = data->xy_data.begin;
	target = tab[begin.row][begin.col];
	fill_arr2(target, data, begin.col, begin.row);
	print_map(data);
	if (data->check_item != data->count_item)
		return(error_layer(ERR_VALIDE_WAY));
	return(0);
}
