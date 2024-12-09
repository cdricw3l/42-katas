/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 08:27:27 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/11/26 16:13:14 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap(int *stack, int a, int b, char c)
{
	int	tmp;

	if (stack)
	{
		tmp = stack[a];
		stack[a] = stack[b];
		stack[b] = tmp;
		if (c == 'a')
			write(1, "sa", 2);
		else
			write(1, "sb", 2);
		write(1, "\n", 2);
	}
}

void	ft_rotate(int *stack, char c)
{
	int	tmp;
	int	i;
	int	len;

	if (stack)
	{
		i = 0;
		tmp = stack[0];
		len = ft_size_of_array(stack);
		while (i < len - 1)
		{
			stack[i] = stack[i + 1];
			i++;
		}
		stack[i] = tmp;
		if (c == 'a')
			write(1, "ra", 2);
		else
			write(1, "rb", 2);
		write(1, "\n", 2);
	}
}

void	ft_reverse_rotate(int *stack, char c)
{
	int	tmp;
	int	i;
	int	len;

	len = ft_size_of_array(stack);
	if (stack)
	{
		i = 0;
		len = len - 1;
		tmp = stack[len];
		while (len > 0)
		{
			stack[len] = stack[len - 1];
			len--;
		}
		stack[len] = tmp;
		if (c == 'a')
			write(1, "rra", 2);
		else
			write(1, "rrb", 2);
		write(1, "\n", 2);
	}
}

void	ft_push(int *dest, int *src, char c_dst)
{
	int	i;
	int	tmp;
	int	len_dst;
	int	len_src;

	i = 0;
	tmp = 0;
	len_dst = ft_size_of_array(dest);
	len_src = ft_size_of_array(src);
	if (len_src > 0)
	{
		ft_memmove(dest + 1, dest, len_dst * sizeof(int));
		dest[0] = src[0];
		ft_memmove(src, src + 1, (len_src - 1) * sizeof(int));
		dest[len_dst + 1] = '\0';
		src[len_src - 1] = '\0';
		if (c_dst == 'a')
			write(1, "pa", 2);
		else
			write(1, "pb", 2);
		write(1, "\n", 2);
	}
}
