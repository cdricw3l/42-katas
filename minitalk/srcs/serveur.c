/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:07:21 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/10 12:48:24 by cw3l             ###   ########.fr       */
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
            usleep(SLEEP_TIME);
            str = NULL;
            free(str);
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
    sigset_t set;
    pid_t pid_serveur;

    sigemptyset(&set);
    sigaddset(&set, SIGINT);

    ft_printf("%d\n",set);
    action.sa_sigaction = ft_handler;
    action.sa_mask = set;
    action.sa_flags = SA_SIGINFO;
    
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