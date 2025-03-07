/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:21:26 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/07 16:51:31 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_print_arr_int(int *arr, int len)
{
	int i;

	i = 0;
	while(i < len)
		printf("%d ", arr[i++]);
	printf("\n");
	
}
void	ft_print_arr_str(char **arr, int len)
{
	int i;

	i = 0;
	while(i < len)
		printf("%s ", arr[i++]);
	printf("\n");
	
}

void	ft_printm(int **arr, int row, int col)
{
	int i;
	int j;

	i = 0;
	while(i < row)
	{
		j = 0;
		while (j < col)
		{
			printf("%d ", arr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
int ft_memcpy(void *src, void *dst, int size)
{
	int i;
	unsigned char *s;
	unsigned char *d;

	if(!src || !dst)
		return(0);
	i = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	while (i  < size)
	{
		printf("voici size %d\n", i);
		d[i] = s[i];
		i++;
	}
	DEBUGG;
	return(i);
	
}