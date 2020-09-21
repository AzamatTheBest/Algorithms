include <stdio.h>

void selection_sort(int *array, int length);
void print_array(int *array, int length);

int main(int argc, char **argv)
{
    int array[5] = {5, 4, 3, 2, 1};
    selection_sort(array, 5);
    print_array(array, 5);
    return 0;
}

void selection_sort(int *array, int length)
{
    int i, j, temp;

    for (i = 0; i < length; i++)
    {
	for (j = i; j < length; j++)
	{
	    if (array[j] < array[i])
	    {
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	    }
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
