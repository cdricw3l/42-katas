/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:07:21 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/09 14:53:15 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_handler(int sig, siginfo_t *info, void *context)
{
	int pid_client;
    (void)context;
    char *tmp;
    static char *str;
    static int bit = 7;
    static int j = 0;

    if(sig == 31)
        j = j | ((int)1 << bit);
	pid_client = info->si_pid;

    if(--bit < 0)
    {
        if(j == 0)
        {
            ft_printf("%s\n", str);
            kill(pid_client, SIGUSR2);
            usleep(120);
            free(str);
            str = NULL;
        }
        else 
        {
            tmp = ft_joint_char(str, j);
            str = tmp;
        }
        
        j = 0;
        bit = 7;
    }
}


int main(void)
{
    struct sigaction action;
    pid_t pid_serveur;

    action.sa_sigaction = ft_handler;
    action.sa_flags = SA_SIGINFO;
    action.sa_mask = 0;
    pid_serveur = getpid();

    ft_printf("PID du serveur : %d\n",pid_serveur);
    
    if(sigaction(SIGUSR1, &action, NULL) == -1 || sigaction(SIGUSR2, &action, NULL) == -1)
    {
        ft_printf("erreur\n");
        return (1);
    }
    
    while (1)
        sleep(1);

    return(0);
}