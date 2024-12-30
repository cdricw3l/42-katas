/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:43:22 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/30 18:10:13 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char *argv[])
{
	t_data		*data;

	if (argc != 2)
	{
		perror(ft_error_return(1));
		return (1);
	}
	else
	{
		data = init_and_check(argv[1]);
		if (data)
		{
			ft_check_valide_way(data->game_data);
			ft_display_data_info(data);
			
			ft_free_memory(data);
		}
		else
		{
			perror(ft_error_return(3));
			return (1);
		}
	}
	return (0);
}
