/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:29:43 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/10/25 03:44:11 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putnbr(int nb, int fd, int acc)
{
	int		result;
	char	*arr;

	arr = "0123456789abcdef";
	if (nb == -2147483647 - 1)
		return (ft_putstr("-2147483648", 1));
	if (nb < 0)
	{
		nb = -nb;
		result = ft_putchar('-', 1);
		if (result == -1)
			return (-1);
		acc++;
	}
	if (nb >= 10)
	{
		result = ft_putnbr(nb / 10, fd, acc + 1);
		if (result == -1)
			return (-1);
		acc = result;
	}
	if (ft_putchar(arr[nb % 10], 1) == -1)
		return (-1);
	return (acc);
}
