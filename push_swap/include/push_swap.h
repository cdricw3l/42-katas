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

typedef struct s_num_lst
{
    int     value;
    void    *next;
} t_num_lst;


int     ft_validation_arg(char **argv);
int     ft_check_repetition(int *arr, int len);
int     ft_are_space(char *str);
int     number_of_int(char **argv);
void    ft_fill_process(char **argv, int *arr);
int     *ft_parsing(char **argv, int len);
void    ft_print_arr(int *arr);
int     get_high(int *arr, int size);
int     get_low(int *arr, int size);
int     ft_print_error();
int     get_low_idx(int *arr, int size);
void    ft_two_or_tree_args(int *arr, int len);
int     ft_size_of_array(int *arr);
//instruction
void    ft_swap(int *stack, int  a, int b, char c);

// rotate >>
void	ft_rotate(int *stack, char c);
// reverse rotate <<
void	ft_reverse_rotate(int *stack, char c);
void	ft_push_a(int *dest, int *src);
void	ft_push_b(int *dest, int *src);
void	ft_qsort_int(int *base, int low, int high);
int     ft_find_cible(int arr[], int pivot, int len);


#endif