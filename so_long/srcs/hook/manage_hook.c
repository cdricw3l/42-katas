/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:59:18 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/21 19:32:05 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void    update_charactere_position(t_data *data, int keycode)
{
    if(keycode == 97)
        data->begin.row -= 1;
    if(keycode == 100)
        data->begin.col += 1;
    if(keycode == 115)
        data->begin.row += 1;
    if(keycode == 119)
        data->begin.col -= 1;
    data->count_mouvement++;
    printf("mise a jour de la position du personnage huateur %d , largeur : %d\n",data->begin.row, data->begin.col);
    printf("Nombre de mouvement %d\n",data->count_mouvement);
}

void ft_keycode_counter_handler(t_data *data,int keycode)
{

    printf("voici le keycode %d\n",keycode);
    if(keycode == 97 || keycode == 100)
        update_charactere_position(data, keycode);
    if(keycode == 115 || keycode == 119)
        update_charactere_position(data, keycode); 
}

int ft_manage_keyboard(int keycode, t_data *data)
{
    ft_keycode_counter_handler(data, keycode);
    if( keycode == 65307)
    {
    
        mlx_destroy_window(data->mlx, data->window);
        exit (0);    
    }
    (void)data;
    return(0);
}

int ft_manage_mouse(int keycode, t_data *data)
{
    
    printf("voici le keycode %d\n", keycode);
    printf("pointeur mlx : %p, pointeur windows %p\n",data->mlx, data->window);
    // if(keycode == 1)
    //     mlx_mouse_get_pos(data->mlx, data->window, &x, &y);
    
    return(0);
}
int ft_close_windows(int keycode, t_data **data)
{
    
    printf("voici le keycode %d\n", keycode);
    printf("%p et %p\n",(*data)->mlx,  (*data)->window);
    //mlx_destroy_window((*data)->mlx, (*data)->window);
  
    
    return(0);
}