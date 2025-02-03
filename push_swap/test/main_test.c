/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:14:58 by cw3l              #+#    #+#             */
/*   Updated: 2025/02/03 06:07:37 by cw3l             ###   ########.fr       */
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

    n = 10;
    stack_a = ft_new_stack(n, n, 97);
    stack_b = ft_new_stack(n, n, 98);
    
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

    stack_b->arr[0] = 9;
    stack_b->arr[1] = 19;
    stack_b->arr[2] = 223;
    stack_b->arr[3] = 8;
    stack_b->arr[4] = 409;
    stack_b->arr[5] = 22211;
    stack_b->arr[6] = 29;
    stack_b->arr[7] = 887;
    stack_b->arr[8] = 87;
    stack_b->arr[9] = 1;

    optimised_rotation(stack_a, 3);
    assert(stack_a->mvm_counter == 3);
    optimised_rotation(stack_a, 6);
    assert(stack_a->mvm_counter == 7);
    optimised_rotation(stack_b, 9);
    assert(stack_b->mvm_counter == 1);
    stack_a->mvm_counter = 0;
    stack_b->mvm_counter = 0;

	ft_print_arr(stack_a->arr,stack_a->len);
	ft_print_arr(stack_b->arr,stack_b->len);
    optimised_double_rotation(stack_a, stack_b, 3);
    
    
    assert(stack_a->mvm_counter == 3 && stack_b->mvm_counter  == 0);
	ft_print_arr(stack_a->arr,stack_a->len);
	ft_print_arr(stack_b->arr,stack_b->len);

    printf("voici le nombre de mouvement %d\n", stack_a->arr[6]);
  
    optimised_double_rotation(stack_a, stack_b, 6);
    printf("voici le nombre de mouvement %d\n", stack_a->mvm_counter);
    
	ft_print_arr(stack_a->arr,stack_a->len);
	ft_print_arr(stack_b->arr,stack_b->len);
    assert(stack_a->mvm_counter == 7 && stack_b->mvm_counter  == 0);
    
    optimised_double_rotation(stack_a, stack_b, 2);
    assert(stack_a->mvm_counter == 7 + 2 && stack_b->mvm_counter  == 0);
    ft_clean_memory(&stack_a, &stack_b);

    

    return(0);
}