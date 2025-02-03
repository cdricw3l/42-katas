/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:56:20 by cw3l              #+#    #+#             */
/*   Updated: 2025/02/03 16:26:36 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libftprintf/include/ft_printf.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <limits.h>

# define BY_PASS_OFF 0
# define BY_PASS_ON 1

typedef struct s_stack
{
	char	stack_name;
	int		*arr;
	int		len;
	int		mvm_counter;
}	t_stack;

// initialisation, parsing and verification

int		ft_check_repetition(t_stack *stack);
int		ft_parsing(char **argv, t_stack *stack);
int		ft_validation_arg(char **argv);
int		ft_get_number_of_int(char **argv);
int		ft_find_space(char *str);

//instruction

int		ft_swap(t_stack *stack);
int		ft_rotate(t_stack *stack, int bypass);
int		ft_reverse_rotate(t_stack *stack, int bypass);
int		ft_push(t_stack **dest, t_stack **src);
int		ft_rr(t_stack *stack_a, t_stack *stack_b);
int		ft_rrr(t_stack *stack_a, t_stack *stack_b);

//algo

int		optimised_rotation(t_stack *stack_a, int index);
int		optimised_double_rotation(t_stack *stk_a, t_stack *stk_b, int index);
void	ft_return_to_max(t_stack *stack);
void	ft_two_values(t_stack *stack_a);
void	ft_tree_values(t_stack *stack_a);
void	ft_five_values(t_stack *stack_a, t_stack *stack_b);
void	ft_turkish_algo(t_stack *stack_a, t_stack *stack_b);
int		get_optimised_cost(int len, int idx);
int		ft_best_cost(t_stack *stack_src, t_stack *stack_dst);

//memory

int		ft_clean_memory(t_stack **stack_a, t_stack **stack_b);

//utils

int		ft_find_space(char *str);
int		ft_print_error(void);
int		ft_get_highest_idx(int *arr, int size);
int		ft_get_lowest_idx(int *arr, int size);
int		ft_get_target_idx(t_stack *stack, int n);
int		ft_print_error(void);

#endif
