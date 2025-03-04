/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:53:10 by cw3l              #+#    #+#             */
/*   Updated: 2025/02/22 20:17:03 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 10

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
//#include "get_next_line/get/get_next_line.h"


typedef struct s_node
{
    int value;
    void **arr_node;
    void *next;

}t_node;

int ft_strlen(char *str)
{
    int i;

    i = 0;
    if(!str)
        return(0);
    while (str[i])
        i++;
    return(i);
}

void ft_display_node_data(t_node *node)
{
    if(node)
    {
        printf("Valeur du noeud: %c\n", node->value);
        printf("Adresse du noeud: %p\n", node);
        if(node->next)
            printf("Adresse du prochain noeud: %p\n", node->next);
        else
            printf("Dernier noeud de la liste\n");
        printf("\n");

    }
}

void    ft_display_lst_data(t_node **lst)
{
    t_node *first_node;

    if(!lst || !*lst)
        return ;
    first_node = *lst;
    while (first_node)
    {
        ft_display_node_data(first_node);
        first_node = first_node->next;
    }
    
}

t_node *ft_get_last_node(t_node **lst_node)
{
    t_node *first_node;

    if (!lst_node || !*lst_node)
        return(NULL);
    first_node = *lst_node;
    while (first_node->next)
        first_node = first_node->next;
    return(first_node);
}

void ft_add_back_node(t_node **lst_node, t_node *new_node)
{
    t_node *last_node;

    if(!lst_node)
        return ;
    if (!*lst_node)
    {
        *lst_node = new_node;
    }
    else
    {
        last_node = ft_get_last_node(lst_node);
        if(last_node)
            last_node->next = new_node;
    }
}

t_node *ft_new_node(int value, int k)
{
    t_node *node;

    node = malloc(sizeof(t_node));
    if (!node)
        return(NULL);
    node->value = value;
    node->arr_node = malloc(sizeof(t_node *) * (k - 1));
    if(!node->arr_node)
        return(NULL);
    node->next = NULL;
    return(node);
}

void    ft_clean_lst(t_node **lst, int idx)
{
    int i;

    i = 0;
    while (i <= idx)
    {
        free(lst[i]->arr_node);
        free(lst[i]);
        i++;
    }
    free(lst);
}

int ft_create_first_couch(t_node **lst, char *str, int strlen, int k)
{
    int i;
    t_node *node;

    if (!lst)
        return(-1);
    i = 0;
    while (str[i])
    {
        node = ft_new_node(str[i], k);
        if(!node)
        {
            ft_clean_lst(lst, i);
            return(-1);
        }
        ft_add_back_node(lst, node);
        i++;
    }
    return(0);
}

t_node **create_tree(char *str)
{
    t_node **start_lst;
    int n;
    int k;

    start_lst = malloc(sizeof(t_node *));
    if(!start_lst)
        return(NULL);
    n = ft_strlen(str);
    k = n;
    assert(ft_create_first_couch(start_lst,str, n, k) > -1);

    return(start_lst);
}



int main() {
    
    char txt[] = "abcde";
    
    t_node *new = ft_new_node(txt[0],4);
    // assert(new->value == 97);
    t_node *last_node = ft_get_last_node(&new);
    // assert(last_node->value == 97);
    // ft_add_back_node(&new, ft_new_node(txt[1]));
    // last_node = ft_get_last_node(&new);
    // assert(last_node->value == 98);
    // ft_add_back_node(&new, ft_new_node(txt[2]));
    // last_node = ft_get_last_node(&new);
    // assert(last_node->value == 99);
    //ft_display_node_data(new);


    t_node **lst =  create_tree(txt);
    ft_display_lst_data(lst);
    (*lst)->arr_node[0] = new;
    assert((*lst)->arr_node[0] == new);
    printf("voici la'adresse %p \n", (*lst)->arr_node[0]);


    return(0);

}
