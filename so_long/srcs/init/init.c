/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:43:22 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/30 08:42:37 by cb               ###   ########.fr       */
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
	return (i);
}

char	**ft_get_map(char *path)
{
	int		line_count;
	char	**map;
	int		i;

	line_count = ft_line_count(path);
	if(line_count == 0)
		return(NULL);
	map = malloc(sizeof(char *) * (line_count + 1));
	if (!map)
		return (NULL);
	i = get_map(path, map);
	if (i == 0)
		return (NULL);
	return (map);
}

void	*ft_check_dimentions(t_data *data)
{
	char **map;
	int row;
	int col;
	int i;
	int j;
	map = data->game_data->map;
	row = ft_arr_len(map);
	i = 0;
	j = -1;
	while (i < row)
	{
		if(i < row - 1)
			col = ft_strlen(map[i]) - 1;
		else
			col = ft_strlen(map[i]);
		if (col != j && j != -1)
			return(NULL);
		j = col;
		i++;
	}
	data->game_data->dimention.col = j;	
	data->game_data->dimention.row = row;	
	printf("dimention %d et %d\n",data->game_data->dimention.row,data->game_data->dimention.col );
	return(data->game_data);
}

t_data	*init_and_check(char *path)
{
	t_data	*data;
	int		fd;

	fd = open(path, O_RDONLY);
	data = ft_init_data_s();
	if (!data)
	{
		printf("probleme initialisation data\n");
		return (ft_free_memory(data));
	}
	data->game_data->map = ft_get_map(path);
	printf("%p\n",data->game_data->map);
	if (!data->game_data->map)
	{
		printf("probleme initialisation games map\n");
		return (ft_free_memory(data));
	}
	//ft_check_dimentions(data);
	return (data);
}

int main(void)
{
    t_data *data;
    char *path;
	char **map;
    path = "/home/cb/Documents/42K/so_long/map/map2.ber";
    data = init_and_check(path);
	printf("voici data %p\n",data);
	if(data)
	{
    	printf("image adresse %p, game_data  ok\n", data->img);
		ft_free_memory(data);
	}
    
	//ft_check_dimentions(data);
    return(0);
}