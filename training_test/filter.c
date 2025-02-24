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

#define BUFFER_SIZE 2

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

char *ft_fgets(char *buffer, int fd)
{
    int b_read;

    b_read = read(fd, buffer, BUFFER_SIZE - 1);
    if(b_read == -1)
        return(NULL);
    printf("voici buffer 0 %d\n", buffer[0]);
    if(buffer[0] == 0)
        return(NULL);
    buffer[b_read] = '\0';

    return(buffer);
}

int main() {
    char buffer[BUFFER_SIZE];

    printf("Tapez plusieurs lignes puis appuyez sur Entrée :\n");

    // while (fgets(buffer,BUFFER_SIZE, stdin) != NULL) {
       
    //     printf("%s", buffer);
    // }

    while (ft_fgets(buffer,0) != NULL) {
        printf("%s", buffer);
    }


    return 0;
}

// int main(int argc, char **argv)
// {
//     char *buffer;
//     char *line;

//     if(argc < 2 || argc > 2)
//         return(-1);
//     buffer = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
//     if(!buffer)
//     {
//         perror("Error :");
//         return (-1);
//     }
//     line = NULL;
//     while (fgets(buffer, BUFFER_SIZE ,stdin) != NULL)
//     {
//         line = ft_strjoin(line, buffer[0]);
//         if(buffer[0]== 10)
//         {
//             printf("%s", line);
//             free(line);
//             line = NULL;
//         }

//     }

//     free(buffer);
//     (void) argv;
//     return(0);
// }