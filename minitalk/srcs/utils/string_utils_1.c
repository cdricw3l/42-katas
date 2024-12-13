/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:51:35 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/11 09:14:52 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_joint_char(char *str, char c)
{
	int		len;
	int		i;
	char	*new_s;

	if (!str)
		len = 0;
	else
		len = ft_strlen(str);
	i = 0;
	new_s = malloc(sizeof(char) * (len + 2));
	if (!new_s)
		return (NULL);
	while (i < len)
	{
		new_s[i] = str[i];
		i++;
	}
	new_s[i++] = c;
	new_s[i] = '\0';
	return (new_s);
}

char	*ft_clean_alloc(char *old_ptr, int c)
{
	char	*new_str;

	new_str = ft_joint_char(old_ptr, c);
	if (!new_str)
		return (NULL);
	if (old_ptr)
		free(old_ptr);
	return (new_str);
}
