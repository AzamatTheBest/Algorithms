#include <stdio.h>

void quicksort(int *array, int low, int high);
int partition(int *array, int low, int high);

int main(int argc, char **argv)
{
    int array[] = {5, 4, 3, 2, 1};
    int size = sizeof(array)/sizeof(int);
    quicksort(array, 0, size - 1);

    int i;
    for (i = 0; i < size; i++)
    {
	printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}


void quicksort(int *array, int low, int high)
{
    int pi;
    
    if (low < high)
    {
	pi = partition(array, low, high);

	quicksort(array, low, pi - 1);
	quicksort(array, pi + 1, high);	
    }
}

int partition(int *array, int low, int high)
{
    int pivot, temp, i, j;

    pivot = array[high];
    i = low - 1;

    for (j = low; j <= high - 1; j++)
    {
	if (array[j] <= pivot)
	{
	    i++;
	    temp = array[j];
	    array[j] = array[i];
	    array[i] = temp;
	    
	}
    }

    temp = array[high];
    array[high] = array[i + 1];
    array[i + 1] = temp;

    return i + 1;
}

