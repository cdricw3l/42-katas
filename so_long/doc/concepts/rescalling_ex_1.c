/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rescalling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:23:52 by cb                #+#    #+#             */
/*   Updated: 2025/01/03 23:06:46 by cb               ###   ########.fr       */
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
    float *scale;
    
} t_indicator;

typedef struct s_data_intput
{
    int         count_indicator;
    t_indicator critique;
    t_indicator vente;
    t_indicator engagement;
    
} t_data_i;



void    ft_process_data(t_data_i *data_i, t_data_i *data_o, float *new_scale)
{
    int i;
    int rescale;
    t_indicator *tmp;
    t_indicator *indic_in[] = {&data_i->critique,&data_i->vente,&data_i->engagement};
    t_indicator *indic_out[] = {&data_o->critique,&data_o->vente,&data_o->engagement};

    i = 0;
    data_o->count_indicator = data_i->count_indicator;
    while (i < data_i->count_indicator)
    {
        tmp = indic_in[i];
        printf(" %f\n", ((tmp->indicator - tmp->scale[0]) / (tmp->scale[1] - tmp->scale[0])));
        rescale = ((tmp->indicator - tmp->scale[0]) / (tmp->scale[1] - tmp->scale[0]))
                    * (new_scale[1] - new_scale[0]) + new_scale[0];
        indic_out[i]->indicator = rescale;
        indic_out[i]->scale = new_scale;
        i++;
    }
    
    
}

t_data_i   *ft_ex1_rescalling(t_data_i *data_i, float *new_scale)
{
    t_data_i *data_o;

    data_o = malloc(sizeof(t_data_i));
    if(!data_o)
        return(NULL);
    ft_process_data(data_i,data_o, new_scale);
    return(data_o);
}
void    printf_value(t_data_i *data)
{
    char *indic[] = {"critique", "vente", "engagement"};
    t_indicator *indic_out[] = {&data->critique,&data->vente,&data->engagement};
    int i;

    i = 0;
    while (i <data->count_indicator)
    {
        printf("voici la valeur pour l'indicateur %s: %f scale min: %f scale max: %f\n", indic[i],indic_out[i]->indicator,indic_out[i]->scale[0],indic_out[i]->scale[1]);
        i++;
    }
    
}

int ft_ex1(void)
{
    t_data_i *data_i;
    float scale1[2] = {0.0,10.0} ;
    float scale2[2] = {0.0,500.0} ;
    float scale3[2] = {0.0,1.0} ;
    float new_scale[] = {0.0,100.0};
    
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
    
    printf_value(data_i);
    t_data_i *data_o = ft_ex1_rescalling(data_i,new_scale);
    if(!data_o)
        return(1);
    free(data_i);
    printf("voici l'adresse de data %p\n", data_o);
    printf_value(data_o);
    free(data_o);
    return(0);
}

int ft_ex2()
{
    
}

int main(void)
{
    
    ft_ex1();

    return(0);
}