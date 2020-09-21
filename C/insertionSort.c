#include <stdio.h>

void insertion_sort(int *array, int length);
void print_array(int *array, int length);

int main(int argc, char **argv)
{
    int array[5] = {5, 4, 3, 2, 1};
    insertion_sort(array, 5);
    print_array(array, 5);
    
    return 0;
}

void insertion_sort(int *array, int length)
{
    int i, j, temp;

    for (i = 1; i < length; i++)
    {
	for (j = i; j > 0 && array[j] < array[j - 1]; j--)
	{
	    temp = array[j];
	    array[j] = array[j - 1];
	    array[j - 1] = temp;
	}
    }
}

void print_array(int *array, int length)
{
    int i;

    for (i = 0; i < length; i++)
	printf("%d ", array[i]);
    printf("\n");
}
