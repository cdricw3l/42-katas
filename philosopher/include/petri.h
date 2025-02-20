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

#ifndef PETRI_H
#define PETRI_H

#include <unistd.h>
#include <stdio.h>
#include <assert.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>

#define DEBUGG printf("DEBUGG\n");
#define PRINT_INT(msg) printf("\x1b[31m" "DEBBUG  INT " "%d\n", msg);

#define TEST_START printf("Initiating function test: %s\n", __func__);
#define TEST_SUCCES printf("Function: %s executed successfully.\n", __func__);


typedef struct s_petri_node
{
	int		n_philosopher;
	int 	rang;
	int		token;
	void	*next_node;
	
} t_petri_node;

int				ft_create_petri_network(int params);
t_petri_node    **ft_init_nodes_network(int n_node);
void    		ft_add_node(t_petri_node **first_node, t_petri_node *node ,int rang);
t_petri_node	*ft_new_p_node(int n_node, int rang);

#endif