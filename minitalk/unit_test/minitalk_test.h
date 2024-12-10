/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_test.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:34:33 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/10 21:14:56 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

#include "ft_printf.h"
#include "libft.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <signal.h>

#define SLEEP_TIME 40

int	    ft_strlen(char *str);
char    *ft_joint_char(char *str, char c);
void    ft_print_bit_test(int n);
char	*ft_send_end_signal_test( int ms);
char	*ft_clean_alloc(char *old_ptr, int c);
char	*ft_send_separator_test( int ms);
char	*ft_send_int_to_pid_test(int n, int ms);

#endif