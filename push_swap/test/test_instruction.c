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
#include <assert.h>

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

t_pile *ft_new_stack(int len)
{
    t_pile *new_s;

    if(len == 0)
        return(NULL);
    new_s = ft_calloc(len, sizeof(t_pile *));
    new_s->arr = ft_calloc(len, sizeof(int));
    if(!new_s || !new_s->arr)
        return(NULL);
    new_s->len = len;
    return(new_s);
}
int ft_test_push(void)
{
    
    t_pile *stack_a;
    t_pile *stack_b;

    stack_a = ft_new_stack(5);
    stack_b = ft_new_stack(5);
    if(!stack_a || !stack_b)
        return(ft_clean_memory(&stack_a, &stack_b));
    ft_get_stack_data(stack_a);
    ft_get_stack_data(stack_b);
    ft_clean_memory(&stack_a, &stack_b);
    return(0);
}

int main(void)
{
   
    ft_test_push();
    return(0);
}