/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:59:18 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/22 10:37:16 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void    exit_game(t_data *data)
{
    mlx_destroy_window(data->mlx, data->window);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    exit (0);
}

void end_game(t_data *data)
{
    printf("Tu as fini le jeu\n");
    printf("Tape 1 pour recommencer\n");
    printf("Tape 2 pour charger une nouvelle map\n");
    printf("Tape 3 pour quitter le jeu\n");

    char *str = get_next_line(0);
    printf("voici l'entre utilisateur %s\n", str);
    free(str);
    (void)data;
}

void    update_charactere_position(t_data *data, int keycode, int init_row, int init_col)
{
        
    if(keycode == 97)
        if (data->game_data.map[data->game_data.begin.row - 1][data->game_data.begin.col] != '1')
            data->game_data.begin.row -= 1;
    if(keycode == 100)
        if (data->game_data.map[data->game_data.begin.row][data->game_data.begin.col + 1] != '1')
            data->game_data.begin.col += 1;
    if(keycode == 115)
        if (data->game_data.map[data->game_data.begin.row + 1][data->game_data.begin.col] != '1')
            data->game_data.begin.row += 1;
    if(keycode == 119)
        if (data->game_data.map[data->game_data.begin.row][data->game_data.begin.col - 1] != '1')
            data->game_data.begin.col -= 1;
    if(init_col != data->game_data.begin.col || init_row != data->game_data.begin.row)
    {
        data->game_data.count_mouvement++;
        if(data->game_data.map[data->game_data.begin.row][data->game_data.begin.col] == 'X')
        {
            data->game_data.count_item--;
            if (data->game_data.count_item == 0)
            {
                printf("You can use the exit\n");
                data->game_data.map[data->game_data.exit_position.row][data->game_data.exit_position.col] = 'E';
            }
        }
        else if (data->game_data.map[data->game_data.begin.row][data->game_data.begin.col] == 'E')
        {
            printf("end game \n");
            end_game(data);
        }
        data->game_data.map[data->game_data.begin.row][data->game_data.begin.col] = 'P';
        data->game_data.map[init_row][init_col] = ' ';
        printf("mise a jour de la position du personnage huateur %d , largeur : %d\n",data->game_data.begin.row, data->game_data.begin.col);
        printf("Nombre de mouvement %d\n",data->game_data.count_mouvement);
        ft_print_map(data->game_data.map,data->game_data.dimention.row,data->game_data.dimention.col,4);
    }
    else
    {
        printf("Le personage ne bouge pas, sa position reste hauteur %d, largeur %d\n", data->game_data.begin.row,data->game_data.begin.col);
        ft_print_map(data->game_data.map,data->game_data.dimention.row,data->game_data.dimention.col,4);
    }
}

void ft_keycode_counter_handler(t_data *data,int keycode)
{

    printf("voici le keycode %d\n",keycode);
    if(keycode == 97 || keycode == 100)
        update_charactere_position(data, keycode,data->game_data.begin.row, data->game_data.begin.col);
    if(keycode == 115 || keycode == 119)
        update_charactere_position(data, keycode, data->game_data.begin.row, data->game_data.begin.col); 
}

int ft_manage_keyboard(int keycode, t_data *data)
{
    ft_keycode_counter_handler(data, keycode);
    if( keycode == 65307)
       exit_game(data);
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