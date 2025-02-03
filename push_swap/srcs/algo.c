/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:02:02 by cw3l              #+#    #+#             */
/*   Updated: 2025/02/03 16:10:35 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_two_values(t_stack *stack_a)
{
	if (stack_a && stack_a->arr)
	{
		if (stack_a->arr[0] > stack_a->arr[1])
			ft_swap(stack_a);
	}
}

void	ft_tree_case_one(t_stack *stack_a)
{
	ft_reverse_rotate(stack_a, BY_PASS_OFF);
	ft_swap(stack_a);
}

void	ft_tree_case_four(t_stack *stack_a)
{
	ft_rotate(stack_a, BY_PASS_OFF);
	ft_swap(stack_a);
}

void	ft_tree_values(t_stack *stack_a)
{
	if (stack_a && stack_a->arr)
	{
		if (stack_a->arr[1] > stack_a->arr[0]
			&& stack_a->arr[1] > stack_a->arr[2]
			&& stack_a->arr[0] < stack_a->arr[2])
			ft_tree_case_one(stack_a);
		else if (stack_a->arr[1] < stack_a->arr[0]
			&& stack_a->arr[1] < stack_a->arr[2]
			&& stack_a->arr[0] < stack_a->arr[2])
			ft_swap(stack_a);
		else if (stack_a->arr[1] > stack_a->arr[0]
			&& stack_a->arr[1] > stack_a->arr[2]
			&& stack_a->arr[0] > stack_a->arr[2])
			ft_reverse_rotate(stack_a, BY_PASS_OFF);
		else if (stack_a->arr[1] < stack_a->arr[0]
			&& stack_a->arr[1] < stack_a->arr[2]
			&& stack_a->arr[0] > stack_a->arr[2])
			ft_rotate(stack_a, BY_PASS_OFF);
		else if (stack_a->arr[1] < stack_a->arr[0]
			&& stack_a->arr[1] > stack_a->arr[2]
			&& stack_a->arr[0] > stack_a->arr[2])
			ft_tree_case_four(stack_a);
	}
}

void	ft_five_values(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (ft_is_sort(stack_a->arr, stack_a->len, sizeof(int), ft_cmp_int))
	{
		while (stack_a->len > 3
			&& ft_is_sort(stack_a->arr,
				stack_a->len, sizeof(int), ft_cmp_int))
		{
			i = ft_get_lowest_idx(stack_a->arr, stack_a->len);
			if (i)
				optimised_rotation(stack_a, i);
			ft_push(&stack_b, &stack_a);
		}
		if (ft_is_sort(stack_a->arr, stack_a->len, sizeof(int), ft_cmp_int))
			ft_tree_values(stack_a);
		while (stack_b->len > 0)
		{
			ft_push(&stack_a, &stack_b);
		}
	}
}
