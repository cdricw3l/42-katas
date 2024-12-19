/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:13:33 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/19 14:39:49 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	is_close_and_rectangle(char **map, int hauteur, int largeur)
{
	int	i;
	int	j;

	i = 0;
	if (hauteur == largeur)
		return (1);
	while (i < hauteur)
	{
		j = 0;
		while (j < largeur)
		{
			if (i == 0 || i == hauteur - 1)
			{
				if (map[i][j] != 49)
					return (1);
			}
			else
				if (j == 0 || j == largeur - 1)
					if (map[i][j] != 49)
						return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_param(char c, int check_arr[5])
{
	if (c == '0')
		check_arr[0] = 1;
	if (c == '1')
		check_arr[1] = 1;
	if (c == 'C')
		check_arr[2] = 1;
	if (c == 'E')
		check_arr[3] = 1;
	if (c == 'P')
		check_arr[4] = 1;
}

int	ft_count_params(int arr[5])
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 5)
		count += arr[i++];
	return(count);
}

int	ft_check_params(char **map, int check_arr[5], int hauteur, int largeur)
{
	int		i;
	int		j;
	char	*set;

	i = 0;
	set = "01CEP";
	if(!map || (hauteur == 0 || largeur == 0))
		return(1);
	while (i < hauteur)
	{
		j = 0;
		while (j < largeur)
		{
			if (ft_isset(map[i][j], set))
				check_param(map[i][j++], check_arr);
			else
				return(1);
		}
		i++;
	}
	if(is_close_and_rectangle(map, hauteur, largeur))
	{
		printf("la map n'est pas rectanglle\n");
		return (1);
	}
	if(ft_count_params(check_arr) != 5)
	{
		printf("il manque des items\n");
		return(1);
	}
	return (0);
}
// int main()
// {
// 	int check_arr[5];
// 	char *no_close_map = "../../map/map2.ber";
// 	int     fd;
// 	t_data  map;
// 	char **m;
// 	fd = open(no_close_map, O_RDONLY);
//     if (fd == -1)
//     {
//         printf("erreur  d'vouverture du fichier: %s \n", no_close_map );
//         return (1);
//     }
// 	ft_get_dimentions(fd, &map);
// 	m = ft_parse_params(no_close_map, map.dimention.hauteur, map.dimention.largeur);
// 	int check = ft_check_params(m,check_arr,map.dimention.hauteur, map.dimention.largeur );

// 	printf("voici la valeur %d\n", check);
// 	return(0);
// }