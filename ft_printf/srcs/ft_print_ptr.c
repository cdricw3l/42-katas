/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:56:43 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/10/25 01:37:48 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_put_ptr(unsigned long nb, int fd, int acc)
{
	int		result;
	char	*arr;

	arr = "0123456789abcdef";
	if (nb >= 16)
	{
		result = ft_put_ptr(nb / 16, fd, acc + 1);
		if (result == -1)
			return (-1);
		acc = result;
	}
	if (ft_putchar(arr[nb % 16], fd) == -1)
		return (-1);
	return (acc);
}

int	ft_print_ptr(void *ptr, int fd)
{
	long	p;
	int		result;

	p = (unsigned long)ptr;
	if (ft_putstr("0x", fd) == -1)
		return (-1);
	result = ft_put_ptr(p, fd, 1);
	if (result == -1)
		return (-1);
	result += 2;
	return (result);
}
