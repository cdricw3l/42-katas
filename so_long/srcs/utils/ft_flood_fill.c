/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:47:03 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/21 10:37:23 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	counter(void)
{
	static int counter;

	counter++;
	printf("voici le counter %d\n", counter);
}


void	fill_arr(char **tab, char **tmp, int target,t_point *size, int col, int row)
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
			counter();
			tmp[row][col] = 'X';
			printf("item row %d,  col %d\n", row, col);
		}
	}
	else if(tab[row][col] != 'X')
		tab[row][col] = ' ';

	fill_arr(tab, tmp ,target, size, col, row - 1);
	fill_arr(tab, tmp ,target, size, col, row + 1);
	fill_arr(tab, tmp ,target, size, col - 1, row);
	fill_arr(tab, tmp ,target, size, col + 1, row);
}
