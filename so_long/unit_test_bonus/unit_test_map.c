/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:13:35 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/11 03:16:31 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

#include <dirent.h>
#include <X11/keysym.h>

// static int	_init(t_data *data, char *map_path)
// {
	
// 	data->map_name = map_path;
// 	data->map = NULL;
// 	data->count_item = 0;
// 	data->check_item = 0;
// 	data->count_mouvement = 0;
// 	data->count_exit = 0;
// 	data->count_begin = 0;
// 	data->xy_data.exit = ft_s_dimention();
// 	data->xy_data.begin = ft_s_dimention();
// 	data->xy_data.map = ft_s_dimention();
// 	data->xy_data.screen_size = ft_s_dimention();
// 	mlx_get_screen_size(data->mlx, &data->xy_data.screen_size.col,
// 				&data->xy_data.screen_size.row);
// 	if(data->xy_data.screen_size.col == 0 
// 			|| data->xy_data.screen_size.row == 0)
// 		return(1);
// 	return(0);
// }


// void ft_clean(t_data **d)
// {
//     t_data *data = *d;
//     int i;

//     i = 0;
//     while(i < 11)
//     {
//         printf("%s\n", data->map[i]);
//         free(data->map[i]);
//         i++;

//     }
//     free(data->map);
//     free(data);
// }


// int main(void)
// {
//     printf("start de la fonction\n");

//     t_data *data;

//     data = malloc(sizeof(t_data));
//     assert(data != NULL);
//     data->mlx = mlx_init();

    

//     printf("voici les dimentions de la map col: %d et row: %d\n", data->xy_data.map.col, data->xy_data.map.row);
//     printf("voici la position du personage y = %d et x = %d\n", data->xy_data.begin.col, data->xy_data.begin.row );
//     printf("voici la position de la sortie : x: %d et y: %d\n", data->xy_data.exit.col,data->xy_data.exit.row);

//     char *valide_map[7];

//     valide_map[0] =  "map/map1.ber";
//     valide_map[1] =  "map/map2.ber";
//     valide_map[2] =  "map/map3.ber";
//     valide_map[3] =  "map/map4.ber";
//     valide_map[4] =  "map/map5.ber";
//     valide_map[5] =  "map/medium.ber";
//     valide_map[6] =  "map/smal.ber";
    

//     int i = 0;
//     while (i < 7)
//     {
//         printf("voici i %s\n", valide_map[i]);
//         _init(data,valide_map[i]);
//         data->map = get_map(data);
//         assert(check_map(data) == 0);
//         if(check_valide_way(data) == 1)
//         {
//             printf("erreur avec les items %s\n",valide_map[i]);
//             print_map(data);
//             return(0);
//         }
//         if(check_valide_way(data) == 2)
//         {
//             printf("erreur avec les exit %s\n",valide_map[i]);
            
//             print_map(data);
//             return(0);
//         }
//         i++;
//     }
    
    
//     // char *invalide_map[17];

//     // invalide_map[1] =  "map/empty.ber";
//     // invalide_map[2] =  "map/empty_space.ber";
//     // invalide_map[3] =  "map/invalide1.ber";
//     // invalide_map[4] =  "map/invalide2.ber ";
//     // invalide_map[5] =  "map/invalide3.ber";
//     // invalide_map[6] =  "map/invalide4.ber";
//     // invalide_map[7] =  "map/invalide5.ber";
//     // invalide_map[8] =  "map/invalide6.ber";
//     // invalide_map[9] =  "map/invalide7.ber";
//     // invalide_map[10] =  "map/no_close.ber";
//     // invalide_map[11] =  "map/no_exit.ber";
//     // invalide_map[12] =  "map/no_item.ber";
//     // invalide_map[13] =  "map/no_rectangle.ber";
//     // invalide_map[14] =  "map/no_start.ber";
//     // invalide_map[15] =  "map/nothing.ber";
//     // invalide_map[16] =  "map/wrong_char.ber";

//     printf("FIN DU PROGRAMME\n");
//     //ft_clean(&data);
//     //free_memory(&data, 0);


//     return(0);
// }