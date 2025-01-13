/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2b_path_loader_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 05:11:16 by cb                #+#    #+#             */
/*   Updated: 2025/01/11 17:41:43 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static char	**get_path_g(void)
{
	char	**img_path;

	img_path = malloc(sizeof(char *) * (SET_SIZE + 1));
	if (!img_path)
		return (NULL);
	img_path[0] = "items/background/grass/11_grass_1.xpm";
	img_path[1] = "items/background/wall/12_wall_1.xpm";
	img_path[2] = "items/collectibles/21_potion_1.xpm";
	img_path[3] = "items/exit/51_door_1.xpm";
	img_path[4] = "items/number/61_0_1.xpm";
	img_path[5] = "items/number/62_1_1.xpm";
	img_path[6] = "items/number/63_2_1.xpm";
	img_path[7] = "items/number/64_3_1.xpm";
	img_path[8] = "items/number/65_4_1.xpm";
	img_path[9] = "items/number/66_5_1.xpm";
	img_path[10] = "items/number/67_6_1.xpm";
	img_path[11] = "items/number/68_7_1.xpm";
	img_path[12] = "items/number/69_8_1.xpm";
	img_path[13] = "items/number/610_9_1.xpm";
	return (img_path);
}
static char	**get_path_l(void)
{
	char	**img_path;

	img_path = malloc(sizeof(char *) * (SET_SIZE + 1));
	if (!img_path)
		return (NULL);
	img_path[0] = "items/hero_xpm_trame/left/31_Pink_Monster_Attack1_4.xpm";
	img_path[1] = "items/hero_xpm_trame/left/32_Pink_Monster_Attack2_6.xpm";
	img_path[2] = "items/hero_xpm_trame/left/33_Pink_Monster_Death_8.xpm";
	img_path[3] = "items/hero_xpm_trame/left/34_Pink_Monster_Hurt_4.xpm";
	img_path[4] = "items/hero_xpm_trame/left/35_Pink_Monster_Jump_8.xpm";
	img_path[5] = "items/hero_xpm_trame/left/36_Pink_Monster_Push_6.xpm";
	img_path[6] = "items/hero_xpm_trame/left/37_Pink_Monster_Run_6.xpm";
	img_path[7] = "items/hero_xpm_trame/left/38_Pink_Monster_Throw_4.xpm";
	img_path[8] = "items/hero_xpm_trame/left/39_Pink_Monster_1.xpm";
	img_path[9] = "items/hero_xpm_trame/left/310_Pink_Monster_Walk_6.xpm";
	img_path[10] = "items/monster_trame/left/41_Dude_Monster_Attack2_6.xpm";
	img_path[11] = "items/monster_trame/left/42_Dude_Monster_Hurt_4.xpm";
	img_path[12] = "items/monster_trame/left/43_Dude_Monster_Jump_8.xpm";
	img_path[13] = "items/monster_trame/left/44_Dude_Monster_Run_6.xpm";
	return (img_path);
}

static char	**get_path_r(void)
{
	char	**img_path;

	img_path = malloc(sizeof(char *) * (SET_SIZE + 1));
	if (!img_path)
		return (NULL);
	img_path[0] = "items/hero_xpm_trame/right/31_Pink_Monster_Attack1_4.xpm";
	img_path[1] = "items/hero_xpm_trame/right/32_Pink_Monster_Attack2_6.xpm";
	img_path[2] = "items/hero_xpm_trame/right/33_Pink_Monster_Death_8.xpm";
	img_path[3] = "items/hero_xpm_trame/right/34_Pink_Monster_Hurt_4.xpm";
	img_path[4] = "items/hero_xpm_trame/right/35_Pink_Monster_Jump_8.xpm";
	img_path[5] = "items/hero_xpm_trame/right/36_Pink_Monster_Push_6.xpm";
	img_path[6] = "items/hero_xpm_trame/right/37_Pink_Monster_Run_6.xpm";
	img_path[7] = "items/hero_xpm_trame/right/38_Pink_Monster_Throw_4.xpm";
	img_path[8] = "items/hero_xpm_trame/right/39_Pink_Monster_1.xpm";
	img_path[9] = "items/hero_xpm_trame/right/310_Pink_Monster_Walk_6.xpm";
	img_path[10] = "items/monster_trame/right/41_Dude_Monster_Attack2_6.xpm";
	img_path[11] = "items/monster_trame/right/42_Dude_Monster_Hurt_4.xpm";
	img_path[12] = "items/monster_trame/right/43_Dude_Monster_Jump_8.xpm";
	img_path[13] = "items/monster_trame/right/44_Dude_Monster_Run_6.xpm";
	return (img_path);
}



char	**get_paths(int set)
{
	char **paths;

	paths = NULL;
	if(set == 1)
		paths = get_path_g();
	if(set == 2)
		paths = get_path_l();
	if(set == 3)
		paths = get_path_r();
	return(paths);
}
