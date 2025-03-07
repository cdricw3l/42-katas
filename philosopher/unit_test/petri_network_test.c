/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   petri_network_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:55:10 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/07 19:28:03 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/petri_network.h"
#include "../include/philosophers.h"

int	main(void)
{   
    int P = 4;
    int T = 3;
    int i;
    int j;
    
    int **arr;
    
    arr = malloc(sizeof(int *) * P);
    if(!arr)
        return(1);
    i = 0;
    while (i < P)
    {
        arr[i] = malloc(sizeof(int) * T);
        if(!arr[i])
        {
            perror("Err ");
            return(((long)ft_clean_matrice_mem(arr, i)));
        }
        j = 0;
        while (j < T)
        {
            arr[i][j] = 0;
            j++;
        }
        i++;
    }
    
    int **cpy = ft_copy_matrice(arr, P, T);
    (void)cpy;
    ft_printm(cpy, P, T);
	return(0);
}