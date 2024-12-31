/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:40:51 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/31 01:08:01 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
#define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../printf/ft_printf.h"

# include <stdio.h>
# include <fcntl.h>


#define CHECK_LIST_SIZE 7
#define MAX_FD 1048576

typedef int t_check_list[CHECK_LIST_SIZE];

typedef struct s_dimention
{
	int row;
	int col;

} t_dimention;

typedef struct s_game_data
{
	char				*map_name;
	char				**map;
	int					count_item;
	int					check_item;
	int					count_begin;
	int					count_exit;
	int					count_mouvement;
	t_dimention			dimention;
	t_dimention			begin;
	t_dimention			exit_position;
	
} t_game_data ;

typedef struct s_img
{
	void				*img;
	char				*addr;
	int					bit_per_pixel;
	int					line_length;
	int					endian;
	
} t_img ;

typedef struct s_data
{
	void				*mlx;
	void				*window;
	t_img				*img;
	t_game_data			*game_data;
	
} t_data;

//##define AREA(data) ((data).col - (data).row)
// check map
t_dimention    ft_get_dimentions(int fd, t_data  *img);
t_data	*init_and_check(char *path);
t_data	*ft_init_data_s(void);
void	*ft_free_memory(t_data *data);
void	ft_process_set(t_game_data *data,char c, int row, int col);
void	ft_analsyse_line(char *str);
void    ft_print_map(t_game_data *data);
void	end_game_menu(t_data *data);
void	exit_game(t_data *data);
void    ft_display_data_info(t_data *data);
char    *ft_error_return(int error);
int		ft_arr_len(char **arr);
int		ft_is_square(t_game_data *data);
int		ft_check_param(t_game_data *data, char *path);
int		ft_is_close(char **map, int hauteur, int largeur);
int		ft_check_dimentions(t_game_data *data);
int		ft_check_valide_way(t_game_data *g_data);
int		ft_close_windows(int keycode, t_data *data);
int		ft_manage_keyboard(int keycode, t_data *data);
int		ft_colors(int larg, int lo);

#endif
