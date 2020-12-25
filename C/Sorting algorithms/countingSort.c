#include <stdio.h>

int uniqe_numbers(int *array);
int max_number(int *array);
void counting_sort(int *array);

int main(int argc, char **agrv)
{
    int array[5] = {5, 4, 3, 2, 1};
    int size = sizeof(array) / sizeof(int);
    counting_sort(array);

    int i;
    for (i = 0; i < size; i++)
    {
	printf("%d ", array[i]);
    }
    return 0;
}


int uniqe_numbers(int *array)
{
    int counter;
    
    int i, j, flag;
    for (i = counter = 0; array[i]; i++)
    {
        flag = 0;
        for (j = 0; j < i; j++)
        {
            if (array[i] == array[j])
            {
                flag = 1;
            }
        }
        
        if (!flag)
        {
            counter++;
        }
    }
    
    return counter;
}

int max_number(int *array)
{
    int i, max;

    for (i = 0, max = array[i]; array[i]; i++)
    {
	max = (array[i] > max) ? array[i] : max;
    }

    return max;
}

void counting_sort(int *array)
{
    int max = max_number(array);
    int uniqes = uniqe_numbers(array);

    int frequencies[max];

    int i;
    for (i = 0; i < max; i++)
    {
        frequencies[i] = 0;
    }
    
    for (i = 0; array[i]; i++)
    {
	frequencies[array[i]]++;
    }

    int output[i];
    
    for (i = 1; frequencies[i]; i++)
    {
	frequencies[i] += frequencies[i - 1];
    }

    for (i = 0; array[i]; i++)
    {
	output[frequencies[array[i]] - 1] = array[i];
	frequencies[array[i]]--;
    }

    for (i = 0; array[i]; i++)
    {
	array[i] = output[i];
    }
    
}
