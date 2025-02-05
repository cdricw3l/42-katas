/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:53:07 by cw3l              #+#    #+#             */
/*   Updated: 2025/02/05 12:30:27 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_is_sort_2(int *arr, int nb)
{
	int	i;
	int	j;

	if (!arr || nb < 2)
		return (-1);
	i = 0;
	while (i < nb - 1)
	{
		j = i + 1;
		if (arr[i] > arr[j])
			return (1);
		i ++;
	}
	return (0);
}

static int	ft_init_progr(char **argv, t_stack *stack)
{
	int	rep;

	if (!ft_validation_arg(&argv[1]))
	{
		ft_parsing(&argv[0], stack);
		if (stack->len < 2)
			return (-1);
		rep = ft_check_repetition(stack);
		if (rep == -1)
			return (-1);
		else if (stack->len < 2)
			return (-1);
		else
			return (rep);
	}
	return (-1);
}

static t_stack	*ft_new_stack(int size, int len, char name)
{
	t_stack	*new_s;

	new_s = ft_calloc(1, sizeof(t_stack));
	if (!new_s)
		return (NULL);
	new_s->arr = ft_calloc(size, sizeof(int));
	if (!new_s->arr)
		return (NULL);
	new_s->len = len;
	new_s->stack_name = name;
	new_s->mvm_counter = 0;
	return (new_s);
}

static void	ft_sort_stack(t_stack *stack_a, t_stack *stack_b, int len)
{
	if (len == 2)
		ft_two_values(stack_a);
	else if (len == 3)
		ft_tree_values(stack_a);
	else if (len == 5)
		ft_five_values(stack_a, stack_b);
	else
		ft_turkish_algo(stack_a, stack_b);
	ft_clean_memory(&stack_a, &stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_b;
	t_stack	*stack_a;
	int		len;
	int		tx;

	if (argc < 2)
		return (1);
	len = ft_get_number_of_int(&argv[1]);
	if (len == 0)
		return (1);
	stack_a = ft_new_stack(len, len, 97);
	stack_b = ft_new_stack(len, 0, 98);
	if (!stack_a->arr || !stack_b->arr)
		return (ft_clean_memory(&stack_a, &stack_b));
	tx = ft_init_progr(&argv[1], stack_a);
	if (tx == -1)
	{
		ft_print_error();
		return (ft_clean_memory(&stack_a, &stack_b));
	}
	if (!ft_is_sort_2(stack_a->arr, stack_a->len))
		return (ft_clean_memory(&stack_a, &stack_b));
	else
		ft_sort_stack(stack_a, stack_b, len);
	return (0);
}
