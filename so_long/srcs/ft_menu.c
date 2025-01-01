/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:43:22 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/01 17:27:19 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
	A * sin(B * t + C ) + D
	
	A = amplitude;
	B = frequence;
	C = decalage de phase;
	D = decalage verticale;

	t= temp;

	B * t + C exprime un angle du cercle trigonometrique;
*/ 

void    ft_put_axe(int screen_x, int screen_y, t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i <= (screen_y / 2))
	{
		j = 0;
		while (j < screen_x / 2)
		{
			if (i == (screen_y / 2)/ 2 || j == (screen_x / 2)/ 2 )
				mlx_pixel_put(data->mlx, data->window, j, i, ft_colors(i, j));
			j++;
		}
		i++;
	}
	
}

void ft_put_grade(int screen_x, int screen_y, t_data *data)
{
	int i;
	int j;
	int px;
	int fq;

	px = 10;
	fq = 15;
	i = ((screen_y / 2)/2) - px;
	while (i <= ((screen_y / 2)/2) + px)
	{
		printf("voici %d et i %d\n", (screen_y / 2) + px, i);
		j = 0;
		while (j < screen_x / 2)
		{
			if (i >= ((screen_y / 2)/2) - px || i <= ((screen_y / 2)/2) + px)
				mlx_pixel_put(data->mlx, data->window, j, i, ft_colors(i, j));
			j+=fq;
		}
		i++;
	}
}

void    ft_put_border(t_data *data, t_border b)
{
	int i;
	int j;

	i = 0;
	while (i <= b.size.col)   
	{
		j = 0;
		while (j <= b.size.row)
		{
			if(i <= b.border_size || (i >= b.size.col - b.border_size && i <= b.size.col))
				mlx_pixel_put(data->mlx, data->window,
				j + b.targ.col - b.size.col/ 2, i + b.targ.row - b.size.row/2, b.b_color);
			else
				if(j<= b.border_size || (j >= b.size.col - b.border_size && j<= b.size.col))
					mlx_pixel_put(data->mlx, data->window,
					j + b.targ.col - b.size.col/ 2, i + b.targ.row - b.size.row/2, b.b_color);
			else
				if (b.r_color)
					mlx_pixel_put(data->mlx, data->window, 
					j + b.targ.col - b.size.col/ 2, i + b.targ.row - b.size.row/2, b.r_color);
			j++;
		}
		i++;
	}
}

void    ft_put_rectangle(t_data *data, int y_size, int x_size, int y_cible, int x_cible)
{
	int i;
	int j;

	i = 0;
	while (i <= y_size)   
	{
		j = 0;
		while (j <= x_size)
		{
			mlx_pixel_put(data->mlx, data->window,
			j + x_cible - x_size/ 2, i + y_cible - y_size/2, ft_colors(i, j));
			j++;
		}
		i++;
	}
}
// void ft_put_sin(int screen_x, int screen_y, t_data *data)
// {
//      double A  = 1;
//     double B  = 500;
//     double C  = 0;
//     double D  = 0;
//     double t = 0;
//     double p;

//     while (t  <= 1)
//     {
//         p = A * sin(B * t + C) + D;
//         printf("x: %2f y: %2f\n", t, p);
//         t += 0.01;
//     }
// }
int main(void)
{
   
	t_data *data;
	int screen_x;
	int screen_y;
	
	screen_x = 0;
	screen_y = 0;
	data = init_and_check("map/map2.ber");
	data->mlx = mlx_init();
	if(!data->mlx)
		return(1);
	mlx_get_screen_size(data->mlx, &screen_x, &screen_y);
	data->window = mlx_new_window(data->mlx, screen_x / 2, screen_y / 2, "hello");
	if(!data->window)
		return(1);
	printf("voici x :%d et y: %d\n", (screen_x / 2),(screen_y / 2));
	ft_put_axe(screen_x,screen_y,data);
	//ft_put_grade(screen_x,screen_y,data);
	t_border border;
	t_point bord = {300,300};
	t_point cible = {1080/2 ,1920/2};

	border.size = bord;
	border.targ = cible;
	border.b_color = 0x0000ff;
	border.r_color = 0;
	border.border_size = 5;
	//ft_put_rectangle(data, 300, 300, 1080/2, 1920/2);
	ft_put_border(data, border);
	
	mlx_hook(data->window, 2, 1L<<0 ,ft_manage_keyboard, data);
	mlx_loop(data->mlx);


	
	
	return(0);
}