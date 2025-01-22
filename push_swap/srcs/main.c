/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:53:07 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/15 12:53:06 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <limits.h>

// static int	ft_init_progr(char **argv, t_pile *stack)
// {
// 	int	rep;

// 	if (!ft_validation_arg(&argv[1]))
// 	{
// 		ft_parsing(&argv[0], stack);
// 		rep = ft_check_repetition(stack);
// 		if (rep == -1)
// 			return (-1);
// 		else
// 			return (rep);
// 	}
// 	return (-1);
// }

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


/* void	ft_push_swap(int *a, int len)
{
	int	*b;
	int value_max;
	int value_min;
	int pivot;
	printf("voici la len %d\n", len);
	b = malloc(sizeof(int) * (len + 1));
	if (!b)
		return ;
	b[0] = '\0';
	
	while (ft_size_of_array(a) > 3)
	{
		value_min =  get_low(a, len);
		value_max =  get_high(a, len);
		pivot = value_min;
		while (ft_find_cible(a, pivot, len) != -1 && ft_size_of_array(a) > 3)
		{
			int i = ft_find_cible(a, pivot, len);
			if(i > len + 1 / 2)
			{
				int j = len - i - 1;
				while ( j != 0)
				{
					ft_rotate(a, 'a');
					j--;
				}
			}
			else
			{
				while ( i != 0)
				{
					ft_reverse_rotate(a, 'a');
					i--;
				}
				
			}
			pivot = a[i];
			ft_push_b(b, a);
		}
	}
	ft_two_or_tree_args(a, 3);
	int i = 0;
	while (b[i])
	{
		ft_push_b(a, b);
		i++;
	}
	ft_print_arr(a);
	(void)value_max;
	free(b);
} */

// int	main(int argc, char **argv)
// {
// 	int	len;
// 	int	*arr;
// 	int	tx;
// 	t_pile *stack_a;
//     t_pile *stack_b;

// 	arr = NULL;
// 	if (argc < 2)
// 		return (ft_print_error());
// 	len = number_of_int(&argv[1]);
// 	if(len == 0)
// 		return(1);
// 	stack_a = ft_new_stack(len, len, 97);
//     stack_b = ft_new_stack(len, 0, 98);
// 	if(!stack_a->arr || !stack_b->arr)
// 		return(ft_clean_memory(&stack_a, &stack_b));
// 	tx = ft_init_progr(&argv[1], stack_a, len);
// 	if (tx == -1)
// 		return (ft_print_error());
// 	else
// 	{
// 		ft_print_arr(stack_a->arr, stack_a->len);
// 		if (len == 2 || len == 3)
// 			ft_two_or_tree_args(stack_a);
// 		else
// 			return(0);
// 		ft_print_arr(stack_a->arr, stack_a->len);
// 		return(ft_clean_memory(&stack_a, &stack_b));
// 	} 
// 	return (0);
// }
