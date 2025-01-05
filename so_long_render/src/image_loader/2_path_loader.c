/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_path_loader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 05:11:16 by cb                #+#    #+#             */
/*   Updated: 2025/01/05 22:54:59 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	**get_image_path(void)
{
	char	**img_path;

	img_path = malloc(sizeof(char *) * IMG_SET_SIZE);
	if (!img_path)
		return (NULL);
	img_path[0] = "tildset/background/grass";
	img_path[1] = "tildset/background/wall";
	img_path[2] = "tildset/charactere/pink_monster_l.xpm";
	img_path[3] = "tildset/charactere/pink_monster_r.xpm";
	img_path[4] = "tildset/collectibles/potion.xpm";
	img_path[5] = "tildset/exit/exit.xpm";
	return (img_path);
}

char	**load_path(void)
{
	char	**path;
	
	path = get_image_path();
	if (!path)
		return (NULL);
	return (path);
}
