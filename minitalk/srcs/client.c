/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:43:21 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/09 14:40:33 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_handler(int sig, siginfo_t *info, void *context)
{
	int pid;

	pid = info->si_pid;
	(void)context;
	if(sig == SIGUSR1)
		ft_printf("size bien recu par le serveur. Alloctation ok");
	if(sig == SIGUSR2)
		ft_printf("Message bien affiché par le serveur");
}

void	send_message(int pid,char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_send_int_to_pid(str[i++], pid, 200);
	
}

int main(int argc, char **argv)
{
	struct sigaction action;
	int	pid;
	int	i;

	i = 2;
	if(argc == 1)
		return (1);
	pid = ft_atoi(argv[1]);
	action.sa_flags = SA_SIGINFO;
	action.sa_mask = 0;
	action.sa_sigaction = ft_handler;

	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);

	if(sigaction(SIGUSR1, &action, NULL) == -1 || sigaction(SIGUSR2, &action, NULL) == -1)
    {
        ft_printf("erreur\n");
        return (1);
    }

	while (argv[i])
	{
		send_message(pid, argv[i]);
		ft_send_end_signal(pid, 150);

		i++;
	}
	return (0);
}