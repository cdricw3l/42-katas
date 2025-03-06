/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:53:10 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/06 16:38:02 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>

void swap(char *x, char *y)  
{  
    char temp;  
    temp = *x;  
    *x = *y;  
    *y = temp;  
}  

void ft_permutation(char *str, int start, int end)
{
    int i;
    if(start == end)
    {
        printf("%s\n", str);
    }
    else
    {
        i = start;
        while (i <= end)
        {
            swap(&str[start], &str[i]);
            ft_permutation(str, start + 1, end);
            swap(&str[start], &str[i]);
            i++;
        }
    }
    
}

int main()
{
    char str[] = "abcd";
    int n = 4;

    ft_permutation(str, 0, n-1);
    return(0);
}