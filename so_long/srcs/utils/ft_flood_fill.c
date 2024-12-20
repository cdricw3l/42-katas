/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:47:03 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/20 19:08:29 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	fill_arr(char **tab, int target, t_dimention size, int col, int row)
{
	if(col < 0 || col >= size.largeur || row < 0 ||  row  >= size.hauteur)
		return ;
		
	if(tab[row][col] == 'F' || tab[row][col] != target)
		return ;

	tab[row][col] = 'F';
    
	fill_arr(tab, target, size, col, row - 1);
	fill_arr(tab, target, size, col, row + 1);
	fill_arr(tab, target, size, col - 1, row);
	fill_arr(tab, target, size, col + 1, row);
}


void ft_flood_fill(char **tab, t_dimention size, t_dimention begin)
{
    int target;

    target = tab[begin.hauteur][begin.largeur];
	fill_arr(tab, target, size, begin.largeur, begin.hauteur);
}
