/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 08:29:02 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/15 12:51:00 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int optimised_rotation(t_pile *stack_a, int index)
{
    int i;

    i = 0;
    if(index > stack_a->len / 2)
    {
        while (i < stack_a->len - index)
        {
            ft_reverse_rotate(stack_a, BY_PASS_OFF);
            i++;
        }
    }
    else
    {
        while (i < index)
        {
            ft_rotate(stack_a, BY_PASS_OFF);
            i++;
        } 
    }
	return (i);
}

void ft_return_to_zero(t_pile *stack)
{
    int i;

    i = ft_get_lowest_idx(stack->arr, stack->len);
    if(i > stack->len / 2)
    {

        while (stack->len - i > 0)
        {
            ft_reverse_rotate(stack, BY_PASS_OFF);
            i++;
        }
    }
    else
    {
        while (i > 0)
        {
            ft_rotate(stack,BY_PASS_OFF);
            i--;
        } 
    }
}

void ft_return_to_max(t_pile *stack)
{
    int i;

    i = ft_get_highest_idx(stack->arr, stack->len);
    if(i > stack->len / 2)
    {

        while (stack->len - i > 0)
        {
            ft_reverse_rotate(stack, BY_PASS_OFF);
            i++;
        }
    }
    else
    {
        while (i > 0)
        {
            ft_rotate(stack, BY_PASS_OFF);
            i--;
        } 
    }
}

int *ft_reverse_arr(int *arr, int len)
{
    int i;
    int j;
    int *rev_arr;
    
    i = 0;
    j = len;
    rev_arr = calloc(len, sizeof(int));
    if(!rev_arr)
        return(NULL);
    while (i < len)
    {
        rev_arr[i] = arr[j - 1];
        j--;
        i++;
    }
    return(rev_arr);
}


int	ft_cmp_int(void *p1, void *p2)
{
	int	v1;
	int	v2;
	v1 = *(int *)(p1);
	v2 = *(int *)(p2);
	return (v1 - v2);
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

void ft_printf_bit_arr(int *arr, int len)
{
	int i;

	i = 0;
	while (i < len)
		ft_print_bit_8(arr[i++]);
	ft_printf("\n");
	
}


void ft_radix_sort(int *arr, int len)
{
	int i;
	int bit;
	int a;
	int b;

	bit = 7;

	while (bit <= 0)
	{
		i = 0;
		while (i < len - 1)
		{
			a = (arr[i] << bit) & 1;
			b = (arr[i + 1] << bit) & 1;
			
			if(b < a)
			{
				int tmp = arr[i];
				arr[i] = arr[i+ 1];
				arr[i+ 1] = tmp;
			}
			i++;
		}
		ft_printf_bit_arr(arr, 10);
		bit++;
	}
	
	
}

// int ft_find_cible(int arr[], int cible, int len)
// {
// 	int i;
// 	int	tmp;
// 	int start;
// 	int index;

// 	i = 0;
// 	start = 0;
// 	tmp = 0;
// 	index = -1;
// 	while (arr[i] != '\0')
// 	{
// 		if(arr[i] > cible && start == 0)
// 		{
// 			tmp = arr[i];
// 			index = i;
// 			start = 1;
// 		}
// 		else if (arr[i] > cible && arr[i] < tmp && start > 0)
// 		{
// 			tmp = arr[i];
// 			index = i;
// 		}
// 		i++;
// 	}
// 	return (index);
// }


// int main(void)
// {
// 	int arr[] = {5, 9, 7, 1, 3, '\0'};
// 	//int value_max;
// 	//int value_min;
// 	//int pivot;
// //
// 	//int len = sizeof(arr) / sizeof(arr[0]);
// 	//ft_generate_number(arr, 10);
// 	ft_print_arr(arr);

// 	ft_qsort_int(arr, 0, 5);
// 	ft_print_arr(arr);
// 	// value_min =  get_low(arr, len);
// 	// value_max =  get_high(arr, len);
// 	// pivot = (value_max - value_min) / 2;

// 	// printf("voici valeur low: %d. Voici valeur max %d et le nombre d'element %d et le pivot %d\n", value_min, value_max, 10, pivot);
// 	// int i= ft_find_cible(arr, pivot,len);
// 	// printf("voici l'index1 %d\n", i);
// 	// printf("arr[i] %d\n", arr[i]);
// 	// int j = ft_find_cible(arr, arr[i],len);
// 	// printf("voici l'index1 %d\n", j);
// 	// printf("arr[i] %d\n", arr[j]);
// 	// int k = ft_find_cible(arr, arr[j],len);
// 	// printf("voici l'index1 %d\n", k);
// 	// printf("arr[i] %d\n", arr[k]);
// 	// int l = ft_find_cible(arr, arr[k],len);
// 	// printf("voici l'index1 %d\n", l);
// 	// printf("arr[i] %d\n", arr[l]);

// 	return (0);
// }