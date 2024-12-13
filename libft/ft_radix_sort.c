/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:48:45 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/13 18:57:45 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_radix_sort(int *arr, int len)
{
    int i;
    int bit;

    i = 0;
    bit = 7;

    while (i < len - 1)
    {
        int a = (arr[i] >> bit) & 1; 
        int b = (arr[i + 1] >> bit) & 1; 
        printf("voici l'entier: %d, sont bit i : %d\n et l'entier + 1: %d et sont bit: %d\n\n",arr[i],a, arr[i + 1],b);
        i++;
    }
    
}

int main()
{
    int arr[] = {3,1,10,2,24};
    int len = sizeof(arr) / sizeof(arr[0]);

    ft_radix_sort(arr, len);
    return (0);
}