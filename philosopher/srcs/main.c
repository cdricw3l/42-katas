/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:15:41 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/02/18 15:37:29 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"


int	main(int argc, char **argv)
{
	long	*arr_args;
	
	if (argc < 5 || argc > 6)
		return(1);
	arr_args = ft_init_arr_arg(&argv[1], argc - 1);
	ft_print_arr_long(arr_args, argc - 1);
	free(arr_args);
	return(0);
}