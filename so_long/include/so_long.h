/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:40:51 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/14 00:27:49 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/mlx_linux/mlx.h"
# include "image_loader.h"
# include "image_layer.h"
# include "error_managment.h"
# include "memory_managment.h"
# include "hook_managment.h"
# include "initialisation.h"
# include "../libft/libft.h"
# include "../src/gnl/get_next_line.h"
# include "../lib/printf/ft_printf.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <X11/keysym.h>

# define M_PI		3.14159265358979323846
# define MAX_FD		1048576
# define TILD_SIZE 	128
# define SET_SIZE	7
# define LEFT		1
# define RIGHT		2
# define FRONT		3
# define FACE		4

typedef struct s_border
{
	t_point	size;
	t_point	targ;

	int		border_size; //epaisseur
	int		b_color;	// border color;
	int		r_color;	// remplissage color;
}	t_border;

typedef struct s_xy
{
	int	row;
	int	col;

}	t_xy;

typedef struct s_xy_data
{
	t_xy			map;
	t_xy			begin;
	t_xy			exit;
	t_xy			screen_size;

}	t_xy_data;

typedef struct s_img
{
	char	*class;
	int		set;
	int		frame_size;
	void	*img;
	char	*addr;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;

}	t_img;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	char		*map_name;
	char		**map;
	int			char_state;
	int			count_item;
	int			check_item;
	int			count_begin;
	int			count_exit;
	int			count_mouvement;
	int			state_game;
	t_xy_data	xy_data;
	t_img		**img_set_global;

}	t_data;

t_data	*initialisation_and_check(char *path);
void	print_map(t_data *data);

void	ft_display_data_info(t_data *data);
void	display_image_data(t_img *im);
void	print_map(t_data *data);
void	print_path(char **path_g);

void	print_dimention(t_xy_data xy_arr, int c);
t_xy	ft_s_dimention(void);
t_xy	rescal(t_xy xy, int scal_factor);
int		get_area(t_xy xy);

#endif
