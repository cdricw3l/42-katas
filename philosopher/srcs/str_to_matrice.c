/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_matrice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 08:34:00 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/08 11:21:14 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/str_to_matrice.h"

int **ft_str_to_matrice(char *str, int x, int y)
{
    char **split;
    int **M;
    int i;
    int j;
    int k;
    
    if(!str)
        return(NULL);
    split = ft_split(str, 32);
    if(!split)
        return(NULL);
    assert(ft_split_len(split) == (x * y));
    if(ft_split_len(split) != (x * y))
        return(ft_clean_split(split, ft_split_len(split)));
    M = malloc(sizeof(int *) * x);
    if(!M)
        return(NULL);
    i = 0;
    k = 0;
    while (i < x)
    {
        M[i] = malloc(sizeof(int) * y);
        if(!M[i])
            return(ft_clean_matrice_mem(M,i));
        j = 0;
        while (j < y)
        {
            M[i][j] = ft_atoi_long(split[k]);
            k++;
            j++;
        }
        i++;
    }
    return(M);
}
