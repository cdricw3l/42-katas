/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_layer_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:43:22 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/17 12:10:12 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/error_managment_bonus.h"

static char	*error_return_2(int error)
{
	if (error == ERR_LINE_LEN)
		return ("Error\n [ err ] A line of the map has a different size\n");
	if (error == ERR_NOTCLOSE)
		return ("Error\n [ err ] The map is not closed\n");
	if (error == ERR_NOTINSET)
		return ("Error\n [ err ] An element on the map is not part of the set\n");
	if (error == ERR_DUPLICATE)
		return ("Error\n [ err ] Two start positions or two exits on the map\n");
	if (error == ERR_FRAME)
		return ("Error\n [ err ] Problem creating the new frame\n");
	if (error == ERR_WIN)
		return ("Error\n [ err ] Error initializing mlx or the window");
	if (error == ERR_NO_ITEM)
		return ("Error\n [ clean ]  No item on the map\n");
	if (error == ERR_SIZE)
		return ("Error\n [ clean ] The map is not the correct size\n");
	if (error == WIN_GAME)
		return ("[ clean ] You Win PROGRAM TERMINATED SUCCESSFULLY\n");
	if (error == ERR_GAME_OVER)
		return ("[ clean ] You Lose GAME OVER\n");
	if (error == ERR_ALLOC_DATA)
		return ("Error\n [ err ] No map passed as parameter");
	if (error == ERR_DRAW)
		return ("Error\n [ err ] Problem with the drawing function");
	return (NULL);
}

static char	*error_return_1(int error)
{
	if (error == ERR_NO_MAP)
		return ("Error\n [ err ] No map passed as parameter");
	if (error == ERR_STRUC_INIT)
		return ("Error\n [ err ] Structure data initialization error\n");
	if (error == ERR_MLX)
		return ("Error\n [ err ] mlx pointer initialization error\n");
	if (error == ERR_IMG_SET)
		return ("Error\n [ err ] Image set initialization error\n");
	if (error == ERR_SCREEN)
		return ("Error\n [ err ] Screen size error\n");
	if (error == ERR_GET_MAP)
		return ("Error\n [ err ] Empty map or incorrect path\n");
	if (error == ERR_CHECK_MAP)
		return ("Error\n [ err ] Problem with map parameters\n");
	if (error == ERR_NO_WAY)
		return ("Error\n [ err ] No valid path\n");
	if (error == ERR_ALLOC_IMG)
		return ("Error\n Image structure creation error\n");
	if (error == ERR_GET_IMGPATH)
		return ("Error\n [ err ] Path retrieval problem\n");
	if (error == ERR_IMG_LOADING)
		return ("Error\n [ err ] Image loading error \n");
	return (NULL);
}

int	error_layer(int err)
{
	char	*error_msg;
	int		fd;
	int		w;

	if (err <= 11)
		error_msg = error_return_1(err);
	else
		error_msg = error_return_2(err);
	if (error_msg)
		ft_printf("%s\n", error_msg);
	if (err != ERR_OPEN_LOG && err != ERR_WRITE_LOG)
	{
		fd = open("src/exit_managment/log/log", O_APPEND
				| O_CREAT
				| O_WRONLY, 0644);
		if (fd == -1)
			error_layer(ERR_OPEN_LOG);
		else
		{
			w = write(fd, error_msg, ft_strlen(error_msg));
			if (w != (int)ft_strlen(error_msg))
				error_layer(ERR_WRITE_LOG);
		}
	}
	return (1);
}
