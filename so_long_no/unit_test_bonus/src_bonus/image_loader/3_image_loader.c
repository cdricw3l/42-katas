/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_image_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:23:15 by cb                #+#    #+#             */
/*   Updated: 2025/01/11 14:47:08 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"


int	clean_img_set(t_img **img_set, int idx)
{
	int i;

	i = 0;
	if (img_set)
	{
		while (i < idx)
		{
			if(img_set[i])
				free(img_set[i++]);
		}
		free(img_set);
	}
	return(1);
}

char *get_image_class(char *path)
{
	char *class;
	int len;

	if(!path || !path[0])
		return(NULL);
	if((ft_strrchr(path, '/') + 1)[2] == '_')
		len = 2;
	else
		len = 3;
	class = ft_substr(ft_strrchr(path, '/') + 1 ,0, len);
	if(!class)
		return(NULL);
	return(class);
}

int	get_image_frame_size(char *path)
{
	int frame_size;
	char *truc_path1;
	
	truc_path1 = ft_substr(ft_strrchr(path, '.') - 1, 0, 1);
	frame_size = ft_atoi(truc_path1);
	free(truc_path1);
	if(frame_size <= 0)
		return(0);
	return (frame_size);
}

int	push_img_set(t_data *data, t_img **img_set, char **path, int set)
{
	int i;
	
	i = 0;
	while(i < SET_SIZE)
	{
		img_set[i] = malloc(sizeof(t_img));
		if(!img_set[i])
			return(clean_img_set(img_set, i));
		img_set[i]->img = mlx_xpm_file_to_image(data->mlx, path[i], &img_set[i]->width,&img_set[i]->height);
		if(!img_set[i]->img)
			return(clean_img_set(img_set, i));
		img_set[i]->class = get_image_class(path[i]);
		if(!img_set[i]->class)
			return(clean_img_set(img_set, i));
		img_set[i]->frame_size = get_image_frame_size(path[i]);
		if(img_set[i]->frame_size == 0)
			return(clean_img_set(img_set, i));
		if(set >= 0 && set <=2)
			img_set[i]->set = set;
		i++;
	}
	return(0);
}

int	image_loader(t_data *data, char **path_g, char **path_l, char **path_r)
{
	t_img_sets *img_set;
	
	img_set = data->img_sets;
	img_set->img_set_global = malloc(sizeof(t_img *) * SET_SIZE);
	img_set->img_set_left = malloc(sizeof(t_img *) * SET_SIZE);
	img_set->img_set_right = malloc(sizeof(t_img *) * SET_SIZE);
	assert(img_set->img_set_global != NULL && img_set->img_set_left != NULL && img_set->img_set_right != NULL);
	if(!img_set->img_set_global
			|| !img_set->img_set_left
			|| !img_set->img_set_right)
		return(1);
	push_img_set(data,img_set->img_set_global, path_g, 0);
	push_img_set(data, img_set->img_set_left, path_l, 1);
	push_img_set(data, img_set->img_set_right, path_r, 2);
	return (0);
}
