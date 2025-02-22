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

int main(int argc, char **argv)
{
    char *buffer;
    int b_read;

    if(argc < 2 || argc > 2)
        return(-1);
    buffer = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
    if(!buffer)
    {
        perror("Error :");
        return (-1);
    }
    b_read = -1;
    while (b_read != 0)
    {
        b_read = read(stdin, buffer, BUFFER_SIZE);
        if(b_read == -1)
        {
            free(buffer);
            perror("Error: ");
            return(-1);
        }
        buffer[b_read] = '\0';
        printf("%s", buffer);
    }
    free(buffer);
    return(0);
}