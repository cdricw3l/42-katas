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
//#include "get_next_line/get/get_next_line.h"

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



char *ft_strjoin(char *str, char buffer[3])
{
    char *new_str;
    int str_len;
    int i;
    int j;
    
    str_len = ft_strlen(str);
    new_str = malloc(sizeof(char) * (str_len + 3));
    if(!new_str)
        return(NULL);
    i = 0;
    while (i < str_len)
    {
        new_str[i] = str[i];
        i++;
    }
    j = 0;
    while (j < 2)
    {
        new_str[i++] = buffer[j++];
    }
    new_str[i] = '\0';
    if(str)
        free(str);
    return(new_str);    
}

int ft_double_n(char buffer[3])
{
    if(buffer[0] == 10 && buffer[1] == 10)
        return(1);
    return(0);

}
// char *get_next_line(char *buffer, int fd)
// {
//     char buffer[3];
//     char *line;
//     int b_read;

//     b_read = -1;
//     line = NULL;

//     while ( (b_read = read(0, buffer, 2)) >= 0)
//     {
//         if(b_read == -1)
//             return(NULL);
//         if(!ft_double_n(buffer))
//         {
//             line = ft_strjoin(line, buffer);
//             printf("passage a\n");
//         }
//         if(ft_double_n(buffer))
//         {
            
//             line = ft_strjoin(line, buffer);
//             printf("passage b\n");
//             return(line);
//         }
//         int c;
//         c = 0;
//         c+=b_read;
//         printf("b read %d\n", c);

//     }
//     printf("fin de  passage\n");
//     return(NULL);
// }

int main() {
    // char buffer[BUFFER_SIZE];
    char line[2];

    printf("Tapez plusieurs lisagnes puis appuyez sur Entrée :\n");

    // while (fgets(buffer,BUFFER_SIZE, stdin) != NULL) {
       
    //     printf("%s", buffer);
    // }
    while (fgets(line,2,stdin) != NULL) {
        
        
        printf("%s", line);
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


// ddd
// ffff
// hhhh
