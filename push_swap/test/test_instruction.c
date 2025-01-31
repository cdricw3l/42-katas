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

int	ft_partition_custome_1(t_pile *src, t_pile *dest, int high)
{
	int	i;
	int	j;
	int	pivot;
	int	idx_pivot;

	idx_pivot = (high - 1) / 2;
	pivot = src->arr[idx_pivot];
	i = 0;
    printf(" ==> pivot %d\n", pivot);
    while (i < idx_pivot)
    {
        if(src->arr[i] < pivot)
        {
            optimised_rotation(src, i);
            ft_push(&dest, &src);
            idx_pivot--;
        }
        i++;
        
    }
	j = src->len - 1;
    printf( "== > ip %d ==> j : %d\n", idx_pivot, j);
    while (j > idx_pivot)
    {
        if(src->arr[j] < pivot)
        {
            int check = src->arr[j];
            optimised_rotation(src, j);
            assert(src->arr[0] == check );
            ft_push(&dest, &src);
        }
        j--;
    }
    ft_get_stack_data(src);
    ft_get_stack_data(dest);

	return (src->mvm_counter + dest->mvm_counter);
}

int	ft_partition_custome_2(t_pile *src, t_pile *dest)
{
	int	i;
	int	j;
	int	pivot;
	int	idx_pivot;
    int o;
	idx_pivot = (src->len) / 2;
	pivot = src->arr[idx_pivot];
	i = 0;
    
	j = src->len - 1;
    while (i < idx_pivot && j >= idx_pivot)
    {

        while (src->arr[i] > pivot)
            i++;
        while (src->arr[j] > pivot)
            j--;
        if(src->arr[i] < src->arr[j])
        {
            o  = optimised_rotation(src, i);
            ft_push(&dest, &src);
            idx_pivot -= o;
            i = 0;
        }
        else if(src->arr[i] > src->arr[j])
        {
            o = optimised_rotation(src, j);
            ft_push(&dest, &src);
            i = 0;
            if(o == 0)
                idx_pivot += 1;
            else
                idx_pivot += o;
        }
        
        j = src->len - 1;
    }
    printf(" ==> pivot %d\n ==> i %d\n ==> j %d\n idx : %d\n",pivot ,i, j, idx_pivot);
    ft_print_arr(src->arr, src->len);
	return (idx_pivot);
}


void process(t_pile *a, t_pile *b)
{

    while (a->len > 2)
    {
        int min = ft_get_lowest_idx(a->arr, a->len);
        optimised_rotation(a,min);
        ft_push(&b, &a);
    }
    if(a->arr[0]>a->arr[1])
        ft_swap(a);
    while (b->len > 0)
    {
        ft_push(&a, &b);
    }
    
    
}

/* int get_optimised_cost(int len, int idx)
{
    if(idx > (len) / 2)
        return(len - idx);
    return(idx);
} */

/* int ft_get_target_idx2(t_pile *stack, int n)
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
} */
/* int ft_get_the_cost(t_pile *dst, t_pile *src, int n)
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
} */

