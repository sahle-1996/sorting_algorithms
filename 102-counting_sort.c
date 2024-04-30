#include "sort.h"
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array
 * @nmemb: number of elements
 * @size: size of each element
 *
 * Return: pointer to the allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < nmemb * size; i++)
		ptr[i] = 0;

	return (ptr);
}

/**
 * counting_sort - sorts an array using counting sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *counter, *sorted;
	size_t i, max = 0;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		if (array[i] > (int)max)
			max = array[i];
	}

	counter = _calloc(max + 1, sizeof(int));
	if (counter == NULL)
		return;

	sorted = _calloc(size, sizeof(int));
	if (sorted == NULL)
	{
		free(counter);
		return;
	}

	for (i = 0; i < size; i++)
		counter[array[i]]++;

	for (i = 1; i <= max; i++)
		counter[i] += counter[i - 1];

	print_array(counter, max + 1);

	for (i = 0; i < size; i++)
	{
		sorted[counter[array[i]] - 1] = array[i];
		counter[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = sorted[i];

	free(counter);
	free(sorted);
}
