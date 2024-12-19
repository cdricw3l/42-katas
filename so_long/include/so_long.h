/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:40:51 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/19 17:06:22 by cbouhadr         ###   ########.fr       */
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
	t_dimention			dimention;
	t_mouse_position	mouse_position;

} t_data;

void    ft_get_dimentions(int fd, t_data  *img);
void    ft_print_map(char **map, int hauteur, int largeur);


// check map
int		ft_check_params(char **map, int check_arr[5], int hauteur, int largeur);;
int		is_close_and_rectangle(char **map, int hauteur, int largeur);
char    **ft_parse_params(char *file, int hauteur, int largeur);
char    *ft_error_return(int error);
int		ft_colors(int larg, int lo);

int ft_manage_mouse(int keycode, t_data *data);
int ft_manage_keyboard(int keycode, t_data *data);
int ft_close_windows(int keycode, t_data **data);

#endif
