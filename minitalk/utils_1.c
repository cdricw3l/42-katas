 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:33:15 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/09 11:29:36 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_char(char *str, char c)
{
	int		len;
	char	*new_str;
	int		i;

	i = 0;
	len = ft_strlen(str);
	new_str = malloc(sizeof(char) * (len + 2));
	if (!new_str)
		return (NULL);
	while (i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i++] = c;
	new_str[i] = '\0';
	return (new_str);
}

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
		kill(pid, SIGUSR1);
		usleep(ms);
		bit--;
	}
}

void	ft_send_separator(int pid, int ms)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		kill(pid, SIGUSR2);
		usleep(ms);
		bit--;
	}
}

void	ft_send_int_to_pid(int n, int pid, int ms)
{
	int	bit;
	(void)pid;
	bit = 7;
	while (bit >= 0)
	{
		if (((n >> bit) & 1) == 0)
		{
			kill(pid, SIGUSR1);
			ft_printf("%d ", 0);
			usleep(ms);
		}
		else
		{
			kill(pid, SIGUSR2);
			ft_printf("%d ", 1);
			usleep(ms);
		}
		bit--;
	}
}
