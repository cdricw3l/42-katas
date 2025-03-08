/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_matrice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 08:34:00 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/08 08:55:10 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/str_to_matrice.h"

int **ft_str_to_matrice(char *str, int x, int y)
{
    char **split;
    int **M;
    
    (void)x;
    (void)y;
    if(!str)
        return(NULL);
    split = ft_split(str, 32);
    if(!split)
        return(NULL);
    M = malloc(sizeof(int *) * x);
    if(!M)
        return(NULL);
    return(NULL);
}