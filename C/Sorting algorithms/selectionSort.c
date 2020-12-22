#include <stdio.h>

void selection_sort(int *array, int size);
void swap(int *a, int *b);

int main(int argc, char **argv)
{
    int array[5] = {5, 3, 4, 2, 1};
    int size = sizeof(array) / sizeof(int);
    selection_sort(array, size);

    int i;
    for (i = 0; i < size; i++)
    {
	printf("%d ", array[i]);
    }
    return 0;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int *array, int size)
{
    int i, j, minimum;
    
    
    for (i = 0; i < size; i++)
    {
	for (j = i, minimum = i; j < size; j++)
	{
	    if (array[minimum] > array[j])
	    {
		minimum = j;
	    }
	}
	swap(&array[i], &array[minimum]);
    }
}
