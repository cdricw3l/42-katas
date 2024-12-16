/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:48:45 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/16 14:45:12 by cw3l             ###   ########.fr       */
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
	ft_print(arr_count, 10);
}

void	ft_count_sort(int *arr, int *tmp, int len, int exp)
{
	int	cumulatif_arr[10] = {0};
	int digit;

	//ft_bzero(cumulatif_arr,10, sizeof(int));
	ft_arr_of_count_digt(arr, cumulatif_arr, len, exp);
	while (len > 0)
	{
		// printf("voici le digit %d et la taille %d et le count %d\n", digit, len, count);
		digit = (arr[len - 1] / exp) % 10;
		printf("%d\n", cumulatif_arr[digit] - 1);
		printf("le digit : %d, len %d et arr[0] %d etz exp %d\n",arr[len - 1], len, cumulatif_arr[digit], exp);
		arr[cumulatif_arr[digit] - 1] = tmp[len - 1];
		// if(exp == 1000)
		// 	ft_print(cumulatif_arr,10);
		cumulatif_arr[digit]--;
		len--;
	}
	free(tmp);
}

void	ft_radix_sort(int *arr, int len)
{
	int	exp;
	int	max_value;
	int	*tmp;

	exp = 10;
	max_value = ft_get_max_value(arr, len);
	tmp = malloc(len * sizeof(int));
	if (!tmp)
		return ;
	ft_copy_arr_int(arr, tmp, len);
	while (max_value / exp > 0)
	{
		ft_count_sort(arr, tmp, len, exp);
		exp *= 10;
	}
}

int main(void)
{
	int arr[] = {1000, 1, 200, 3, 44, 5, 650, 7, 8, 9};
	ft_radix_sort(arr, 10);
	//ft_arr_of_count_digt(arr, arr_count, 10, 1000);
	ft_print(arr, 10);

	// int	count_digit[10];
	// int	cumulatif_arr[10];

	// ft_arr_of_count_digt(arr, count_digit,10, 10);
	// ft_print(count_digit, 10);
	// ft_cumulatif_arr(count_digit,cumulatif_arr,10);

}