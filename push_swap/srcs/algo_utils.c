/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 08:29:02 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/02/03 18:01:53 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_optimised_cost(int len, int idx)
{
	if (idx > (len) / 2)
		return (len - idx);
	return (idx);
}

int	optimised_rotation(t_stack *stack_a, int index)
{
	int	i;

	i = 0;
	if (index > stack_a->len / 2)
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

int	optimised_double_rotation(t_stack *stack_a, t_stack *stack_b, int index)
{
	int	i;

	i = 0;
	if (index > stack_b->len / 2)
	{
		while (i < stack_a->len - index)
		{
			ft_rrr(stack_a, stack_b);
			i++;
		}
	}
	else
	{
		while (i < index)
		{
			ft_rr(stack_a, stack_b);
			i++;
		}
	}
	return (i);
}

void	ft_return_to_max(t_stack *stack)
{
	int	i;

	i = ft_get_highest_idx(stack->arr, stack->len);
	if (i > stack->len / 2)
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
