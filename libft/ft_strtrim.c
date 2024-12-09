/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:58:24 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/10/12 10:43:52 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	size_t	i;

	i = 0;
	if (!set)
		return (-1);
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	s_len;
	size_t	len;
	char	*str;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	s_len = ft_strlen(s1);
	while (ft_isset(s1[i], set))
		i++;
	if (i == s_len)
		return (ft_strdup(""));
	while (ft_isset(s1[s_len - 1], set))
		s_len--;
	len = (s_len - i) + 1;
	str = malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[i], len);
	return (str);
}
