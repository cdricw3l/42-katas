/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:34:33 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/11 11:14:22 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

# define SLEEP_TIME 60
# define BIT_SIZE 7

int		ft_strlen(char *str);
char	*ft_joint_char(char *str, char c);
void	ft_print_bit(int n);
void	ft_send_int_to_pid(int n, int pid, int ms);
void	ft_send_separator(int pid, int ms);
void	ft_send_end_signal(int pid, int ms);
char	*ft_clean_alloc(char *old_ptr, int c);
void	ft_send_separator(int pid, int ms);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

#endif