/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:56:23 by cb                #+#    #+#             */
/*   Updated: 2025/01/05 14:56:24 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:43:22 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/05 06:18:37 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*ft_error_img(int e)
{
	if(e == 1)
		printf("Erreur creation structure image\n");
	if(e == 2)
		printf("probleme recuperation de l'imaged (path)\n");
	if(e == 3)
		printf("probleme recuperation data addr\n");
	if(e == 4)
		printf("probleme initialisation arr path\n");
	if(e == 5)
		printf(" voir error 1 2 ou 3\n");
	return(NULL);
}
	
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
		data = initialisation_and_check(argv[1]);
		if (data)
		{		
			ft_display_data_info(data);
			start_game(&data);
			ft_free_memory(data, 13);
		}
		else
		{
			perror(ft_error_return(3));
			return (1);
		}
	}
	return (0);
}
