/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:59:18 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/02 22:37:21 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_update_mouvement(t_data *data, t_game_data *g, t_dimention *begin)
{
	g->count_mouvement++;
	if (g->map[begin->row][begin->col] == 'X')
	{
		g->count_item--;
		printf("voici le nbr d'item restant %d\n", g->count_item);
		if (g->count_item == 0)
		{
			g->map[g->exit_position.row][g->exit_position.col] = 'E';
			printf("You can use the exit\n");
		}
		g->map[begin->row][begin->col] = 'P';
	}
	else
	{
		if (g->map[begin->row][begin->col] == 'E')
			if(g->count_item == 0)
				exit_game(data);
		g->map[begin->row][begin->col] = 'P';
		printf("Update position : y: %d, x: %d\n", begin->row, begin->col);
		printf("Nombre de mouvement %d\n", g->count_mouvement);
	}
}

void	ft_update_position(t_data *d, t_game_data *g, int key, t_dimention *b)
{
	int	init_col;
	int	init_row;

	init_col = b->col;
	init_row = b->row;
	if (key == 100 || key == 65362)
		if (g->map[b->row - 1][g->begin.col] != '1')
			b->row -= 1;
	if (key == 100 || key == 65363)
		if (g->map[b->row][b->col + 1] != '1')
			b->col += 1;
	if (key == 115 || key == 65364)
		if (g->map[b->row + 1][b->col] != '1')
			b->row += 1;
	if (key == 119 || key == 65361)
		if (g->map[b->row][b->col - 1] != '1')
			b->col -= 1;
	if (init_col != b->col || init_row != b->row)
	{
		g->map[init_row][init_col] = ' ';
		ft_update_mouvement(d, g, b);
	}
	else
		printf("Le personage ne bouge pas:\ny: %d, x: %d\n", b->row, b->col);
	ft_print_map(g);
}

void	ft_keycode_counter_handler(t_data *data, int keycode)
{
	t_dimention	*begin;

	begin = &data->game_data->begin;
	printf("voici le keycode %d\n", keycode);
	if (keycode == 97 || keycode == 100)
		ft_update_position(data, data->game_data, keycode, begin);
	if (keycode == 115 || keycode == 119)
		ft_update_position(data, data->game_data, keycode, begin);
	if (keycode == 65361 || keycode == 65362)
		ft_update_position(data, data->game_data, keycode, begin);
	if (keycode == 65363 || keycode == 65364)
		ft_update_position(data, data->game_data, keycode, begin);
}

int	ft_manage_keyboard(int keycode, t_data *data)
{
	ft_keycode_counter_handler(data, keycode);
	if(data->img->img)
		
	char_layer(data);
	if (keycode == 65307 || keycode == 64)
		exit_game(data);
	return (0);
}
void	exit_game2(t_data **d)
{

	t_data *data = *d;
	printf("clean memory...\n");
	//mlx_destroy_image(data->mlx, data->img->img);
	//mlx_destroy_window(data->mlx, data->window);
	//mlx_destroy_display(data->mlx);
	//ft_free_memory(data);
	(void)data;
	printf("END GAME\n");
	exit (0);
}

int ft_close_windows(int keycode, t_data *data)
{
    printf("voici le keycode %d\n", keycode);
	(void)data;
	
	exit_game2(&data);
    return(0);
}