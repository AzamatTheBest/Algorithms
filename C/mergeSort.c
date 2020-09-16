#include <stdio.h>

#define LENGTH 5

void merge(int *array, int low, int mid , int high);
void merge_sort(int *array, int low, int high);
void print_array(int *array, int length);

int main(int argc, char **argv)
{
    int arr[5] = {5, 4, 1, 2, 3};

    print_array(arr, LENGTH);
    merge_sort(arr, 0, 4);
    print_array(arr, LENGTH);
    
    return 0; 
}

void merge_sort(int *array, int low, int high)
{
    if (low < high)
    {
	int mid = low + (high - low) / 2;
	merge_sort(array, low, mid);
	merge_sort(array, mid + 1, high);

	merge(array, low, mid, high);
    }
}

void merge(int *array, int low, int mid, int high)
{
    int i, j, k;

    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1];
    int R[n2];

    for (i = 0; i < n1; i++) L[i] = array[low + i];
    for (j = 0; j < n2; j++) R[j] = array[mid + 1 + j];

    j = i = 0;
    k = low;
    while (i < n1 && j < n2)
    {
	if (L[i] <= R[j])
	{
	    array[k] = L[i];
	    i++;
	}
	else
	{
	    array[k] = R[j];
	    j++;
	}
	k++;
    }

    while (i < n1)
    {
	array[k] = L[i];
	k++;
	i++;
    }
    
    while (j < n2)
    {
	array[k] = R[j];
	k++;
	j++;
    }
    
}

void print_array(int *array, int length)
{
    int i;
    for (i = 0; i < length; i++)
	printf("%d ", array[i]);
    printf("\n");
}
