/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:07:21 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/11 11:15:23 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	ft_init_sigaction(struct sigaction *action)
{
	if (sigaction(SIGUSR1, action, NULL) == -1)
		return (-1);
	if (sigaction(SIGUSR2, action, NULL) == -1)
		return (-1);
	return (0);
}

void	ft_process_end_send_confirmation(char **str, int pid_client)
{
	ft_printf("%s\n", *str);
	kill(pid_client, SIGUSR2);
	usleep(SLEEP_TIME);
	*str = NULL;
	free(*str);
}

void	ft_handler(int sig, siginfo_t *info, void *context)
{
	int			pid_client;
	static char	*str = NULL;
	static int	bit = 7;
	static int	j = 0;

	if (sig == 31)
		j = j | (1 << bit);
	pid_client = info->si_pid;
	if (--bit < 0)
	{
		if (j == 0)
			ft_process_end_send_confirmation(&str, pid_client);
		else
			str = ft_clean_alloc(str, j);
		j = 0;
		bit = 7;
	}
	(void)context;
}

int	main(void)
{
	struct sigaction	action;
	sigset_t			set;
	pid_t				pid_serveur;

	sigemptyset(&set);
	sigaddset(&set, SIGINT);
	action.sa_sigaction = ft_handler;
	action.sa_mask = set;
	action.sa_flags = SA_SIGINFO;
	pid_serveur = getpid();
	ft_printf("Serveur PID : %d.\nEn attente d'un message...\n", pid_serveur);
	if (ft_init_sigaction(&action) == -1)
		return (1);
	while (1)
		sleep(1);
	return (0);
}
