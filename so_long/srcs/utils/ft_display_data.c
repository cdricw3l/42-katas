/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:08:35 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/21 10:55:00 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void    ft_display_data_info(t_data *data)
{
    printf("\n//////////////////////////////////////////\nContenu de la structure data: 🤙🤙🤙\n\n");

    printf("Nom de la map: %s \n\n", data->map_name);

    printf("Dimention de la map: \n");
    printf("Hauteur: %d \ncol: %d\n\n", data->dimention.row, data->dimention.col);

    printf("Position de depart du personnage\n");
    printf("Hauteur: %d \ncol: %d\n\n", data->begin.row, data->begin.col);

    printf("Nombre d'item: \n");
    printf("Nombre d'item sur la map: %d\n\n", data->count_item);

    printf("Check list value: \n");
    printf("Valeur attendu: 5. Valeur effective : %d \n", ft_check_params(data));


    printf("Affichage de la map: \n\n");
    ft_print_map(data->map,data->dimention.row, data->dimention.col, 13);
    printf("//////////////////////////////////////////\n\n");

}