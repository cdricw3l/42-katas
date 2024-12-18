/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:27:46 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/18 08:36:26 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fill_arr()
{
	
}


void flood_fill(char **tab, t_point *size, t_point begin)
{
    int target;

    target = tab[begin.y][begin.x];
    printf("target : %c, la haute %d et la largeur %d\n", target, size->y, size->x);
	//fill_arr(tab, size, target);
	
}


char **make_area(char *zone[], t_point *size)
{
	int larg;
	int hauteur;
	int i;
	int k;
	int j;
	char **area;

	hauteur = size->y;
	larg = size->x;
	printf("voici la hauteur : %d et voici la largeur %d\n",hauteur, larg);
	i = 0;
	k = 0;
	area = malloc(sizeof(char *) * hauteur);
	if(!area)
	{
		printf("erreur\n");
		return (NULL);
	}
	while (i < hauteur)
	{
		j = 0;
		k = 0;
		area[i] = malloc(sizeof(char *) * larg);
		if(!area[i])
		{
			printf("erreur\n");
			return (NULL);
		}
		while (j < larg)
		{
			area[i][j] = zone[i][k];
			j++;
			k += 2;
		}
		i++;
	}
	return(area);
}

int main(void)
{
	char **area;
	t_point size = {8, 5};
	t_point begin = {2, 2};
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 1 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 1 1 0 0 0 1",
		"1 1 1 0 0 0 0 1",
	};
	
	area =  make_area(zone, &size);
	(void)area;
	
	int i = 0;
	int j;

	while (i < size.y)
	{
		j = 0;
		while (j < size.x)
		{
			printf("%c ", area[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	flood_fill(area, &size, begin);
	return (0);
}