int ft_test_cost(void)
{
    t_pile *stack_a;
    t_pile *stack_b;
    int n;

    n = 10;
    stack_a = ft_new_stack(n, 6, 97);
    stack_b = ft_new_stack(n, 0, 98);
    if(!stack_a || !stack_b)
        return(ft_clean_memory(&stack_a, &stack_b));

    stack_a->arr[0] = 44;
    stack_a->arr[1] = 2;
    stack_a->arr[2] = 10;
    stack_a->arr[3] = 32;
    stack_a->arr[4] = 12;
    stack_a->arr[5] = 21;

    ft_push(&stack_b, &stack_a);
    ft_push(&stack_b, &stack_a);

    assert(ft_get_the_cost(stack_b,stack_a, stack_a->arr[0]) == 0);
    assert(ft_get_the_cost(stack_b,stack_a, stack_a->arr[1]) == 1);
    assert(ft_get_the_cost(stack_b,stack_a, stack_a->arr[2]) == 2);
    assert(ft_get_the_cost(stack_b,stack_a, stack_a->arr[3]) == 1);

    stack_a->arr[0] = -2;
    stack_a->arr[1] = -44;
    stack_a->arr[2] = -10;
    stack_a->arr[3] = -32;
    stack_a->arr[4] = 12;
    stack_a->arr[5] = 210;


    stack_a->len = 6;
    stack_b->arr[0] = 0;
    stack_b->arr[1] = 0;
    stack_b->len = 0;
    ft_push(&stack_b, &stack_a);
    ft_push(&stack_b, &stack_a);

    assert(ft_get_the_cost(stack_b,stack_a, stack_a->arr[0]) == 0);
    assert(ft_get_the_cost(stack_b,stack_a, stack_a->arr[1]) == 1);
    assert(ft_get_the_cost(stack_b,stack_a, stack_a->arr[2]) == 3);
    assert(ft_get_the_cost(stack_b,stack_a, stack_a->arr[3]) == 2);


    stack_a->arr[0] = 312;
    stack_a->arr[1] = 2;
    stack_a->arr[2] = -10;
    stack_a->arr[3] = -32;
    stack_a->arr[4] = 12;
    stack_a->arr[5] = 210;
    stack_a->arr[6] = -3;
    stack_a->arr[7] = 21;

    stack_a->len = 8;
    stack_b->len = 0;
    stack_b->arr[0] = 0;
    stack_b->arr[1] = 0;
    ft_push(&stack_b, &stack_a);
    ft_push(&stack_b, &stack_a);

    ft_get_stack_data(stack_a);
    ft_get_stack_data(stack_b);

    assert(ft_get_the_cost(stack_b,stack_a, stack_a->arr[0]) == 1);
    assert(ft_get_the_cost(stack_b,stack_a, stack_a->arr[1]) == 2);
    assert(ft_get_the_cost(stack_b,stack_a, stack_a->arr[2]) == 2);
    assert(ft_get_the_cost(stack_b,stack_a, stack_a->arr[3]) == 3);
    assert(ft_get_the_cost(stack_b,stack_a, stack_a->arr[4]) == 3);
    assert(ft_get_the_cost(stack_b,stack_a, stack_a->arr[5]) == 1);

    ft_clean_memory(&stack_a, &stack_b);

    return(0);
}


int ft_test_rotation(void)
{
    t_pile *stack_a;
    t_pile *stack_b;
    int n;
    int i;
    int best_cost_idx;
    int best_cost;

    n = 15;
    stack_a = ft_new_stack(n, n, 97);
    stack_b = ft_new_stack(n, 0, 98);
    if(!stack_a || !stack_b)
        return(ft_clean_memory(&stack_a, &stack_b));
    int g = ft_generate_number(stack_a->arr, stack_a->len);
        assert(g == 0);
    assert(ft_is_rsort(stack_a->arr, stack_a->len, 4, ft_cmp_int) == 1);

    ft_push(&stack_b, &stack_a);
    ft_push(&stack_b, &stack_a);
    best_cost_idx = 0;
    best_cost = 0;
    ft_get_stack_data(stack_a);
    while (stack_a->len > 0)
    {
        i = 0;
        while (i < stack_a->len)
        {
            int cost = ft_get_the_cost(stack_b, stack_a, stack_a->arr[i]);
            if(cost < best_cost)
                best_cost_idx = i;
            i++;
        }
        int taret_idx = ft_get_target_idx2(stack_b, stack_a->arr[best_cost_idx]);
        
        //printf("voici la cible == 1  %d\n",stack_a->arr[best_cost_idx]);
        optimised_rotation(stack_a, best_cost_idx);
        //printf("voici la cible == 2 %d\n",stack_a->arr[0]);
        optimised_rotation(stack_b, taret_idx);
        ft_push(&stack_b, &stack_a);
        //printf("voici la cible == 3 %d\n",stack_b->arr[0]);
        assert(stack_a->arr[0] ==  stack_a->arr[best_cost_idx]);
        ft_get_stack_data(stack_b);
    }
    ft_return_to_max(stack_b);
    assert(ft_is_rsort(stack_b->arr, stack_b->len, 4, ft_cmp_int) == 0);
    // ft_get_stack_data(stack_b);
    // ft_get_stack_data(stack_a);
    ft_clean_memory(&stack_a, &stack_b);
    
    return(0);
}


