#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * the Selection sort algorithm
 * @array: array
 * @size: size
 */
void selection_sort(int *array, size_t size)
{
    if (array == NULL || size <= 1)
        return;

    for (size_t i = 0; i < size - 1; i++)
    {
        size_t min_idx = i;

        for (size_t j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_idx])
                min_idx = j;
        }

        if (min_idx != i)
        {
            int temp = array[i];
            array[i] = array[min_idx];
            array[min_idx] = temp;
            print_array(array, size);
        }
    }
}
