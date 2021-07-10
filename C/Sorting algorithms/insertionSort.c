#include <stdio.h>

void insertion_sort(int *array, int size);
void swap(int *a, int *b);

int main(int argc, char **argv)
{
    int array[5] = {5, 3, 4, 2, 1};
    int size = sizeof(array) / sizeof(int);
    insertion_sort(array, size);

    int i;
    for (i = 0; i < size; i++)
    {
	printf("%d ", array[i]);
    }
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort(int *array, int size)
{
    int i, j;

    for (i = 1; i < size; i++)
    {
	for (j = i; j > 0 && array[j] < array[j - 1]; j--)
	{
	    swap(&array[j], &array[j - 1]);
	}
    }
    
}
