/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_to_matrice.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 08:34:00 by cw3l              #+#    #+#             */
/*   Updated: 2025/03/08 14:19:23 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/str_to_matrice.h"

void    *ft_clean_matrice_mem(int **M, int idx)
{
    int i;

    i = 0;
    while(i < idx)
    {
        free(M[i]);
        i++;
    }
    free(M);
    return(NULL);
}

static int	ft_is_valide_split(char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i] != NULL)
	{
		j = 0;
		while (split[i][j])
		{
			if (!ft_isdigit(split[i][j]) && split[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_get_split_len(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return (0);
	while (split[i])
		i++;
	return (i);
}

static void	*ft_process_matrice(int **M, char **split, int x, int y)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < x)
	{
		M[i] = malloc(sizeof(int) * y);
		if (!M[i])
			return (ft_clean_matrice_mem(M, i));
		j = 0;
		while (j < y)
		{
			if (ft_atoi_long(split[k]) < INT_MIN
				|| ft_atoi_long(split[k]) > INT_MAX)
				return (ft_clean_matrice_mem(M, i));
			M[i][j] = ft_atoi_long(split[k]);
			k++;
			j++;
		}
		i++;
	}
	M[i] = NULL;
	return (M);
}

int	**ft_str_to_matrice(char *str, int x, int y)
{
	char	**split;
	int		**m;

	if (!str || x <= 0 || y <= 0)
		return (NULL);
	split = ft_split(str, 32);
	if (!split || !ft_is_valide_split(split))
		return (NULL);
	if (ft_get_split_len(split) != (x * y))
		return (ft_clean_split(split, ft_get_split_len(split)));
	m = malloc(sizeof(int *) * (x + 1));
	if (!m)
		return (NULL);
	if (!ft_process_matrice(m, split, x, y))
		return (NULL);
	return (m);
}

// int main()
// {
// 	char *str = "1 -22222 0 2 0 0 3 0 0 4 0 44";
// 	int **m = ft_str_to_matrice(str, 4, 3);
	
// 	if(m)
// 	{
// 		while (*m)
// 		{
// 			ft_print_arr_int(*m,3);
// 			m++;
// 		}
// 	}
// 	exit(0);
// 	return(0);
// }
