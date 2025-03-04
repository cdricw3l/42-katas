/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   petri.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 09:36:39 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/02/20 10:53:15 by cbouhadr         ###   ########.fr       */
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
#include "petri.h"

typedef struct s_philosophe
{
    int rang;
    int state;
    int **fork;
    
} t_philosophe ;


typedef struct s_thread_managment_data
{
    int counter;
    
    int time_data[5];
    pthread_mutex_t **forks;
    pthread_t **threads;
    t_philosophe **philosophes;

}   t_thread_managment_data;





typedef struct s_thread_manager
{
    pthread_t   **thread;
    pthread_mutex_t **arr_mutex;
    
} t_thread_manager;


typedef struct s_thread_data
{
    int *counter;
    t_philosophe *philo;
    pthread_mutex_t **arr_mutex;
    
} p_thread_data;


#define DEBUGG printf("DEBUGG\n");
#define PRINT_INT(msg) printf("\x1b[31m" "DEBBUG  INT " "%d\n", msg);

#define TEST_START printf("Initiating function test: %s\n", __func__);
#define TEST_SUCCES printf("Function: %s executed successfully.\n", __func__);

void	ft_print_arr_int(int *arr, int len);
void	ft_print_arr_str(char **arr, int len);
int     ft_atoi_long(char *argv);
int     *ft_init_arr_arg(char **argv, int argc);
int     ft_isdigit(char c);
int     ft_memcpy(void *src, void *dst, int len);
int ft_clean_tmd(t_thread_managment_data *tmd, int idx);
void       *ft_clean_memory(void **arr, int idx);
#endif