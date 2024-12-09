/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:34:33 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/09 14:41:45 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

#include "ft_printf.h"
#include "libft.h"

#include <unistd.h>
#include <stdio.h>
#include <assert.h>
#include <signal.h>

int	    ft_strlen(char *str);
char    *ft_strjoin_char(char *str, char c);
void    ft_print_bit(int n);
void	ft_send_int_to_pid(int n, int pid, int ms);
void	ft_send_separator(int pid, int ms);
void	ft_send_end_signal(int pid, int ms);

#endif