/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:02:02 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/13 18:36:54 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void ft_get_stack_data(t_pile *stack)
{
	int i;

	i = 0;
	if (stack)
	{
		ft_printf("====== stack %c info ======\n",stack->stack_name);
		ft_printf("[ NAME ] %c\n" ,stack->stack_name);
		ft_printf("[ ADDR ] %p\n", stack);
		ft_printf("[ ARR SIZE ] %d\n", stack->len);
		ft_printf("[ Nb MOVE ] %d\n", stack->mvm_counter);
		ft_printf("[ ADDR ARR] %p\n", stack->arr);
		ft_printf("\n");
		if(stack->arr)
		{
			while (i < stack->len)
			{
				if(i < stack->len)
				{
					ft_printf("[ INT N°%d ] ==> %d : ", i, stack->arr[i]);
					ft_print_bit_16(stack->arr[i]);
				}
				ft_printf("\n");
				i++;
			}
		}
		ft_printf("\n");
	}
}

void    ft_print_arr(int *arr, int len)
{
	int i;

	i = 0;
	while (i < len)
		printf(" %d", arr[i++]);
	printf("\n");
}

int ft_print_error(void)
{
	write(1, "ERROR", 5);
	return (1);
}