/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 08:29:02 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/05 16:12:53 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_cmp_int(void *p1, void *p2)
{
	int	v1;
	int	v2;
	v1 = *(int *)(p1);
	v2 = *(int *)(p2);
	return (v1 - v2);
}

int	get_high(int *arr, int size)
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

int	get_low(int *arr, int size)
{
	int	i;
	int	low;

	i = 1;
	low = arr[0];
	while (i < size)
	{
		if (arr[i] < low)
			low = arr[i];
		i++;
	}
	return (low);
}

void	ft_quick_swap(int *arr, int a, int b)
{
	int	tmp;

	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

int	ft_partition_end_pivot(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high - 1];
	i = low;
	j = low;
	while (j < high - 1)
	{
		if (arr[i] < pivot)
		{
			i++;
			j++;
		}
		else
			j++;
		if (arr[j] < arr[i])
			ft_quick_swap(arr, j, i);
	}
	return (i);
}

int	ft_partition_middle_pivot(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	int	idx_pivot;

	idx_pivot = (high - 1) / 2;
	pivot = arr[idx_pivot];
	i = low;
	j = high - 1;
	while (i < j)
	{
		while(arr[i] < pivot)
			i++;
		while(arr[j] > pivot)
			j--;
		if(arr[i] > arr[j])
			ft_quick_swap(arr, i, j);
	}
	return (i);
}

void	ft_qsort_int(int *base, int low, int high)
{
	int	i;

	if (low < high)
	{
		i = ft_partition_middle_pivot(base, low, high);
		ft_qsort_int(base, 0, i);
		ft_qsort_int(&base[i + 1], 0, (high  - i) - 1);
	}
}




int main(void)
{
	int len[10];
	
	ft_generate_number(len, 10);
	printf("tableau numero 1 \n");
	ft_print_arr(len, 10);
	ft_qsort_int(len, 0, 10);
	
	printf("tableau numero 2 \n");
	ft_print_arr(len, 10);
	
	
	//ft_print_arr(&len[num + 1], 10 - 1 - i);
	//ft_print_arr(len, 7);
	if(!ft_is_sort(len, 10))
		printf("tableau trier\n");
	else
		printf("tableau NON trier\n");

	return (0);
}