/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:53:07 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/15 12:53:06 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

int	ft_parsing(char **argv, t_pile *stack)
{
	char	**split;
	int		i;

	i = 0;
	while (*argv)
	{
		if (ft_find_space(*argv))
		{
			split = ft_split(*argv, 32);
			while (*split)
			{
				stack->arr[i] = ft_atoi(*split);
				free(*split);
				split++;
				i++;
			}
		}
		else
		{
			stack->arr[i] = ft_atoi(*argv);
			i++;
		}
		argv++;
	}
	return (0);
}

int	ft_check_repetition(t_pile *stack)
{
	int	i;
	int	j;
	int	tx;

	i = 0;
	tx = 0;
	while (i < stack->len - 1)
	{
		j = i + 1;
		if(stack->arr[i] == stack->arr[j])
			return (-1);
		if(stack->arr[i] < stack->arr[j])
			tx++;
		i++;
	}
	tx = (100 * tx) / (stack->len - 1) ;
	return (tx);
}

int	ft_get_number_of_int(char **argv)
{
	int		i;
	int		count;
	char	**split;

	i = 0;
	count = 0;
	while (argv[i])
	{
		if (ft_find_space(argv[i]))
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