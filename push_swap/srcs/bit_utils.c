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

int ft_get_byte_max(int *arr, int len)
{
	int i;
	int j;
	int bit;

	i = 31;
	if(!arr || len == 0)
		return(-1);
	while (i > 0)
	{
		j = 0;
		while (j < len)
		{
			bit = (arr[j] >> i) & 1;
			if(bit == 1)
			{
				printf(" %d\n", arr[j]);
				return (i);
			}
			j++;
		}
		i--;		
	}
	return(-1);
}

int		ft_get_n_byte(int n, int byte)
{
	return ((n >> (byte)) & 1);
}