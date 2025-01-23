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

int	ft_clean_memory(t_pile **stack_a, t_pile **stack_b)
{
	ft_printf("Start clean fonction\n");
	if (*stack_a)
	{
		if ((*stack_a)->arr)
			free((*stack_a)->arr);
		free(*stack_a);
		ft_printf("Stack A clean\n");
	}
	if (*stack_b)
	{
		if ((*stack_b)->arr)
			free((*stack_b)->arr);
		free(*stack_b);
		ft_printf("Stack B clean\n");
	}
	return (0);
}
