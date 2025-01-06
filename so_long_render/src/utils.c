/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:55:17 by cb                #+#    #+#             */
/*   Updated: 2025/01/06 22:04:00 by cb               ###   ########.fr       */
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