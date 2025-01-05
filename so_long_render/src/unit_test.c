/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:51:28 by cb                #+#    #+#             */
/*   Updated: 2025/01/05 16:12:37 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int error_layer_test(void)
{
    int i = -1;
    int count;

    while (i < ERR_SCOPE + 10)
       count =  error_layer(i++);
    return(count); 
}
int main(void)
{
    printf("%d\n",error_layer_test());
    return (0);
}
