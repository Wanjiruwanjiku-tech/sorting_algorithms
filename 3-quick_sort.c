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
*partition - A Function that performs the partitioning
*step of the quick sort algorithm
*@array: An array
*@low: lowest integer
*@high: highest integer
*Return: Integer Type
*/
int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - i; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

/**
*quick_sort_recursive - A recursive helper function
*Description: It Implements the divide and conqure
*approach to recursively sort the sub-arrays
*@array: The array
*@low: The lower index
*@high: The higher index
*Return: VOID
*/
void quick_sort_recursive(int *array, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high);
		print_array(array + low, high - low + 1);

		quick_sort_recursive(array, low, pivot - 1);
		quick_sort_recursive(array, pivot + 1, high);
	}
}

/**
*quick_sort - Sorts an array of integers in ascending
*order using the sort algorithm
*@array: Pointer to array to sort
*@size: Size of array
*Return: VOID
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
	{
		return;
	}
	quick_sort_recursive(array, 0, size - 1);
}
