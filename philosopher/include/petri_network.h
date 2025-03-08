/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   petri_network.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:46:05 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/08 08:39:43 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PETRI_NETWORK_H
#define PETRI_NETWORK_H

#include <unistd.h>
#include <stdio.h>
#include <assert.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>
#include "philosophers.h"
#include "str_to_matrice.h"

#define DEBUGG printf("DEBUGG\n");
#define PRINT_INT(msg) printf("\x1b[31m" "DEBBUG  INT " "%d\n", msg);

#define TEST_START printf("Initiating function test: %s\n", __func__);
#define TEST_SUCCES printf("Function: %s executed successfully.\n", __func__);


typedef struct s_petri_network
{
    int     *P;
    int     *T;
    int     *M0;
    int     **M_in;        
    int     **M_out;

} t_petri_network;


int                 *ft_create_place(int P, int *M_0);
int                 *ft_create_transitions(int T);
int                 **ft_copy_matrice(int **M_in, int P, int T);
void                *ft_clean_matrice_mem(int **M, int idx);
t_petri_network     *ft_create_network(int *PT, int *M_0, int **M_in, int **M_out);

#endif