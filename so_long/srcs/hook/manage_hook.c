/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:59:18 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/19 17:07:52 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int ft_manage_keyboard(int keycode, t_data *data)
{
    printf("voici le keycode %d\n", keycode);
    printf("pointeur mlx : %p, pointeur windows %p\n",data->mlx, data->window);
    if( keycode == 65307)
    {
        mlx_destroy_window(data->mlx, data->window);
        exit (0);    
    }
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