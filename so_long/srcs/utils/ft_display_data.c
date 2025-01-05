/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:08:35 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/05 06:27:06 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void    ft_display_data_info(t_data *data)
{

    printf("\n//////////////////////////////////////////\nContenu de la structure data: 🤙🤙🤙\n\n");
    printf("Nom de la map: %s \n\n", data->map_name);
    printf("Dimention de la map: \n");
    printf("Hauteur: %d \nlargeur: %d\n\n", data->xy_data.map.row, data->xy_data.map.col);
    printf("Position de depart du personnage\n");
    printf("Hauteur: %d \nlargeur: %d\n\n", data->xy_data.begin.row, data->xy_data.begin.col);
    printf("Nombre d'item: \n");
    printf("Nombre d'item sur la map: %d\n\n", data->count_item);
    printf("Check list value: \n");
    //printf("Valeur attendu: 5. Valeur effective : %d \n", ft_check_params(data));
    printf("Affichage de la map: \n\n");
    ft_print_map(data);
    printf("\n//////////////////////////////////////////\n\n");

}

void	end_game_menu(t_data *data)
{
	char	*str;

	printf("Tu as fini le jeu\n");
	printf("Tape 1 pour recommencer\n");
	printf("Tape 2 pour charger une nouvelle map\n");
	printf("Tape 3 pour quitter le jeu\n");
	str = get_next_line(0);
	printf("voici l'entre utilisateur %s\n", str);
	free(str);
	(void)data;
}
