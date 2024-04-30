#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge_sort - sorts an array using the Merge Sort algorithm
 * @array: array of integers to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *arr;

	if (array == NULL || size < 2)
		return;

	arr = malloc(sizeof(int) * size);
	if (arr == NULL)
		return;

	merge_recursion(arr, array, 0, size);
	free(arr);
}

/**
 * merge_recursion - recursive function that merge sorts an array
 * @arr: copy array
 * @array: array to merge sort
 * @left: index of the left element
 * @right: index of the right element
 */
void merge_recursion(int *arr, int *array, size_t left, size_t right)
{
	size_t middle;

	if (right - left > 1)
	{
		middle = (right - left) / 2 + left;
		merge_recursion(arr, array, left, middle);
		merge_recursion(arr, array, middle, right);
		merge_subarray(arr, array, left, middle, right);
	}
}

/**
 * merge_subarray - merges subarrays
 * @arr: copy array
 * @array: array to merge
 * @left: index of the left element
 * @middle: index of the middle element
 * @right: index of the right element
 */
void merge_subarray(int *arr, int *array, size_t left,
		size_t middle, size_t right)
{
	size_t i = left, j = middle, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, middle - left);
	printf("[right]: ");
	print_array(array + middle, right - middle);

	while (i < middle && j < right)
		arr[k++] = (array[i] < array[j]) ? array[i++] : array[j++];

	while (i < middle)
		arr[k++] = array[i++];

	while (j < right)
		arr[k++] = array[j++];

	for (k = left, i = 0; k < right; k++)
		array[k] = arr[i++];

	printf("[Done]: ");
	print_array(array + left, right - left);
}
