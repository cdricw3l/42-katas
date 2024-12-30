/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valide_way.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:18:35 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/30 18:18:11 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	fill_arr2(int target, t_game_data *data, int col, int row)
{
	int		h;
	int		w;
	char	**tab;

	tab = data->map;
	h = data->dimention.row;
	w = data->dimention.col;
	if (col < 0 || row >= h || row < 0 || col >= w)
		return ;
	if (tab[row][col] == ' ' || (tab[row][col] == '1' ))
		return ;
	if (tab[row][col] == 'C')
	{
		printf("itemp touvé\n");
		data->count_item--;
		tab[row][col] = 'X';
	}
	else if (tab[row][col] == '0')
		tab[row][col] = ' ';
	fill_arr2(target, data, col, row - 1);
	fill_arr2(target, data, col, row + 1);
	fill_arr2(target, data, col - 1, row);
	fill_arr2(target, data, col + 1, row);
}

void	ft_check_valide_way(t_game_data *g_data)
{
	char		**tab;
	int			target;
	t_dimention	begin;

	tab = g_data->map;
	begin = g_data->begin;
	target = tab[begin.row][begin.col];
	printf("Recherche d'un chemin valide ...\n");
	fill_arr2(target, g_data, begin.col, begin.row);
	ft_print_map(g_data);
	if (g_data->count_item > 0)
		printf("Il n'y a pas de chemin valide. %d\n", g_data->count_item);
}
