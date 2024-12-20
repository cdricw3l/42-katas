/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:40:51 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/20 14:30:28 by cbouhadr         ###   ########.fr       */
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


typedef struct s_dimention
{
	int hauteur;
	int largeur;

} t_dimention;

typedef struct s_mouse_position
{
	int x;
	int y;
	
} t_mouse_position;

typedef struct s_data
{
	void				*mlx;
	void				*window;
	void				*img;
	char				*addr;
	int					bit_per_pixel;
	int					line_length;
	int					endian;
	char				**map;
	char				*map_name;
	int					check_arr[5];
	t_dimention			dimention;
	t_dimention			begin;
	t_mouse_position	mouse_position;
	int					count_item;

} t_data;

void    ft_get_dimentions(int fd, t_data  *img);
void    ft_print_map(char **map, int hauteur, int largeur);


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
#endif
