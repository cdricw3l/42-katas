/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 08:51:55 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/08 09:30:12 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/petri_network.h"
#include "../include/philosophers.h"

void *ft_clean_split(char **str, int idx)
{
    int i;

    i = 0;
    if(!str)
        return(NULL);
    while (i < idx)
    {
        if(str[i])
            free(str[i]);
        i++;
    }
    free(str);
    return(NULL);
}

static int	count_word(char *str, char c)
{
	int	i;
    int	word_count;
	int	is_word;

	i = 0;
	word_count = 0;
	is_word = 0;
	while (str[i] && i < ft_strlen(str) - 1)
	{
		if (str[i] == c)
		{
			is_word = 0;
			i++;
		}
		if (str[i] != c)
		{
			if (is_word == 0)
				word_count++;
			is_word = 1;
			i++;
		}
	}
	return (word_count);
}

int ft_get_word_size(char *str, char c)
{
    int i;

    i = 0;
    if(!str)
        return(-1);
    while (str[i] && str[i] != c)
        i++;
    return(i);
}

char **ft_split(char *str, char c)
{
    int word_count;
    char **split;
    int i;
    int j;
    int word_size;
    
    word_count = count_word(str, 32);
    split = malloc(sizeof(char *) * (word_count + 1));
    if(!split)
        return(NULL);
    i = 0;
    j = 0;
    while (str[i])
    {
        while (str[i] == c)
            i++;
        word_size = ft_get_word_size(&str[i], c);
        if(word_size == -1 || (!ft_isdigit(str[i]) && str[i] != c))
            return(ft_clean_split(split, j));
        split[j] = malloc(sizeof(char) * (word_size + 1));
        if(!split[j])
            return(ft_clean_split(split, j));
        ft_strlcpy(split[j], &str[i], word_size + 1);
        i += word_size;
        j++;
    }
    split[j] = NULL;
    return(split);
}