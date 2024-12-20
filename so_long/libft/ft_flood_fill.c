/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:27:46 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/20 20:11:14 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	counter(void)
{
	static int counter;

	counter++;
	printf("voici le counter %d\n", counter);
}


void	fill_arr(char **tab, char **tmp, int target,t_point *size, int col, int row)
{
	if(col < 0 || row >= size->row || row < 0 ||  col  >= size->col )
		return ;
		
	if(tab[row][col] == 'B' || (tab[row][col] == '1' ))
		return ;

	if(tab[row][col] == 'C')
	{
		tab[row][col] = 'X';
		if(tmp[row][col] != 'X')
		{
			counter();
			tmp[row][col] = 'X';
			printf("item row %d,  col %d\n", row, col);
		}
	}
	else if(tab[row][col] != 'X')
		tab[row][col] = 'B';

	fill_arr(tab, tmp ,target, size, col, row - 1);
	fill_arr(tab, tmp ,target, size, col, row + 1);
	fill_arr(tab, tmp ,target, size, col - 1, row);
	fill_arr(tab, tmp ,target, size, col + 1, row);
}


void flood_fill(char **tab, t_point *size, t_point begin)
{
    int target;
	char **tmp;

	tmp = tab;
    target = tab[begin.row][begin.col];
    printf("target : %c, la haute %d et la largeur %d\n", target, size->col, size->row);
	fill_arr(tab, tmp ,target, size ,begin.col, begin.row);
	
}


char **make_area(char *zone[], t_point *size)
{
	int larg;
	int hauteur;
	int i;
	int k;
	int j;
	char **area;

	hauteur = size->row;
	larg = size->col;
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
		"1 C 0 0 1 0 0 1",
		"1 0 C 1 0 0 0 1",
		"1 0 1 1 0 0 0 1",
		"1 1 1 0 0 0 0 1",
	};
	
	area =  make_area(zone, &size);
	(void)area;
	
	int i = 0;
	int j;

	while (i < size.row)
	{
		j = 0;
		while (j < size.col)
		{
			printf("%c ", area[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	
	flood_fill(area, &size, begin);

	i = 0;

	while (i < size.row)
	{
		j = 0;
		while (j < size.col)
		{
			printf("%c ", area[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}