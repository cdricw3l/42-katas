/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:21:26 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/02/18 15:33:21 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_isdigit(char c)
{
	if(c < 48 || c > 57)
		return (0);
	return(1);
}

long	ft_atoi_long(char *argv)
{
	long result;
	int i;

	result = 0;
	i = 0;
	if(!argv)
		return(-1);
	if(!ft_isdigit(argv[i]))
		return (-1);
	while (argv[i])
	{
		result = ((result * 10) + (argv[i] - '0'));
		i++;
	}
	return(result);
}

void	ft_print_arr_long(long *arr, int len)
{
	int i;

	i = 0;
	while(i < len)
		printf("%ld ", arr[i++]);
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
long	*ft_init_arr_arg(char **argv, int len)
{
	long *arr;
	int i;

	arr = malloc(sizeof(long) * 6);
	if(!arr)
		return(NULL);
	i = 0;
	while (i < len)
    {
        arr[i] = ft_atoi_long(argv[i]);
		if(i < 5)
        	assert(arr[i] != -1);
        i++;
    }
	return (arr);
}