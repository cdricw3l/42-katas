/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:51:35 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/11 09:15:10 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

int	ft_isspace(int c)
{
	if (c == '\n' || c == '\t' || c == '\v' || c == '\f'
		|| c == '\r' || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	is_neg;
	int		result;

	i = 0;
	is_neg = 0;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
	{
		if (str[i] == '-')
			is_neg = 1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	if (is_neg)
		return (-result);
	return (result);
}

int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57))
		return (1);
	return (0);
}
