/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_managment_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:13:54 by cb                #+#    #+#             */
/*   Updated: 2025/01/17 07:33:14 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MANAGMENT_BONUS_H
# define ERROR_MANAGMENT_BONUS_H

# include "so_long_bonus.h"

# define O_LAYER -1
# define ERR_NO_MAP 0
# define ERR_STRUC_INIT 1
# define ERR_MLX 2
# define ERR_IMG_SET 3
# define ERR_SCREEN 4
# define ERR_GET_MAP 5
# define ERR_CHECK_MAP 6
# define ERR_NO_WAY 7
# define ERR_ALLOC_IMG 8
# define ERR_GET_IMGPATH 9
# define ERR_IMG_LOADING 10
# define ERR_LINE_LEN 11
# define ERR_NOTCLOSE 12
# define ERR_NOTINSET 13
# define ERR_DUPLICATE 14
# define ERR_FRAME 15 
# define ERR_SIZE 16
# define ERR_OPEN_LOG 17 
# define ERR_WRITE_LOG 18 
# define ERR_SCOPE 19
# define ERR_NO_ITEM 20
# define ERR_WIN 21
# define WIN_GAME 22
# define ERR_ALLOC_DATA 23
# define ERR_DRAW 24
# define ERR_GAME_OVER 25

int	error_layer(int err);

#endif