#include <stdio.h>

void quick_sort(int *array,
		int low, int high);
int partition(int *array,
	      int low, int high);
void swap(int *a, int *b);

int main(int argc, char **argv)
{
    int array[5] = {5, 3, 4, 2, 1};
    int size  = sizeof(array) / sizeof(int);

    quick_sort(array, 0, size - 1);

    int i;

    for (i = 0; i < size; i++)
    {
	printf("%d ", array[i]);
    }
    return 0;
}

void quick_sort(int *array,
		int low, int high)
{
    if (low < high)
    {
	int pi = partition(array, low, high);
	quick_sort(array, low, pi);
	quick_sort(array, pi + 1, high);
    }
}

int partition(int *array,
	      int low, int high)
{
    int pivot = array[high];

    int i, j;

    for (i = low - 1, j = low; j <= high - 1; j++)
    {
	if (array[j] <= pivot)
	{
	    i++;
	    swap(&array[i], &array[j]);
	}
    }

    swap(&array[i + 1], &array[j]);

    return i + 1;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
