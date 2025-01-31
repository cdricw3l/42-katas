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

#include "../include/test.h"

static void ft_bublesort(t_pile *stack)
{
    int i;
    int j;

    i = 0;
    printf("==> Start Bubble sort fonction\n");
    while (i <= stack->len)
    {

        j = 0;
        while (j <= stack->len)
        {
            if(stack->arr[0] < stack->arr[1])
                ft_swap(stack);
            ft_rotate(stack, BY_PASS_OFF);
            j++;
        }
        i++;
    }
    printf("Pour %d entier, nombre de mouvements: %d\n", stack->len, stack->mvm_counter);
    ft_get_stack_data(stack);
}

void    complexité_test(t_pile *stack, int algo)
{
    if(algo == BUBBLE_SORT)
        ft_bublesort(stack);
}