int ft_test_push(void)
{
    
    t_pile *stack_a;
    t_pile *stack_b;
    int n;

    n = 10;
    stack_a = ft_new_stack(n, 6, 97);
    stack_b = ft_new_stack(n, 0, 98);
    if(!stack_a || !stack_b)
        return(ft_clean_memory(&stack_a, &stack_b));
    // int g = ft_generate_number(stack_a->arr, stack_a->len);
    // assert(g == 0);

    stack_a->arr[0] = 44;
    stack_a->arr[1] = 2;
    stack_a->arr[2] = 10;
    stack_a->arr[3] = 32;
    stack_a->arr[4] = 12;
    stack_a->arr[5] = 21;

    // stack_a->arr[6] = 7;
    // stack_a->arr[7] = 78;
    // stack_b->arr[0] = 3;
    // stack_b->arr[1] = 23;


    // ft_print_arr(stack_a->arr, stack_a->len);

    int i = 0;
    int best_cost;
    int cost;
    int index_best_cost;
    int max_in_b;

    while (stack_a->len > 2)
    {
        index_best_cost = 0;
        best_cost = 0;
        i = 0;
        while (i < stack_a->len)
        {
            max_in_b = ft_get_target_idx2(stack_b, stack_a->arr[i]);
            printf("analyse du cout pour %d et idx cible %d\n", stack_a->arr[i], max_in_b);
            printf("voici la cible dans d %d\n", stack_b->arr[max_in_b]);
            cost = ft_get_the_cost(stack_b, stack_a, stack_a->arr[i]);
            printf("cout egale : %d\n", cost);
            if(cost < best_cost)
            {
                best_cost = cost;
                index_best_cost = i;
            }
            i++;
        }
        printf("voici le meilleur element %d et sont index %d\n", stack_a->arr[index_best_cost], index_best_cost);
        optimised_rotation(stack_a, index_best_cost);
        optimised_rotation(stack_b, max_in_b);
        ft_push(&stack_b, &stack_a);
        
    }
     ft_get_stack_data(stack_a);
        ft_get_stack_data(stack_b);
    
    ft_clean_memory(&stack_a, &stack_b);
    return(0);
}

int ft_get_biggest_unit(int *arr, int len)
{
    int i;
    int n;
    int unit;
    int max_unit;

    i = 0;
    max_unit = 0;
    while (i < len)
    {
        n = arr[i];
        unit = 0;
        while (n / 10 > 0)
        {
            unit++;
            n = n / 10;
        }
        if(unit > max_unit)
            max_unit = unit;
      
        i++;
    }
    return(max_unit);
}

int *ft_frequence_arr(t_pile *stack, int u)
{
    int i;
    int *arr;
    int unit;

    i = 0;
    arr = calloc(10, sizeof(int));
    if(!arr)
        return(NULL);
    while (i < stack->len)
    {
        unit = (stack->arr[i] / u) % 10 ;
        arr[unit]++;
        i++;
    }    
    return(arr);
}

// int main(void)
// {
//     //ft_test_cost();
//     //ft_test_rotation();
//     //ft_test_push();

//     int n;    
//     int unit_max;
//     t_pile *stack_a;
//     t_pile *stack_b;

//     n = 10;
//     stack_a = ft_new_stack(n, n, 97);
//     stack_b = ft_new_stack(n, 0, 98);
    
//     stack_a->arr[0] = 9;
//     stack_a->arr[1] = 19;
//     stack_a->arr[2] = 223;
//     stack_a->arr[3] = 8;
//     stack_a->arr[4] = 409;
//     stack_a->arr[5] = 22211;
//     stack_a->arr[6] = 29;
//     stack_a->arr[7] = 887;
//     stack_a->arr[8] = 87;
//     stack_a->arr[9] = 1;

//     unit_max = ft_get_biggest_unit(stack_a->arr, stack_a->len);
//     (void)unit_max;
//     int *arr = ft_frequence_arr(stack_a, 1);
//     ft_print_arr(arr, 10);
    
//     free(arr);

//     ft_clean_memory(&stack_a, &stack_b);
//     return(0);
// }