/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 06:52:16 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/18 08:54:50 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define FD_LIMITS 256

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strlen_idx(const char *s, int mode);
char	*ft_substr_gnl(char *str, int start, int len);
char	*ft_strdup_gnl(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_strchr_gnl(char *str, char c);
int		ft_len_index_of(char *str, char mode);

#endif