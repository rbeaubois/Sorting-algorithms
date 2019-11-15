#include "selection.h"

void swap(unsigned int *a, unsigned int *b)
{
    unsigned int tmp = *a;
    *a = *b;
    *b = tmp;
}

unsigned int* Selection::sort(unsigned int data[], int len)
{
    int min_index;
    int j;

    for (int i = 0; i < len - 1; i++)
    {
        min_index = i;

        for (j = i + 1; j < len; j++)
        {
            if (data[j] < data[min_index])
            {
                min_index = j;
            }
        }
        swap(&data[min_index], &data[i]);
    }
    return data;
}