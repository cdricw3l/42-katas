/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:43:22 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/31 19:25:36 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_process_set(t_game_data *data, char c, int row, int col)
{
	if (data)
	{
		if (c == 'C')
			data->count_item++;
		if (c == 'E')
		{
			data->exit_position.col = col;
			data->exit_position.row = row;
			data->count_exit++;
		}
		if (c == 'P')
		{
			data->begin.row = row;
			data->begin.col = col;
			data->count_begin++;
		}
	}
}

int	ft_check_param(t_game_data *data, char *path)
{
	char	*set;
	int		i;
	int		j;

	i = 0;
	set = "01CEP";
	if (ft_check_dimentions(data))
		return (ft_check_dimentions(data));
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] && data->map[i][j] != '\n')
		{
			if (ft_isset(data->map[i][j], set))
				ft_process_set(data, data->map[i][j], i, j);
			else
				return (2);
			j++;
		}
		i++;
	}
	if (data->count_exit + data->count_begin != 2)
		return (3);
	data->map_name = path;
	return (0);
}

int	ft_check_dimentions(t_game_data *data)
{
	int	row;
	int	col;
	int	j;
	int	i;

	row = ft_arr_len(data->map);
	i = 0;
	j = -1;
	while (i < row)
	{
		if (i < row - 1)
			col = ft_strlen(data->map[i]) - 1;
		else
			col = ft_strlen(data->map[i]);
		if (col != j && j != -1)
			return (1);
		j = col;
		i++;
	}
	if (ft_is_close(data->map, row, j))
		return (2);
	data->dimention.col = j;
	data->dimention.row = row;
	return (0);
}

int	ft_is_close(char **map, int hauteur, int largeur)
{
	int	i;
	int	j;

	i = 0;
	if (hauteur == largeur)
		return (1);
	while (i < hauteur)
	{
		j = 0;
		while (j < largeur)
		{
			if (i == 0 || i == hauteur - 1)
			{
				if (map[i][j] != 49)
					return (1);
			}
			else
				if (j == 0 || j == largeur - 1)
					if (map[i][j] != 49)
						return (1);
			j++;
		}
		i++;
	}
	return (0);
}
