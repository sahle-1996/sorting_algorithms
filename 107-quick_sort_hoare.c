#include "sort.h"

/**
 * swap - swaps the positions of two elements in an array
 * @array: array
 * @item1: array element
 * @item2: array element
 */
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}

/**
 * hoare_partition - implements the Hoare partition sorting scheme
 * @array: array
 * @first: first array element
 * @last: last array element
 * @size: size of the array
 * Return: the position of the last element sorted
 */
int hoare_partition(int *array, int first, int last, int size)
{
	int pivot = array[last];
	int current = first - 1;
	int finder = last + 1;

	while (1)
	{
		do {
			current++;
		} while (array[current] < pivot);
		do {
			finder--;
		} while (array[finder] > pivot);

		if (current >= finder)
			return current;

		swap(array, current, finder);
		print_array(array, size);
	}
}

/**
 * qs - implements the Quicksort algorithm
 * @array: array
 * @first: first array element
 * @last: last array element
 * @size: size of the array
 */
void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = hoare_partition(array, first, last, size);
		qs(array, first, position - 1, size);
		qs(array, position, last, size);
	}
}

/**
 * quick_sort_hoare - sorts an array using the Quicksort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	qs(array, 0, size - 1, size);
}
