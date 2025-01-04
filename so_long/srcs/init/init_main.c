/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:43:22 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/04 23:30:57 by cb               ###   ########.fr       */
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
	printf("voici %d\n", i);
	return (i);
}

char	**ft_get_map(char *path)
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
	i = get_map(path, map);
	if (i == 0)
		return (NULL);
	return (map);
}

t_data	*init_and_check(char *path)
{
	t_data	*data;
	int		check_param;

	data = ft_init_data_s();
	if (!data)
	{
		printf("probleme d'initialisation de la structure data\n");
		return (ft_free_memory(data));
	}
	data->game_data->map = ft_get_map(path);
	if (!data->game_data->map)
	{
		printf("probleme d'initialisation de la map\n");
		return (ft_free_memory(data));
	}
	check_param = ft_check_param(data->game_data, path);
	if (check_param)
	{
		printf("probleme avec les parametre de la map %d\n", check_param);
		return (ft_free_memory(data));
	}
	if (ft_check_valide_way(data->game_data) == 1)
		return (ft_free_memory(data));
	return (data);
}


// int main(void)
// {
//     t_data *data;
//     char *path;
// 	char **map;
//     path = "map/map2.ber";
//     data = init_and_check(path);
// 	if(!data)
// 	{
// 		printf("probleme d'initialisation data\n");
// 		return(-1);
// 	}
//     ft_display_data_info(data);
// 	ft_free_memory(data);
//     return(0);
// }