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
        for (i = start; i <= end; i++)  
        {  
            swap((str + start), (str + i));  
            ft_permutation(str, start + 1, end);  
  
            //backtrack  
            swap((str + start), (str + i));  
        }
    }
    
}

// int main()
// {
//     char str[] = "abcd";
//     int n = 4;

//     ft_permutation(str, 0, n-1);
//     return(0);
// }