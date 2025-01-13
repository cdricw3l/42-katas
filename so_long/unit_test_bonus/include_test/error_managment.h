/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_managment.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:13:54 by cb                #+#    #+#             */
/*   Updated: 2025/01/11 03:40:52 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ERROR_MANAGMENT_H
#define ERROR_MANAGMENT_H

#include "so_long.h"

#define O_LAYER -1
#define ERR_NO_MAP 0
#define ERR_STRUC_INIT 1
#define ERR_MLX 2
#define ERR_IMG_SET 3
#define ERR_SCREEN 4
#define ERR_GET_MAP 5
#define ERR_CHECK_MAP 6
#define ERR_NO_WAY 7
#define ERR_ALLOC_IMG 8
#define ERR_GET_IMGPATH 9
#define ERR_IMG_LOADING 10
#define ERR_LINE_LEN 11
#define ERR_NOTCLOSE 12
#define ERR_NOTINSET 13
#define ERR_DUPLICATE 14
#define ERR_FRAME 15 
#define ERR_VALIDE_WAY 16
#define ERR_
#define ERR_OPEN_LOG 16 
#define ERR_WRITE_LOG 17 
#define ERR_SCOPE 16 
#define ERR_NO_ITEM 17
#define ERR_WIN 18


int error_layer(int err);

#endif