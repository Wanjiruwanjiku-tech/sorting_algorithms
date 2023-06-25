#include "sort.h"

/**
*bubble_sort - Sorts an array of integers in ascending
*order using the Bubble Sort Algorithm
*@array: Pointer to the array to sort
*@size: The size of the array
*Return: VOID
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j; /*Vars for iteration*/
	int temp; /*Temporary var for swapping*/
	int swapped; /*Tracker*/

	/*Outer loop for transversing array*/
	for (i = 0; i < size - 1; i++)
	{
		swapped = 0; /*Initialize tracker*/
		/*Loop for Comparison & Swapping*/
		for (j = 0; j < size - i - 1; j++)
		{
			/*Compare and swap if true*/
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1; /*True*/
				print_array(array, size);
			}
		}
		if (swapped == 0)
		{
			break;
		}
	}
}
