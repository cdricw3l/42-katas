/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:48:45 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/14 14:31:01 by cbouhadr         ###   ########.fr       */
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
			//printf("value %d , arr[i]/10 %d\n", arr[i] ,arr[i] / exp);
			if (arr[i] / exp > 0)
			{
				digit = (arr[i] / exp) % 10;
				arr_count[digit] += 1;
			}
			i++;
		}
	}

}

void	ft_cumulatif_arr(int *count_digit, int *cumulatif_arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (i == 0)
			cumulatif_arr[i] = count_digit[i];
		else
			cumulatif_arr[i] = count_digit[i] + cumulatif_arr[i - 1];
		i++;
	}
}

void	ft_count_sort(int *arr, int *tmp, int len, int exp)
{
	int	count_digit[10];
	int	cumulatif_arr[10];
	int	digit;
	int	index;

	ft_bzero(count_digit,10, sizeof(int));
	ft_bzero(cumulatif_arr,10, sizeof(int));
	ft_arr_of_count_digt(arr, count_digit, len, exp);
	ft_cumulatif_arr(count_digit, cumulatif_arr, 10);
	while (len >= 1)
	{
		if(tmp[len - 1] / exp > 0)
		{
			digit = (tmp[len - 1] / exp) % 10;
			index = cumulatif_arr[digit] - 1;
			cumulatif_arr[digit]--;
			arr[index] = tmp[len - 1];
		}
		len--;
	}

}

void	ft_radix_sort(int *arr, int len)
{
	int	exp;
	int	max_value;
	int	*tmp;

	exp = 1;
	max_value = ft_get_max_value(arr, len);
	tmp = malloc(len * sizeof(int));
	if (!tmp)
		return ;
	ft_copy_arr_int(arr, tmp, len);
	while (max_value / exp > 0)
	{
		printf("deuxieme passage %d\n", max_value / exp);
		ft_count_sort(arr, tmp, len, exp);
		exp *= 10;
	}
}

int main(void)
{
	int arr[10] = {4, 7, 8, 6, 3, 10, 2, 9, 1, 5};
	
	int *tmp;
	tmp = malloc(10 * sizeof(int));
	if (!tmp)
		return 1;
	ft_radix_sort(arr, 10);
	ft_print(arr, 10);


}