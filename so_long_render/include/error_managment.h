/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_managment.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:13:54 by cb                #+#    #+#             */
/*   Updated: 2025/01/05 16:40:13 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ERROR_MANAGMENT_H
#define ERROR_MANAGMENT_H

#include "so_long.h"
#include <fcntl.h> 

#define ERR_VALIDE_WAY 4
#define ERR_OPEN_LOG 16 
#define ERR_WRITE_LOG 17 
#define ERR_SCOPE 16 


int error_layer(int err);

#endif