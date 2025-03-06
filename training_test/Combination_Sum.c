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

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>

#define DEBUGG printf("DEBUGG\n");
#define TEST_START printf("Initiating function test: %s\n", __func__);
#define TEST_SUCCES printf("Function: %s executed successfully.\n", __func__);

void ft_print_arr(int *arr, int n)
{
    int i;

    i = 0;

    while(i < n)
    {
        printf("%d ", arr[i]);
        i++;
    }

    printf("\n");
}

int *ft_push(int **arr, int len,int n)
{
    int *new_arr;
    int i;
    int j;

    new_arr = malloc(sizeof(int) * (len + 1));
    if(!new_arr)
        return(NULL);
    i = 0;
    new_arr[i++] = n;
    if(!(*arr))
        return(new_arr);
    j = 0;
    while (j < len)
        new_arr[i++] = (*arr)[j++];
    free(*arr);
    return(new_arr);
}
int main()
{
    int arr[] = {2, 4, 6, 8};
    int *arr2 = NULL;
    int target = 8;

    arr2 = ft_push(&arr2, 0, 10);
    ft_print_arr(arr2, 1);
    arr2 = ft_push(&arr2, 1, 190);
    ft_print_arr(arr2, 2);
    free(arr2);
    return(0);
}