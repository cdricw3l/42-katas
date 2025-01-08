// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   2_path_loader_bonus.c                              :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/01/05 05:11:16 by cb                #+#    #+#             */
// /*   Updated: 2025/01/05 19:28:53 by cb               ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../include/so_long.h"

// char	**get_image_path_part3(void)
// {
// 	char	**img_path;

// 	img_path = malloc(sizeof(char *) * IMG_SET_SIZE);
// 	if (!img_path)
// 		return (NULL);
// 	img_path[0] = "tildset/background/grass";
// 	img_path[1] = "tildset/background/wall";
// 	img_path[2] = "tildset/charactere/Pink_Monster.xpm";
// 	img_path[3] = "tildset/collectibles/potion.xpm";
// 	img_path[3] = "tildset//potion.xpm";
// 	img_path[4] = "items/monster/l_monster/monster_l_5.xpm";
// 	img_path[5] = "items/monster/l_monster/monster_l_6.xpm";
// 	img_path[6] = "items/monster/l_monster/monster_l_7.xpm";
// 	img_path[7] = "items/monster/l_monster/monster_l_8.xpm";
// 	img_path[8] = "items/monster/r_monster/monster_r_1.xpm";
// 	img_path[9] = "items/monster/r_monster/monster_r_2.xpm";
// 	img_path[10] = "items/monster/r_monster/monster_r_3.xpm";
// 	img_path[11] = "items/monster/r_monster/monster_r_4.xpm";
// 	img_path[12] = "items/monster/r_monster/monster_r_5.xpm";
// 	img_path[13] = "items/monster/r_monster/monster_r_6.xpm";
// 	img_path[14] = "items/monster/r_monster/monster_r_7.xpm";
// 	img_path[15] = "items/monster/r_monster/monster_r_7.xpm";
// 	img_path[16] = "items/monster/r_monster/monster_r_7.xpm";
// 	return (img_path);
// }

// char	**get_image_path_part2(void)
// {
// 	char	**img_path;

// 	img_path = malloc(sizeof(char *) * 17);
// 	if (!img_path)
// 		return (NULL);
// 	img_path[0] = "items/monster/l_monster/monster_l_1.xpm";
// 	img_path[1] = "items/monster/l_monster/monster_l_2.xpm";
// 	img_path[2] = "items/monster/l_monster/monster_l_3.xpm";
// 	img_path[3] = "items/monster/l_monster/monster_l_4.xpm";
// 	img_path[4] = "items/monster/l_monster/monster_l_5.xpm";
// 	img_path[5] = "items/monster/l_monster/monster_l_6.xpm";
// 	img_path[6] = "items/monster/l_monster/monster_l_7.xpm";
// 	img_path[7] = "items/monster/l_monster/monster_l_8.xpm";
// 	img_path[8] = "items/monster/r_monster/monster_r_1.xpm";
// 	img_path[9] = "items/monster/r_monster/monster_r_2.xpm";
// 	img_path[10] = "items/monster/r_monster/monster_r_3.xpm";
// 	img_path[11] = "items/monster/r_monster/monster_r_4.xpm";
// 	img_path[12] = "items/monster/r_monster/monster_r_5.xpm";
// 	img_path[13] = "items/monster/r_monster/monster_r_6.xpm";
// 	img_path[14] = "items/monster/r_monster/monster_r_7.xpm";
// 	img_path[15] = "items/monster/r_monster/monster_r_7.xpm";
// 	img_path[16] = "items/monster/r_monster/monster_r_7.xpm";
// 	return (img_path);
// }

// char	**get_image_path(void)
// {
// 	char	**img_path;

// 	img_path = malloc(sizeof(char *) * 17);
// 	if (!img_path)
// 		return (NULL);
// 	img_path[0] = "items/monster/l_monster/monster_l_1.xpm";
// 	img_path[1] = "items/monster/l_monster/monster_l_2.xpm";
// 	img_path[2] = "items/monster/l_monster/monster_l_3.xpm";
// 	img_path[3] = "items/monster/l_monster/monster_l_4.xpm";
// 	img_path[4] = "items/monster/l_monster/monster_l_5.xpm";
// 	img_path[5] = "items/monster/l_monster/monster_l_6.xpm";
// 	img_path[6] = "items/monster/l_monster/monster_l_7.xpm";
// 	img_path[7] = "items/monster/l_monster/monster_l_8.xpm";
// 	img_path[8] = "items/monster/r_monster/monster_r_1.xpm";
// 	img_path[9] = "items/monster/r_monster/monster_r_2.xpm";
// 	img_path[10] = "items/monster/r_monster/monster_r_3.xpm";
// 	img_path[11] = "items/monster/r_monster/monster_r_4.xpm";
// 	img_path[12] = "items/monster/r_monster/monster_r_5.xpm";
// 	img_path[13] = "items/monster/r_monster/monster_r_6.xpm";
// 	img_path[14] = "items/monster/r_monster/monster_r_7.xpm";
// 	img_path[15] = "items/monster/r_monster/monster_r_7.xpm";
// 	img_path[16] = "items/monster/r_monster/monster_r_7.xpm";
// 	return (img_path);
// }

// int	load_path(char **path[3])
// {
// 	int		i;
// 	char	**path_1;
// 	char	**path_2;
// 	char	**path_3;

// 	i = 0;
// 	path[0] = get_image_path();
// 	if (!path[0])
// 	{
// 		return (1);
// 	}
// 	path[1] = get_image_path_part2();
// 	if (!path[1])
// 	{
// 		free(path[0]);
// 		return (1);
// 	}
// 	path[2] = get_image_path_part3();
// 	if (!path[2])
// 	{
// 		free(path[0]);
// 		free(path[1]);
// 		return (1);
// 	}
// 	return (0);
// }
