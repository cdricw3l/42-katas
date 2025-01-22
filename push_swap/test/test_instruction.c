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

t_pile *ft_new_stack(int size, int len, char name)
{
    t_pile *new_s;

    new_s = ft_calloc(1, sizeof(t_pile));
    if (!new_s)
            return(NULL);
    new_s->arr = ft_calloc(size, sizeof(int));
    if (!new_s->arr)
        return (NULL);
    new_s->len = len;
    new_s->stack_name = name;
    new_s->mvm_counter = 0;
    return(new_s);
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
    stack_a->arr[0] = __INT32_MAX__;
    ft_clean_memory(&stack_a, &stack_b);
    return(0);
}

int main(void)
{
   
    ft_test_push();
    return(0);
}