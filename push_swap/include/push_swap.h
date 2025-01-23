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


int     ft_find_space(char *str);
void	ft_qsort_int(int *base, int low, int high);
int      ft_find_cible(int arr[], int pivot, int len);


// initialisation, parsing and verification

int     ft_check_repetition(t_pile *stack);
int     ft_parsing(char **argv, t_pile *stack);
int     ft_validation_arg(char **argv);
int	    ft_get_number_of_int(char **argv);

//instruction

int     ft_swap(t_pile *stack);
int	    ft_rotate(t_pile *stack);
int	    ft_reverse_rotate(t_pile *stack);
int	    ft_push(t_pile **dest, t_pile **src);

//algo

void    optimised_rotation(t_pile *stack_a, int index);
void    ft_return_to_zero(t_pile *stack);
void    ft_two_values(t_pile *stack_a);
void    ft_tree_values(t_pile *stack_a);
void    ft_five_value(t_pile *stack_a, t_pile *stack_b);

//memory

int	    ft_clean_memory(t_pile **stack_a, t_pile **stack_b);

//utils
int     ft_find_space(char *str);
void    ft_print_arr(int *arr, int len);
int		ft_get_n_byte(int n, int byte);
int     ft_get_byte_max(int *arr, int len);
t_pile *ft_new_stack(int size, int len, char name);
int     ft_print_error(void);
void    ft_get_stack_data(t_pile *stack);

int     ft_get_highest_value(int *arr, int size);
int     ft_get_lowest_value(int *arr, int size);
int     ft_get_highest_idx(int *arr, int size);
int     ft_get_lowest_idx(int *arr, int size);

void    ft_print_arr(int *arr, int len);
int     ft_print_error();

#endif