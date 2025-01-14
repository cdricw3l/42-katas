/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_image_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:23:15 by cb                #+#    #+#             */
/*   Updated: 2025/01/14 00:41:13 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/image_layer_bonus.h"

static int	clean_img_set(t_img **img_set, int idx)
{
	int	i;

	i = 0;
	if (img_set)
	{
		while (i < idx)
		{
			if (img_set[i])
				free(img_set[i++]);
		}
		free(img_set);
	}
	return (1);
}

static char	*get_image_class(char *path)
{
	char	*class;
	char	*cpy;

	if (!path || !path[0])
		return (NULL);
	cpy = ft_strdup(path);
	class = ft_substr(ft_strchr(cpy, '/') + 1, 0, 1);
	if (!class)
		return (NULL);
	free(cpy);
	return (class);
}

int	push_img_set(t_data *data, t_img **img_set, char **path)
{
	int	i;

	i = 0;
	while (i < SET_SIZE)
	{
		img_set[i] = calloc(1, sizeof(t_img));
		if (!img_set[i])
			return (clean_img_set(img_set, i));
		img_set[i]->img = mlx_xpm_file_to_image(data->mlx, path[i],
				&img_set[i]->width, &img_set[i]->height);
		if (!img_set[i]->img)
			return (clean_img_set(img_set, i));
		img_set[i]->class = get_image_class(path[i]);
		if (!img_set[i]->class)
			return (clean_img_set(img_set, i));
		img_set[i]->addr = mlx_get_data_addr(img_set[i]->img,
				&img_set[i]->bit_per_pixel,
				&img_set[i]->line_length,
				&img_set[i]->endian);
		if (!img_set[i]->addr)
			return (clean_img_set(img_set, i));
		printf("voici i %d et l'adresse %p\n", i, data->img_set_global[i]->img);
		i++;
	}
	return (0);
}

int	image_loader(t_data *data, char **path_g)
{
	int		r;
	t_img	**img_set;

	img_set = data->img_set_global;
	if (!img_set)
		return (1);
	r = push_img_set(data, img_set, path_g);
	if (r != 0)
		return (1);
	free(path_g);
	return (0);
}
