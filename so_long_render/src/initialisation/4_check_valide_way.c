/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_check_valide_way.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:18:35 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/08 01:39:26 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/initialisation.h"

void ft_put_pixel(t_img *data, int x, int y, int color)
{
    char *pxl;
    
    if (x >= 0 && x < 128 && y >= 0 && y < 128)
    {
        pxl = data->addr + (y * data->line_length + x * (data->bit_per_pixel / 8));
        *(unsigned int *)pxl = color;
    }
}

void	fill_arr2(int target, t_data *data, int col, int row)
{
	int		h;
	int		w;
	char	**tab;

	tab = data->map;
	h = data->xy_data.map.row;
	w = data->xy_data.map.col;

	printf("target %c\n",target);
	if (col < 1 || col > w ||  row > h || row < 1 )
	{

		return;
	}
	if (tab[row][col] == 'C')
		data->check_item++;
	if (tab[row][col] == target)
		return;
	else if (tab[row][col] == '0'|| tab[row][col] == 'E' || tab[row][col] == '1')
		tab[row][col] = ' ';
	fill_arr2(target, data, col, row - 1);
	fill_arr2(target, data, col, row + 1);
	fill_arr2(target, data, col - 1, row);
	fill_arr2(target, data, col + 1, row);
	print_map(data);
}

int	check_valide_way(t_data *data)
{
	char		**tab;
	int			target;
	t_xy		begin;

	print_dimention(data->xy_data,'b');
	if (!data)
		return(1);
	tab = data->map;
	begin = data->xy_data.begin;
	target = tab[begin.row][begin.col];
	fill_arr2(target, data, begin.col, begin.row);
	//print_map(data);
	if (data->check_item != data->count_item)
		return(1);
	return(0);
}
int main(void)
{
	void *mlx;
	t_img *img;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx,1280,1220,"hello");
	//check_valide_way(data);


	// bien penser a liberer cette memoire.
	img = malloc(sizeof(t_img));
	if(!img)
		return(1);
	img->img = mlx_xpm_file_to_image(mlx, "/home/cb/Documents/42K/so_long_render/items/trames/monster_trame.xpm", &img->width, &img->height);
	if(!img->img)
		return(1);
	printf("voici la taille de l'image : col %d et row %d\n", img->width, img->height);
	t_img *new_img;
	new_img = mlx_new_image(mlx,128,128);
	if(!new_img)
		return(1);
	char *addr1 = mlx_get_data_addr(new_img,&new_img->bit_per_pixel, &new_img->line_length, &new_img->endian);
	char *addr2 = mlx_get_data_addr(img->img,&img->bit_per_pixel, &img->line_length, &img->endian);
	if(!addr1 || !addr2)
		return(1);
	//mlx_loop(mlx);
	mlx_destroy_image(mlx,img->img);
	mlx_destroy_image(mlx,new_img);
	mlx_destroy_window(mlx,win);
	mlx_destroy_display(mlx);
	free(img);
	free(mlx);
	return(0);
}