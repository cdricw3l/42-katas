/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:58:47 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/04 14:58:55 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void *ft_factoriel(void *p)
{
    pthread_t pid;

    pid = pthread_self();
    (void)p;
    printf("je suis le thread : [ %ld ]\n", (long)pid);
    return(NULL);
}
#define THREAD 16

void       *ft_clean_memory(pthread_mutex_t **arr, int idx)
{
    int i;

    i = 0;
    TEST_START;
    while(i < idx)
    {
        free(arr[i]);
        i++;
    }
    free(arr);
    TEST_SUCCES;
    return(NULL);
}
pthread_mutex_t **ft_init_mutex(int p)
{
    pthread_mutex_t **mutex_arr;
    int i;

    TEST_START

    mutex_arr = malloc(sizeof(pthread_mutex_t *) * p);
    if(!mutex_arr)
        return(NULL);
    i = 0;
    while (i < p)
    {
        mutex_arr[i] = malloc(sizeof(pthread_mutex_t));
        if(!mutex_arr[i])
            return(ft_clean_memory(mutex_arr, i));
        if(pthread_mutex_init(mutex_arr[i], NULL) != 0)
            return(ft_clean_memory(mutex_arr, i));
        i++;
    }
    TEST_SUCCES;
    return(mutex_arr);
}

int main()
{
    pthread_mutex_t **mutexs;
    int p = 5;


    mutexs = ft_init_mutex(p);
    assert(mutexs);
    return(0);
}