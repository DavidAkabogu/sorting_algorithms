#include "sort.h"

/**
 * swap_integers - Swap two integers in an array.
 * @i: The first integer to swap.
 * @j: The second integer to swap.
 */
void swap_integers(int *i, int *j)
{
	int temporary;

	temporary = *i;
	*i = *j;
	*j = temporary;
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @low: The starting index of the subset to order.
 * @high: The ending index of the subset to order.
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int *pivot = array + high, above = low, below;

	for (below = low; below < high; below++)
	{
		if (array[below] < *pivot)
		{
			if (above != below)
			{
				swap_integers(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}
	if (array[above] > *pivot)
	{
		swap_integers(array + above, pivot);
		print_array(array, size);
	}
	return (above);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @low: The starting index of the array partition to order.
 * @high: The ending index of the array partition to order
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int low, int high)
{
	int partition_index;

	if (high - low > 0)
	{
		partition_index = lomuto_partition(array, size, low, high);
		lomuto_sort(array, size, low, partition_index - 1);
		lomuto_sort(array, size, partition_index + 1, high);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
