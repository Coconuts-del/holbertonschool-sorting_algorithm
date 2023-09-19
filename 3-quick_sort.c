#include "sort.h"

/**
 * partition - scans a partition of an array of integers for values less than
 * pivot value, and swaps them with first value in partition, then swaps pivot
 * value with first value in partition
 * @array: array of integers to be sorted
 * @beg_part: index in array that begins partition
 * @end_part: index in array that ends partition
 * @size: amount of elements in array
 * Return: new index at which to start new recursive partition
 */
int partition(int *array, int beg_part, int end_part, size_t size)
{
	int i, j, pivot, tmp;

	pivot = array[end_part];
	i = beg_part;
	for (j = beg_part; j < end_part; j++)
	{
		if (array[j] < pivot)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (array[i] != array[j])
				print_array(array, size);
			i++;
		}
	}
	tmp = array[i];
	array[i] = array[end_part];
	array[end_part] = tmp;
	if (array[i] != array[end_part])
		print_array(array, size);
	return (i);
}

/**
 * qs_recursion - recursively sorts array of integers by separating into two
 * partitions, using Lomuto quick sort
 * @array: array of integers to be sorted
 * @beg_part: index in array that begins partition
 * @end_part: index in array that ends partition
 * @size: amount of elements in array
 */
void qs_recursion(int *array, int beg_part, int end_part, size_t size)
{
	int pivot;

	if (beg_part < end_part)
	{
		pivot = partition(array, beg_part, end_part, size);
		qs_recursion(array, beg_part, pivot - 1, size);
		qs_recursion(array, pivot + 1, end_part, size);
	}
}

/**
 * quick_sort - sorts integers array in ascending order using quick sort algo
 * @array: array interger to sort
 * @size : number of elements of the array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	qs_recursion(array, 0, size - 1, size);
}
