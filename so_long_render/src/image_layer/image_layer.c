/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_layer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:33:22 by cb                #+#    #+#             */
/*   Updated: 2025/01/06 15:44:49 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/image_layer.h"

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

t_img *get_image_in_set(t_data *data, char c, int state)
{
    t_img *img;

    printf("voici %c\n", data->map[data->xy_data.begin.col][data->xy_data.begin.row]);
    
    if(c == '0')
        return (data->img_set[0]);
    if(c == '1')
        return (data->img_set[1]);
    if(c == 'P')
    {
        printf("state : %d\n",data->char_state);
        printf("state : %d\n",state);
        state == 1;
        if(state == 1)
            return(data->img_set[2]);
        else
            return(data->img_set[3]);
    }
    if(c == 'C')
        return (data->img_set[4]);
    if(c == 'E')
        return (data->img_set[5]);

}

int    run_image_layer(t_data **d)
{
    t_img   frame;
    t_img   *tpm;
    int     *addr;
    t_xy    map_xy;
    char    **map;
    int     i;
    t_data *data = *d;

    map_xy = data->xy_data.map;
    
    map = data->map; 
    frame.img = mlx_new_image(data->mlx, map_xy.col * TILD_SIZE, map_xy.row * TILD_SIZE);
    if(!mlx_new_image)
        return(ERR_FRAME);
    frame.addr = (int *)mlx_get_data_addr(frame.img,&frame.bit_per_pixel,&frame.line_length,&frame.endian);
    if(!frame.addr)
        return(ERR_FRAME);
    i = 0;
    print_dimention(data->xy_data, 'b');
    tpm = get_image_in_set(data, map[data->xy_data.begin.col][data->xy_data.begin.row], data->char_state);
    printf("voici tpm %d\n", tpm->position);
    print_dimention(data->xy_data, 'b');
    mlx_put_image_to_window(data->mlx,data->window,tpm->img,data->xy_data.begin.col * TILD_SIZE,data->xy_data.begin.row *  TILD_SIZE);
    printf("line len %d", tpm->line_length), map[0][0];
    if(!tpm)
        return(ERR_FRAME);
    //addr = (int *)mlx_get_data_addr(tpm ,&tpm->bit_per_pixel,&tpm->line_length,&tpm->endian);
   
    if(!addr)
        return(ERR_FRAME);
    printf("start %d et %d \n", tpm->line_length, tpm->endian);
    
    return(0);

}

