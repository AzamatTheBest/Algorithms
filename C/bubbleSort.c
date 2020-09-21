#include <stdio.h>

void buble_sort(int *array, int length);
void print_array(int *array);

int main(int argc, char **argv)
{
    int array[5] = {5, 4, 3, 2, 1};
    buble_sort(array, 5);
    print_array(array);
    
    return 0;
}

void buble_sort(int *array, int length)
{
    int i, j, temp;

    for (i = 0; i < length - 1; i++)
    {
	for (j = i; j < length; j++)
	{
	    if (array[j] > array[j + 1])
	    {
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	    }
	}
    }
}

void print_array(int *array)
{
    int i;
    
    for (i = 0; i < 5; i++)
	printf("%d ", array[i]);
    printf("\n");
}
