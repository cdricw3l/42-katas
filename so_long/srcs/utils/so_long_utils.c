/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:41:56 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/21 21:39:37 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"


void  ft_get_dimentions(int fd, t_data  *data)
{
    char *str;
    int largeur;
    int hauteur;
    
    largeur = 0;
    hauteur = 0;
    str  = "";
    while (str != NULL)
    {
        str = get_next_line(fd);
        if (str != NULL)
        {
            printf("%s\n",str);
            if (largeur == 0)
                largeur = ft_strlen(str) - 1;
            hauteur++;
            free(str);
        }
    }
    data->dimention.row = hauteur;
    data->dimention.col = largeur;
}

void    ft_print_map(char **map, int hauteur, int largeur, int fd)
{
    int i;
    int j;
    char c;

    i = 0;

    while (i < hauteur)
    {
        j = 0;
        while(j < largeur)
        {
            if(fd != 13)
            {
                c =  map[i][j];
                printf("%c", c);
                //printf("impression dans le fichier de log: %d\n", fd);
                write(fd, &c, 1);
                
                //printf("voici le nombre de byte ajoute %d\n",h);
            }
            j++;
        }
        if(fd != 13)
            write(fd, "\n", 1);
        printf("\n");
        i++;
    }
}

char **ft_parse_params(char *file, t_data *data)
{
    int i;
    int j;
    int fd;
    char **map;
    char *tmp;
    
    i = 0;

    map = malloc(sizeof(char *) * data->dimention.row);
    if(!map)
        return(NULL);
    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        perror(ft_error_return(2));
        return (NULL);
    }
    while (i < data->dimention.row)
    {
        j = 0;
        map[i] = malloc(sizeof(char *) * data->dimention.col);
        if (!map[i])
            return(NULL);
        tmp = get_next_line(fd);
        while (j < data->dimention.col)
        {
            if(tmp)
            {
                if(tmp[j] == 'C')
                    data->count_item++;
                else if(tmp[j] == 'E')
                {
                    data->exit_position.row = i;
                    data->exit_position.col = j;
                }
                map[i][j] = tmp[j];
                j++;  
            }
        }
        free(tmp);
        i++;
    }
   
    return(map);
}

char *ft_error_return(int error)
{
    if (error == 1)
        return("Aucune map passée en paramètre");
    if (error == 2)
        return("Map introuvable");
    if (error == 3)
        return("Map icomplete");
    if (error == 4)
        return("Erreur d'initialisation de la mlx ou de la fenetre");
    return (NULL);
}

int ft_colors(int larg, int lo)
{
    int colors;

    colors = 0;
    if(larg >= 640 && larg <= 1280 )
        colors = 0x009900CC;
    if(larg % 3 == 0 && lo % 2 == 0)
        colors = 0x00FF36CC;
    else if(larg % 3  != 0 && 2 != 0)
        colors = 0x0033CCFF;
    return(colors);
}