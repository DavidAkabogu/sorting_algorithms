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
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t interval, i, j;

	if (array == NULL || size < 2)
		return;

	for (interval = 1; interval < (size / 3);)
	{
		interval = interval * 3 + 1;
	}
	for (; interval >= 1; interval /= 3)
	{
		for (i = interval; i < size; i++)
		{
			j = i;
			while (j >= interval && array[j - interval] > array[j])
			{
				swap_integers(array + j, array + (j - interval));
				j -= interval;
			}
		}
		print_array(array, size);
	}
}
