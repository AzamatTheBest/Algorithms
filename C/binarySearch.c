#include <stdio.h>

int binary_search(int *array, int p, int q, int elem);

int main(int argc, char **argv)
{
    int array[5] = {1, 2, 3, 4, 5};

    printf("%d\n", binary_search(array, 0, 4, 5));
    return 0;
}


int binary_search(int *array, int p, int q, int elem)
{
    int index = (p + q) / 2;
    if (array[index] == elem)
    {
	return index;
    }
    else if (array[index] < elem)
    {
	binary_search(array, index + 1, q, elem);
    }
    else
    {
	binary_search(array, p, index - 1, elem);
    }
}
