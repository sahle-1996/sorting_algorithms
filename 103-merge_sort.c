#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _calloc - allocates memory for an array and initializes it to 0
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
 * merge - merge two subarrays of arr[]
 * @arr: array to be sorted
 * @tmp: temporary array
 * @start: starting index of the first subarray
 * @mid: ending index of the first subarray and starting index of the second
 * @end: ending index of the second subarray
 */
void merge(int *arr, int *tmp, int start, int mid, int end)
{
	int size_left = mid - start + 1, size_right = end - mid;
	int *left_array, *right_array;
	int left, right, i = 0;

	left_array = &tmp[0];
	right_array = &tmp[size_right];

	for (left = 0; left < size_left; left++)
		left_array[left] = arr[start + left];
	for (right = 0; right < size_right; right++)
		right_array[right] = arr[mid + 1 + right];

	left = 0, right = 0, i = start;

	while (left < size_left && right < size_right)
	{
		if (left_array[left] <= right_array[right])
			arr[i] = left_array[left++];
		else
			arr[i] = right_array[right++];
		i++;
	}

	while (left < size_left)
		arr[i++] = left_array[left++];
	while (right < size_right)
		arr[i++] = right_array[right++];

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left_array, size_left);
	printf("[right]: ");
	print_array(right_array, size_right);
	printf("[Done]: ");
	print_array(&arr[start], size_left + size_right);
}

/**
 * merge_sort - sorts an array using the merge sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (array == NULL || size < 2)
		return;

	tmp = _calloc(size, sizeof(int));
	if (tmp == NULL)
		return;

	mergesort(array, tmp, 0, size - 1);
	free(tmp);
}
