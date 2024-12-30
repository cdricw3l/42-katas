/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:59:18 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/30 23:42:45 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void    exit_game(t_data *data)
{
    mlx_destroy_image(data->mlx, data->img->img);
    mlx_destroy_window(data->mlx, data->window);
    mlx_destroy_display(data->mlx);
    ft_free_memory(data);
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

void    update_charactere_position(t_data *data,t_game_data *game_data, int keycode, t_dimention *begin)
{
    int init_col;
    int init_row;

    init_col = begin->col;
    init_row = begin->row;
    printf("voici init col %d et init row %d et keycode %d\n",init_col, init_row,keycode);
    if(keycode == 97)
        if (game_data->map[begin->row - 1][game_data->begin.col] != '1')
            begin->row -= 1;
    if(keycode == 100)
        if (game_data->map[begin->row][begin->col + 1] != '1')
            begin->col += 1;
    if(keycode == 115)
        if (game_data->map[begin->row + 1][begin->col] != '1')
            begin->row += 1;
    if(keycode == 119)
        if (game_data->map[begin->row][begin->col - 1] != '1')
            begin->col -= 1;
    if(init_col != begin->col || init_row != begin->row)
    {
        game_data->count_mouvement++;
        if(game_data->map[begin->row][begin->col] == 'X')
        {
            game_data->count_item--;
            printf("voici le nbr d'item restant %d\n",game_data->count_item);
            if (game_data->count_item == 0)
            {
                game_data->map[game_data->exit_position.row][game_data->exit_position.col] = 'E';
                printf("You can use the exit\n");
            }
        }
        else if (game_data->map[begin->row][begin->col] == 'E')
        {
            printf("end game \n");
            exit_game(data);
        }
        game_data->map[begin->row][begin->col] = 'P';
        game_data->map[init_row][init_col] = ' ';
        printf("mise a jour de la position du personnage huateur %d , largeur : %d\n",begin->row, begin->col);
        printf("Nombre de mouvement %d\n",game_data->count_mouvement);
        ft_print_map(data->game_data);
    }
    else
    {
        printf("Le personage ne bouge pas, sa position reste hauteur %d, largeur %d\n", begin->row, begin->col);
        ft_print_map(data->game_data);
    }
}

void ft_keycode_counter_handler(t_data *data,int keycode)
{
    t_dimention *begin;

    begin = &data->game_data->begin;
    printf("voici le keycode %d\n",keycode);
    if(keycode == 97 || keycode == 100)
        update_charactere_position(data,data->game_data, keycode, begin);
    if(keycode == 115 || keycode == 119)
        update_charactere_position(data, data->game_data, keycode ,begin); 
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