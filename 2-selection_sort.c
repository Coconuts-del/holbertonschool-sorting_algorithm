#include "sort.h"

/**
 * selection_sort - sorts integers array in ascending order using
 * selection sort algorithm
 * @array: array interger to sort
 * @size : number of elements of the array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, tmpidx;
	int tmpdata = 0;


	for (i = 0; i < size - 1; i++)
	{
		tmpidx = i;
		for (j = i + 1; j < size ; j++)
		{
			if (array[tmpidx] > array[j])
				tmpidx = j;
		}
		if (tmpidx != i)
		{
			tmpdata = array[i];
			array[i] = array[tmpidx];
			array[tmpidx] = tmpdata;
			print_array(array, size);
		}
	}
}
