/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:02:02 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/13 18:36:54 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_fill_process(char **argv, int *arr)
{
	char	**split;
	int		i;

	i = 0;
	while (*argv)
	{
		if (ft_are_space(*argv))
		{
			split = ft_split(*argv, 32);
			while (*split)
			{
				*arr = ft_atoi(*split);
				free(*split);
				split++;
				arr++;
			}
		}
		else
		{
			*arr = ft_atoi(argv[i]);
			arr++;
		}
		argv++;
	}
	*arr = '\0';
}

int	*ft_parsing(char **argv, int len)
{
	int	*arr;

	arr = malloc(sizeof(int) * (len + 1));
	if (!arr)
		return (NULL);
	ft_fill_process(argv, arr);
	return (arr);
}

int	number_of_int(char **argv)
{
	int		i;
	int		count;
	char	**split;

	i = 0;
	count = 0;
	while (argv[i])
	{
		if (ft_are_space(argv[i]))
		{
			split = ft_split(argv[i], 32);
			while (*split)
			{
				count++;
				split++;
			}
		}
		else
			count++;
		i++;
	}
	return (count);
}

int	ft_are_space(char *str)
{
	while (*str)
	{
		if (*str == 32)
			return (1);
		str++;
	}
	return (0);
}

int	ft_check_repetition(int *arr, int len)
{
	int	i;
	int	j;
	int	tx;

	i = 0;
	tx = 0;
	while (i < len)
	{
		j = i + 1;
		if(arr[i] == arr[j])
			return (-1);
		if(arr[i] < arr[j])
			tx++;
		i++;
	}
	tx = (100 * tx) / (len - 1) ;
	return (tx);
}

int ft_validation_arg(char **argv)
{
	char *tmp;
	int digits;
	
	while (*argv)
	{
		tmp = *argv;
		digits = 0;
		while (*tmp)
		{
			if(!ft_isdigit(*tmp) && *tmp != 32 && *tmp != 45)
				return(1);
			if(ft_isdigit(*tmp))
				digits++;
			tmp++;
		}
		if (digits == 0)
			return (1);
		argv++;
	}
	return (0);  
}

void    ft_print_arr(int *arr)
{
	int i;

	i = 0;
	while (arr && arr[i] != '\0')
		printf(" %d", arr[i++]);
	printf("\n");
}

int ft_print_error()
{
	write(1, "ERROR", 5);
	return (1);
}

void    ft_two_args(int *arr)
{
	if(arr[0] > arr[1])
		ft_swap(arr, 0, 1, 'a');
}

void    ft_two_or_tree_args(int *arr, int len)
{
	if (len == 2)
	{
		if(arr[0] > arr[1])
			ft_swap(arr, 0, 1, 'a');
	} 
	else if(len == 3)
	{
		if(arr[0] > arr[1])
			ft_swap(arr, 0, 1, 'a');
		if(arr[2] < arr[0])
			ft_rotate(arr, 'a');
		if(arr[1] > arr[2])
		{
			ft_reverse_rotate(arr, 'a');
			ft_swap(arr, 0, 1, 'a');
		}
	}
}

int ft_size_of_array(int *arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);

}
