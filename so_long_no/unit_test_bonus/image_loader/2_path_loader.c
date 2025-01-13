/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_path_loader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 05:11:16 by cb                #+#    #+#             */
/*   Updated: 2025/01/11 18:43:32 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static char	**get_path_g(void)
{
	char	**img_path;

	img_path = malloc(sizeof(char *) * (SET_SIZE + 1));
	if (!img_path)
		return (NULL);
	img_path[0] = "tildset/1_CL_Pink_Monster_l.xpm";
	img_path[1] = "tildset/2_CR_Pink_Monster_r.xpm";
	img_path[2] = "tildset/3_exit.xpm";
	img_path[3] = "tildset/4_grass.xpm";
	img_path[4] = "tildset/5_potion.xpm";
	img_path[5] = "tildset/6_wall.xpm";
	return (img_path);
}

char	**get_paths()
{
	char **paths;

	paths = get_path_g();
	return(paths);
}
