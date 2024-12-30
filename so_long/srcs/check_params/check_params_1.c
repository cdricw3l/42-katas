/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:13:33 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/30 12:10:06 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"



void	check_list_param(char c, t_data *data, int row, int col)
{
	if (c == '0')
		data->check_list.check_list[0] = 1;
	if (c == '1')
		data->check_list.check_list[1] = 1;
	if (c == 'C')
		data->check_list.check_list[2] = 1;
	if (c == 'E')
		data->check_list.check_list[3] = 1;
	if (c == 'P')
	{
		data->game_data.begin.row = row;
		data->game_data.begin.col = col;
		data->check_list.check_list[4] = 1;
	}
}

int	ft_count_params(int arr[6])
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 6)
		count += arr[i++];
	return(count);
}

int	ft_check_params(t_data *data)
{
	int		i;
	int		j;
	char	*set;

	i = 0;
	set = "01CEP";
	if(!data->game_data->map || (data->game_data->dimention.row == 0 || data->game_data->dimention.row == 0))
		return(1);
	while (i < data->game_data.dimention.row)
	{
		j = 0;
		while (j < data->game_data.dimention.col)
		{
			if (ft_isset(data->game_data.map[i][j], set))
			{
				check_list_param(data->game_data.map[i][j], data, i, j);
				j++;
			}
			else
				return(1);
		}
		i++;
	}
	if(!is_close_and_rectangle(data->game_data.map, data->game_data.dimention.row, data->game_data.dimention.col))
		data->check_list.check_list[5] = 1;
	if(ft_count_params(data->check_list.check_list) != 6)
	{
		printf("Le nombre de parametre n'est pas juste:  %d\n",ft_count_params(data->check_list.check_list) );
		return(1);
	}
	return (0);
}

// int main()
// {
// 	int check_arr[5];
// 	char *no_close_map = "../../map/map2.ber";
// 	int     fd;
// 	t_data  map;
// 	char **m;
// 	fd = open(no_close_map, O_RDONLY);
//     if (fd == -1)
//     {
//         printf("erreur  d'vouverture du fichier: %s \n", no_close_map );
//         return (1);
//     }
// 	ft_get_dimentions(fd, &map);
// 	m = ft_parse_params(no_close_map, map.dimention.hauteur, map.dimention.largeur);
// 	int check = ft_check_params(m,check_arr,map.dimention.hauteur, map.dimention.largeur );

// 	printf("voici la valeur %d\n", check);
// 	return(0);
// }