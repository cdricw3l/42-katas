/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:41:56 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/20 13:25:40 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
            if (largeur == 0)
                largeur = ft_strlen(str) - 1;
            hauteur++;
        }
    }
    data->dimention.hauteur = hauteur;
    data->dimention.largeur = largeur;
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

    map = malloc(sizeof(char *) * data->dimention.hauteur);
    if(!map)
        return(NULL);
    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        perror(ft_error_return(2));
        return (NULL);
    }
    while (i < data->dimention.hauteur)
    {
        j = 0;
        map[i] = malloc(sizeof(char *) * data->dimention.hauteur);
        if (!map[i])
            return(NULL);
        tmp = get_next_line(fd);
        while (j < data->dimention.largeur)
        {
            if(tmp)
            {
                if(tmp[j] == 'C')
                    data->count_item++;
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
        colors = 0x00FF33CC;
    else if(larg % 3  != 0 && 2 != 0)
        colors = 0x0033CCFF;
    return(colors);
}