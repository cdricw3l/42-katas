/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_and_verification.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:53:07 by cw3l              #+#    #+#             */
/*   Updated: 2025/02/05 12:29:55 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_validation_arg(char **argv)
{
	char	*tmp;
	int		digits;

	while (*argv)
	{
		tmp = *argv;
		digits = 0;
		if (ft_is_bigger_than_intmax(*argv) || ft_is_less_than_intmin(*argv))
			return (1);
		while (*tmp)
		{
			if (!ft_isdigit(*tmp) && *tmp != 32 && *tmp != 45)
				return (1);
			if (ft_isdigit(*tmp))
				digits++;
			tmp++;
		}
		if (digits == 0)
			return (1);
		argv++;
	}
	return (0);
}

int	ft_parsing(char **argv, t_stack *stack)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	while (*argv)
	{
		if (ft_find_space(*argv))
		{
			j = 0;
			split = ft_split(*argv, 32);
			while (split[j])
			{
				stack->arr[i] = ft_atoi(split[j]);
				free(split[j]);
				i++;
				j++;
			}	
			free(split);
		}
		else
			stack->arr[i++] = ft_atoi(*argv);
		argv++;
	}
	return (0);
}

int	ft_check_repetition(t_stack *stack)
{
	int	i;
	int	j;
	int	tx;

	i = 0;
	tx = 0;
	while (i < stack->len - 1)
	{
		j = i + 1;
		while (j < stack->len)
		{
			if (stack->arr[i] == stack->arr[j])
				return (-1);
			if (stack->arr[i] < stack->arr[j])
				tx++;
			j++;
		}
		i++;
	}
	tx = (100 * tx) / (stack->len - 1);
	return (tx);
}

int	ft_get_number_of_int(char **argv)
{
	int		i;
	int		j;
	int		count;
	char	**split;

	i = 0;
	count = 0;
	while (argv[i])
	{
		if (ft_find_space(argv[i]))
		{
			split = ft_split(argv[i], 32);
			j = 0;
			while (split[j])
			{
				count++;
				free(split[j++]);
			}
			free(split);
		}
		else
			count++;
		i++;
	}
	return (count);
}
