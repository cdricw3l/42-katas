/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   petri_network.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:43:15 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/08 15:02:44 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/petri_network.h"
#include "../include/philosophers.h"

void *ft_clean_petri_network_mem(t_petri_network *network)
{
    int i;
    
    if(network->M_in)
    {
        i = 0;
        while (i < PETRI_P)
        {
            if(network->M_in[i])
                free(network->M_in[i]);
            i++;
        }
    }
    if(network->M_out)
    {
        i = 0;
        while (i < PETRI_P)
        {
            if(network->M_out[i])
                free(network->M_out[i]);
            i++;
        }
    }
    free(network->P);
    free(network->T);
    free(network);
    return(NULL);
}



int *ft_create_place(int P, int *M_0)
{
    int *places;
    int i;

    places = malloc(sizeof(int) * P);
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

t_petri_network *ft_create_network(int *PT, int **M_0, int **M_in, int **M_out)
{
    t_petri_network *network;
    
    if(PT[0] < 1)
        return(NULL);
    network = malloc(sizeof(t_petri_network));
    if(!network)
        return(NULL);
    ft_memset(network, 0,sizeof(t_petri_network));
    network->P = ft_create_place(PT[0],*M_0);
    if(!network->P)
    {
        free(network);
        return(NULL);
    }
    network->T =  ft_create_transitions(PT[1]);
    if(!network->T)
    {
        free(network->P);
        free(network);
        return(NULL);
    }
    network->M_in = M_in;
    network->M_out = M_out;
    network->M0 = M_0;
    if(!network->M_in || !network->M_out || !network->M0)
        return(ft_clean_petri_network_mem(network));
    return(network);    
}

void ft_print_matrice_network(t_petri_network *network)
{
    int i;

    i = 0;
    printf("\n[ matrice M0]\n\n");
    while (network->M0[i])
        ft_print_arr_int(network->M0[i++], *network->T);
    i = 0;
    printf("\n[ matrice M_out ]\n\n");
    while (network->M_out[i])
        ft_print_arr_int(network->M_out[i++], *network->T);
    i = 0;
    printf("\n[ matrice M_in ]\n\n");
    while (network->M_in[i])
        ft_print_arr_int(network->M_in[i++], *network->T);
    printf("\n");
}

int main(void)
{
    int PT[] = {4,3};
    int **m0;
    int **m_in;
    int **m_out;
    t_petri_network *network;

    m0 = ft_str_to_matrice("1 0 0 1", 1, 4);
    m_out = ft_str_to_matrice("1 0 0 0 1 0 0 0 2 0 1 0", 4, 3);
    m_in = ft_str_to_matrice("0 0 1 1 0 0 0 2 0 0 0 1", 4, 3);
    
    network = ft_create_network(PT,m0,m_in,m_out);
    if(network)
        printf("ADDR %p\n", network);
    ft_print_matrice_network(network);
    return(0);
}
