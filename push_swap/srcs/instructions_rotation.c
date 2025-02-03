/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rotation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 08:27:27 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/02/03 18:10:49 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_rotate(t_stack *stack, int bypass)
{
	int	tmp;
	int	len;

	if (!stack || !stack->arr)
		return (1);
	len = stack->len - 1;
	tmp = stack->arr[0];
	ft_memmove(stack->arr, stack->arr + 1, len * sizeof(int));
	stack->arr[len] = tmp;
	if (bypass != BY_PASS_ON)
	{
		if (stack->stack_name == 'a')
			write(1, "ra", 2);
		else
			write(1, "rb", 2);
		write(1, "\n", 1);			
		stack->mvm_counter += 1;
	}
	return (0);
}

int	ft_reverse_rotate(t_stack *stack, int bypass)
{
	int	tmp;
	int	len;

	if (!stack || !stack->arr)
		return (1);
	len = stack->len - 1;
	tmp = stack->arr[len];
	ft_memmove(stack->arr + 1, stack->arr, len * sizeof(int));
	stack->arr[0] = tmp;
	if (bypass != BY_PASS_ON)
	{
		if (stack->stack_name == 'a')
			write(1, "rra", 3);
		else
			write(1, "rrb", 3);
		stack->mvm_counter += 1;
		write(1, "\n", 1);
	}
	return (0);
}

int	ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_a->arr
		|| !stack_b || !stack_b->arr)
		return (1);
	ft_reverse_rotate(stack_a, BY_PASS_ON);
	ft_reverse_rotate(stack_b, BY_PASS_ON);
	write(1, "rrr", 3);
	write(1, "\n", 1);
	stack_a->mvm_counter += 1;
	return (0);
}

int	ft_rr(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_a->arr
		|| !stack_b || !stack_b->arr)
		return (1);
	ft_rotate(stack_a, BY_PASS_ON);
	ft_rotate(stack_b, BY_PASS_ON);
	write(1, "rr", 2);
	write(1, "\n", 1);
	stack_a->mvm_counter += 1;
	return (0);
}
