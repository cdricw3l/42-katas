/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:48:45 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/14 06:21:56 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_print_arr(int *arr, int len)
{
	int i;

	i = 0;
	while (i < len)
		printf(" %d", arr[i++]);
	printf("\n");
}

int	ft_get_max_value(int *arr, int size)
{
	int	i;
	int	high;

	i = 1;
	high = arr[0];
	while (i < size)
	{
		if (arr[i] > high)
			high = arr[i];
		i++;
	}
	return (high);
}

void ft_arr_of_count_digt(int *arr, int *arr_count, int len, int exp)
{
    int i;
    int digit;

    i = 0;
    if(arr && len > 0)
    {
        while (i < len)
        {
            digit = (arr[i] / exp) % 10;
            arr_count[digit] += 1;
            i++; 
        }
    }
}

void    ft_count_sort(int *arr, int len, int exp)
{
    int count_digit[10];

    ft_arr_of_count_digt(arr,count_digit, len, exp);

}

void    ft_radix_sort(int *arr, int len)
{
    int exp;
    int max_value;

    exp = 1;
    max_value = ft_get_max_value(arr, len);

    while ( max_value / exp > 0)
    {
        ft_count_sort(arr, len, exp);
        exp *= 10;
    }
    
}

int main()
{
    int arr[] = {10, 100, 11, 24, 243, 34, 2};
    int len = sizeof(arr) / sizeof(arr[0]);
    int c[10] = {0};
    ft_arr_of_count_digt(arr, c,len, 1);

    ft_print_arr(c, 7);
    
    //ft_radix_sort(arr, len);
    return (0);
}