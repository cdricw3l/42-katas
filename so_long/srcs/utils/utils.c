/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:43:22 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/31 12:18:14 by cb               ###   ########.fr       */
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
    printf("voici les dim %d et %d\n",x, y);
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

void    ft_print_map(t_game_data *data)
{
    int i;
    int j;
    int hauteur;
    int largeur;
    char **map;

    i = 0;
    if(data->dimention.row && data->dimention.col)
    {
        hauteur = data->dimention.row;
        largeur = data->dimention.col;
        map = data->map;
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

void	exit_game(t_data *data)
{

	printf("clean memory...\n");
    if (data->mlx)
    {
        if(data->img->img)
            mlx_destroy_image(data->mlx, data->img->img);
        if(data->window)
            mlx_destroy_window(data->mlx, data->window);
        mlx_destroy_display(data->mlx);
    }
	ft_free_memory(data);
	printf("END GAME\n");
	exit (0);
}