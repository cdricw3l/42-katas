/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   petri_network_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 09:02:54 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/02/20 10:57:43 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

// void	ft_clean_node_list(t_petri_node    **p_node_1, int idx)
// {
// 	int i;

// 	if(!p_node_1)
// 		return ;
// 	i = 0;
// 	while (i < idx)
// 	{
		
// 	}
	
// }


t_petri_node *ft_new_p_node(int n_node, int rang)
{
	t_petri_node *node;

	node = malloc(sizeof(t_petri_node));
	if (!node)
		return (NULL);
	node->n_philosopher = n_node;
	node->rang = rang;
	node->token = 1;
	node->next_node = NULL;
	return (node);
}

void    ft_add_node(t_petri_node **first_node, t_petri_node *node ,int rang)
{
	t_petri_node *next_node;
	
	if(!(*first_node))
		*first_node = node;
	else
	{
		next_node = (*first_node)->next_node;
		while ((*first_node)->next_node)
		{
			next_node = (*first_node)->next_node;
		}
		printf("nous voici arrive au dernier noeud %p\n", next_node);
	}
	(void)rang;
}

t_petri_node    **ft_init_nodes_network(int n_node)
{
	int             i;
	t_petri_node    **p_node_1;
	t_petri_node    *p_node;

	i = 1;
	p_node_1 = malloc(sizeof(t_petri_node *));
	if (!p_node_1)
		return(NULL);
	while (i <= n_node)
	{
		p_node = ft_new_p_node(n_node, i);
		if (!p_node)
		{
			//ft_clean_node_list(p_node_1, i);
			free(p_node_1);
			return (NULL);
		}
		ft_add_node(p_node_1, p_node, i);
		i++;
	}

	return(p_node_1);
}

int    ft_create_petri_network(int params)
{
	t_petri_node **p_node_1;

	if(!params)
		return(-1);
	p_node_1 = ft_init_nodes_network(params);
	if(!p_node_1)
		return(-1);
	return (params);
}
