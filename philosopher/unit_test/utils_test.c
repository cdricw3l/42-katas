/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:21:26 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/02/20 11:00:11 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_print_arr_int(int *arr, int len)
{
	int i;

	i = 0;
	while(i < len)
		printf("%d ", arr[i++]);
	printf("\n");
	
}
void	ft_print_arr_str(char **arr, int len)
{
	int i;

	i = 0;
	while(i < len)
		printf("%s ", arr[i++]);
	printf("\n");
	
}
int ft_memcpy(void *src, void *dst, int len)
{
	unsigned char *arr_s;
	unsigned char *arr_d;
	int  i;

	i = 0;
	arr_s = (unsigned char *)src;
	arr_d = (unsigned char *)dst;
	while (i < len)
	{
		arr_d[i] = arr_s[i];
		i++;
	}
	return(i);
}

void       *ft_clean_memory(void **arr, int idx)
{
    int i;

    i = 0;
    TEST_START;
    while(i < idx)
    {
        if(arr[i])
            free(arr[i]);
        printf("voici i %d\n", i);
        i++;
    }
    TEST_SUCCES;
    free(arr);
    return(NULL);
}
int ft_clean_tmd(t_thread_managment_data *tmd, int idx)
{
	int i;

	i = 0;
	while (i < idx)
	{
		if(tmd->philosophes[i])
			free(tmd->philosophes[i]);
		if(tmd->threads[i])
			free(tmd->threads[i]);
		if(tmd->forks[i])
			free(tmd->forks[i]);
		i++;
	}
	free(tmd->forks);
	free(tmd->philosophes);
	free(tmd->threads);
	free(tmd);
	return(-1);
}
