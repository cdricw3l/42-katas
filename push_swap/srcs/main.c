/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:53:07 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/05 12:43:22 by cbouhadr         ###   ########.fr       */
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
	int	len_b;
	int	len_a;

	len_b = 0;
	len_a = len;
	b = malloc(sizeof(int) * len);
	if (!b)
		return ;
	b[0] = '\0';
}

// int	main(int argc, char **argv)
// {
// 	int	len;
// 	int	*arr;
// 	int	tx;

// 	arr = NULL;
// 	if (argc < 2)
// 		return (ft_print_error());
// 	len = number_of_int(&argv[1]);
// 	tx = ft_init_progr(&argv[1], &arr);
// 	if (tx == -1)
// 		return (ft_print_error());
// 	else
// 	{
// 		if (len == 2 || len == 3)
// 			ft_two_or_tree_args(arr, len);
// 		else
// 			ft_push_swap(arr, len);
// 	}

// 	int nb = 10;
// 	int a[nb];

// 	ft_generate_number((int *)&a, nb);

// 	ft_print_arr(a, nb);
// 	int kk = ft_is_sort(a, nb);
// 	ft_qsort_int(a,0, nb);
// 	print_int(kk);
// 	ft_print_arr(a, nb);
// 	kk = ft_is_sort(a, nb);
// 	print_int(kk);
// 	return (0);
// }
