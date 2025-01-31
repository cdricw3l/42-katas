/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dispatch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:14:58 by cw3l              #+#    #+#             */
/*   Updated: 2024/11/18 16:00:50 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

int main(void)
{
    ft_printf("Test de rotation du mouvement et de liberation de memoire\n\n");
    
    assert(rotation_test() == 0);
    
    ft_printf("Test de rotation du mouvement et de liberation de memoire OK\n\n");

    int n;
	t_pile *stack_a;
    t_pile *stack_b;
	int start_point_a;
	int start_point_b;

    n = 10;
    stack_a = ft_new_stack(n, n, 97);
    stack_b = ft_new_stack(n, 0, 98);

    stack_a->arr[0] = 9;
    stack_a->arr[1] = 19;
    stack_a->arr[2] = 223;
    stack_a->arr[3] = 8;
    stack_a->arr[4] = 409;
    stack_a->arr[5] = 22211;
    stack_a->arr[6] = 29;
    stack_a->arr[7] = 887;
    stack_a->arr[8] = 87;
    stack_a->arr[9] = 1;


    start_point_a = stack_a->arr[0];
	start_point_b = stack_b->arr[0];

    (void)start_point_a;
    (void)start_point_b;

    ft_print_arr(stack_a->arr,stack_a->len);
	ft_print_arr(stack_b->arr,stack_b->len);

    complexité_test(stack_a ,BUBBLE_SORT);

    ft_clean_memory(&stack_a, &stack_b);


    return(0);
}