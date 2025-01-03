/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valide_way.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:18:35 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/31 19:42:24 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	fill_arr2(int target, t_game_data *data, int col, int row)
{
	int		h;
	int		w;
	char	**tab;
	char	c;

	tab = data->map;
	h = data->dimention.row;
	w = data->dimention.col;
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
	ft_print_map(data);
}

int	ft_check_valide_way(t_game_data *g_data)
{
	char		**tab;
	int			target;
	t_dimention	begin;

	if (!g_data)
		return(1);
	tab = g_data->map;
	begin = g_data->begin;
	target = tab[begin.row][begin.col];
	printf("Recherche d'un chemin valide ... %d\n", g_data->check_item);
	fill_arr2(target, g_data, begin.col, begin.row);
	ft_print_map(g_data);
	if (g_data->check_item != g_data->count_item)
	{
		printf("Il n'y a pas de chemin valide. %d\n", g_data->check_item);
		return(1);
	}
	return(0);
}
