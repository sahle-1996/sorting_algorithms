#include "sort.h"

/**
 * bitonic_sort - sorts an array using the Bitonic Sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_recursion(array, 0, size - 1, 1, size);
}

/**
 * bitonic_recursion - recursive function for bitonic sort
 * @array: array to sort
 * @l: index of the left-most element
 * @r: index of the right-most element
 * @direction: ascending (1) or descending (0)
 * @size: size of the array
 */
void bitonic_recursion(int *array, int l, int r, int direction, size_t size)
{
	int step;

	if (r - l >= 1)
	{
		step = (r + l) / 2;
		printf("Merging [%d/%lu] %s:\n", r - l + 1, size, direction ? "(UP)" : "(DOWN)");
		print_array(array + l, r - l + 1);
		bitonic_recursion(array, l, step, 1, size);
		bitonic_recursion(array, step + 1, r, 0, size);
		bitonic_merge(array, l, r, direction);
		printf("Result [%d/%lu] %s:\n", r - l + 1, size, direction ? "(UP)" : "(DOWN)");
		print_array(array + l, r - l + 1);
	}
}

/**
 * bitonic_merge - merges a sequence in ascending or descending order
 * @array: array to sort
 * @l: index of the left-most element
 * @r: index of the right-most element
 * @direction: ascending (1) or descending (0)
 */
void bitonic_merge(int *array, int l, int r, int direction)
{
	int tmp, i, step = (l + r) / 2, mid = (r - l + 1) / 2;

	if (r - l >= 1)
	{
		for (i = l; i < l + mid; i++)
		{
			if (direction == (array[i] > array[i + mid]))
			{
				tmp = array[i + mid];
				array[i + mid] = array[i];
				array[i] = tmp;
			}
		}
		bitonic_merge(array, l, step, direction);
		bitonic_merge(array, step + 1, r, direction);
	}
}
