/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:51:28 by cb                #+#    #+#             */
/*   Updated: 2025/01/09 06:29:43 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int error_layer_test(void)
{
    int i = -1;
    int count;

    while (i < ERR_SCOPE + 10)
       count =  error_layer(i++);
    return(count); 
}
int main(void)
{
    t_data *data;

    data = malloc(sizeof(t_data));

    assert(data != NULL);
	data->mlx    = mlx_init();
    assert(data->mlx != NULL);
	
    char		**path_g;
	char		**path_l;
	char		**path_r;

    path_g = get_paths(1);
	path_l = get_paths(2);
	path_r = get_paths(3);

    assert(path_g !=NULL);
    assert(path_l !=NULL);
    assert(path_r !=NULL);
    data->img_sets = malloc(sizeof(t_img_sets));
	if(!data->img_sets)
		return(error_layer(ERR_GET_IMGPATH));
    int i = image_loader(data, path_g, path_l, path_r);
    printf("image i %d\n", i);
    assert(i == 0);
    
    return (0);
}
