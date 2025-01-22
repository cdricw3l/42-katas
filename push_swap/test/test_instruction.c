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

    i = get_low_idx(stack->arr, stack->len);
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
        {
            prev = i;
            return(prev);
        }
        i++;
    }
    return (0);
}

void ft_five_arg(t_pile *stack_a, t_pile *stack_b)
{
    int i;

    ft_push(&stack_b, &stack_a);
    ft_push(&stack_b, &stack_a);
   // printf("voici stack b len %d\n", stack_b->len); 
    ft_two_or_tree_args(stack_b);
    ft_two_or_tree_args(stack_a);
    ft_get_stack_data(stack_a);
    i = 0;
    while (i <= stack_b->len)
    {
        int position = ft_get_index(stack_b->arr[i], stack_a);
       // printf("voici position %d de %d \n", position, stack_b->arr[i]);
        while (position + 1 > 0)
        {
            ft_rotate(stack_a);
            ft_get_stack_data(stack_a);
            position--;
        }
       // printf("push\n");
        ft_push(&stack_a, &stack_b);
        i++;
    }
    ft_return_to_zero(stack_a);
    ft_get_stack_data(stack_a);
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
    assert(g == 0);

    
    ft_get_stack_data(stack_a);
    int dex = ft_get_index(3, stack_b);
    printf("voici la position de 3 %d\n", dex);

    ft_five_arg(stack_a, stack_b);
    ft_clean_memory(&stack_a, &stack_b);
    return(0);
}

int main(void)
{
   
    ft_test_push();

    
    return(0);
}