/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   petri_network.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:43:15 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/08 21:05:22 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/petri_network.h"
#include "../include/philosophers.h"

void ft_print_matrice_network(t_petri_network *network)
{
    int i;

    i = 0;
    printf("\n[ P: ]\n\n");
    ft_print_arr_int(network->M0, network->p);
    printf("\n[ T: ]\n\n");
    ft_print_arr_int(network->T, network->t);
    printf("\n[ matrice M 0 ]\n\n");
    ft_print_arr_int(network->M0, network->p);
    printf("\n[ matrice M_out ]\n\n");
    while (network->M_out[i])
        ft_print_arr_int(network->M_out[i++], network->t);
    i = 0;
    printf("\n[ matrice M_in ]\n\n");
    while (network->M_in[i])
        ft_print_arr_int(network->M_in[i++], network->t);
    printf("\n");
}

void *ft_clean_petri_network_mem(t_petri_network *network)
{
    int i;
    
    if(network->M_in)
    {
        i = 0;
        while (i < network->p)
        {
            if(network->M_in[i])
                free(network->M_in[i]);
            i++;
        }
    }
    if(network->M_out)
    {
        i = 0;
        while (i < network->p)
        {
            if(network->M_out[i])
                free(network->M_out[i]);
            i++;
        }
    }
    free(network->M0);
    free(network->T);
    free(network);
    return(NULL);
}



int *ft_create_place(int P, int *M_0)
{
    int *places;
    int i;

    places = malloc(sizeof(int) * (P + 1));
    if(!places)
        return(NULL);
    i = 0;
    while (i < P)
    {
        places[i] = M_0[i];
        i++;
    }
    return(places);
}

int  *ft_create_transitions(int T)
{
    int *transitions;
    int i;
    
    transitions = malloc(sizeof(int) * (T));
    if(!transitions)
        return(NULL);
    i = 0;
    while (i < T)
    {
        transitions[i] = 0;
        i++;
    }
    return(transitions);

}

int **ft_copy_matrice(int **M_in, int P, int T)
{
    int i;
    int r;
    int **M;

    M = malloc(sizeof(int *) * P);
    if(!M)
        return(NULL);
    i = 0;
    while (i < P)
    {
        M[i] = malloc(sizeof(int) * T);
        if(!M[i])
            return(ft_clean_matrice_mem(M, i));
        r = ft_memcpy(M_in[i], M[i], sizeof(int) * T);
        if(r / sizeof(r) != T)
        {
            perror("Err ft_copy_matrice");
            return(ft_clean_matrice_mem(M, i));
        }
        i++;
    }
    return(M);
}
void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	if (!b && len == 0)
		return (NULL);
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

t_petri_network *ft_init_network(int pt[2], char *m0)
{
    t_petri_network *network;
    
    if(pt[0] < 1 && pt[1] < 1)
        return(NULL);
    network = malloc(sizeof(t_petri_network));
    if(!network)
        return(NULL);
    network->M0 = *ft_str_to_matrice(m0, 1, pt[0]);
    if(!network->M0)
    {
        free(network);
        return(NULL);
    }
    network->p = pt[0];
    network->t = pt[1];
    network->T =  ft_create_transitions(network->t);
    if(!network->T)
    {
        free(network->M0);
        free(network);
        return(0);
    }
    return(network);    
}


t_petri_network *ft_create_petri_net(int pt[2], char *m0, char *m_in, char *m_out)
{
    t_petri_network *network;

    network = ft_init_network(pt, m0);
    if(!network)
        return(NULL);
    if(!m_in || !m_out)
        return(NULL);
    network->M_out = ft_str_to_matrice(m_out, pt[0], pt[1]);
    if(!network->M_out)
    {
        free(network->M0);
        free(network->T);
        free(network);
        return(NULL);
    }
    network->M_in = ft_str_to_matrice(m_in, pt[0], pt[1]);
    if(!network->M_in)
    {
        free(network->M0);
        free(network->T);
        ft_clean_matrice_mem(network->M_out, network->p);
        free(network);
        return(NULL);
    }
    return(network);
}

int main(void)
{
    t_petri_network *network_1;
    t_petri_network *network_2;

    int pt[2] = {4,3};
    
    char *m0 = "1 0 0 1";
    char *m_out = "1 0 0 0 1 0 0 0 2 0 1 0";

    
    char *m_int = "0 0 1 1 0 0 0 2 0 0 0 1";
    
    network_1 = ft_create_petri_net(pt,m0,m_int,m_out);
    if(network_1)
        ft_print_matrice_network(network_1);
        
    network_2 = ft_create_petri_net(pt,m0,m_int,m_out);
    if(network_2)
        ft_print_matrice_network(network_2);

    return(0);
}
