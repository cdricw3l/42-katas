/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valide_way.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:18:35 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/20 14:35:06 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void fill_arr2(char **tab, int target, t_data *data, int col, int row)
{
    
	if(col < 0 || col >= data->dimention.largeur || row < 0 ||  row  >= data->dimention.hauteur)
		return ;
		
	if(tab[row][col] == 'C' || tab[row][col] != target)
    {
        printf("item trouve : hauteur %d, largeur : %d \n", row, col);
		return ;
    }
	fill_arr2(tab, target, data, col, row - 1);
	fill_arr2(tab, target, data, col, row + 1);
	fill_arr2(tab, target, data, col - 1, row);
	fill_arr2(tab, target, data, col + 1, row);
}


void ft_check_valide_way(char **tab, t_data *data, t_dimention begin)
{
    int target;
    int counter;

    counter = 0;
    target = tab[begin.hauteur][begin.largeur];
    printf("voici la target %c\n", target);
	fill_arr2(tab, target, data, begin.largeur, begin.hauteur);
    (void)counter;
    printf("voici le counter %d\n", counter); 
}