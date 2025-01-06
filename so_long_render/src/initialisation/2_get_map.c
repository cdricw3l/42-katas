/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_get_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:59:05 by cb                #+#    #+#             */
/*   Updated: 2025/01/06 22:34:59 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/initialisation.h"

void   print_map(t_data *data)
{
    int i;
    int j;
    int hauteur;
    int largeur;
    char **map;

    i = 0;
    if(data->xy_data.map.row && data->xy_data.map.col)
    {
        hauteur = data->xy_data.map.row;
        largeur = data->xy_data.map.col;
        map = data->map;
        while (i < hauteur)
        {
            j = 0;
            while(j < largeur)
            {
                printf("%c", map[i][j]);
                j++;
            }
            printf("\n");
            i++;
        }
    }
	printf("\n");
}

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

int	_get_map(char *path, char **map)
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

char	**get_map(t_data *data)
{
	char	**map;
	int		i;
	int		line_count;

	line_count = ft_line_count(data->map_name);
	if (line_count == 0)
		return (NULL);
	map = malloc(sizeof(char *) * (line_count + 1));
	if (!map)
		return (NULL);
	i = _get_map(data->map_name, map);
	printf("voici get map%d\n", i);
	if (i == 0)
		return (NULL);
	return (map);
}