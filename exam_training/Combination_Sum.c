/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Combination_Sum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:53:10 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/06 17:33:38 by cbouhadr         ###   ########.fr       */
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
int *ft_pop(int **arr, int len)
{
    int *new_arr;
    int i;
    int j;

    new_arr = malloc(sizeof(int) * (len));
    if(!new_arr)
        return(NULL);
    i = 1;
    if(!(*arr))
        return(NULL);
    j = 0;
    while (j < len)
        new_arr[j++] = (*arr)[i++];
    free(*arr);
    return(new_arr);
}


void conbine(int *arr,int *result,int *len, int arr_len, int target, int idx)
{
    if(target == 0)
    {
        printf("combinaison trouve\n");
    }
    if(target < 0 || idx >= arr_len)
        return ;
    result = ft_push(&result,len, arr[idx]);
    *len++;
    ft_print_arr(arr, len);
    conbine(arr, result,&((*len) + 1), arr_len,target - arr[idx],idx);

    ft_pop(&result, *len);
    conbine(arr, result,(*len) + 1, arr_len,target,idx + 1);
}

int main()
{
    int arr[] = {2, 4, 6, 8};
    int *arr2 = NULL;
    int target = 8;
    int len = 0;
    conbine(arr,arr2, &len,4, target,0);
    
    free(arr2);
    return(0);
}