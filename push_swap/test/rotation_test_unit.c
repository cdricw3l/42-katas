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

#include "../include/push_swap.h"

int rotation_test(void)
{
	int n;
	int i;
	t_pile *stack_a;
    t_pile *stack_b;
	int start_point_a;
	int start_point_b;

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

	start_point_a = stack_a->arr[0];
	start_point_b = stack_b->arr[0];

	i = 0;
	while (i < 10)
	{
		/* 
			ft_print_arr(stack_a->arr,stack_a->len);
			ft_print_arr(stack_b->arr,stack_b->len);
			printf("\n\n");
		
		*/

		ft_reverse_rotate(stack_a, BY_PASS_OFF);
		ft_rotate(stack_b, BY_PASS_OFF);
		i++;
	}
	assert(stack_a->len == 10);
	assert(stack_b->len == 10);
	assert(stack_a->arr[0] == start_point_a);
	assert(stack_b->arr[0] == start_point_b);
	assert(ft_reverse_rotate(NULL, BY_PASS_OFF) == 1);
	printf("====> Fonction reverse rotate Ok\n\n");	
	
	i = 0;
	while (i < 10)
	{
		/* 
			ft_print_arr(stack_a->arr,stack_a->len);
			ft_print_arr(stack_b->arr,stack_b->len);
			printf("\n\n");
		*/
		ft_rotate(stack_a, BY_PASS_OFF);
		ft_rotate(stack_b, BY_PASS_OFF);
		i++;
	}
	assert(stack_a->len == 10);
	assert(stack_b->len == 10);
	assert(stack_a->arr[0] == start_point_a);
	assert(stack_b->arr[0] == start_point_b);
    assert(ft_rotate(NULL, BY_PASS_OFF) == 1);
	
	printf("====> Fonction rotate: OK\n\n");	

	stack_a->mvm_counter = 0;

	printf("====> Test de la fonction rrr: stack a len: %d\n\n", stack_a->mvm_counter);	

	i = 0;
	while (i < 10)
	{
		/* 
		
			ft_print_arr(stack_a->arr,stack_a->len);
			ft_print_arr(stack_b->arr,stack_b->len);
			printf("\n\n");
		
		*/
		ft_rrr(stack_a, stack_b);
		i++;
	}
	/* 
		ft_print_arr(stack_a->arr,stack_a->len);
		ft_print_arr(stack_b->arr,stack_b->len);
		printf("\n"); 
	*/
	assert(stack_a->len == 10);
	assert(stack_a->arr[0] == start_point_a);
	assert(stack_b->arr[0] == start_point_b);
    assert(ft_rr(NULL, NULL) == 1);

	stack_a->mvm_counter = 0;
	printf("====> Fonction rrr Ok\n\n");	
	printf("====> Test de la fonction rr: stack a len: %d\n\n", stack_a->mvm_counter);	

	i = 0;
	while (i < 10)
	{
		/* 
			ft_print_arr(stack_a->arr,stack_a->len);
			ft_print_arr(stack_b->arr,stack_b->len);
			printf("\n\n");
		*/
		ft_rr(stack_a, stack_b);
		i++;
	}

	/* 
		ft_print_arr(stack_a->arr,stack_a->len);
		ft_print_arr(stack_b->arr,stack_b->len);
		printf("\n"); 
	*/
	assert(stack_a->len == 10);
	assert(stack_a->arr[0] == start_point_a);
	assert(stack_b->arr[0] == start_point_b);
    assert(ft_rrr(NULL, NULL) == 1);
	printf("====> Fonction rr Ok\n\n");	
	ft_clean_memory(&stack_a,&stack_b);

	return(0);
}