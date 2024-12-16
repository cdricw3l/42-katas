/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:32:15 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/16 21:43:01 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include <strings.h>

void ft_print_arr(int *arr, int len)
{
	int i;

	i = 0;
	while (i < len)
		printf("%d ", arr[i++]);
}

void	ft_arr_cpy(int *src, int *dst, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	
}

int ft_get_max(int *arr, int len)
{
	int i;
	int max;

	i = 0;
	if (!arr || len == 0)
		return (-1);
	while(i < len)
	{
		if(arr[i] > max)
			max = arr[i];
		i++;
	}
	return(max);
}

void	ft_count_digit(int *arr, int *cumulatif, int len, int exp)
{
	int i;
	int digit;

	i = 0;
	while (i < len)
	{
		digit = (arr[i] / exp) % 10;
		cumulatif[digit]++;
		i++;
	}
}
void ft_cumulatif_arr(int *cumulatif_arr)
{
	int i;
	
	i = 1;
	while (i < 10)
	{
		cumulatif_arr[i] += cumulatif_arr[i - 1];
		i++;
	}
}
void ft_sort(int *arr, int *tmp ,int len, int exp)
{
	int digit;
	int h;
	int cumulatif_arr[10];

	// etape zero, mettre a initialiser a zero le tableau cumulatif.
	ft_bzero(cumulatif_arr, len, 4);
	//etape 1 etablire le compte pour chaque digit.
	ft_count_digit(arr, cumulatif_arr, len, exp);
	ft_cumulatif_arr(cumulatif_arr);
	h = len - 1;
	while (h >= 0)
	{
		digit = (arr[h] / exp) % 10;
		tmp[cumulatif_arr[digit] - 1] = arr[h];
		cumulatif_arr[digit]--;
		h--;
	}
	ft_memcpy(arr,tmp,len * sizeof(int));
}

void ft_radix_sort(int *arr, int len)
{
	int exp;
	int max;
	int *tmp;

	tmp = malloc(len * sizeof(int));
	if(!tmp)
		return ;
	exp = 1;
	max = ft_get_max(arr, len);
	if (max == -1)
		return ; 
	while (max / exp > 0)
		ft_sort(arr, tmp ,len, exp *= 10);
}

int main()
{
	int arr[] = {100, 1000, 1, 33, 54, 77, 3455};
	int len = sizeof(arr) / sizeof(arr[0]);

	ft_radix_sort(arr, len);
	ft_print_arr(arr, len);
	return(0);
}