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

#define BUFFER_SIZE 1

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    if(!str)
        return(0);
    while(str[i])
        i++;
    return(i);
}

char *ft_strjoin(char *str, char c)
{
    char *new_str;
    int str_len;
    int i;

    
    str_len = ft_strlen(str);
    new_str = malloc(sizeof(char) * (str_len + 2));
    if(!new_str)
        return(NULL);
    i = 0;
    while (i < str_len)
    {
        new_str[i] = str[i];
        i++;
    }
    new_str[i++] = c;
    new_str[i] = '\0';
    if(str)
        free(str);
    return(new_str);    
}

int main(int argc, char **argv)
{
    char *buffer;
    int b_read;
    char *line;

    if(argc < 2 || argc > 2)
        return(-1);
    buffer = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
    if(!buffer)
    {
        perror("Error :");
        return (-1);
    }
    b_read = -1;
    line = NULL;
    while (b_read != 0)
    {
        b_read = read(0, buffer, BUFFER_SIZE);
        if(b_read == -1)
        {
            free(buffer);
            if(line)
                free(line);
            printf("quidddddddd\n");
            perror("Error: ");
            return(-1);
        }
        buffer[BUFFER_SIZE]= '\0';
        if(buffer[0] != 10)
        {
            line = ft_strjoin(line, buffer[0]);
            if(!line)
            {
                perror("Err: ");
                free(buffer);
            }
        }
        else if(buffer[0] == 10)
        {
            printf("%s\n", line);
            free(line);
            line = NULL;
        }
        else if(buffer[0] == EOF)
        {
            free(line);
            line = NULL;
        }
    }
    if(line)
        free(line);
    free(buffer);
    (void) argv;
    return(0);
}