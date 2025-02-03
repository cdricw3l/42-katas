/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_max_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:59:12 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/14 01:08:06 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_get_max_value(int *arr, int size)
{
	int	i;
	int	high;

	i = 1;
	high = arr[0];
	if (!arr || size == 0)
		return (-1);
	while (i < size)
	{
		if (arr[i] > high)
			high = arr[i];
		i++;
	}
	return (high);
}
