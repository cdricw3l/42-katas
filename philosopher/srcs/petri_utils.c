/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   petri_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 08:50:09 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/13 19:26:08 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/petri_network.h"
#include "../include/philosophers.h"

int **ft_create_matrice(int p, int t, int n)
{
    int **new_matrice;
    int i;
    int j;

    new_matrice = malloc(sizeof(int *) * (p * n));
    if(!new_matrice)
        return(NULL);
    i = 0;
    while (i < p * n)
    {
        new_matrice[i] = malloc(sizeof(int) * (t * n));
        if(!new_matrice[i])
            return(ft_clean_matrice_mem(new_matrice, i));
        j = 0;
        while (j < t*n)
            new_matrice[i][j++] = 0;
        i++;
    }
    return(new_matrice);
}

void ft_join_matrice(int **old_m,int **new_m, int p, int t , int n)
{
    int i;
    int j;
    int off_set_col;
    int off_set_row;

    i = 0;
    j = 0;
    off_set_col = 0;
    off_set_row = 0;
    while (n > 0)
    {
        while(i < p)
        {
            j = 0;    
            while (j < t)
            {
                new_m[i + off_set_row][j + off_set_col] =  old_m[i][j];   //a decommenter ;
                j++;
            }
            i++;
        }
        i = 0;
        off_set_col += 3;
        off_set_row += 4;
        n--;
    }
}

int **matrice_fusion(int **m, int p, int t, int n)
{
    int **new_matrice;

    new_matrice = ft_create_matrice(p, t, n);
    if(!new_matrice)
        return(NULL);
    ft_join_matrice(m,new_matrice, p, t, n);
    ft_print_matrice(new_matrice,p, t,n);
    free(m);
    return(new_matrice);
}