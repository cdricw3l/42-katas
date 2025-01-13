/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:40:51 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/10 14:01:12 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
#define SO_LONG_H

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
#include <assert.h>



#define MLX_SYNC_IMAGE_WRITABLE		1
#define MLX_SYNC_WIN_FLUSH_CMD		2
#define MLX_SYNC_WIN_CMD_COMPLETED	3
#define CHECK_LIST_SIZE 			7
#define MAX_FD 						1048576
#define TILD_SIZE 					128
# define M_PI						3.14159265358979323846

#define LEFT 	1
#define RIGHT	2
#define FRONT	3
#define	FACE 	4

#define	IMG_SET_SIZE 3
#define	SET_SIZE 14

typedef struct s_xy
{
	int row;
	int col;

} t_xy;

typedef struct s_img_sets
{
	t_img				**img_set_global;
	t_img				**img_set_left;
	t_img				**img_set_right;
	
} t_img_sets;


typedef struct s_xy_data
{
	t_xy			map;
	t_xy			begin;
	t_xy			exit;
	t_xy			screen_size;

} t_xy_data;

typedef struct s_img
{
	char 				*class;
	int					set;
	int 				frame_size;
	void				*img;
	char				*addr;
	int					bit_per_pixel;
	int					line_length;
	int					endian;
	int					width;
	int					height;
	
} t_img ;

typedef struct s_data
{
	void				*mlx;
	void				*window;
	char				*map_name;
	char				**map;
	int					char_state;
	int					count_item;
	int					check_item;
	int					count_begin;
	int					count_exit;
	int					count_mouvement;
	t_xy_data			xy_data;
	t_img_sets			*img_sets;
	int					img_set_size;
	
} t_data ;

typedef struct s_border
{
	t_point	size;
	t_point	targ;
	
	int		border_size; //epaisseur
	int		b_color;	// border color;
	int		r_color;	// remplissage color;
	
} t_border;


t_data	*data_initialisation(char *map_path);
void    print_map(t_data *data);
void	exit_game(t_data *data);

int		get_area(t_xy xy);
t_xy	rescal(t_xy xy, int scal_factor);
void    print_dimention(t_xy_data xy_arr, char c);
void    ft_display_data_info(t_data *data);
t_xy	ft_s_dimention(void);
void    print_dimention(t_xy_data xy_arr, char c);
void	ft_put_border(t_data *data, t_border b);
void	print_map(t_data *data);
void 	print_path(char **path_g, char **path_l, char **path_r);
void	ft_slice_img(t_img *img);
// void	ft_process_set(t_data *data,char c, int row, int col);
// void    ft_print_map(t_data *data);
// void	end_game_menu(t_data *data);
// void	exit_game(t_data *data);
// void    ft_display_data_info(t_data *data);
// char    *ft_error_return(int error);
// int		ft_arr_len(char **arr);
// int		ft_is_square(t_data *data);
// int		ft_check_param(t_data *data, char *path);
// int		ft_is_close(char **map, int hauteur, int largeur);
// int		ft_check_dimentions(t_data *data);
// int		ft_check_valide_way(t_data *g_data);
// int		ft_close_windows(int keycode, t_data *data);
// int		ft_manage_keyboard(int keycode, t_data *data);
// int		ft_colors(int larg, int lo);
// int		ft_put_img(t_data *data);
// void 	*char_layer(t_data *data, int keycode);

#endif
