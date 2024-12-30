/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valide_way.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:18:35 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/30 13:05:18 by cb               ###   ########.fr       */
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
		tab[row][col] = 'I';
		if(tmp[row][col] != 'I')
		{
			ft_counter();
			tmp[row][col] = 'I';
			printf("item row %d,  col %d\n", row, col);
		}
	}
	else if(tab[row][col] != 'I')
		tab[row][col] = ' ';

	fill_arr2(tab, tmp ,target, size, col, row - 1);
	fill_arr2(tab, tmp ,target, size, col, row + 1);
	fill_arr2(tab, tmp ,target, size, col - 1, row);
	fill_arr2(tab, tmp ,target, size, col + 1, row);
}


void ft_check_valide_way(char **tab, t_dimention *size_map, t_dimention begin)
{
    int target;
    char **tmp;

	tmp = tab;
    target = tab[begin.row][begin.col];
    printf("voici la target %c\n", target);
	fill_arr2(tab, tmp,target, size_map, begin.col, begin.row);
    ft_print_map(tab, size_map->row, size_map->row);
    
}