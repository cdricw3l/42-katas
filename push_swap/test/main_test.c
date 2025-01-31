/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dispatch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:14:58 by cw3l              #+#    #+#             */
/*   Updated: 2024/11/18 16:00:50 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

int main(void)
{
    ft_printf("Test de rotation du mouvement et de liberation de memoire\n\n");
    
    assert(rotation_test() == 0);
    
    ft_printf("Test de rotation du mouvement et de liberation de memoire OK\n\n");

    return(0);
}