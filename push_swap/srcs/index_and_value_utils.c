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

int	ft_get_highest_idx(int *arr, int size)
{
	int	i;
	int	high_value;
	int	high_idx;

	i = 1;
	high_value = arr[0];
	high_idx = INT_MIN;
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

int	ft_get_lowest_value(int *arr, int size)
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

int	ft_get_highest_value(int *arr, int size)
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
int	ft_find_space(char *str)
{
	while (*str)
	{
		if (*str == 32)
			return (1);
		str++;
	}
	return (0);
}
