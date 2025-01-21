/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:56:20 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/13 16:13:24 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libftprintf/include/ft_printf.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <assert.h>




#define PRINT_INT(msg) printf("%d ", msg)
#define PRINT_2INT(msg1, msg2) printf("%d - %d\n", msg1, msg2)
#define PRINT_CHAR(msg) printf("%c", msg)

typedef struct s_pile
{
    char    stack_name;
    int    *arr;
    int     len;
    int     mvm_counter;
    
} t_pile;


int     ft_validation_arg(char **argv);
int     ft_check_repetition(int *arr, int len);
int     ft_are_space(char *str);
int     number_of_int(char **argv);
void    ft_fill_process(char **argv, int *arr);
int     *ft_parsing(char **argv, int len);
void    ft_print_arr(int *arr, int len);
int     get_high(int *arr, int size);
int     get_low(int *arr, int size);
int     ft_print_error();
int     get_low_idx(int *arr, int size);
void    ft_two_or_tree_args(int *arr, int len);
int     ft_size_of_array(int *arr);
void    ft_get_stack_data(t_pile *stack);
//instruction
void    ft_swap(int *stack, int pile);

// rotate >>
int	ft_rotate(t_pile *stack);
// reverse rotate <<
int	ft_reverse_rotate(t_pile *stack);
void	ft_push_a(int *dest, int *src);
void	ft_push_b(int *dest, int *src, int len);
void	ft_qsort_int(int *base, int low, int high);
int        ft_find_cible(int arr[], int pivot, int len);
int	    ft_clean_memory(t_pile **stack_a, t_pile **stack_b);

#endif