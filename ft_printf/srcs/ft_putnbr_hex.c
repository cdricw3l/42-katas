/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:04:03 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/10/25 01:38:10 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_process_hex(unsigned int nb, int fd, int acc, char k)
{
	char	*arr;
	int		result;

	arr = "0123456789abcdef";
	if (nb >= 16)
	{
		result = ft_process_hex(nb / 16, fd, acc + 1, k);
		if (result == -1)
			return (-1);
		acc = result;
	}
	if (k == 'X')
	{
		if (ft_putchar(ft_toupper(arr[nb % 16]), fd) == -1)
			return (-1);
	}
	else
	{
		if (ft_putchar(arr[nb % 16], fd) == -1)
			return (-1);
	}
	return (acc);
}

int	ft_putnbr_hex(int nb, int fd, char k)
{
	int				result;
	unsigned int	nbr;

	nbr = (unsigned int)nb;
	result = ft_process_hex(nbr, fd, 1, k);
	if (result == -1)
		return (-1);
	return (result);
}
