/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_managment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 08:29:02 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/02/03 15:58:52 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_clean_memory(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a)
	{
		if ((*stack_a)->arr)
			free((*stack_a)->arr);
		free(*stack_a);
	}
	if (*stack_b)
	{
		if ((*stack_b)->arr)
			free((*stack_b)->arr);
		free(*stack_b);
	}
	return (0);
}
