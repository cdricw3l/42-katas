/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:32:15 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/16 20:30:27 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_print(int *arr, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		printf("%d ", arr[i]);
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
void ft_sort(int *arr, int *tmp, int len, int exp)
{
	int i;
	int digit;
	//int h;
	int cumulatif_arr[10] = {0};

	i = 0;

	//etape 1 etablire le compte pour chaque digit.
	while (i < len)
	{
		digit = (tmp[i] / exp) % 10;
		cumulatif_arr[digit]++;
		i++;
	}
	ft_print(cumulatif_arr, 10);

	// etablire le tableau cumulatif;
	printf("\n");
	i = 1;
	while (i < len)
	{
		cumulatif_arr[i] = cumulatif_arr[i] + cumulatif_arr[i - 1];
		i++;
	}
	ft_print(cumulatif_arr, 10);
	printf("\n");
	// h = len - 1;
	// while (h >= 0)
	// {
	// 	digit = (tmp[h] / exp) % 10;

	// }
	

	// processer
	(void)arr;
}

void ft_radix_sort(int *arr, int len)
{
	int exp;
	int max;
	int *tmp;

	exp = 1;
	max = ft_get_max(arr, len);
	tmp = arr;
	if (max == -1)
		return ; 
	while (max / exp > 0)
	{
		ft_sort(arr, tmp, len, exp);
		printf("\n");
		exp *= 10;
	}
	//sft_print(arr, len);
}

int main()
{
	int arr[] = {100, 1000, 1, 33, 54, 77, 3455};
	int len = sizeof(arr) / sizeof(arr[0]);

	ft_radix_sort(arr, len);
	return(0);
}