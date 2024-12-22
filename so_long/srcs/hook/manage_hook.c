/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:59:18 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/22 08:23:53 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"



void    update_charactere_position(t_data *data, int keycode, int init_row, int init_col)
{
        
    if(keycode == 97)
        if (data->map[data->begin.row - 1][data->begin.col] != '1')
            data->begin.row -= 1;
    if(keycode == 100)
        if (data->map[data->begin.row][data->begin.col + 1] != '1')
            data->begin.col += 1;
    if(keycode == 115)
        if (data->map[data->begin.row + 1][data->begin.col] != '1')
            data->begin.row += 1;
    if(keycode == 119)
        if (data->map[data->begin.row][data->begin.col - 1] != '1')
            data->begin.col -= 1;
    if(init_col != data->begin.col || init_row != data->begin.row)
    {
        data->count_mouvement++;
        if(data->map[data->begin.row][data->begin.col] == 'X')
        {
            data->count_item--;
            if (data->count_item == 0)
            {
                printf("end game \n");
                exit(0);
            }
        }
        data->map[data->begin.row][data->begin.col] = 'P';
        data->map[init_row][init_col] = ' ';
        printf("mise a jour de la position du personnage huateur %d , largeur : %d\n",data->begin.row, data->begin.col);
        printf("Nombre de mouvement %d\n",data->count_mouvement);
        ft_print_map(data->map,data->dimention.row,data->dimention.col,4);
    }
    else
    {
        printf("Le personage ne bouge pas, sa position reste hauteur %d, largeur %d\n", data->begin.row,data->begin.col);
        ft_print_map(data->map,data->dimention.row,data->dimention.col,4);
    }
}

void ft_keycode_counter_handler(t_data *data,int keycode)
{

    printf("voici le keycode %d\n",keycode);
    if(keycode == 97 || keycode == 100)
        update_charactere_position(data, keycode,data->begin.row, data->begin.col);
    if(keycode == 115 || keycode == 119)
        update_charactere_position(data, keycode, data->begin.row, data->begin.col); 
}

int ft_manage_keyboard(int keycode, t_data *data)
{
    ft_keycode_counter_handler(data, keycode);
    if( keycode == 65307)
    {
    
        mlx_destroy_window(data->mlx, data->window);
        mlx_destroy_display(data->mlx);
        free(data->mlx);
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