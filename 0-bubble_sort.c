#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - Sorts an array in ascending order using bubble sort algorithm
 * @array: Array of integers to be sorted
 * @size: Size of the array
 *
 * Description: This function sorts an array of integers in ascending order
 * using the bubble sort algorithm.
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j;
	int tmp;

	if (size < 2 || array == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
