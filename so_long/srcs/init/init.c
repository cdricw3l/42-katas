/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:43:22 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/30 12:24:30 by cb               ###   ########.fr       */
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
		if (line )
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

int	ft_check_dimentions(t_game_data *data)
{
	int row;
	int col;
	int i;
	int j;
	
	row = ft_arr_len(data->map);
	i = 0;
	j = -1;
	while (i < row)
	{
		if(i < row - 1)
			col = ft_strlen(data->map[i]) - 1;
		else
			col = ft_strlen(data->map[i]);
		if (col != j && j != -1)
			return(1);
		j = col;
		i++;
	}
	if(ft_is_close(data->map,row,j))
		return(1);
	data->dimention.col = j;	
	data->dimention.row = row;	
	return(0);
}

void	ft_process_set(t_game_data *data,char c, int row, int col)
{
	if (data)
	{
		if(c == 'C')
			data->count_item++;
		if(c == 'E')
		{
			data->exit_position.col = col; 
			data->exit_position.row = row;
			data->count_exit++;
		}
		if(c == 'P')
		{
			data->begin.row = row;
			data->begin.col = col;
			data->count_begin++;
		}
	}
}

int	ft_check_param(t_game_data *data, char *path)
{
	char *set;
	int i;
	int j;
	
	i = 0;
	set = "01CEP";
	if(ft_check_dimentions(data))
		return (1);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] && data->map[i][j] != '\n')
		{
			if(ft_isset(data->map[i][j],set))
				ft_process_set(data,data->map[i][j],i,j); 
			else
				return(1);
			j++;
		}
		i++;	
	}
	if(data->count_exit + data->count_begin != 2)
		return(1);
	data->map_name = path;
	return(0);
}

t_data	*init_and_check(char *path)
{
	t_data	*data;
	int		fd;
	int		check_param;

	fd = open(path, O_RDONLY);
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
	if(check_param)
		return(ft_free_memory(data));
	return (data);
}

int main(void)
{
    t_data *data;
    char *path;
	char **map;
    path = "map/map2.ber";
    data = init_and_check(path);
	if(!data)
	{
		printf("probleme d'initialisation data\n");
		return(-1);
	}
    ft_display_data_info(data);
	ft_free_memory(data);

    
	//ft_check_dimentions(data);
    return(0);
}