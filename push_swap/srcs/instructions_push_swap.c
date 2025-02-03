/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_push_swap.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:36:21 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/02/03 17:50:08 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_swap(t_stack *stack)
{
	int	tmp;

	if (!stack || !stack->arr)
		return (1);
	tmp = stack->arr[0];
	stack->arr[0] = stack->arr[1];
	stack->arr[1] = tmp;
	if (stack->stack_name == 97)
		write(1, "sa", 2);
	else
		write(1, "sb", 2);
	stack->mvm_counter++;
	write(1, "\n", 1);
	return (0);
}

int	ft_push(t_stack **dest, t_stack **src)
{
	int	value;

	if (!dest || !src)
		return (1);
	if ((*src)->len == 0)
		return (1);
	value = (*src)->arr[0];
	if ((*src)->len > 0)
	{
		(*src)->len--;
		ft_memmove((*src)->arr, (*src)->arr + 1, (*src)->len * sizeof(int));
	}
	if ((*dest)->len > 0)
		ft_memmove((*dest)->arr + 1, (*dest)->arr, (*dest)->len * sizeof(int));
	(*dest)->len++;
	(*dest)->arr[0] = value;
	if ((*dest)->stack_name == 'a')
	{
		write(1, "pa", 2);
	}
	else
		write(1, "pb", 2);
	write(1, "\n", 1);
	(*dest)->mvm_counter++;
	return (0);
}
