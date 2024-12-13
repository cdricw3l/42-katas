/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:26:03 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/11 09:35:48 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

void	ft_print_bit(int n)
{
	int	bit;

	bit = BIT_SIZE;
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

	bit = BIT_SIZE;
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

	bit = BIT_SIZE;
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

	bit = BIT_SIZE;
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
