/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:08:25 by cb                #+#    #+#             */
/*   Updated: 2025/01/13 00:13:57 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	display_image_data(t_img *im)
{
	printf("Voici les informations concernant l'image:\n");
	printf("Dimentions de l'image ... hauteur: %d largeur : %d",
		im->height, im->width);
	printf("voici la taile de la frame %d et la classe : %s",
		im->frame_size, im->class);
}

void	ft_display_data_info(t_data *data)
{
	printf("Contenu de la structure data: 🤙🤙🤙\n\n");
	printf("Nom de la map: %s \n\n",
		data->map_name);
	printf("Dimention de la map: \n");
	printf("Hauteur: %d \nlargeur: %d\n\n",
		data->xy_data.map.row, data->xy_data.map.col);
	printf("Position de depart du personnage\n");
	printf("Hauteur: %d\nlargeur: %d\n\n",
		data->xy_data.begin.row, data->xy_data.begin.col);
	printf("Nombre d'item: \n");
	printf("Nombre d'item sur la map: %d\n\n",
		data->count_item);
	printf("Check list value: \n");
	printf("Affichage de la map: \n\n");
	print_map(data);
}

void	print_map(t_data *data)
{
	int		i;
	int		j;
	int		hauteur;
	int		largeur;
	char	**map;

	i = 0;
	if (data->xy_data.map.row && data->xy_data.map.col)
	{
		hauteur = data->xy_data.map.row;
		largeur = data->xy_data.map.col;
		map = data->map;
		while (i < hauteur)
		{
			j = 0;
			while (j < largeur)
			{
				printf("%c", map[i][j]);
				j++;
			}
			i++;
			printf("\n");
		}
	}
	printf("\n");
}

void	print_path(char **path_g)
{
	int	i;

	i = 0;
	while (i < SET_SIZE)
	{
		printf("[ path-G ] %s\n", path_g[i]);
		i++;
	}
	printf("\n");
}
