/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:40:59 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/17 20:47:30 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

typedef struct s_data
{
    void    *img;
    char    *addr;
    int     bit_per_pixel;
    int     line_length;
    int     endian;

} t_data;


void ft_put_px(t_data *data, int x, int y, int color)
{
    char *dst;
    

  
    dst = data->addr + (y * data->line_length + x * (data->bit_per_pixel / 8));
    *(unsigned int *)dst = color;
}

int ft_colors(int larg, int lo)
{
    int colors;

    colors = 0;
    if(larg % 3 == 0 && lo % 2 == 0)
        colors = 0x00FF33CC;
    else if(larg % 3  != 0 && 2 != 0)
        colors = 0x0033CCFF;
    return(colors);
}

char *ft_error_return(int error)
{
    if (error == 1)
        return("Aucune map passée en paramètre");
    if (error == 2)
        return("Map introuvable");
    return (NULL);
}

int ft_init_map(void *mlx, void *new_w, t_data *img)
{
    mlx = mlx_init();
    new_w = mlx_new_window(mlx, 1920, 1080, "hello");
    (*img).img = mlx_new_image(mlx, 1920, 1080);
    (*img).addr = mlx_get_data_addr((*img).img, &(*img).bit_per_pixel, &(*img).line_length, &(*img).endian);

    int lo = 0;
    while (lo < 1080)
    {
        int larg = 0;
        while (larg  < 1920)
        {
            ft_put_px(img, larg, lo, ft_colors(larg, lo));
            larg++;
        }
        lo++;
    }
    
    mlx_put_image_to_window(mlx, new_w, (*img).img, 0, 0);
    return(1);
}

// int ft_check_params(ch)
// {
    
// }


int	main(int argc, char *argv[])
{
    //void	*mlx = NULL;
    //void    *new_w = NULL;
    //t_data  img;

    if(argc != 2)
    {
        perror(ft_error_return(1));
        return (1);
    }
    else
    {
        int fd = open(argv[1],O_RDONLY);
        if (fd == -1)
        {
            perror(ft_error_return(2));
            return (1);
        }
    }
        printf("voici ladresse de la map %s\n", argv[1]);
    //ft_init_map(mlx, new_w, &img);
    //mlx_loop(mlx);

    return(0);
}


//valgrind --leak-check=yes myprog arg1 arg2