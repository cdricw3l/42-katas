/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:48:45 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/16 12:04:39 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print(int *arr, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
	
}

void	ft_copy_arr_int(int *arr, int *tmp, int len)
{
	int i;

	i = 0;
	while (i <  len)
	{
		tmp[i] = arr[i];
		i++;
	}
}

void	ft_arr_of_count_digt(int *arr, int *arr_count, int len, int exp)
{
	int	i;
	int	digit;

	i = 0;
	if (arr && len > 0)
	{
		while (i < len)
		{
			digit = (arr[i] / exp) % 10;
			arr_count[digit]++;
			i++;
		}
	}
	i = 1;
	while (i < len)
	{
		arr_count[i] += arr_count[i - 1];
		i++;
	}
}

void	ft_count_sort(int *arr, int *tmp, int len, int exp)
{
	int	cumulatif_arr[10];

	ft_bzero(cumulatif_arr,10, sizeof(int));
	ft_arr_of_count_digt(arr, cumulatif_arr, len, exp);
	ft_print(cumulatif_arr,10);
	while (len - 1 > 0)
	{
		arr[(cumulatif_arr[(tmp[len - 1] / exp) % 10]) - 1] = tmp[len -1];
		cumulatif_arr[(arr[len - 1] / exp) % 10]--;
	}
	ft_print(tmp, 10);
}

void	ft_radix_sort(int *arr, int len)
{
	int	exp;
	//int	max_value;
	int	*tmp;

	exp = 10;
	//max_value = ft_get_max_value(arr, len);
	tmp = malloc(len * sizeof(int));
	if (!tmp)
		return ;
	ft_copy_arr_int(arr, tmp, len);
	while (exp == 10)
	{
		ft_count_sort(arr, tmp, len, exp);
		exp *= 10;
	}
}

int main(void)
{
	int arr[] = {1000, 1, 200, 3, 44, 5, 650, 7, 8, 9};
	ft_radix_sort(arr, 10);
	ft_print(arr, 10);


	// int	count_digit[10];
	// int	cumulatif_arr[10];

	// ft_arr_of_count_digt(arr, count_digit,10, 10);
	// ft_print(count_digit, 10);
	// ft_cumulatif_arr(count_digit,cumulatif_arr,10);

}