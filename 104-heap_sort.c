#include "sort.h"

/**
 * heap_sort - sorts an array using the Heap Sort algorithm
 * @array: array of integers to sort
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
		int tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}

/**
 * heapify - turns an array into a heap tree
 * @array: array to turn into heap
 * @size: size of the heap
 * @root: index of the root of the heap
 * @total_size: total size of the array
 */
void heapify(int *array, size_t size, size_t root, size_t total_size)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		int temp = array[root];
		array[root] = array[largest];
		array[largest] = temp;
		print_array(array, total_size);
		heapify(array, size, largest, total_size);
	}
}
