/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_layer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:43:22 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/05 16:46:49 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/error_managment.h"

char *error_return(int error)
{
	if (error == 0)
		return("[ err ] Aucune map passée en paramètre");
	if (error == 2)
		return("[ err ] probleme d'initialisation de la structure data\n");
	if (error == 2)
		return("[ err ] probleme d'initialisation de la map\n");
	if (error == 3)
		return("[ err ] probleme avec les parametre de la map\n");
	if (error == 4)
		return("[ err ] Pas de chemin valide\n");
	if (error == 5)
		return("[ err ] Probleme d'initialisation du pointeur mlx\n");
	if (error == 6)
		return("[ err ] Probleme d'initialisation du set image\n");
	if (error == 7)
		return("[ err ] Probleme screen size \n");
	if (error == 8)
		return("[ err ] Erreur d'initialisation de la mlx ou de la fenetre");
	if (error == 16)
		return("[ err ] Erreur ouverture file logs\n");
	return (NULL);
}

int error_layer(int err)
{
	char	*error_msg;
	int		fd;
	int		w;

	error_msg = error_return(err);
	if(error_msg)
		printf("%s\n", error_msg);
	else
	{
		error_msg = "le code d'erreur n'est pas dans le scope\n";
		printf("%s\n",error_msg);
	}
	if(err != ERR_OPEN_LOG && err != ERR_WRITE_LOG)
	{
		fd = open("src/error_managment/log/log", O_APPEND | O_CREAT | O_WRONLY, 0644);
		if(fd == -1)
			error_layer(ERR_OPEN_LOG);
		else
		{
			w = write(fd, error_msg, ft_strlen(error_msg));
			if (w != (int)ft_strlen(error_msg))
				error_layer(ERR_WRITE_LOG);
		}
	}
	return(1);
}

