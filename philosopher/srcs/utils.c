/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:21:26 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/02/20 10:51:04 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_isdigit(char c)
{
	if(c < 48 || c > 57)
		return (0);
	return(1);
}

int	ft_atoi_long(char *argv)
{
	long result;
	int i;

	result = 0;
	i = 0;
	if(!argv)
		return(-1);
	
	while (argv[i])
	{

		if(!ft_isdigit(argv[i]))
			return (-1);
		result = ((result * 10) + (argv[i] - '0'));
		if(result > INT_MAX)
			return (-1);
		i++;
	}
	return(result);
}

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
int	*ft_init_arr_arg(char **argv, int len)
{
	int *arr;
	int i;

	if(!argv)
		return(NULL);
	arr = malloc(sizeof(int) * 6);
	if(!arr)
		return(NULL);
	i = 0;
	while (i < len)
	{
		arr[i] = ft_atoi_long(argv[i]);
		if(arr[i] == -1)
		{
			printf("Programme argument error\n");
			free(arr);
			return (NULL);
		}
		i++;
	}
	return (arr);
}
