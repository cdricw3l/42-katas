/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valide_way.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:18:35 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/22 10:38:31 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_counter(void)
{
	static int counter_i;

	counter_i++;
	printf("voici le counter %d\n", counter_i);
}


void	fill_arr2(char **tab, char **tmp, int target,t_dimention *size, int col, int row)
{
	if(col < 0 || row >= size->row || row < 0 ||  col  >= size->col )
		return ;
		
	if(tab[row][col] == ' ' || (tab[row][col] == '1' ))
		return ;

	if(tab[row][col] == 'C')
	{
		tab[row][col] = 'X';
		if(tmp[row][col] != 'X')
		{
			ft_counter();
			tmp[row][col] = 'X';
			printf("item row %d,  col %d\n", row, col);
		}
	}
	else if(tab[row][col] != 'X')
		tab[row][col] = ' ';

	fill_arr2(tab, tmp ,target, size, col, row - 1);
	fill_arr2(tab, tmp ,target, size, col, row + 1);
	fill_arr2(tab, tmp ,target, size, col - 1, row);
	fill_arr2(tab, tmp ,target, size, col + 1, row);
}


void ft_check_valide_way(char **tab, t_data *data, t_dimention begin)
{
    int target;
    int fd;
    char **tmp;

	tmp = tab;
    fd = open("/home/cb/Documents/42K/so_long/srcs/check_params/item_output", O_APPEND);
    if(fd == -1)
        printf("Erreur d'impression de l 'item output check\n");
    else
        printf("voici le file descriptor %d\n", fd);
    target = tab[begin.row][begin.col];
    printf("voici la target %c\n", target);
	fill_arr2(tab, tmp,target, &data->game_data.dimention, begin.col, begin.row);
    ft_print_map(tab, data->game_data.dimention.row, data->game_data.dimention.col, fd);
    
}