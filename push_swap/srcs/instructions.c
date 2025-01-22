/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 08:27:27 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/15 12:52:08 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_swap(t_pile *stack)
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
	stack->mvm_counter+=1;
	write(1, "\n", 2);
	return (0);
}

int	ft_rotate(t_pile *stack)
{
	int	tmp;
	int len;

	if (!stack || !stack->arr)
		return (1);
	len = stack->len - 1;
	tmp = stack->arr[0];
	ft_memmove(stack->arr, stack->arr + 1, len * sizeof(int));
	stack->arr[len] = tmp;
	if (stack->stack_name == 'a')
		write(1, "ra", 3);
	else
		write(1, "rb", 3);
	write(1, "\n", 2);
	stack->mvm_counter+=1;
	return (0);
}

int	ft_reverse_rotate(t_pile *stack)
{
	int	tmp;
	int len;

	if (!stack || !stack->arr)
		return (1);
	len = stack->len - 1;
	tmp = stack->arr[len];
	ft_memmove(stack->arr + 1, stack->arr, len * sizeof(int));
	stack->arr[0] = tmp;
	if (stack->stack_name == 'a')
		write(1, "rra", 3);
	else
		write(1, "rrb", 3);
	write(1, "\n", 2);
	stack->mvm_counter+=1;
	return (0);
}

int	ft_push(t_pile **dest, t_pile **src)
{
	int value;

	if(!dest || !src)
		return (1);
	if((*src)->len == 0)
		return (1);
	value = (*src)->arr[0];
	if((*src)->len > 0)
	{
		(*src)->len--;
		ft_memmove((*src)->arr , (*src)->arr + 1, (*src)->len * sizeof(int));
	}
	if((*dest)->len > 0)
	{
		ft_memmove((*dest)->arr + 1, (*dest)->arr, (*dest)->len * sizeof(int));
	}
	(*dest)->len++;
	(*dest)->arr[0] = value;
	(*src)->mvm_counter++;
	return(0);
}



// int main(void)
// {
// 	int tab1[8] = {9, 7, 5, 3, 1, 4, 6, '\0'};
// 	int tab2[8] = {'\0'};
// 	ft_print_arr(tab1);
// 	ft_reverse_rotate(tab1, 'a');
// 	ft_print_arr(tab1);
// 	while (tab1[0] != 9)
// 	{
// 		ft_reverse_rotate(tab1, 'a');
// 		ft_print_arr(tab1);
// 	}
// 	return(0);
// }