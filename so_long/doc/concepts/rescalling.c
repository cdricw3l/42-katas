/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rescalling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:23:52 by cb                #+#    #+#             */
/*   Updated: 2025/01/03 13:30:03 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
/*
                     |    Valeur − min ancien N​    |
    Valeur rescale = | --------------------------- | x (max N cible − min N cible) + min N cible
                     | max ancien N − min ancien N​ | 
*/
typedef struct Indicator
{
    float indicator;
    int *scale;
    
} t_indicator;

typedef struct s_data_intput
{
    int         count_indicator;
    t_indicator critique;
    t_indicator vente;
    t_indicator engagement;
    
} t_data_i;



void    ft_process_data(t_data_i *data_i, t_data_i *data_o, int *new_scale)
{
    int i;
    int rescale;
    t_indicator *tmp;
    t_indicator *indic_in[] = {&data_i->critique,&data_i->engagement,&data_i->vente};
    t_indicator *indic_out[] = {&data_o->critique,&data_o->engagement,&data_o->vente};

    i = 0;
    data_o->count_indicator = data_i->count_indicator;
    while (i < data_i->count_indicator)
    {
        tmp = indic_in[i];
        rescale = (tmp->indicator - tmp->scale[0] / tmp->scale[1] - tmp->scale[0])
                    * (new_scale[1] - new_scale[0]) + new_scale[0];
        indic_out[i]->indicator = rescale;
        indic_out[i]->scale = new_scale;
        i++;
    }
    
    
}

t_data_i   *ft_ex1_rescalling(t_data_i *data_i, int *new_scale)
{
    t_data_i *data_o;

    data_o = malloc(sizeof(t_data_i));
    if(!data_o)
        return(NULL);
    ft_process_data(data_i,data_o, new_scale);
    free(data_i);
    return(data_o);
}
void    printf_value(t_data_i *data)
{
    char *indic[] = {"critique", "engagement", "vente"};
    t_indicator *indic_out[] = {&data->critique,&data->engagement,&data->vente};
    int i;

    i = 0;
    while (i <data->count_indicator)
    {
        printf("voici la valeur pour l'indicateur %s: %f scale min: %d scale max: %d\n", indic[i],indic_out[i]->indicator,indic_out[i]->scale[0],indic_out[i]->scale[1]);
        i++;
    }
    
}

int main(void)
{
    t_data_i *data_i;
    int scale1[2] = {0,10} ;
    int scale2[2] = {0,500} ;
    int scale3[2] = {0,1} ;
    int new_scale[] = {0,100};
    
    data_i = malloc(sizeof(t_data_i));
    if(!data_i)
        return(1);
    data_i->critique.indicator = 7;
    data_i->critique.scale = scale1;
    data_i->vente.indicator = 300;
    data_i->vente.scale = scale2;
    data_i->engagement.indicator = 0.65;
    data_i->engagement.scale = scale3;
    data_i->count_indicator = 3;
    
    t_data_i *data_o = ft_ex1_rescalling(data_i,new_scale);
    printf("voici l'adresse de data %p\n", data_o);
    printf_value(data_o);
    free(data_o);
    
    return(0);
}