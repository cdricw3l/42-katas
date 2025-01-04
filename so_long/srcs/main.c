/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:43:22 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/04 17:13:59 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <signal.h>

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
char	**ft_charct_arr(int keycode)
{
	char **img_arr;
	
	
	img_arr = malloc(sizeof(char *) * 12);
	if (!img_arr)
		return(NULL);
	(void)keycode;
	img_arr[0] ="items/monster/l_monster/monster_l_1.xpm";
	img_arr[1] ="items/monster/l_monster/monster_l_2.xpm";
	img_arr[2] ="items/monster/l_monster/monster_l_3.xpm";
	img_arr[3] ="items/monster/l_monster/monster_l_4.xpm";
	img_arr[4] ="items/monster/l_monster/monster_l_5.xpm";
	img_arr[5] ="items/monster/l_monster/monster_l_6.xpm";
	img_arr[6] ="items/monster/l_monster/monster_l_7.xpm";
	img_arr[7] ="items/monster/l_monster/monster_l_8.xpm";
	img_arr[8] ="items/monster/r_monster/monster_r_1.xpm";
	img_arr[9] ="items/monster/r_monster/monster_r_2.xpm";
	img_arr[10] ="items/monster/r_monster/monster_r_3.xpm";
	img_arr[11] ="items/monster/r_monster/monster_r_4.xpm";
	img_arr[12] ="items/monster/r_monster/monster_r_5.xpm";
	img_arr[13] ="items/monster/r_monster/monster_r_6.xpm";
	img_arr[14] ="items/monster/r_monster/monster_r_7.xpm";
	img_arr[15] ="items/monster/r_monster/monster_r_8.xpm";
	
	return(img_arr);
}

void *char_layer(t_data *data, int keycode)
{
    t_img *new_image;
	char **img_path;
	int i;
	int j;
	
	i = 0;
	j = 0;
	img_path = ft_charct_arr(keycode);
	new_image = NULL;
	if(!img_path)
		return(ft_error_img(4));
	if(keycode == 65363)
	{
		i = 6;
		j = 12;
	}
	else
	{
		i = 0;
		j = 6;
	}
	while (i < j)
	{
		
		new_image = ft_new_image(data, img_path[i]);
		if(new_image)
		{
			printf("voici la destination %d et % d \n",data->game_data->begin.row,data->game_data->begin.col);
			mlx_put_image_to_window(data->mlx,data->window,new_image->img,data->game_data->begin.col * (TILD_SIZE),data->game_data->begin.row * TILD_SIZE);
			mlx_destroy_image(data->mlx,new_image->img);

		}
		else
			return(ft_error_img(5));
		free(new_image);
		i++;
	}
	data->img->img = new_image;
    return(data);
}

void	_putwall(t_data *data, void *im)
{
	int w;
	int h;
	int i;
	int j;

	w = data->game_data->dimention.col;
	h = data->game_data->dimention.row;
	i = 0;
	while (i < h *TILD_SIZE)
	{
		j = 0;
		while (j < w * TILD_SIZE)
		{
			if (i == 0 || i == (h - 1) * TILD_SIZE)
			{
				mlx_put_image_to_window(data->mlx,data->window,im,j,i);
			}
			else
				if (j == 0 || j == (w - 1) * TILD_SIZE)
					mlx_put_image_to_window(data->mlx,data->window,im,j,i);
			j+= TILD_SIZE;
		}
		i += TILD_SIZE;
	}
}

void	ft_put_wall(t_data *data)
{
	void	*im;
	int 	w;
	int		h;

	im = mlx_xpm_file_to_image(data->mlx, "items/wall.xpm", &w, &h);
	if(!im)
	{
		printf("erreur douverutre de l'item\n");
		return ;
	}
	else
		printf("push image w %d et h %d sur map %d X %d ...\n", w,h,data->game_data->dimention.col,data->game_data->dimention.row);
	_putwall(data, im);
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

	ft_put_wall(*data);
	while (1)
	{
		if(char_layer(*data,0) == NULL)
			return ;
		/* code */
	}
	
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
