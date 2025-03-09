/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   petri_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 08:50:09 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/09 11:51:14 by cw3l             ###   ########.fr       */
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

void ft_join_matrice(int **m, int p, int t, int x ,int y)
{
    if(x < 0)
    {
        printf("\n");
        return ;
    }
    if(y < 0)
    {
        printf("\n");
        ft_join_matrice(m, p, t, x - 1, t - 1);
        return ;
    }
    printf("%d ", m[x][y]);
    ft_join_matrice(m,p,t, x , y - 1);
}

int **matrice_fusion(int **m, int p, int t, int n)
{
    int **new_matrice;

    new_matrice = ft_create_matrice(p, t, n);
    if(!new_matrice)
        return(NULL);
    // if(ft_joint_matrice(m, p, t, n) == -1)
    //     return(ft_clean_matrice_mem(new_matrice, p * n));
    assert(p == 4 && t == 3);
    ft_join_matrice(m, p, t,p -1,t -1);
    free(m);
    return(new_matrice);
}