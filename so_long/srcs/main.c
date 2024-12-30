/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:43:22 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/30 23:39:51 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int ft_put_img(void **mlx, void **new_w, t_img *img)
{
    int hauteur;
    int largeur;
	int i;
	int j;
    
    hauteur = 0;
	largeur = 0;
	i = 0;
	img->img  = mlx_xpm_file_to_image(*mlx, "items/door.xpm",&hauteur,&largeur);
    while (i < 1080)
    {
		j = 0;
        while (j  < 1920)
        {
    		mlx_put_image_to_window(*mlx, *new_w, img->img, j, i);
            j += largeur;
        }
        i += hauteur;
    }
    return(1);
}

void    start_game(t_data **data)
{

	(*data)->mlx = mlx_init();
    (*data)->window = mlx_new_window((*data)->mlx, 1920, 1080, "hello");
    if(!(*data)->window || !(*data)->mlx)
    {
        perror(ft_error_return(4));
        return ;
    }
    ft_put_img(&(*data)->mlx, &(*data)->window, (*data)->img);
    mlx_key_hook((*data)->window, ft_manage_keyboard, (*data));
    printf("adresse 1: %p et adresse 2: %p\n", (*data)->mlx, (*data)->window);
    mlx_hook((*data)->window, 17, 0 ,ft_close_windows, (*data));
    mlx_loop((*data)->mlx) ;
}

int	main(int argc, char *argv[])
{
	t_data		*data;

	if (argc != 2)
	{
		perror(ft_error_return(1));
		return (1);
	}
	else
	{
		data = init_and_check(argv[1]);
		if (data)
		{
			ft_display_data_info(data);
			start_game(&data);
			ft_free_memory(data);
		}
		else
		{
			perror(ft_error_return(3));
			return (1);
		}
	}
	return (0);
}
