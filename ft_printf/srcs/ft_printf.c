/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:20:25 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/10/25 01:36:40 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	process_print(char k, va_list *lst)
{
	int	result;

	if (k == 'c')
		result = ft_putchar(va_arg(*lst, int), 1);
	if (k == 's')
		result = ft_putstr(va_arg(*lst, char *), 1);
	if (k == 'u')
		result = ft_put_nbr_uns(va_arg(*lst, unsigned int), 1, 1);
	if (k == 'i' || k == 'd')
		result = ft_putnbr(va_arg(*lst, int), 1, 1);
	if (k == 'p')
		result = ft_print_ptr(va_arg(*lst, void *), 1);
	if (k == 'X')
		result = ft_putnbr_hex(va_arg(*lst, int), 1, 'X');
	if (k == 'x')
		result = ft_putnbr_hex(va_arg(*lst, int), 1, 'x');
	if (k == '%')
		result = ft_putchar('%', 1);
	if (result == -1)
		return (-1);
	return (result);
}

static int	dispatch_print(char c, va_list *lst, int *acc)
{
	int	result;

	result = process_print(c, lst);
	if (result == -1)
		return (-1);
	*acc += result;
	return (0);
}

static int	print_string(char c, int *acc)
{
	int	result;

	result = ft_putchar(c, 1);
	if (result == -1)
		return (-1);
	*acc += result;
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		result;
	va_list	ap;

	va_start(ap, format);
	result = 0;
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			if (ft_isset(*(format + 1), "cspdiuxX%"))
			{
				if (dispatch_print(*(format + 1), &ap, &result) == -1)
					return (-1);
				format++;
			}
		}
		else
			if (print_string(*format, &result) == -1)
				return (-1);
		format++;
	}
	va_end (ap);
	return (result);
}
