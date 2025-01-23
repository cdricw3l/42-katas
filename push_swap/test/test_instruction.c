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

int *ft_reverse_arr(int *arr, int len)
{
    int i;
    int j;
    int *rev_arr;
    
    i = 0;
    j = len;
    rev_arr = calloc(len, sizeof(int));
    if(!rev_arr)
        return(NULL);
    while (i < len)
    {
        rev_arr[i] = arr[j - 1];
        j--;
        i++;
    }
    return(rev_arr);
}

void ft_return_to_zero(t_pile *stack)
{
    int i;

    i = ft_get_low_idx(stack->arr, stack->len);
    printf("voici l'index %d\n", i);
    if(i > stack->len / 2)
    {

        while (stack->len - i > 0)
        {
            ft_reverse_rotate(stack);
            i++;
        }
    }
    else
    {
        while (i > 0)
        {
            ft_rotate(stack);
            i--;
        } 
    }
}

int ft_get_index(int n, t_pile *stack)
{
    int i;
    int prev;

    i = 0;
    prev = INT_MIN;
    while (i < stack->len)
    {
        if(stack->arr[i] < n && stack->arr[i] > prev)
            prev = i;
        i++;
    }
    return (prev);
}

void optimised_rotation(t_pile *stack_a, int index)
{
    int i;

    i = 0;
    if(index > stack_a->len / 2)
    {
        while (i < stack_a->len - index)
        {
            ft_reverse_rotate(stack_a);
            i++;
        }
    }
    else
    {
        while (i < index)
        {
            ft_rotate(stack_a);
            i++;
        } 
    }
}

void ft_five_arg(t_pile *stack_a, t_pile *stack_b)
{
    int i;

    if(ft_is_sort(stack_a->arr, stack_a->len, sizeof(int), ft_cmp_int))
    {
        while (stack_a->len > 3 && ft_is_sort(stack_a->arr, stack_a->len, sizeof(int), ft_cmp_int))
        {
            i = ft_get_low_idx(stack_a->arr, stack_a->len);
            if(i)
                optimised_rotation(stack_a, i);
            ft_push(&stack_b, &stack_a);
        }
        if(ft_is_sort(stack_a->arr, stack_a->len, sizeof(int), ft_cmp_int))
            ft_two_or_tree_args(stack_a);
        while (stack_b->len > 0)
        {
            ft_push(&stack_a, &stack_b);
        }
        ft_get_stack_data(stack_a);
        ft_get_stack_data(stack_b);
        (void)stack_b;
    }
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
    //int g = ft_generate_number(stack_a->arr, stack_a->len);
    //assert(g == 0);
    stack_a->arr[0] = 4;
    stack_a->arr[1] = 2;
    stack_a->arr[2] = 1;
    stack_a->arr[3] = 5;
    stack_a->arr[4] = 3;
    
    ft_get_stack_data(stack_a);
    ft_five_arg(stack_a, stack_b);
    ft_clean_memory(&stack_a, &stack_b);
    return(0);
}

int main(void)
{
   
    ft_test_push();

    
    return(0);
}