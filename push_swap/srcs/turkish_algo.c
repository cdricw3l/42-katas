/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 06:10:55 by cw3l              #+#    #+#             */
/*   Updated: 2025/02/03 17:29:24 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_get_target_idx(t_stack *stack, int n)
{
	int	i;
	int	prev_int;
	int	prev_idx;

	i = 0;
	prev_int = INT_MIN;
	prev_idx = -1;
	while (i < stack->len)
	{
		if (stack->arr[i] < n && stack->arr[i] > prev_int)
		{
			prev_int = stack->arr[i];
			prev_idx = i;
		}
		i++;
	}
	if (prev_idx == -1)
		return (ft_get_highest_idx(stack->arr, stack->len));
	return (prev_idx);
}

int	ft_best_cost(t_stack *stack_src, t_stack *stack_dst)
{
	int	i;
	int	src_cost;
	int	dst_cost;
	int	best_total_cost_idx;
	int	best_total_cost;

	i = 0;
	best_total_cost = INT_MAX;
	best_total_cost_idx = -1;
	while (i < stack_src->len)
	{
		src_cost = get_optimised_cost(stack_src->len, i);
		dst_cost = get_optimised_cost(stack_dst->len,
				ft_get_target_idx(stack_dst, stack_src->arr[i]));
		if (dst_cost + src_cost < best_total_cost)
		{
			best_total_cost_idx = i;
			best_total_cost = dst_cost + src_cost;
		}
		i++;
	}
	return (best_total_cost_idx);
}

void	fill_arr_b(t_stack *stack_a, t_stack *stack_b)
{
	int	best;
	int	target_idx;

	while (stack_a->len > 0)
	{
		best = ft_best_cost(stack_a, stack_b);
		target_idx = ft_get_target_idx(stack_b, stack_a->arr[best]);
		if (target_idx == best)
			optimised_double_rotation(stack_a, stack_b, target_idx);
		else
		{
			optimised_rotation(stack_a, best);
			optimised_rotation(stack_b, target_idx);
		}
		ft_push(&stack_b, &stack_a);
	}
}

void	fill_arr_a(t_stack *stack_b, t_stack *stack_a)
{
	while (stack_b->len > 0)
		ft_push(&stack_a, &stack_b);
}

void	ft_turkish_algo(t_stack *stack_a, t_stack *stack_b)
{
	fill_arr_b(stack_a, stack_b);
	ft_tree_values(stack_a);
	ft_return_to_max(stack_b);
	fill_arr_a(stack_b, stack_a);
}
