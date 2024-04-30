#include "sort.h"
#include <stdio.h>

/**
 * swap - swaps two integers
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - ensures the max heap property is maintained
 * @array: array to heapify
 * @size: size of the heap
 * @idx: index of the current node
 * @n: size of the array for printing
 */
void heapify(int *array, size_t size, int idx, size_t n)
{
	int largest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;

	if (left < (int)size && array[left] > array[largest])
		largest = left;

	if (right < (int)size && array[right] > array[largest])
		largest = right;

	if (largest != idx)
	{
		swap(&array[idx], &array[largest]);
		print_array(array, n);
		heapify(array, size, largest, n);
	}
}

/**
 * heap_sort - sorts an array using the Heap Sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (int i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}
