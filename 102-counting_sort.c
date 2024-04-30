#include "sort.h"

/**
 * counting_sort - sorts an array with the Counting sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count_arr, *out_arr, max;
	size_t i, k, m, n;

	if (size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	count_arr = malloc(sizeof(int) * (max + 1));
	out_arr = malloc(sizeof(int) * size);

	if (!count_arr || !out_arr)
	{
		free(count_arr);
		free(out_arr);
		return;
	}

	for (i = 0; i <= max; i++)
		count_arr[i] = 0;

	for (k = 0; k < size; k++)
		count_arr[array[k]]++;

	for (i = 1; i <= max; i++)
		count_arr[i] += count_arr[i - 1];

	for (m = size - 1; m < size; m--)
	{
		out_arr[count_arr[array[m]] - 1] = array[m];
		count_arr[array[m]]--;
	}

	for (n = 0; n < size; n++)
		array[n] = out_arr[n];

	print_array(count_arr, max + 1);

	free(count_arr);
	free(out_arr);
}
