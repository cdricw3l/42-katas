/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:40:51 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/22 10:17:32 by cb               ###   ########.fr       */
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


#define CHECK_LIST_SIZE 6
#define CHECK_NAME_SIZE 20

typedef int check_list[CHECK_LIST_SIZE];
typedef char **check_list_name[CHECK_LIST_SIZE];
typedef char *check_name[CHECK_NAME_SIZE];

typedef struct s_check_list
{
	check_list		check_list;
	check_list_name	check_list_name;

} t_check_list ;


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
	int					count_mouvement;
	t_dimention			dimention;
	t_dimention			begin;
	t_dimention			exit_position;
	
} t_game_data ;

typedef struct s_img
{
	void				*img;
	void				*door;
	char				*addr;
	int					bit_per_pixel;
	int					line_length;
	int					endian;
	
} t_img ;


typedef struct s_data
{
	void				*mlx;
	void				*window;
	t_img				img;
	t_check_list		check_list;
	t_game_data			game_data;
	
} t_data;

t_dimention    ft_get_dimentions(int fd, t_data  *img);


// check map
int		ft_check_params(t_data *data);
void    ft_display_data_info(t_data *data);
int		is_close_and_rectangle(char **map, int hauteur, int largeur);
char	**ft_parse_params(char *file, t_data *data);
char    *ft_error_return(int error);
int		ft_colors(int larg, int lo);

int		ft_manage_mouse(int keycode, t_data *data);
int		ft_manage_keyboard(int keycode, t_data *data);
int		ft_close_windows(int keycode, t_data **data);
void	ft_flood_fill(char **tab, t_dimention size, t_dimention begin);
void	ft_check_valide_way(char **tab, t_data *data, t_dimention begin);
int		check_and_init(char *path, t_data *data);
void    ft_print_map(char **map, int hauteur, int largeur, int fd);


#endif
