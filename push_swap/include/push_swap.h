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
#include <limits.h>





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
int     ft_check_repetition(t_pile *stack);
int     ft_are_space(char *str);
int     number_of_int(char **argv);
void    ft_fill_process(char **argv, int *arr);
int     ft_parsing(char **argv, t_pile *stack);
void    ft_print_arr(int *arr, int len);
int     get_high(int *arr, int size);
int     get_low(int *arr, int size);
int     ft_print_error();
int     get_low_idx(int *arr, int size);
void    ft_two_or_tree_args(t_pile *stack);
int     ft_size_of_array(int *arr);
void    ft_get_stack_data(t_pile *stack);
void	ft_qsort_int(int *base, int low, int high);
int      ft_find_cible(int arr[], int pivot, int len);

//instruction

int    ft_swap(t_pile *stack);
int	    ft_rotate(t_pile *stack);
int	    ft_reverse_rotate(t_pile *stack);
int	    ft_push(t_pile **dest, t_pile **src);
//memory
int	    ft_clean_memory(t_pile **stack_a, t_pile **stack_b);
//utils
int		ft_get_n_byte(int n, int byte);
int     ft_get_byte_max(int *arr, int len);
t_pile *ft_new_stack(int size, int len, char name);
#endif