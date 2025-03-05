/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:53:10 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/05 14:05:21 by cw3l             ###   ########.fr       */
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

#define DEBUGG printf("DEBUGG\n");
#define TEST_START printf("Initiating function test: %s\n", __func__);
#define TEST_SUCCES printf("Function: %s executed successfully.\n", __func__);

void *ft_clean_memory(void **arr, int idx)
{
    int i;

    i = 0;
    if(!arr)
        return(NULL);
    while (i < idx)
    {
        if(arr[i])
            free(arr[i]);
        i++;
    }
    free(arr);
    return(NULL);
    
}

char **ft_result_arr(int n)
{
    char **res;
    int i;

    TEST_START;
    if(n <= 0)
        return(NULL);
    res =  malloc(sizeof(char *) * 500);
    if(!res)
        return(NULL);
    i = 0;
    while (i < 500)
    {
        res[i] = malloc(sizeof(char) * (n + 1));
        if(!res[i])
            return(ft_clean_memory((void **)res, i));
        i++;
    }
    TEST_SUCCES;
    return(res);
}

void ft_bzero(int **arr, int n)
{
    int i;
    int j;

    TEST_START;
    i = 0;
    while(i < n)
    {
        j = 0;
        while(j < n)
        {
            arr[i][j] = 0;
            j++;
        }
        i++;
    }
    TEST_SUCCES;
}

void ft_print_arr(int **arr, int n)
{
    int i;
    int j;

    i = 0;
    while(i < n)
    {
        j = 0;
        while(j < n)
        {
            printf("%d ", arr[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    printf("\n");
}

// void ft_is_diag_safe(int mat[4][4], int n ,int row, int col)
// {


//     if(row < 0 || row > n - 1 || col < 0 || col > n - 1)
//         return ;

//     if(mat[row][col] != 0)
//         return;

//     if(mat[row][col] == 0)
//     {
//         mat[row][col] = 1;
       
//     }

//     ft_is_diag_safe(mat, n , row - 1, col - 1);
//     ft_is_diag_safe(mat, n , row - 1, col + 1);
//     if(row > 0)
//         ft_is_diag_safe(mat, n , row + 1 , col - 1);
//     if(row > 0)
//         ft_is_diag_safe(mat, n , row + 1, col + 1);
// }

int ft_is_diag_safe(int **mat, int n ,int row, int col)
{
    int i;
    int j;

    i = row;
    j = col;
    while (i - 1 >= 0 && j - 1 >= 0)
    {
        if(mat[i - 1][j - 1] == 1)
            return (0);
        i--;
        j--;
    }
    i = row;
    j = col;
    while (i - 1 >= 0 && j + 1 < n)
    {
        if(mat[i - 1][j + 1] == 1)
            return (0);
        i--;
        j++;
    }
    return(1);
}

int issafe(int **mat, int n ,int row, int col)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < n)
    {
        if(mat[row][i] == 1)
            return(0);
        if(mat[j][col] == 1)
            return(0);
        i++;
        j++;
    }
    if(!ft_is_diag_safe(mat,n, row, col))
        return(0);
    return(1);
}

int ft_nqueen(int row,int **mat, int n)
{
    int i;

    i = 0;
    if(row == n)
        return(1);
    while (i < n)
    {
        if(issafe(mat, n,row, i))
        {
            mat[row][i] = 1;
            if(ft_nqueen(row + 1, mat, n))
                return(1);
            mat[row][i] = 0;
        }
        i++;
    }
    return(0);
}

int **ft_create_mat(int n)
{
    int **mat;
    int i;

    TEST_START;
    mat = malloc(sizeof(int *) * n);
    if(!mat)
        return(NULL);
    i =  0;
    while(i < n)
    {
        mat[i] = malloc(sizeof(int) * n);
        if(!mat[i])
            return(ft_clean_memory((void **)mat, i));
        i++;
    }
    TEST_SUCCES;
    return(mat);
}

int main(int argc, char **argv) {
    
    int n;

    n = atoi(argv[1]);
    
    int **mat;
    char **result;
    int i;

    i = 0;
    result = ft_result_arr(n);
    mat = ft_create_mat(n);
    if(!result || !mat)
        return(-1);
    ft_bzero(mat, n);
    ft_print_arr(mat,n);
    assert(mat[0][0] == 0);
    
    while (ft_nqueen(0, mat, n))
    {
        ft_print_arr(mat,n);
        printf("\n");
    }
    
    ft_clean_memory((void **)result, 500);
    return(0);

}
