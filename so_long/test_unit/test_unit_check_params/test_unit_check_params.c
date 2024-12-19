/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unit_check_params.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:43:46 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/19 09:54:15 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include <assert.h>


int main(void)
{
    int     fd;
    char    **m;
    t_data  map;

    int check_arr[5];
        
    char *no_close_map = "map/error_map/no_close.ber";
    char *no_exit_map = "map/error_map/no_exit.ber";
    char *no_item_map = "map/error_map/no_item.ber";
    char *no_rectangle = "map/error_map/no_rectangle.ber";
    char *no_start = "map/error_map/no_start.ber";
    char *nothing =  "map/error_map/nothing.ber";
    char *empty_space = "map/error_map/empty_space.ber";
    char *wrong_char =  "map/error_map/wrong_char.ber";
    char *empty_map =  "map/error_map/empty.ber";
    char *good_map =  "map/map1.ber";
    char *good_map2 =  "map/map2.ber";

    // NO CLOSE MAP
    fd = open(no_close_map, O_RDONLY);
    if (fd == -1)
    {
        printf("erreur  d'vouverture du fichier: %s \n", no_close_map );
        return (1);
    }
    ft_get_dimentions(fd, &map);
    
    assert(map.dimention.hauteur == 6);
    assert(map.dimention.largeur == 34);
    
    m = ft_parse_params(no_close_map, map.dimention.hauteur, map.dimention.largeur);
    assert(ft_check_params(m,check_arr,map.dimention.hauteur, map.dimention.largeur ) == 1);
    
    map.dimention.hauteur =  0;
    map.dimention.largeur =  0;
    ft_bzero(check_arr, 5 * sizeof(int));

    //NO EXIT MAP
    fd = open(no_exit_map, O_RDONLY);
    if (fd == -1)
    {
        printf("erreur  d'vouverture du fichier: %s \n", no_exit_map);
        return (1);
    }
    ft_get_dimentions(fd, &map);

    assert(map.dimention.hauteur == 3);
    assert(map.dimention.largeur == 9);

    m = ft_parse_params(no_exit_map, map.dimention.hauteur, map.dimention.largeur);

    assert(ft_check_params(m,check_arr,map.dimention.hauteur, map.dimention.largeur ) == 1);
    
    map.dimention.hauteur =  0;
    map.dimention.largeur =  0;
    ft_bzero(check_arr, 5 * sizeof(int));


    // NO ITEM
    fd = open(no_item_map, O_RDONLY);
    if (fd == -1)
    {
        printf("erreur  d'vouverture du fichier: %s \n", no_item_map);
        return (1);
    }
    ft_get_dimentions(fd, &map);

    assert(map.dimention.hauteur == 6);
    assert(map.dimention.largeur == 6);

    m = ft_parse_params(no_item_map, map.dimention.hauteur, map.dimention.largeur);

    assert(ft_check_params(m,check_arr,map.dimention.hauteur, map.dimention.largeur ) == 1);
    
    map.dimention.hauteur =  0;
    map.dimention.largeur =  0;
    ft_bzero(check_arr, 5 * sizeof(int));
    

    // NO ITEM
    fd = open(no_rectangle, O_RDONLY);
    if (fd == -1)
    {
        printf("erreur  d'vouverture du fichier: %s \n", no_rectangle);
        return (1);
    }
    ft_get_dimentions(fd, &map);

    assert(map.dimention.hauteur == 6);
    assert(map.dimention.largeur == 6);

    m = ft_parse_params(no_rectangle, map.dimention.hauteur, map.dimention.largeur);

    assert(ft_check_params(m,check_arr,map.dimention.hauteur, map.dimention.largeur ) == 1);
    
    map.dimention.hauteur =  0;
    map.dimention.largeur =  0;
    ft_bzero(check_arr, 5 * sizeof(int));

    // NO START
    fd = open(no_start, O_RDONLY);
    if (fd == -1)
    {
        printf("erreur  d'vouverture du fichier: %s \n", no_start);
        return (1);
    }
    
    ft_get_dimentions(fd, &map);
    assert(map.dimention.hauteur == 6);
    assert(map.dimention.largeur == 34);

    m = ft_parse_params(no_start, map.dimention.hauteur, map.dimention.largeur);

    assert(ft_check_params(m,check_arr,map.dimention.hauteur, map.dimention.largeur ) == 1);
    
    map.dimention.hauteur =  0;
    map.dimention.largeur =  0;
    ft_bzero(check_arr, 5 * sizeof(int));

    // NOTHING
    fd = open(nothing, O_RDONLY);
    if (fd == -1)
    {
        printf("erreur  d'vouverture du fichier: %s \n", nothing);
        return (1);
    }
    ft_get_dimentions(fd, &map);

    assert(map.dimention.hauteur == 12);
    assert(map.dimention.largeur == 12);

    m = ft_parse_params(nothing, map.dimention.hauteur, map.dimention.largeur);

    assert(ft_check_params(m,check_arr,map.dimention.hauteur, map.dimention.largeur ) == 1);
    
    map.dimention.hauteur =  0;
    map.dimention.largeur =  0;
    ft_bzero(check_arr, 5 * sizeof(int));

    //EMPTY SPACE
    fd = open(empty_space, O_RDONLY);
    if (fd == -1)
    {
        printf("erreur  d'vouverture du fichier: %s \n", empty_space);
        return (1);
    }
    ft_get_dimentions(fd, &map);

    assert(map.dimention.hauteur == 6);
    assert(map.dimention.largeur == 34);

    m = ft_parse_params(empty_space, map.dimention.hauteur, map.dimention.largeur);

    assert(ft_check_params(m,check_arr,map.dimention.hauteur, map.dimention.largeur ) == 1);
    
    map.dimention.hauteur =  0;
    map.dimention.largeur =  0;
    ft_bzero(check_arr, 5 * sizeof(int));
    //EMPTY SPACE
    fd = open(wrong_char, O_RDONLY);
    if (fd == -1)
    {
        printf("erreur  d'vouverture du fichier: %s \n", wrong_char);
        return (1);
    }
    ft_get_dimentions(fd, &map);

    assert(map.dimention.hauteur == 6);
    assert(map.dimention.largeur == 34);

    m = ft_parse_params(wrong_char, map.dimention.hauteur, map.dimention.largeur);

    assert(ft_check_params(m,check_arr,map.dimention.hauteur, map.dimention.largeur ) == 1);
    
    map.dimention.hauteur =  0;
    map.dimention.largeur =  0;
    ft_bzero(check_arr, 5 * sizeof(int));

    // GOOD MAP 1
    fd = open(good_map, O_RDONLY);
    if (fd == -1)
    {
        printf("erreur  d'vouverture du fichier: %s \n", good_map);
        return (1);
    }
    ft_get_dimentions(fd, &map);

    assert(map.dimention.hauteur == 6);
    assert(map.dimention.largeur == 34);

    m = ft_parse_params(good_map, map.dimention.hauteur, map.dimention.largeur);

    assert(ft_check_params(m,check_arr,map.dimention.hauteur, map.dimention.largeur ) == 0);
    
    map.dimention.hauteur =  0;
    map.dimention.largeur =  0;
    ft_bzero(check_arr, 5 * sizeof(int));

    // GOOD MAP 2
    fd = open(good_map2, O_RDONLY);
    if (fd == -1)
    {
        printf("erreur  d'vouverture du fichier: %s \n", good_map2);
        return (1);
    }
    ft_get_dimentions(fd, &map);

    assert(map.dimention.hauteur == 6);
    assert(map.dimention.largeur == 5);

    m = ft_parse_params(good_map2, map.dimention.hauteur, map.dimention.largeur);

    assert(ft_check_params(m,check_arr,map.dimention.hauteur, map.dimention.largeur ) == 0);
    
    map.dimention.hauteur =  0;
    map.dimention.largeur =  0;
    ft_bzero(check_arr, 5 * sizeof(int));

    // Empty MAP
    fd = open(empty_map, O_RDONLY);
    if (fd == -1)
    {
        printf("erreur  d'vouverture du fichier: %s \n", empty_map);
        return (1);
    }

    ft_get_dimentions(fd, &map);
    assert(map.dimention.hauteur == 0);
    assert(map.dimention.largeur == 0);

    m = ft_parse_params(empty_map, map.dimention.hauteur, map.dimention.largeur);
    assert(ft_check_params(m,check_arr,map.dimention.hauteur, map.dimention.largeur ) == 1);
    map.dimention.hauteur =  0;
    map.dimention.largeur =  0;
    ft_bzero(check_arr, 5 * sizeof(int));

    printf(" LES TEST CE SONT DEROULe AVEC SUCCESS\n");
}