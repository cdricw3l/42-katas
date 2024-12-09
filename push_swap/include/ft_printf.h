/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:10:32 by cw3l              #+#    #+#             */
/*   Updated: 2024/10/24 17:38:26 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <assert.h>
# include <unistd.h>
# include <libc.h>
# include <ctype.h>
# include <string.h>

# define CHAR 99
# define STR 115
# define PTR 112
# define HEX_L 120
# define HEX_U 88
//777/////777///777////777//777//
// # define INT_MIN -2147483648
// # define INT_MAX 2147483647
// # define LONG_MIN -9223372036854775808
// # define LONG_MAX 9223372036854775807
// # define UINT_MAX = 4294967295

int		ft_toupper(int c);
size_t	ft_strlen(const char *s);
int		ft_putchar_fd(char c, int fd);
int		ft_printptr(void *ptr, int fd, int base);
int		ft_put_uns(unsigned int nb, int fd, int stock);
int		ft_printf(const char *str, ...);
int		ft_putnbr_base(unsigned int nb, int fd, int stock, char k);
int		ft_putstr(char *str, int fd);
int		ft_isset(char c, char const *set);
int		ft_putnbr(int nb, int fd, int stock);

# define print_str(msg) printf("%s\n",msg)
# define print_size(msg) printf("voici le int %zu\n",msg)
# define print_int(msg) printf("voici le int %i\n",msg)
# define print_ptr(msg) printf("voici le int %p\n",msg)
# define print_char(msg) printf("%c\n",msg)
# define print_float(msg) printf("voici le float %f\n",msg)
# define print_hex(msg) printf("voici le float %x\n",msg)
#endif