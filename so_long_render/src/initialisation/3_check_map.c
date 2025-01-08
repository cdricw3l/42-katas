/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_check_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:43:22 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/08 03:04:30 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/initialisation.h"

int ft_arr_len(char **arr)
{
    int i;

    i = 0;
    if(arr)
    {
        while (arr[i] != NULL)
            i++;
        return(i);
    }
    return (-1);
}

int	is_close(char **map, int hauteur, int largeur)
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

int	check_dimentions(t_data **data)
{
	int	row;
	int	col;
	int	j;
	int	i;

	row = ft_arr_len((*data)->map);
	i = 0;
	j = -1;
	while (i < row)
	{
		if (i < row - 1)
			col = ft_strlen((*data)->map[i]) - 1;
		else
			col = ft_strlen((*data)->map[i]);
		if (col != j && j != -1)
			return (ERR_LINE_LEN);
		j = col;
		i++;
	}
	if (is_close((*data)->map, row, j))
		return (ERR_NOTCLOSE);
	(*data)->xy_data.map.col = j;
	(*data)->xy_data.map.row = row;

	return (0);
}

void	process_set(t_data **data, char c, int row, int col)
{
	
	if (data)
	{
		if (c == 'C')
			(*data)->count_item++;
		if (c == 'E')
		{
			(*data)->xy_data.exit.col = col;
			(*data)->xy_data.exit.row = row;
			(*data)->count_exit++;
		}
		if (c == 'P')
		{
			
			(*data)->xy_data.begin.row = row;
			(*data)->xy_data.begin.col = col;
			if((*data)->xy_data.begin.col > (*data)->xy_data.map.col / 2)
			{
				(*data)->char_state = LEFT;
				printf("state : %d\n",(*data)->char_state);
			}
			else
			{
				(*data)->char_state = RIGHT;
				printf("state : %d\n",(*data)->char_state);

			}
			(*data)->count_begin++;
		}
	}
}

int	check_map(t_data **data, char *path)
{
	char	*set;
	int		i;
	int		j;

	i = 0;
	set = "01CEP";
	if (check_dimentions(data))
		return (check_dimentions(data));
	while ((*data)->map[i])
	{
		j = 0;
		while ((*data)->map[i][j] && (*data)->map[i][j] != '\n')
		{
			if (ft_isset((*data)->map[i][j], set))
				process_set(data, (*data)->map[i][j], i, j);
			else
				return (ERR_NOTINSET);
			j++;
		}
		i++;
	}
	if ((*data)->count_exit + (*data)->count_begin != 2)
		return (ERR_DUPLICATE);
	(*data)->map_name = path;
	return (0);
}

