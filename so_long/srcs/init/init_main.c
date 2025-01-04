/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:43:22 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/04 22:22:21 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_line_count(char *path)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	line = "";
	fd = open(path, O_RDONLY);
	if (fd < 0 || fd > MAX_FD)
		return (0);
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line)
		{
			free(line);
			i++;
		}
	}
	return (i);
}

int	get_map(char *path, char **map, int ws, int hs)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	line = "";
	fd = open(path, O_RDONLY);
	if (fd < 0 || fd > MAX_FD)
		return (0);
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line)
		{
			printf("voici i %d et w %d et h %d\n", ((int)ft_strlen(line)) * TILD_SIZE, ws, i);
			if (((int)ft_strlen(line) - 1) * TILD_SIZE > ws)
			 	return(0);
			map[i++] = ft_strdup(line);
			free(line);
		}
	}
	(void)hs;
	// if (i * TILD_SIZE > hs)
	// 	return(0);
	map[i] = NULL;
	return (i);
}

char	**ft_get_map(char *path,t_dimention *dim)
{
	char	**map;
	int		i;
	int		line_count;

	line_count = ft_line_count(path);
	if (line_count == 0)
		return (NULL);
	map = malloc(sizeof(char *) * (line_count + 1));
	if (!map)
		return (NULL);
	i = get_map(path, map, dim->col, dim->row);
	if (i == 0)
		return (NULL);
	return (map);
}

t_data	*ft_init_and_check(char *path)
{
	t_data	*data;
	int		check_param;

	data = ft_init_data_s();
	if (!data)
		return (ft_free_memory(data, 1));
	data->game_data->map = ft_get_map(path, &data->screen_size);
	if (!data->game_data->map)
		return (ft_free_memory(data, 2));
	check_param = ft_check_param(data->game_data, path);
	if (check_param)
		return (ft_free_memory(data, 3));
	if (ft_check_valide_way(data->game_data) == 1)
		return (ft_free_memory(data, 4));
	return (data);
}
