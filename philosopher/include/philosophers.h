/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:14:49 by cbouhadr          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/03/04 11:16:05 by cbouhadr         ###   ########.fr       */
=======
/*   Updated: 2025/03/04 15:14:41 by cw3l             ###   ########.fr       */
>>>>>>> d45aa1faa8b5846874cf2d2f4ddffe9f110822d7
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

}   t_thread_data;


typedef struct s_philosophe
{
    int rang;
    int state;
    int **fork;
    
} t_philosophe ;

typedef struct s_thread_manager
{
    pthread_t   **thread;
    pthread_mutex_t **arr_mutex;
    t_philosophe **philosophes;
    
} t_thread_manager;

typedef struct s_thread_data
{
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

#endif