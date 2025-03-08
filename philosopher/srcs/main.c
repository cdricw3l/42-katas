/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:15:41 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/08 11:44:22 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"


int	main(int argc, char **argv)
{
	int	*arr_args;
	
	if (argc < 5 || argc > 6)
		return(1);
	arr_args = ft_init_arr_arg(&argv[1], argc - 1);
	if (!arr_args)
		return (1);

	char *m_out = "1 0 0 0 1 0 0 0 2 0 1 0";
	int ** tt;
	int p = 4;
	int t = 3;
	
    tt = ft_str_to_matrice(m_out, p, t);
	if(!tt)
		return(1);
	int i = 0;
    while (i < p)
    {
        ft_print_arr_int(tt[i],t);
        i++;
    }
	free(arr_args);
	return(0);
}