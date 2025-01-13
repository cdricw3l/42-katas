// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   image_layer.c                                      :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/01/06 11:33:22 by cb                #+#    #+#             */
// /*   Updated: 2025/01/09 05:52:46 by cb               ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */


// #include "../../include/image_layer.h"

// t_img *get_image_in_set(t_data *data, char c, int state)
// {

//     printf("voicis %c\n", data->map[data->xy_data.begin.col][data->xy_data.begin.row]);
    
//     if(c == '0')
//         return (data->img_set[0]);
//     if(c == '1')
//         return (data->img_set[1]);
//     if(c == 'P')
//     {
//         printf("state : %d\n",data->char_state);
//         printf("state : %d\n",state);
//         if(state == 1)
//             return(data->img_set[2]);
//         else
//             return(data->img_set[3]);
//     }
//     if(c == 'C')
//         return (data->img_set[4]);
//     if(c == 'E')
//         return (data->img_set[5]);
//     else
//         return(NULL);

// }

// int    run_image_layer(t_data *d)
// {
//     t_img   *tpm;
//     //int     *addr;
//     char    **map;
//     t_data *data = d;

//     map = data->map; 
//     print_dimention(data->xy_data, 'b');
//     print_map(data);
//     printf("%d\n", map[data->xy_data.begin.col][data->xy_data.begin.row]);
//     tpm = get_image_in_set(data, map[data->xy_data.begin.col][data->xy_data.begin.row], data->char_state);
//     if(!tpm)
//         return(ERR_FRAME);
//     mlx_put_image_to_window(data->mlx,data->window,tpm->img,data->xy_data.begin.col * TILD_SIZE,data->xy_data.begin.row *  TILD_SIZE);
//     //addr = (int *)mlx_get_data_addr(tpm ,&tpm->bit_per_pixel,&tpm->line_length,&tpm->endian);
   
//     // if(!addr)
//     //     return(ERR_FRAME);
//     printf("start %d et %d \n", tpm->line_length, tpm->endian);
    
//     return(0);

// }

