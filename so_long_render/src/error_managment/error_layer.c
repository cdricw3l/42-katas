/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_layer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:43:22 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/06 12:05:32 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/error_managment.h"

char *error_return(int error)
{
	if (error == ERR_NO_MAP)
		return("[ err ] Aucune map passée en paramètre");
	if (error == ERR_STRUC_INIT)
		return("[ err ] probleme d'initialisation de la structure data\n");
	if (error == ERR_MLX)
		return("[ err ] Probleme d'initialisation du pointeur mlx\n");
	if (error == ERR_IMG_SET)
		return("[ err ] Probleme d'initialisation du set image\n");
	if (error == ERR_SCREEN)
		return("[ err ] Probleme screen size \n");
	if (error == ERR_GET_MAP)
		return("[ err ] Map vide ou path incorrect\n");
	if (error == ERR_CHECK_MAP)
		return("[ err ] probleme avec les parametre de la map\n");
	if (error == ERR_NO_WAY)
		return("[ err ] Pas de chemin valide\n");
	if (error == ERR_ALLOC_IMG)
		return("Erreur creation structures image\n");
	if (error == ERR_GET_IMGPATH)
		return("[ err ] proble de recuperation des path\n");
	if (error == ERR_IMG_LOADING)
		return("[ err ] Erreur chargement des images \n");
	if (error == ERR_LINE_LEN)
		return("[ err ] Une ligne de la map est de taille differente \n");
	if (error == ERR_NOTCLOSE)
		return("[ err ] La map n'est pas close\n");
	if (error == ERR_NOTINSET)
		return("[ err ] Un element de la map ne fait pas parti du set\n");
	if (error == ERR_DUPLICATE)
		return("[ err ] Deux position de depart ou deux exit sur la map\n");
	if (error == ERR_FRAME)
		return("[ err ] probleme creation de la nouvelle frame\n");
	if (error == 6)
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

