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
 * hoare_partition - Order a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @low: The starting index of the subset to order.
 * @high: The ending index of the subset to order.
 * Return: The final partition index.
 * Description: Uses the last element of the partition as the pivot.
 *		Prints the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int low, int high)
{
	int above, below, pivot = array[high];

	for (above = low - 1, below = high + 1; above < below;)
	{
		while (array[above] < pivot)
		{
			above++;
		}
		while (array[below] > pivot)
		{
			below--;
		}
		if (above < below)
		{
			swap_integers(array + above, array + below);
			print_array(array, size);
		}
	}
	return (above);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @low: The starting index of the array partition to order.
 * @high: The ending index of the array partition to order.
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int low, int high)
{
	int partition_index;

	if (high - low > 0)
	{
		partition_index = hoare_partition(array, size, low, high);
		hoare_sort(array, size, low, partition_index - 1);
		hoare_sort(array, size, partition_index, high);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
