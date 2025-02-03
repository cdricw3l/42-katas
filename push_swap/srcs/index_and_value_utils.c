/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_and_value_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 08:29:02 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/02/03 15:31:59 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_get_highest_idx(int *arr, int size)
{
	int	i;
	int	high_value;
	int	high_idx;

	i = 1;
	high_value = arr[0];
	high_idx = 0;
	while (i < size)
	{
		if (arr[i] > high_value)
		{
			high_value = arr[i];
			high_idx = i;
		}
		i++;
	}
	return (high_idx);
}

int	ft_get_lowest_idx(int *arr, int size)
{
	int	i;
	int	low_value;
	int	low_idx;

	i = 1;
	low_value = arr[0];
	low_idx = INT_MIN;
	while (i < size)
	{
		if (arr[i] < low_value)
		{
			low_value = arr[i];
			low_idx = i;
		}
		i++;
	}
	return (low_idx);
}
