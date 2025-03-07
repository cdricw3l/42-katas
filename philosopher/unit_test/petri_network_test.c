/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   petri_network_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:55:10 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/07 19:54:19 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/petri_network.h"
#include "../include/philosophers.h"

int	main(void)
{   
    int P = 4;
    int T = 3;
    
    int **M_plus;
    int arr2[4][3] = {{0,1,2}, {3,4,5}, {6,7,8}, {9,10,11}};
    
    M_plus = ft_copy_matrice(&arr2,P, T);
    
    ft_printm(M_plus, P, T);
	return(0);
}