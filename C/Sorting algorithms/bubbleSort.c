#include <stdio.h>

void bubble_sort(int *array, int size);
void swap(int *a, int *b);

int main(int argc, char **argv)
{
    int array[5] = {3,44,38,5,47};
    int size = sizeof(array) / sizeof(int);
    bubble_sort(array, size);
    for (int i = 0; i < size; i++) printf("%d\n", array[i]);
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *array, int size)
{
    int i, j;

    for (i = 0; i < size; i++)
    {
	for (j = 0; j < size - 1; j++)
	{
	    if (array[j] > array[j + 1])
	    {
		swap(&array[j], &array[j + 1]);
	    }
	}
    }
}
