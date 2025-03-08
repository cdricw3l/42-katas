/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:15:41 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/08 09:32:29 by cw3l             ###   ########.fr       */
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
	ft_print_arr_int(arr_args, argc - 1);


	char *m = "1 0 0 1 0 1 1 0 0 1 0 1 1 0 1 0";
    
    char **split = ft_split(m, 32);
    if(!split)
    {
        printf("Erreur split\n");
        return(1);
    }
	while (*split)
    {
        printf(" %s\n", *split);
        split++;
    }
	free(arr_args);
	return(0);
}