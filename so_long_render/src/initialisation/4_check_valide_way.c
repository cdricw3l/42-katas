/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_check_valide_way.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:18:35 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/06 23:49:18 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/initialisation.h"

void	fill_arr2(int target, t_data *data, int col, int row)
{
	int		h;
	int		w;
	char	**tab;

	tab = data->map;
	h = data->xy_data.map.row;
	w = data->xy_data.map.col;

	printf("target %c\n",target);
	if (col < 1 || col > w ||  row > h || row < 1 )
	{

		return;
	}
	if (tab[row][col] == 'C')
		data->check_item++;
	if (tab[row][col] == target)
		return;
	else if (tab[row][col] == '0'|| tab[row][col] == 'E' || tab[row][col] == '1')
		tab[row][col] = ' ';
	fill_arr2(target, data, col, row - 1);
	fill_arr2(target, data, col, row + 1);
	fill_arr2(target, data, col - 1, row);
	fill_arr2(target, data, col + 1, row);
	print_map(data);
}

int	check_valide_way(t_data *data)
{
	char		**tab;
	int			target;
	t_xy		begin;

	print_dimention(data->xy_data,'b');
	if (!data)
		return(1);
	tab = data->map;
	begin = data->xy_data.begin;
	target = tab[begin.row][begin.col];
	fill_arr2(target, data, begin.col, begin.row);
	//print_map(data);
	if (data->check_item != data->count_item)
		return(1);
	return(0);
}
int main()
{
	t_data *data;
	t_img	**image_set;

	data = initialisation_and_check("/home/cb/Documents/42K/so_long_render/map/map2.ber");
	if(!data->map)
		return(1);
	image_set = malloc(sizeof(t_img *) * IMG_SET_SIZE);
	if (!image_set)
		return (1);
	ft_display_data_info(data);
	//check_valide_way(data);
	free_memory(data, 1);
	return(0);
}