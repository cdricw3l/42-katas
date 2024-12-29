/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:43:22 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/29 10:41:54 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_dimention ft_dim(void)
{
	t_dimention dimention;

	dimention.col = 0;
	dimention.row = 0;

	return(dimention);
}

t_img *ft_init_image(void)
{
	t_img image;

	t_img *im = &image;
	
	image.img = NULL;
	image.addr = NULL;
	image.bit_per_pixel = 0;
	image.line_length = 0;
	image.endian = 0;

	return(im);
}

t_game_data	*ft_init_game_data(void)
{
	t_game_data game_data;
	t_game_data *g_data;


	game_data.map_name = NULL;
	game_data.map = NULL;
	game_data.count_item = 0;
	game_data.count_mouvement = 0;
	game_data.dimention = ft_dim();
	game_data.begin = ft_dim();
	game_data.exit_position = ft_dim();
	g_data = &game_data;
	return (g_data);
}

int	ft_init_data(t_data *data)
{
	t_check_list check_list;

	if (!data)
		return(1);
	data->mlx = NULL;
	data->window = NULL;
	data->img = ft_init_image();
	if(!data->img)
		return(1);
	ft_bzero(&check_list,sizeof(int) * CHECK_LIST_SIZE);
	data->check_list = &check_list;
	data->game_data = ft_init_game_data();
	if(!data->game_data)
	 	return(1);
	return (0);
}

t_data	*ft_init(void)
{	
	t_data data;
	t_data *d;
	int init;
	
	init = ft_init_data(NULL);
	if (init == 1)
	{
		printf("erreur d'initalisation de la structure\n");
		return(NULL);
	}
	else
	{
		d = &data;
		printf("structure initialiser avec succes, adresse : %p \n", d);
	}
	return (d);
}




int main(void)
{
	t_data *data;

	data = ft_init();
	printf("voici l'adresse de la struc %p\n", data);
	return(0);
}