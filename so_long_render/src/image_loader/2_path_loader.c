/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_path_loader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 05:11:16 by cb                #+#    #+#             */
/*   Updated: 2025/01/09 06:58:26 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static char	**get_path_g(void)
{
	char	**img_path;

	img_path = malloc(sizeof(char *) * (IMG_SET_SIZE + 1));
	if (!img_path)
		return (NULL);
	img_path[0] = "../../items/background/grass/11_grass.xpm";
	img_path[1] = "../../items/background/wall/12_wall.xpm";
	img_path[2] = "../../items/collectibles/21_potion.xpm.xpm";
	img_path[3] = "../../items/exit/51_door.xpm";
	img_path[4] = "../../items/number/61_0.xpm";
	img_path[5] = "../../items/number/62_1.xpm";
	img_path[6] = "../../items/number/63_2.xpm";
	img_path[7] = "../../items/number/64_3.xpm";
	img_path[8] = "../../items/number/65_4.xpm";
	img_path[9] = "../../items/number/66_5.xpm";
	img_path[10] = "../../tildset/number/67_6.xpm";
	img_path[11] = "../../tildset/number/68_7.xpm";
	img_path[12] = "../../tildset/number/69_8.xpm";
	img_path[13] = "../../tildset/number/610_9.xpm";
	img_path[14] = NULL;
	return (img_path);
}
static char	**get_path_l(void)
{
	char	**img_path;

	img_path = malloc(sizeof(char *) * (IMG_SET_SIZE + 1));
	if (!img_path)
		return (NULL);
	img_path[0] = "../../items/hero_xpm_trame/left/31_Pink_Monster_Attack1_4.xpm";
	img_path[1] = "../../items/hero_xpm_trame/left/32_Pink_Monster_Attack2_6.xpm";
	img_path[2] = "../../items/hero_xpm_trame/left/33_Pink_Monster_Death_8.xpm";
	img_path[3] = "../../items/hero_xpm_trame/left/34_Pink_Monster_Hurt_4.xpm";
	img_path[4] = "../../items/hero_xpm_trame/left/35_Pink_Monster_Jump_8.xpm";
	img_path[5] = "../../items/hero_xpm_trame/left/36_Pink_Monster_Push_6.xpm";
	img_path[6] = "../../items/hero_xpm_trame/left/37_Pink_Monster_Run_6.xpm";
	img_path[7] = "../../items/hero_xpm_trame/left/38_Pink_Monster_Throw_4.xpm";
	img_path[8] = "../../items/hero_xpm_trame/left/39_Pink_Monster.xpm";
	img_path[9] = "../../items/hero_xpm_trame/left/310_Pink_Monster_Walk_6.xpm";
	img_path[10] = "../../items/monster_trame/left/41_Dude_Monster_Attack2_6.xpm";
	img_path[11] = "../../items/monster_trame/left/42_Dude_Monster_Hurt_4.xpm";
	img_path[12] = "../../items/monster_trame/left/43_Dude_Monster_Jump_8.xpm";
	img_path[13] = "../../items/monster_trame/left/44_Dude_Monster_Run_6.xpm";
	img_path[14] = NULL;
	return (img_path);
}

static char	**get_path_r(void)
{
	char	**img_path;

	img_path = malloc(sizeof(char *) * (IMG_SET_SIZE + 1));
	if (!img_path)
		return (NULL);
	img_path[0] = "../../items/hero_xpm_trame/left/31_Pink_Monster_Attack1_4.xpm";
	img_path[1] = "../../items/hero_xpm_trame/left/32_Pink_Monster_Attack2_6.xpm";
	img_path[2] = "../../items/hero_xpm_trame/left/33_Pink_Monster_Death_8.xpm";
	img_path[3] = "../../items/hero_xpm_trame/left/34_Pink_Monster_Hurt_4.xpm";
	img_path[4] = "../../items/hero_xpm_trame/left/35_Pink_Monster_Jump_8.xpm";
	img_path[5] = "../../items/hero_xpm_trame/left/36_Pink_Monster_Push_6.xpm";
	img_path[6] = "../../items/hero_xpm_trame/left/37_Pink_Monster_Run_6.xpm";
	img_path[7] = "../../items/hero_xpm_trame/left/38_Pink_Monster_Throw_4.xpm";
	img_path[8] = "../../items/hero_xpm_trame/left/39_Pink_Monster.xpm";
	img_path[9] = "../../items/hero_xpm_trame/left/310_Pink_Monster_Walk_6.xpm";
	img_path[10] = "../../items/monster_trame/left/41_Dude_Monster_Attack2_6.xpm";
	img_path[11] = "../../items/monster_trame/left/42_Dude_Monster_Hurt_4.xpm";
	img_path[12] = "../../items/monster_trame/left/43_Dude_Monster_Jump_8.xpm";
	img_path[13] = "../../items/monster_trame/left/44_Dude_Monster_Run_6.xpm";
	img_path[14] = NULL;
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
