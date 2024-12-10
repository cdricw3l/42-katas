/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:45:57 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/09 16:57:02 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c, int fd);
int	ft_putstr(char *str, int fd);
int	ft_put_nbr_uns(unsigned int nb, int fd, int acc);
int	ft_putnbr(int nb, int fd, int acc);
int	ft_print_ptr(void *ptr, int fd);
int	ft_printf(const char *format, ...);
int	ft_isset(char c, const char *set);
int	ft_toupper(int c);
int	ft_putnbr_hex(int nb, int fd, char k);

#endif