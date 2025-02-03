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

int ft_get_target_idx2(t_pile *stack, int n)
{
    int i;
    int prev_int;
    int prev_idx;

    prev_int = INT_MIN;
    prev_idx = -1;
    i = 0;
    while (i < stack->len)
    {
        if(stack->arr[i] < n && stack->arr[i] > prev_int)
        {
            prev_int = stack->arr[i];
            prev_idx = i;
        }
        i++;
    }
    if(prev_idx == -1)
    {
        return(ft_get_highest_idx(stack->arr, stack->len));
    }
    return(prev_idx);
}

int get_optimised_cost(int len, int idx)
{
    if(idx > (len) / 2)
        return(len - idx);
    return(idx);
}

int ft_get_the_cost(t_pile *dst, t_pile *src, int n)
{
    int dest_cost;
    int src_cost;


    //printf("voici higherst %d et idx %d\n", ft_get_highest_idx(dst->arr, dst->len),ft_index_of(src->arr, src->len, n) );

    dest_cost = get_optimised_cost(dst->len,ft_get_target_idx2(dst, n));
    //printf("dest cost = %d\n", dest_cost);
    src_cost = get_optimised_cost(src->len,ft_index_of(src->arr, src->len, n));

    // ft_get_stack_data(dst);
    // ft_get_stack_data(src);

    return(dest_cost + src_cost);
}

void ft_fill_pill_b(t_pile *stack_b, t_pile *stack_a)
{
    int i;
    int best_cost_idx;
    int best_cost;
    int taret_idx;

    if(stack_a->len > 3)
    {
	    ft_push(&stack_b, &stack_a);
        ft_push(&stack_b, &stack_a);
    }
	while (stack_a->len > 3)
    {
        i = 0;
	    best_cost_idx = 0;
        best_cost = ft_get_the_cost(stack_b, stack_a, stack_a->arr[0]);
        while (i < stack_a->len)
        {
            int cost = ft_get_the_cost(stack_b, stack_a, stack_a->arr[i]);
            if(cost < best_cost)
                best_cost_idx = i;
            i++;
        }
        taret_idx = ft_get_target_idx2(stack_b, stack_a->arr[best_cost_idx]);
        //printf("target  index %d , best cost%d\n", best_cost_idx, taret_idx);
        optimised_rotation(stack_a, best_cost_idx);
        optimised_rotation(stack_b, taret_idx);
        ft_push(&stack_b, &stack_a);
    }
    
}

void ft_fill_pill_a(t_pile *stack_a, t_pile *stack_b)
{
    int i;
    int best_cost_idx;
    int best_cost;

	best_cost_idx = 0;
    best_cost = 0;
	while (stack_b->len > 0)
    {
        i = 0;
        while (i < stack_b->len)
        {
            int cost = ft_get_the_cost(stack_a, stack_b, stack_b->arr[i]);
            if(cost < best_cost)
                best_cost_idx = i;
            i++;
        }
        int taret_idx = ft_get_target_idx2(stack_a, stack_b->arr[best_cost_idx]);
        optimised_rotation(stack_b, best_cost_idx);
        optimised_rotation(stack_a, taret_idx);
        ft_push(&stack_a, &stack_b);
        assert(stack_a->arr[0] ==  stack_a->arr[best_cost_idx]);
    }
}
