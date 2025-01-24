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

int ft_get_median_value(int *arr, int len)
{
    ft_print_arr(arr, len);
    return(0);
}

int ft_test_push(void)
{
    
    t_pile *stack_a;
    t_pile *stack_b;
    int n;

    n = 5;
    stack_a = ft_new_stack(n, n, 97);
    stack_b = ft_new_stack(n, 0, 98);
    if(!stack_a || !stack_b)
        return(ft_clean_memory(&stack_a, &stack_b));
    int g = ft_generate_number(stack_a->arr, stack_a->len);
    ft_get_median_value(stack_a->arr, stack_a->len);
    assert(g == 0);
    ft_get_stack_data(stack_a);
    /* stack_a->arr[0] = 3;
    stack_a->arr[1] = 5;
    stack_a->arr[2] = 2;
    stack_a->arr[3] = 1;
    stack_a->arr[4] = 4; */
   /*  stack_a->arr[0] = -11;
    stack_a->arr[1] = -22;
    stack_a->arr[2] = -3;
    stack_a->arr[3] = -54;
    stack_a->arr[4] = 5; */
    ft_five_value(stack_a, stack_b);
    ft_get_stack_data(stack_a);
    printf(" ==> Nombre d'operation : %d \n", stack_a->mvm_counter + stack_b->mvm_counter);
    assert(ft_is_sort(stack_a->arr, 5, 4, ft_cmp_int) == 0);
    ft_clean_memory(&stack_a, &stack_b);
    return(0);
}

int main(void)
{
   
    ft_test_push();

    
    return(0);
}