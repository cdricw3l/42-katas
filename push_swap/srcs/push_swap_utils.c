/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:02:02 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/13 18:36:54 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_fill_process(char **argv, int *arr)
{
	char	**split;
	int		i;

	i = 0;
	while (*argv)
	{
		if (ft_are_space(*argv))
		{
			split = ft_split(*argv, 32);
			while (*split)
			{
				*arr = ft_atoi(*split);
				free(*split);
				split++;
				arr++;
			}
		}
		else
		{
			*arr = ft_atoi(argv[i]);
			arr++;
		}
		argv++;
	}
	*arr = '\0';
}

int	*ft_parsing(char **argv, int len)
{
	int	*arr;

	arr = malloc(sizeof(int) * (len + 1));
	if (!arr)
		return (NULL);
	ft_fill_process(argv, arr);
	return (arr);
}

int	number_of_int(char **argv)
{
	int		i;
	int		count;
	char	**split;

	i = 0;
	count = 0;
	while (argv[i])
	{
		if (ft_are_space(argv[i]))
		{
			split = ft_split(argv[i], 32);
			while (*split)
			{
				count++;
				split++;
			}
		}
		else
			count++;
		i++;
	}
	return (count);
}

int	ft_are_space(char *str)
{
	while (*str)
	{
		if (*str == 32)
			return (1);
		str++;
	}
	return (0);
}

int	ft_check_repetition(int *arr, int len)
{
	int	i;
	int	j;
	int	tx;

	i = 0;
	tx = 0;
	while (i < len)
	{
		j = i + 1;
		if(arr[i] == arr[j])
			return (-1);
		if(arr[i] < arr[j])
			tx++;
		i++;
	}
	tx = (100 * tx) / (len - 1) ;
	return (tx);
}

int ft_validation_arg(char **argv)
{
	char *tmp;
	int digits;
	
	while (*argv)
	{
		tmp = *argv;
		digits = 0;
		while (*tmp)
		{
			if(!ft_isdigit(*tmp) && *tmp != 32 && *tmp != 45)
				return(1);
			if(ft_isdigit(*tmp))
				digits++;
			tmp++;
		}
		if (digits == 0)
			return (1);
		argv++;
	}
	return (0);  
}

void    ft_print_arr(int *arr, int len)
{
	int i;

	i = 0;
	while (i < len)
		printf(" %d", arr[i++]);
	printf("\n");
}

int ft_print_error()
{
	write(1, "ERROR", 5);
	return (1);
}

void    ft_two_args(int *arr)
{
	if(arr[0] > arr[1])
		ft_swap(arr, 1);
}

// void    ft_two_or_tree_args(int *arr, int len)
// {
// 	if (len == 2)
// 	{
// 		if(arr[0] > arr[1])
// 			ft_swap(arr, 1);
// 	} 
// 	else if(len == 3)
// 	{
// 		if(arr[0] > arr[1])
// 			ft_swap(arr,  1);
// 		if(arr[2] < arr[0])
// 			ft_rotate(arr, len,'a');
// 		if(arr[1] > arr[2])
// 		{
// 			ft_reverse_rotate(arr, len ,'a');
// 			ft_swap(arr, 1);
// 		}
// 	}
// }

int ft_size_of_array(int *arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void ft_get_stack_data(t_pile *stack)
{
	int i;

	i = 0;
	ft_printf("[ NAME ] %c\n", stack->stack_name);
	ft_printf("[ ADDR ] %p\n", stack);
	ft_printf("[ ARR SIZE ] %d\n", stack->len);
	if(stack->arr)
	{
		while (i < stack->len)
		{
			ft_printf("[ INT N°%d ] ==> %d bit format: ",
					i, stack->arr[i]);
			ft_print_bit_16(stack->arr[i]);
			i++;
		}
	}
	ft_printf("\n");
}




int	ft_clean_memory(t_pile **stack_a, t_pile **stack_b)
{
	ft_printf("Start clean fonction\n");
	if (stack_a)
	{
		if ((*stack_a)->arr)
			free((*stack_a)->arr);
		free(*stack_a);
		ft_printf("Stack A clean\n");
	}
	else
		return(1);
	if (stack_b)
	{
		if ((*stack_b)->arr)
			free((*stack_b)->arr);
		free(*stack_b);
		ft_printf("Stack B clean\n");
	}
	else
		return(1);
	return (0);
}
