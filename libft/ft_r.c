/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:56:43 by cw3l              #+#    #+#             */
/*   Updated: 2024/12/16 13:07:01 by cw3l             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// C Program to implement Radix Sort
#include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

static int ft_is_used(int *arr, int len, int value)
{
    int i;

    i = 0;
    while (i < len)
    {
        if(arr[i] == value)
            return (1);
        i++;
    }
    return (0);
}


void ft_generate_number(int *arr, int size)
{
    int i;
    int random_num;

    i = 0;
    while (i < size)
    {
       random_num =  random() % size + 1;
       if(!ft_is_used(arr, i + 1 ,random_num))
       {
            arr[i] = random_num;
            i++;
       }
    }
    
}

void	ft_print(int *arr, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
	
}

// A utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
	// output array
	int output[n];
	int i, count[10] = { 0 };

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;
    ft_print(count, 10);
	// Change count[i] so that count[i] now contains actual
	// position of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
    ft_print(count, 10);

	// Build the output array
	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		printf("voici l'index %d et %d\n", ((arr[i] / exp) % 10) - 1 , count[(arr[i] / exp) % 10] - 1);
		count[(arr[i] / exp) % 10]--;
	}
    ft_print(output, 10);

	// Copy the output array to arr[], so that arr[] now
	// contains sorted numbers according to current digit
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void ft_radixsort(int arr[], int n)
{
	// Find the maximum number to know number of digits
	int m = getMax(arr, n);

	// Do counting sort for every digit. Note that instead
	// of passing digit number, exp is passed. exp is 10^i
	// where i is current digit number
	for (int exp = 10; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}

// A utility function to print an array
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}

// Driver program to test above functions
int main()
{
	int arr2[] = {1000, 1, 200, 3, 44, 5, 650, 7, 8, 9};

	// Radix sort function
	ft_radixsort(arr2, 10);

	print(arr2, 10);
	return 0;
}
