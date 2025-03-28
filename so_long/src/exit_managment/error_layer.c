/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_layer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:43:22 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/17 11:56:37 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/error_managment.h"

static char	*error_return_2(int error)
{
	if (error == ERR_LINE_LEN)
		return ("[ err ] Une ligne de la map est de taille differente \n");
	if (error == ERR_NOTCLOSE)
		return ("[ err ] La map n'est pas close\n");
	if (error == ERR_NOTINSET)
		return ("[ err ] Un element de la map ne fait pas parti du set\n");
	if (error == ERR_DUPLICATE)
		return ("[ err ] Deux position de depart ou deux exit sur la map\n");
	if (error == ERR_FRAME)
		return ("[ err ] probleme creation de la nouvelle frame\n");
	if (error == ERR_WIN)
		return ("[ err ] Erreur d'initialisation de la mlx ou de la fenetre");
	if (error == ERR_NO_ITEM)
		return ("[ clean ]  Pas d'item du la carte\n");
	if (error == ERR_SIZE)
		return ("[ clean ]  La map n'est pas a la bonne dimention\n");
	if (error == WIN_GAME)
		return ("[ clean ]  PROGRAMME TERMEINNER AVEC SUCCES\n");
	if (error == ERR_ALLOC_DATA)
		return ("[ err ] Aucune map passée en paramètre");
	if (error == ERR_DRAW)
		return ("[ err ] Probleme avec la fonction de dessin");
	return (NULL);
}

static char	*error_return_1(int error)
{
	if (error == ERR_NO_MAP)
		return ("[ err ] Aucune map passée en paramètre");
	if (error == ERR_STRUC_INIT)
		return ("[ err ] probleme d'initialisation de la structure data\n");
	if (error == ERR_MLX)
		return ("[ err ] Probleme d'initialisation du pointeur mlx\n");
	if (error == ERR_IMG_SET)
		return ("[ err ] Probleme d'initialisation du set image\n");
	if (error == ERR_SCREEN)
		return ("[ err ] Probleme screen size \n");
	if (error == ERR_GET_MAP)
		return ("[ err ] Map vide ou path incorrect\n");
	if (error == ERR_CHECK_MAP)
		return ("[ err ] probleme avec les parametre de la map\n");
	if (error == ERR_NO_WAY)
		return ("[ err ] Pas de chemin valide\n");
	if (error == ERR_ALLOC_IMG)
		return ("Erreur creation structures image\n");
	if (error == ERR_GET_IMGPATH)
		return ("[ err ] proble de recuperation des path\n");
	if (error == ERR_IMG_LOADING)
		return ("[ err ] Erreur chargement des images \n");
	return (NULL);
}

int	error_layer(int err)
{
	char	*error_msg;
	int		fd;
	int		w;

	if (err <= 11)
		error_msg = error_return_1(err);
	else
		error_msg = error_return_2(err);
	if (error_msg)
		ft_printf("%s\n", error_msg);
	if (err != ERR_OPEN_LOG && err != ERR_WRITE_LOG)
	{
		fd = open("src/exit_managment/log/log", O_APPEND
				| O_CREAT
				| O_WRONLY, 0644);
		if (fd == -1)
			error_layer(ERR_OPEN_LOG);
		else
		{
			w = write(fd, error_msg, ft_strlen(error_msg));
			if (w != (int)ft_strlen(error_msg))
				error_layer(ERR_WRITE_LOG);
		}
	}
	return (1);
}
