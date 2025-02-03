/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_check_valide_way_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:18:35 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/17 12:02:50 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/initialisation_bonus.h"

static void	*ft_clean_arr(char **arr, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(arr[j++]);
	free(arr);
	return (NULL);
}

static	char	**ft_tmp_arr(char **arr, t_xy map)
{
	char	**tmp;
	int		height;
	int		i;

	height = map.row;
	i = 0;
	tmp = malloc(sizeof(char *) * height);
	if (!tmp)
		return (NULL);
	while (i < height)
	{
		tmp[i] = ft_strdup(arr[i]);
		if (!tmp[i])
			return (ft_clean_arr(tmp, i));
		i++;
	}
	return (tmp);
}

static void	fill_arr(char **tab, t_data *data, int col, int row)
{
	t_xy	size;

	size = data->xy_data.map;
	if (tab[row][col] != '0' && tab[row][col] != 'P'
			&& tab[row][col] != 'C' && tab[row][col] != 'E')
		return ;
	if (tab[row][col] == 'C')
	{
		data->check_item++;
		data->map[row][col] = 'X';
	}
	if (tab[row][col] == 'E')
		data->count_exit--;
	tab[row][col] = ' ';
	if (row > 1)
		fill_arr(tab, data, col, row - 1);
	if (row < size.row - 1)
		fill_arr(tab, data, col, row + 1);
	if (col > 1)
		fill_arr(tab, data, col - 1, row);
	if (col < size.col - 1)
		fill_arr(tab, data, col + 1, row);
}

int	check_valide_way(t_data *data)
{
	char		**tab;
	char		**tmp;
	t_xy		begin;

	if (!data->map)
		return (1);
	tab = data->map;
	begin = data->xy_data.begin;
	tmp = ft_tmp_arr(tab, data->xy_data.map);
	if (!tmp)
		return (1);
	fill_arr(tmp, data, begin.col, begin.row);
	ft_clean_arr(tmp, data->xy_data.map.row);
	if (data->check_item != data->count_item)
		return (1);
	if (data->count_exit != 0)
		return (2);
	print_map(data);
	return (0);
}
