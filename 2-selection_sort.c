#include "sort.h"

/**
*swap - A function that swaps two integers
*@a: Pointer to the first integer
*@b: Pointer to the second integer
*Return: VOID
*/
void swap(int *a, int *b)
{
	int temp; /*Temporary Variable*/

	temp = *a;
	*a = *b;
	*b = temp;

}

/**
*selection_sort - Sorts an array of integers in
*ascending order using the Selection Sort
*@array: Pointer to the array to sort
*@size: Size of the array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	/*Loop to iterate the array*/
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}
		if (min_idx != i)
		{
			swap(&array[i], &array[min_idx]);
			print_array(array, size);
		}
	}
}
