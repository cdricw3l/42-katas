/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:24:58 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/10 21:43:13 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_test.h"

void	ft_print_bit_test(int n)
{
	int	bit;

	bit = 15;
	while (bit >= 0)
	{
		ft_printf("%c", ((n >> bit) & 1) + '0');
		bit--;
	}
	ft_printf("\n");
}

char	*ft_send_end_signal_test( int ms)
{
	int	bit;
    char *str = malloc(9);
	if(!str)
		return(NULL);
    int i;

	bit = 15;
    i = 0;
	while (bit >= 0)
	{
		usleep(ms);
		str[i] = (SIGUSR1 - 30) + '0';
		bit--;
        i++;
	}
    str[i] = '\0';
	return(str);
}

char	*ft_send_separator_test( int ms)
{
	int	bit;
    char *str = malloc(9);
	if(!str)
		return(NULL);
    int i;

	bit = 15;
    i = 0;
	while (bit >= 0)
	{
		usleep(ms);
		str[i] = (SIGUSR1 - 30) + '0';
		bit--;
        i++;
	}
    str[i] = '\0';
    return (str);
}

char	*ft_send_int_to_pid_test(int n, int ms)
{
	int	bit;
     char *str = malloc(17);
	if(!str)
		return(NULL);
    int i;

	bit = 15;
    i = 0;
	while (bit >= 0)
	{
		if (((n >> bit) & 1) == 0)
		{
			usleep(ms);
			str[i] = (SIGUSR1 - 30) + '0';
		}
		else
		{
			usleep(ms);
			str[i] = (SIGUSR2 - 30) + '0';
		}
		bit--;
        i++;
	}
    str[i] = '\0';
    return (str);
}