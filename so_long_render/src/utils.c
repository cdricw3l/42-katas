/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:55:17 by cb                #+#    #+#             */
/*   Updated: 2025/01/08 02:15:25 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    print_dimention(t_xy_data xy_arr, char c)
{
    t_xy    xy;
    
    if(c == 'b')
        xy = xy_arr.begin;
    else if(c == 'e')
        xy = xy_arr.exit;
    else if(c == 'm')
        xy = xy_arr.map;
    else if(c == 's')
        xy = xy_arr.screen_size;
    printf("[ data ] coordonees de la structure: col: %d row: %d\n",
            xy.col, xy.row);

}

t_xy	rescal(t_xy xy, int scal_factor)
{
	t_xy new_xy;

	new_xy.col = xy.col * scal_factor;
	new_xy.row = xy.row * scal_factor;
	
	return(new_xy);
}

int	get_area(t_xy xy)
{
	return (xy.col * xy.row);
}

void    ft_display_data_info(t_data *data)
{

    printf("\n//////////////////////////////////////////\nContenu de la structure data: 🤙🤙🤙\n\n");
    printf("Nom de la map: %s \n\n", data->map_name);
    printf("Dimention de la map: \n");
    printf("Hauteur: %d \nlargeur: %d\n\n", data->xy_data.map.row, data->xy_data.map.col);
    printf("Position de depart du personnage\n");
    printf("Hauteur: %d \nlargeur: %d\n\n", data->xy_data.begin.row, data->xy_data.begin.col);
    printf("Nombre d'item: \n");
    printf("Nombre d'item sur la map: %d\n\n", data->count_item);
    printf("Check list value: \n");
    //printf("Valeur attendu: 5. Valeur effective : %d \n", ft_check_params(data));
    printf("Affichage de la map: \n\n");
    print_map(data);
    printf("\n//////////////////////////////////////////\n\n");

}

t_xy	ft_s_dimention(void)
{
	t_xy	dimention;

	dimention.col = 0;
	dimention.row = 0;
	return (dimention);
}

void	ft_put_border(t_data *data, t_border b)
{
	int	i;
	int	j;

	i = 0;
	while (i <= b.size.col)
	{
		j = 0;
		while (j <= b.size.row)
		{
			if (i <= b.border_size
				|| (i >= b.size.col - b.border_size && i <= b.size.col))
				mlx_pixel_put(data->mlx, data->window,
				j + b.targ.col-b.size.col / 2, i + b.targ.row - b.size.row /2, b.b_color);
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