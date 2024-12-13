/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:47:39 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/10/25 03:45:45 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putstr(char *str, int fd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str)
		return (ft_putstr("(null)", fd));
	while (*str)
	{
		i = ft_putchar(*str, fd);
		if (i == -1)
			return (-1);
		j += i;
		str++;
	}
	return (j);
}
