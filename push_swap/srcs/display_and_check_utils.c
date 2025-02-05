/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_and_check_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:02:02 by cw3l              #+#    #+#             */
/*   Updated: 2025/02/05 12:32:57 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <assert.h>

int	ft_print_error(void)
{
	write(1, "Error", 5);
	write(1, "\n", 1);
	return (1);
}

int	ft_find_space(char *str)
{
	while (*str)
	{
		if (*str == 32)
			return (1);
		str++;
	}
	return (0);
}

int	ft_is_bigger_than_intmax(char *argv)
{
	char	*tmp;

	tmp = malloc(2);
	if (!tmp)
		return (1);
	if (argv[0] != '-')
	{
		if (ft_strlen(argv) > 10)
			return (1);
		else if (ft_strlen(argv) == 10)
		{
			tmp[0] = argv[9];
			tmp[1] = '\n';
			if (ft_atoi(tmp) > 7)
			{
				free(tmp);
				return (1);
			}
		}
	}
	free(tmp);
	return (0);
}

int	ft_is_less_than_intmin(char *argv)
{
	char	*tmp;

	tmp = malloc(2);
	if (!tmp)
		return (1);
	if (argv[0] == '-')
	{
		if (ft_strlen(argv) > 11)
			return (1);
		else if (ft_strlen(argv) == 11)
		{
			tmp[0] = argv[10];
			tmp[1] = '\n';
			if (ft_atoi(tmp) > 8)
			{
				free(tmp);
				return (1);
			}
		}
	}
	free(tmp);
	return (0);
}
