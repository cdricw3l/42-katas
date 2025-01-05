/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 23:56:59 by cb                #+#    #+#             */
/*   Updated: 2025/01/05 04:56:13 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

char   **get_image_path_part3()
{
    char **img_path;

    img_path = malloc(sizeof(char *) * 17);
    if(!img_path)
        return(NULL);
    img_path[0] = "items/monster/l_monster/monster_l_1.xpm";
	img_path[1] = "items/monster/l_monster/monster_l_2.xpm";
	img_path[2] = "items/monster/l_monster/monster_l_3.xpm";
	img_path[3] = "items/monster/l_monster/monster_l_4.xpm";
	img_path[4] = "items/monster/l_monster/monster_l_5.xpm";
	img_path[5] = "items/monster/l_monster/monster_l_6.xpm";
	img_path[6] = "items/monster/l_monster/monster_l_7.xpm";
	img_path[7] = "items/monster/l_monster/monster_l_8.xpm";
	img_path[8] = "items/monster/r_monster/monster_r_1.xpm";
	img_path[9] = "items/monster/r_monster/monster_r_2.xpm";
	img_path[10] = "items/monster/r_monster/monster_r_3.xpm";
	img_path[11] = "items/monster/r_monster/monster_r_4.xpm";
	img_path[12] = "items/monster/r_monster/monster_r_5.xpm";
	img_path[13] = "items/monster/r_monster/monster_r_6.xpm";
	img_path[14] = "items/monster/r_monster/monster_r_7.xpm";
	img_path[15] = "items/monster/r_monster/monster_r_7.xpm";
	img_path[16] = "items/monster/r_monster/monster_r_7.xpm";
    return (img_path);
}

char   **get_image_path_part2()
{
    char **img_path;

    img_path = malloc(sizeof(char *) * 17);
    if(!img_path)
        return(NULL);
    img_path[0] = "items/monster/l_monster/monster_l_1.xpm";
	img_path[1] = "items/monster/l_monster/monster_l_2.xpm";
	img_path[2] = "items/monster/l_monster/monster_l_3.xpm";
	img_path[3] = "items/monster/l_monster/monster_l_4.xpm";
	img_path[4] = "items/monster/l_monster/monster_l_5.xpm";
	img_path[5] = "items/monster/l_monster/monster_l_6.xpm";
	img_path[6] = "items/monster/l_monster/monster_l_7.xpm";
	img_path[7] = "items/monster/l_monster/monster_l_8.xpm";
	img_path[8] = "items/monster/r_monster/monster_r_1.xpm";
	img_path[9] = "items/monster/r_monster/monster_r_2.xpm";
	img_path[10] = "items/monster/r_monster/monster_r_3.xpm";
	img_path[11] = "items/monster/r_monster/monster_r_4.xpm";
	img_path[12] = "items/monster/r_monster/monster_r_5.xpm";
	img_path[13] = "items/monster/r_monster/monster_r_6.xpm";
	img_path[14] = "items/monster/r_monster/monster_r_7.xpm";
	img_path[15] = "items/monster/r_monster/monster_r_7.xpm";
	img_path[16] = "items/monster/r_monster/monster_r_7.xpm";
    return (img_path);
}

char   **get_image_path()
{
    char **img_path;

    img_path = malloc(sizeof(char *) * 17);
    if(!img_path)
        return(NULL);
    img_path[0] = "items/monster/l_monster/monster_l_1.xpm";
	img_path[1] = "items/monster/l_monster/monster_l_2.xpm";
	img_path[2] = "items/monster/l_monster/monster_l_3.xpm";
	img_path[3] = "items/monster/l_monster/monster_l_4.xpm";
	img_path[4] = "items/monster/l_monster/monster_l_5.xpm";
	img_path[5] = "items/monster/l_monster/monster_l_6.xpm";
	img_path[6] = "items/monster/l_monster/monster_l_7.xpm";
	img_path[7] = "items/monster/l_monster/monster_l_8.xpm";
	img_path[8] = "items/monster/r_monster/monster_r_1.xpm";
	img_path[9] = "items/monster/r_monster/monster_r_2.xpm";
	img_path[10] = "items/monster/r_monster/monster_r_3.xpm";
	img_path[11] = "items/monster/r_monster/monster_r_4.xpm";
	img_path[12] = "items/monster/r_monster/monster_r_5.xpm";
	img_path[13] = "items/monster/r_monster/monster_r_6.xpm";
	img_path[14] = "items/monster/r_monster/monster_r_7.xpm";
	img_path[15] = "items/monster/r_monster/monster_r_7.xpm";
	img_path[16] = "items/monster/r_monster/monster_r_7.xpm";
    return (img_path);
}
int clean_image_memory(t_img **img, int index)
{
    int i;

    i = 0;
    while (i < index)
    {
        if (img[i])
            free(img[i]);
        i++;
    }
    return (1);
}

int	load_image(char **path[3], t_img **img, void *mlx)
{
    int i;
    int j;

    i = 0;
    j = 16;
    while (i < IMG_SET)
    {
        if (i <= 16)
            img[i]->img = mlx_xpm_file_to_image(mlx, path[0][i], &(img[i]->width), &(img[i]->height));
        else if (i > 16 && i <= 32)
            img[i]->img = mlx_xpm_file_to_image(mlx, path[1][i - j], &(img[i]->width), &(img[i]->height));
        else
            img[i]->img = mlx_xpm_file_to_image(mlx, path[2][i - j * 2], &(img[i]->width), &(img[i]->height));
        if(!img[i]->img)
            return(clean_image_memory(img, i));
        i++;
        printf("%d\n", i);
    }
    return(0);
}

int	load_path(char **path[3])
{
    int i;
    char **path_1;
    char **path_2;
    char **path_3;

    i = 0;
    path[0] = get_image_path();
    if (!path[0])
    {
        return (1);
    }
    path[1] = get_image_path_part2();
    if (!path[1])
    {
        free(path[0]);
        return (1);
    }
    path[2] = get_image_path_part3();
    if (!path[2])
    {
        free(path[0]);
        free(path[1]);
        return (1);
    }
	return(0);
}

int    init_image(t_img **img, int img_set)
{
    int i;
    t_img *im;

    i = 0;
    if (!img || img_set <= 0)
        return (1);
    while (i < img_set)
    {
        im = malloc(sizeof(t_img));
        if (!im)
            return (1);
        im->endian = 0;
        im->line_length = 0;
        im->height = 0;
        im->width = 0;
        im->bit_per_pixel = 0;
        im->img = NULL;
        im->addr = NULL;
        img[i] = im;
        i++;
    }
    return (0);
}

int image_loader(void *mlx, t_img **img, int img_set)
{
    int init;
    int get_path;
    int load;
    char **path[3];
    
    init = init_image(img, img_set);
    if(init)
        return (1);
    get_path = load_path(path);
    if(get_path)
        return (1);
    load = load_image(path,img, mlx);
    if(load)
        return(1);
    return (0);
}
int main(void)
{

    char **arr[3];
    int get = load_path(arr);
    char **path1 = arr[0];

    
    t_data *data;

    data = malloc(sizeof(data) * 1);
    data->mlx = mlx_init();
    
    t_img **img;
    
    img = malloc(sizeof(t_img *) * IMG_SET);
    init_image(img, IMG_SET);
    printf("voici le pointeur %p\n", img);
    int j = load_image(arr,img,data->mlx);
    if(j)
    {
        printf("erreur\n");
        return(3);
    }
    free(data->mlx);
    int i = 0;
    while (i < IMG_SET)
    {
        if (i < 3)
            free(arr[i]);
        free(img[i]->img);
        free(img[i]);
        i++;
    }

    free(img);
    free(data);
    
    
    return(0);
}