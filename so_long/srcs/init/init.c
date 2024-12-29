/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:43:22 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/29 19:29:55 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

int	get_map(char *path, char **map)
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
			map[i++] = ft_strdup(line);
			free(line);
		}
	}
	map[i] = NULL;
	return (i);
}

char	**ft_get_map(char *path)
{
	int		line_count;
	char	**map;
	int		i;

	line_count = ft_line_count(path);
	map = malloc(sizeof(char *) * (line_count + 1));
	if (!map)
		return (NULL);
	i = get_map(path, map);
	if (i == 0)
		return (NULL);
	return (map);
}

t_data	*check_and_init(char *path)
{
	t_data	*data;
	int		fd;

	fd = open(path, O_RDONLY);
	data = ft_init_data_s();
	if (!data)
	{
		printf("probleme initialisation data\n");
		return (NULL);
	}
	data->game_data->map = ft_get_map(path);
	if (!data->game_data->map)
	{
		printf("probleme initialisation game map\n");
		return (ft_free_memory(data));
	}
	return (data);
}

// int main(void)
// {
//     t_data *data;
//     char *path;

//     path = "/home/cb/Documents/42K/so_long/map/map1.ber";
//     data = check_and_init(path);
//     char **map = data->game_data->map;
//     while (*map)
//     {
//         printf("%s\n",*map);
//         map++;
//     }
//     ft_free_memory(data);
//     return(0);
// }