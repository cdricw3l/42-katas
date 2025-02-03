/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:08:25 by cb                #+#    #+#             */
/*   Updated: 2025/01/14 01:39:30 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/so_long_bonus.h"

void	display_image_data(t_img *im)
{
	ft_printf("Voici les informations concernant l'image:");
	ft_printf("Dimentions de l'image ... hauteur: %d largeur : %d",
		im->height, im->width);
	ft_printf("voici la taile de la frame %d et la classe : %s",
		im->frame_size, im->class);
}

void	ft_display_data_info(t_data *data)
{
	ft_printf("Contenu de la structure data: 🤙🤙🤙\n\n");
	ft_printf("Nom de la map: %s\n\n",
		data->map_name);
	ft_printf("Dimention de la map: \n");
	ft_printf("Hauteur: %d \nlargeur: %d\n\n",
		data->xy_data.map.row, data->xy_data.map.col);
	ft_printf("Position de depart du personnage\n");
	ft_printf("Hauteur: %d\nlargeur: %d\n\n",
		data->xy_data.begin.row, data->xy_data.begin.col);
	ft_printf("Nombre d'item: \n");
	ft_printf("Nombre d'item sur la map: %d\n\n",
		data->count_item);
	ft_printf("Check list value: \n");
	ft_printf("Affichage de la map: \n\n");
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
				ft_printf("%c", map[i][j]);
				j++;
			}
			i++;
			ft_printf("\n");
		}
	}
	ft_printf("\n");
}

void	print_path(char **path_g)
{
	int	i;

	i = 0;
	while (i < SET_SIZE)
	{
		ft_printf(" ==> [ path-G ] %s\n", path_g[i]);
		i++;
	}
	ft_printf("\n");
}
