/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr_uns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:46:34 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/10/25 01:36:45 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_put_nbr_uns(unsigned int nb, int fd, int acc)
{
	int		result;
	char	*arr;

	arr = "0123456789abcdef";
	if (nb >= 10)
	{
		result = ft_put_nbr_uns(nb / 10, fd, acc + 1);
		if (result == -1)
			return (-1);
		acc = result;
	}
	if (ft_putchar(arr[nb % 10], 1) == -1)
		return (-1);
	return (acc);
}
