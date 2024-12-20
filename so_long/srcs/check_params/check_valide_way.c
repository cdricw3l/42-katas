/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valide_way.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:18:35 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/20 16:58:39 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void fill_arr2(char **tab, int target, t_data *data, int col, int row)
{
    
	if(col < 0 || col >= data->dimention.largeur || row < 0 ||  row  >= data->dimention.hauteur)
    {
        printf("retour\n");
		return ;
    }   

		
	if(tab[row][col] != 'P' || tab[row][col] != '0' || tab[row][col] != 'C' || tab[row][col] != 'E')
    {
        printf("retour  %c \n", tab[row][col]);
		return ;
    }

    
    tab[row][col] = 'X';
            
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
	fill_arr2(tab, target, data, begin.largeur +1, begin.hauteur);
    (void)counter;
    printf("voici le counter %d\n", counter); 

    ft_print_map(tab, data->dimention.hauteur, data->dimention.largeur);
    
}