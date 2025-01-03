/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:53:07 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/15 12:53:06 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_init_progr(char **argv, int **arr)
{
	int	len;
	int	rep;

	if (!ft_validation_arg(&argv[1]))
	{
		len = number_of_int(argv);
		*arr = ft_parsing(&argv[0], len);
		rep = ft_check_repetition(*arr, len);
		if (rep == -1)
			return (-1);
		else
			return (rep);
	}
	return (-1);
}



void	ft_push_swap(int *a, int len)
{
	int	*b;
	int value_max;
	int value_min;
	int pivot;
	printf("voici la len %d\n", len);
	b = malloc(sizeof(int) * (len + 1));
	if (!b)
		return ;
	b[0] = '\0';
	
	while (ft_size_of_array(a) > 3)
	{
		value_min =  get_low(a, len);
		value_max =  get_high(a, len);
		pivot = value_min;
		while (ft_find_cible(a, pivot, len) != -1 && ft_size_of_array(a) > 3)
		{
			int i = ft_find_cible(a, pivot, len);
			if(i > len + 1 / 2)
			{
				int j = len - i - 1;
				while ( j != 0)
				{
					ft_rotate(a, 'a');
					j--;
				}
			}
			else
			{
				while ( i != 0)
				{
					ft_reverse_rotate(a, 'a');
					i--;
				}
				
			}
			pivot = a[i];
			ft_push_b(b, a);
		}
	}
	ft_two_or_tree_args(a, 3);
	int i = 0;
	while (b[i])
	{
		ft_push_b(a, b);
		i++;
	}
	ft_print_arr(a);
	(void)value_max;
}

// int	main(int argc, char **argv)
// {
// 	int	len;
// 	int	*arr;
// 	int	tx;

// 	arr = NULL;
// 	// if (argc < 2)
// 	// 	return (ft_print_error());
// 	// len = number_of_int(&argv[1]);
// 	// tx = ft_init_progr(&argv[1], &arr);
// 	// if (tx == -1)
// 	// 	return (ft_print_error());
// 	// else
// 	// {
// 	// 	if (len == 2 || len == 3)
// 	// 		ft_two_or_tree_args(arr, len);
// 	// 	else
// 	// 		ft_push_swap(arr, len);
// 	// }

// 	int tab[] = {2, 5, 7, 9, 3, 1, 4, 6, '\0'};
// 	ft_print_arr(tab);
// 	ft_push_swap(tab, 9);
// 	return (0);
// }
