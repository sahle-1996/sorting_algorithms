#include "sort.h"

/**
 * quick_sort_hoare - sorts an array using the Quicksort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2)
		return;

	quick_recursion(array, 0, (int)size - 1, size);
}

/**
 * quick_recursion - helper function for Quicksort
 * @array: array to sort
 * @left: index of the left element
 * @right: index of the right element
 * @size: size of the array
 */
void quick_recursion(int *array, int left, int right, size_t size)
{
	int piv;

	if (left < right)
	{
		piv = partition(array, left, right, size);
		quick_recursion(array, left, piv, size);
		quick_recursion(array, piv + 1, right, size);
	}
}

/**
 * partition - finds the pivot index for Quicksort
 * @array: array to find the pivot in
 * @low: index of the left element
 * @high: index of the right element
 * @size: size of the array
 *
 * Return: the index of the pivot element
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[low + (high - low) / 2];
	int i = low - 1, j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return j;

		int tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, size);
	}
}
