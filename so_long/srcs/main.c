/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:43:22 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/02 22:41:08 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*ft_error_img(int e)
{
	if(e == 1)
		printf("Erreur creation structure image\n");
	if(e == 2)
		printf("probleme recuperation de l'imaged (path)\n");
	if(e == 3)
		printf("probleme recuperation data addr\n");
	if(e == 4)
		printf("probleme initialisation arr path\n");
	if(e == 5)
		printf(" voir error 1 2 ou 3\n");
	return(NULL);
}
	

t_img *ft_new_image(t_data *data,char *str)
{
	t_img *image;

	image = malloc (sizeof(t_img) *  1);
	if(!image)
		return(ft_error_img(1));
	image->img = mlx_xpm_file_to_image(data->mlx,str, &image->width, &image->height);
	if(!image->img)
		return(ft_error_img(2));
	image->addr = (int *)mlx_get_data_addr(image->img,&image->bit_per_pixel,&image->line_length, &image->endian);
	if(!image->addr)
		return(ft_error_img(3));
	return(image);
}
char	**ft_charct_arr()
{
	char **img_arr;
	
	img_arr = malloc(sizeof(char *) * 7);
	if (!img_arr)
		return(NULL);
	img_arr[0] ="items/char/es2.xpm";
	img_arr[1] ="items/char/es3.xpm";
	img_arr[2] ="items/char/es4.xpm";
	img_arr[3] ="items/char/es5.xpm";
	img_arr[4] ="items/char/es6.xpm";
	img_arr[5] ="items/char/es7.xpm";
	img_arr[6] ="items/char/es8.xpm";
	
	return(img_arr);
}

void *char_layer(t_data *data)
{
    t_img *new_image;
	char **img_path;
	int i;
	
	i = 0;
	img_path = ft_charct_arr();
	new_image = NULL;
	if(!img_path)
		return(ft_error_img(4));
	while (i < 7)
	{
		
		new_image = ft_new_image(data, img_path[i]);
		if(new_image)
		{
			printf("voici la destination %d et % d \n",data->game_data->begin.row,data->game_data->begin.col);
			mlx_put_image_to_window(data->mlx,data->window,new_image->img,data->game_data->begin.col * TILD_SIZE,data->game_data->begin.row * TILD_SIZE);
			mlx_destroy_image(data->mlx,new_image->img);
			

		}
		else
			return(ft_error_img(5));
		i++;
	}
	data->img->img = new_image;
    return(data);
}

void    start_game(t_data **data)
{

	(*data)->mlx = mlx_init();
	mlx_get_screen_size((*data)->mlx, &(*data)->screen_size.col, &(*data)->screen_size.row);
    printf("Dimention de l'ecran : x_screen: %d et y_screen: %d\n",(*data)->screen_size.col,(*data)->screen_size.row);
    (*data)->window = mlx_new_window((*data)->mlx, TILD_SIZE * (*data)->game_data->dimention.col, TILD_SIZE * (*data)->game_data->dimention.row, "hello");
    if(!(*data)->window || !(*data)->mlx)
    {
        perror(ft_error_return(4));
        return ;
    }
	if(char_layer(*data) == NULL)
		return ;
    mlx_hook((*data)->window, 2, 1L<<0 ,ft_manage_keyboard, (*data));
    printf("adresse 1: %p et adresse 2: %p\n", (*data)->mlx, (*data)->window);
   	mlx_hook((*data)->window, 17, 1L<<0 ,ft_close_windows, (*data));
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
