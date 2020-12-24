#include <stdio.h>

void merge_sort(int *array,
		int low, int high);

void merge(int *array,
	   int low, int high, int mid);


int main(int argc, char **argv)
{
    int array[5] = {5,3,4,2,1};
    int size = sizeof(array) / sizeof(int);
    merge_sort(array, 0, size - 1);

    int i;
    for (i = 0; i < size; i++)
    {
	printf("%d ", array[i]);
    }
    return 0;
}

void merge_sort(int *array,
		int low, int high)
{
    if (low < high)
    {
	int mid = low + (high - low) / 2;
	merge_sort(array, low, mid);
	merge_sort(array, mid + 1, high);
	merge(array,
	      low, high, mid);
    }
}

void merge(int *array,
	   int low, int high, int mid)
{
    int left_len = (mid - low) + 1;
    int right_len = (high - mid) + 1;
    
    int left_part[left_len];
    int right_part[right_len];

    int i, j;
    int part_counter;

    for (i = 0; i < left_len; i++)
    {
	left_part[i] = array[low + i];
    }

    for (j = 0; j < right_len; j++)
    {
	right_part[j] = array[mid + 1 + j];
    }

    i = j = 0;
    int index = low;
    while (i < left_len && j < right_len)
    {
	if (left_part[i] < right_part[j])
	{
	    array[index++] = left_part[i++];	    
	}
	else
	{
	    array[index++] = right_part[j++];
	}
    }

    while (i < left_len)
    {
	array[index++] = left_part[i++];	    
    }

    while (j < right_len)
    {
	array[index++] = right_part[j++];
    }
}


