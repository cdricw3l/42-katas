/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:43:22 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/30 09:58:19 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	*ft_free_memory(t_data *data)
{
    char **map;

    map = data->game_data->map;
    if(map)
    {
        while (*map)
        {
            free(*map);
            map++;
        }
    }
    free(data->img);
    free(data->game_data->map);
	free(data->game_data);
	free(data->check_list);
	free(data);
	return (NULL);
}

void ft_analsyse_line(char *str)
{
	if(!str)
		return ;
	while (*str)
	{
		printf("%d ", *str);
		str++;
	}
	printf("\n");
	
}

int ft_is_square(t_game_data *data)
{
    int x;
    int y;

    if(!data)
        return(1);
    x = data->dimention.col;
    y = data->dimention.row;
    if( x - y == 0)
    {
        printf("La map est carré\n");
        return(1);
    }        
    return(0);
}

// void  ft_get_dimentions(int fd, t_data  *data)
// {
//     char *str;
//     int largeur;
//     int hauteur;
    
//     largeur = 0;
//     hauteur = 0;
//     str  = "";
//     while (str != NULL)
//     {
//         str = get_next_line(fd);
//         if (str != NULL)
//         {
//             if (largeur == 0)
//                 largeur = ft_strlen(str) - 1;
//             hauteur++;
//         }
//     }
//     data->dimention.hauteur = hauteur;
//     data->dimention.largeur = largeur;
// }

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

int ft_arr_len(char **arr)
{
    int i;

    i = 0;
    if(arr)
    {
        while (arr[i] != NULL)
            i++;
        return(i);
    }
    return (-1);
}

// char **ft_parse_params(char *file, t_data *data)
// {
//     int i;
//     int j;
//     int fd;
//     char **map;
//     char *tmp;
    
//     i = 0;

//     map = malloc(sizeof(char *) * data->game_data->dimention.row);
//     if(!map)
//         return(NULL);
//     fd = open(file, O_RDONLY);
//     if (fd == -1)
//     {
//         perror(ft_error_return(2));
//         return (NULL);
//     }
//     while (i < data->dimention.hauteur)
//     {
//         j = 0;
//         map[i] = malloc(sizeof(char *) * data->dimention.hauteur);
//         if (!map[i])
//             return(NULL);
//         tmp = get_next_line(fd);
//         while (j < data->dimention.largeur)
//         {
//             if(tmp)
//             {
//                 if(tmp[j] == 'C')
//                     data->count_item++;
//                 else if(tmp[j] == 'E')
//                 {
//                     data->exit_position.hauteur = i;
//                     data->exit_position.largeur = j;
//                 }
//                 map[i][j] = tmp[j];
//                 j++;  
//             }
//         }
//         i++;
//     }
//     return(map);
// }

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