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

void       *ft_clean_memory(void **arr, int idx)
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

t_thread_managment_data *_init_thread_data_struc(int arr[5])
{
    t_thread_managment_data *tmd;
    
    tmd = malloc(sizeof(t_thread_managment_data));
    if(!tmd)
        return(NULL);
    tmd->philosophes = malloc(sizeof(t_philosophe *));
    if(!tmd->philosophes)
        return(NULL);
    tmd->threads = malloc(sizeof(pthread_t *));
    if(!tmd->threads)
    {
        free(tmd->philosophes);
        return(NULL);
    }
    tmd->forks = malloc(sizeof(pthread_mutex_t *));
    if(!tmd->forks)
    {
        free(tmd->philosophes);
        free(tmd->threads);
        return(NULL);
    }
    // if(ft_create_thread_data(tmd->philosophes, tmd->threads, tmd->forks)
    //         == -1);
    //     return(NULL);
    if(ft_memcpy(arr, tmd->time_data, 5 * sizeof(int)) != 5 * sizeof(int))
        return(NULL);

    return(tmd);
}

int main()
{
    t_thread_managment_data *master_data;
    int arr[5];
    
    arr[0] = 5;
    arr[1] = 4000;
    arr[2] = 4000;
    arr[3] = 4000;
    arr[4] = 0;
    master_data = _init_thread_data_struc(arr);
    if(!master_data)
    {
        printf("error\n");
        return(-1);
    }
    ft_clean_memory(master_data->forks, 5);
    ft_clean_memory(master_data->philosophes, 5);
    ft_clean_memory(master_data->threads, 5);
    free(master_data);
    return(0);
}