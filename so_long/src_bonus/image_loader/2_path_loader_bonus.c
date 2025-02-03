/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_path_loader_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 05:11:16 by cb                #+#    #+#             */
/*   Updated: 2025/01/17 09:50:21 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/image_layer_bonus.h"

static char	**get_path_g(void)
{
	char	**img_path;

	img_path = malloc(sizeof(char *) * (SET_SIZE));
	if (!img_path)
		return (NULL);
	img_path[0] = "tildset/hero/1_CL_Pink_Monster_l.xpm";
	img_path[1] = "tildset/hero/2_CR_Pink_Monster_r.xpm";
	img_path[2] = "tildset/exit/31_exit.xpm";
	img_path[3] = "tildset/background/4_grass.xpm";
	img_path[4] = "tildset/collectibles/5_potion.xpm";
	img_path[5] = "tildset/background/6_wall.xpm";
	img_path[6] = "tildset/exit/3_exit.xpm";
	img_path[7] = "tildset/mask/7_mask.xpm";
	img_path[8] = "tildset/monster/43_Dude_Monster_Jump_8_left.xpm";
	img_path[9] = "tildset/monster/43_Dude_Monster_Jump_8_right.xpm";
	img_path[10] = "tildset/hero/36_Pink_Monster_Push_6_left.xpm";
	img_path[11] = "tildset/hero/36_Pink_Monster_Push_6_right.xpm";
	img_path[12] = "tildset/monster/41_Dude_Monster_Attack2_6_left.xpm";
	img_path[13] = "tildset/monster/41_Dude_Monster_Attack2_6_right.xpm";
	img_path[14] = "tildset/hero/34_Pink_Monster_Hurt_4_left.xpm";
	img_path[15] = "tildset/hero/34_Pink_Monster_Hurt_4_right.xpm";
	img_path[16] = "tildset/hero/33_Pink_Monster_Death_8_left.xpm";
	img_path[17] = "tildset/hero/33_Pink_Monster_Death_8_right.xpm";
	img_path[18] = "tildset/background/6_wall_life.xpm";
	return (img_path);
}

char	**get_paths(void)
{
	char	**paths;

	paths = get_path_g();
	return (paths);
}
