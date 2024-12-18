/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:41:56 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/18 12:23:46 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void  ft_get_dimentions(int fd, t_data  *img)
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
            if (largeur == 0)
                largeur = ft_strlen(str) - 1;
            hauteur++;
        }
    }
    img->dimention.hauteur = hauteur;
    img->dimention.largeur = largeur;
}

void    ft_print_map(char **map, int hauteur, int largeur)
{
    int i;
    int j;

    i = 0;
    while (i < hauteur)
    {
        j = 0;
        while(j < largeur)
        {
            printf("%c", map[i][j]);
            j++;
        }
        i++;
    }
    printf("\n");
    
}

char **ft_parse_params(char *file, int hauteur, int largeur)
{
    int i;
    int j;
    int fd;
    char **map;
    char *tmp;
    
    i = 0;
    map = malloc(sizeof(char *) * hauteur);
    if(!map)
        return(NULL);
    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        perror(ft_error_return(2));
        return (NULL);
    }
    while (i < hauteur)
    {
        j = 0;
        map[i] = malloc(sizeof(char *) * largeur);
        if (!map[i])
            return(NULL);
        tmp = get_next_line(fd);
        while (j < largeur)
        {
            if(tmp)
            {
                map[i][j] = tmp[j];
                j++;  
            }
        }
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
    return (NULL);
}
