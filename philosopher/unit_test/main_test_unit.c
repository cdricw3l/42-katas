/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_unit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:22:41 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/03/04 07:27:32 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void test_atoi_long(void)
{
    long ld;

    TEST_START;
    ld = ft_atoi_long("10");
    assert(ld == 10);
    ld = ft_atoi_long("2147483647");
    assert(ld == INT_MAX);
    ld = ft_atoi_long("9223372036854775807");
    assert(ld == -1);
    ld = ft_atoi_long(NULL);
    assert(ld == -1);
    ld = ft_atoi_long("-10");
    assert(ld == -1);
    ld = ft_atoi_long("-2147483648");
    assert(ld == -1);
    TEST_SUCCES;
}

void test_isdigit(void)
{
    char c;

    TEST_START;
    c = '0';
    assert(ft_isdigit(c) == 1);
    c = '5';
    assert(ft_isdigit(c) == 1);
    c = '9';
    assert(ft_isdigit(c) == 1);
    c = 'a';
    assert(ft_isdigit(c) == 0);
    c = 'w';
    assert(ft_isdigit(c) == 0);
    c = '-';
    assert(ft_isdigit(c) == 0);
    TEST_SUCCES;
}

int *test_ft_init_arr(char **argv, int argc)
{
    TEST_START;
    int *arr;

    assert(argc == 4);
    arr = ft_init_arr_arg(argv, argc);
   
    assert(arr != NULL);
    assert(arr[0] == (int)5);
    assert(arr[1] == (int)4000);
    assert(arr[2] == (int)4000);
    assert(arr[3] == (int)4000);
    
    TEST_SUCCES;
    return(arr);
}

// int	main(int argc, char **argv)
// {
//     int *arr;
//     int network_status;
//     test_isdigit();
// 	test_atoi_long();
//     arr = test_ft_init_arr(&argv[1], argc - 1);
//     ft_print_arr_int(arr, argc - 1);
//     printf("START NETWORK CREATION\n");
//     network_status = ft_create_petri_network(arr[0]);
//     assert(network_status != -1);
// 	return(0);
// }