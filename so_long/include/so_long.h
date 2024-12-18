/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:40:51 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/18 13:49:42 by cbouhadr         ###   ########.fr       */
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


typedef struct s_data
{
	void        *img;
	char        *addr;
	int         bit_per_pixel;
	int         line_length;
	int         endian;
	t_dimention dimention;

} t_data;

void    ft_get_dimentions(int fd, t_data  *img);
void    ft_print_map(char **map, int hauteur, int largeur);


// check map
int     ft_check_params(char **map, int  hauteur, int largeur);
int     is_rectangle(int hauteur, int largeur);
int     are_exit(char **map, int  hauteur, int largeur);
int     are_item(char **map, int  hauteur, int largeur);
int     are_start(char **map, int  hauteur, int largeur);
int     is_close(char **map, int  hauteur, int largeur);
int		is_empty_or_wrong(char **map, int hauteur, int largeur);
char    **ft_parse_params(char *file, int hauteur, int largeur);
char    *ft_error_return(int error);

#endif
