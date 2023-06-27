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
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < *min)
			{
				min = array + j;
			}
			else
			{
				min = min;
			}
		}
		if ((array + i) != min)
		{
			swap_integers(array + i, min);
			print_array(array, size);
		}
	}
}
