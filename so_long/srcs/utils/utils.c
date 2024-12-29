/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:43:22 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/29 13:34:00 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	*ft_free_memory(t_data *data)
{
	free(data->img);
	free(data->game_data);
	free(data->check_list);
	free(data);
	return (NULL);
}