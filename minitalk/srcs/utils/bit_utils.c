/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:26:03 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/10 19:29:25 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

void	ft_print_bit(int n)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		ft_printf("%c ", ((n >> bit) & 1) + '0');
		bit--;
	}
	ft_printf("\n");
}

void	ft_send_end_signal(int pid, int ms)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		usleep(ms);
		kill(pid, SIGUSR1);
		bit--;
	}
}

void	ft_send_separator(int pid, int ms)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		usleep(ms);
		kill(pid, SIGUSR2);
		bit--;
	}
}

void	ft_send_int_to_pid(int n, int pid, int ms)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (((n >> bit) & 1) == 0)
		{
			usleep(ms);
			kill(pid, SIGUSR1);
		}
		else
		{
			usleep(ms);
			kill(pid, SIGUSR2);
		}
		bit--;
	}
}