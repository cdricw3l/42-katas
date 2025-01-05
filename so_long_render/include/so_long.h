/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:40:51 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/05 16:18:35 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
#define SO_LONG_H

# include "../lib/mlx_linux/mlx.h"
# include "image_loader.h"
# include "error_managment.h"
//# include "../mlx_linux/mlx_int.h"
# include "../libft/libft.h"
# include "../src/gnl/get_next_line.h"
# include "../lib/printf/ft_printf.h"


# include <assert.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>


#define MLX_SYNC_IMAGE_WRITABLE		1
#define MLX_SYNC_WIN_FLUSH_CMD		2
#define MLX_SYNC_WIN_CMD_COMPLETED	3
#define CHECK_LIST_SIZE 			7
#define MAX_FD 						1048576
#define TILD_SIZE 					128
# define M_PI						3.14159265358979323846

#define LEFT 1
#define RIGHT 2
#define FRONT 3
#define	FACE  4

#define	IMG_SET	31

typedef struct s_xy
{
	int row;
	int col;

} t_xy;

typedef struct s_xy_data
{
	t_xy			map;
	t_xy			begin;
	t_xy			exit;
	t_xy			screen_size;

} t_xy_data;



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
	t_img				**img_set;
	
} t_data ;

typedef struct s_border
{
	t_point	size;
	t_point	targ;
	
	int		border_size; //epaisseur
	int		b_color;	// border color;
	int		r_color;	// remplissage color;
	
} t_border;


t_data	*initialisation_and_check(char *path);
t_data	*data_initialisation(char *map_path);

void	*ft_free_memory(t_data *data, int err);
void	ft_process_set(t_data *data,char c, int row, int col);
void	ft_analsyse_line(char *str);
void    ft_print_map(t_data *data);
void	end_game_menu(t_data *data);
void	exit_game(t_data *data);
void    ft_display_data_info(t_data *data);
char    *ft_error_return(int error);
int		ft_arr_len(char **arr);
int		ft_is_square(t_data *data);
int		ft_check_param(t_data *data, char *path);
int		ft_is_close(char **map, int hauteur, int largeur);
int		ft_check_dimentions(t_data *data);
int		ft_check_valide_way(t_data *g_data);
int		ft_close_windows(int keycode, t_data *data);
int		ft_manage_keyboard(int keycode, t_data *data);
int		ft_colors(int larg, int lo);
int		ft_put_img(t_data *data);
void 	*char_layer(t_data *data, int keycode);

#endif
