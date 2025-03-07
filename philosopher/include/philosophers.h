/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:14:49 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/07 17:16:12 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <unistd.h>
#include <stdio.h>
#include <assert.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>
#include "petri_network.h"

#define DEBUGG printf("DEBUGG\n");
#define PRINT_INT(msg) printf("\x1b[31m" "DEBBUG  INT " "%d\n", msg);

#define TEST_START printf("Initiating function test: %s\n", __func__);
#define TEST_SUCCES printf("Function: %s executed successfully.\n", __func__);

#define PETRI_P 4
#define PETRI_T (PETRI_P - 1)

typedef struct s_thread_data
{
    int ttd;
    int tte;
    int tts;
    
} s_thread_data;


typedef struct s_thread_managment_data
{
    int counter;
    
    pthread_mutex_t **forks;
    pthread_t **thread;
    s_thread_data data;

}   s_thread_managment_data;




 

void	ft_print_arr_int(int *arr, int len);
void	ft_print_arr_str(char **arr, int len);
int     ft_atoi_long(char *argv);
int     *ft_init_arr_arg(char **argv, int argc);
int     ft_isdigit(char c);
int     ft_memcpy(void *src, void *dst, int size);
void	ft_printm(int **arr, int row, int col);

#endif