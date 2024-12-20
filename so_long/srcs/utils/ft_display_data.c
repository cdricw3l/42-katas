/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:08:35 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/20 14:16:25 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    ft_display_data_info(t_data *data)
{
    printf("\n//////////////////////////////////////////\nContenu de la structure data: 🤙🤙🤙\n\n");

    printf("Nom de la map: %s \n\n", data->map_name);

    printf("Dimention de la map: \n");
    printf("Hauteur: %d \nlargeur: %d\n\n", data->dimention.hauteur, data->dimention.largeur);

    printf("Position de depart du personnage\n");
    printf("Hauteur: %d \nlargeur: %d\n\n", data->begin.hauteur, data->begin.largeur);

    printf("Nombre d'item: \n");
    printf("Nombre d'item sur la map: %d\n\n", data->count_item);

    printf("Check list value: \n");
    printf("Valeur attendu: 5. Valeur effective : %d \n", ft_check_params(data));


    printf("Affichage de la map: \n\n");
    ft_print_map(data->map,data->dimention.hauteur, data->dimention.largeur);
    printf("//////////////////////////////////////////\n\n");

}