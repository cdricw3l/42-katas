/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:28:41 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/17 11:42:41 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/so_long_bonus.h"

int	ft_get_offset(int k)
{
	if (k == 0)
		return (0);
	else
		return (128 * k);
}

int	ft_get_path(int k)
{
	static int	f = 0;

	if (k == 0)
		f++;
	if (f % 2 == 0)
		return (8);
	else
		return (9);
}
