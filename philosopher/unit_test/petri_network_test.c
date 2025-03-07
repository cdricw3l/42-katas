/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   petri_network_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:55:10 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/07 17:14:58 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/petri_network.h"
#include "../include/philosophers.h"

int	main(void)
{   
    int P = 4;
    int T = 3;

    int arr[4][3]= {{1,2,3},{4,5,6}, {7, 8, 9}, {10, 11, 12}};
    int **cpy = ft_copy_matrice(arr, P, T);
    ft_printm(cpy, 4, 3);
	return(0);
}