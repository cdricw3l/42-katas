/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 08:27:27 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/15 12:52:08 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap(int *stack, int pile)
{
	int	tmp;

	if (stack)
	{
		tmp = stack[0];
		stack[0] = stack[1];
		stack[1] = tmp;
		if (pile == 1)
			write(1, "sa", 2);
		else
			write(1, "sb", 2);
		write(1, "\n", 2);
	}
}

void	ft_reverse_rotate(int *stack, int len ,char c)
{
	int	tmp;
	int	i;
	//int	j;

	if (stack)
	{
		i = 0;
		tmp = stack[0];
		while (i < len - 1)
		{
			stack[i] = stack[i + 1];
			i++;
		}
		stack[i] = tmp;
		if (c == 'a')
			write(1, "rra", 3);
		else
			write(1, "rrb", 3);
		write(1, "\n", 2);
	}
}

void	ft_rotate(int *stack, int len,char c)
{
	int	tmp;

	if (stack)
	{
		tmp = stack[len - 1];
		
		while (len > 0)
		{
			stack[len - 1] = stack[len - 2];
			len--;
		}
		stack[0] = tmp;
		if (c == 'a')
			write(1, "ra", 3);
		else
			write(1, "rb", 3);
		write(1, "\n", 2);
	}
}

void	ft_push_a(int *dest, int *src)
{
	int	len_dst;
	int	len_src;

	len_dst = ft_size_of_array(dest);
	len_src = ft_size_of_array(src);
	if (len_src > 0)
	{
		ft_memmove(dest + 1, dest, len_dst * sizeof(int));
		dest[0] = src[0];
		ft_memmove(src, src + 1, (len_src - 1) * sizeof(int));
		dest[len_dst + 1] = '\0';
		src[len_src - 1] = '\0';
		write(1, "pa", 2);
		write(1, "\n", 2);
	}
}

void	ft_push_b(int *dest, int *src, int len)
{
	int	len_dst;
	int	len_src;

	len_dst = ft_size_of_array(dest);
	len_src = len;
	if (len_src > 0)
	{
		ft_memmove(dest + 1, dest, len_dst * 4);
		dest[0] = src[0];
		ft_memmove(src, src + 1, (len_src - 1) * 4);
		//write(1, "pb", 2);
		//write(1, "\n", 2);
	}
}

// int main(void)
// {
// 	int tab1[8] = {9, 7, 5, 3, 1, 4, 6, '\0'};
// 	int tab2[8] = {'\0'};
// 	ft_print_arr(tab1);
// 	ft_reverse_rotate(tab1, 'a');
// 	ft_print_arr(tab1);
// 	while (tab1[0] != 9)
// 	{
// 		ft_reverse_rotate(tab1, 'a');
// 		ft_print_arr(tab1);
// 	}
// 	return(0);
// }