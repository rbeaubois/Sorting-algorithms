#include "insertion.h"

unsigned int* Insertion::sort(unsigned int data[], int len)
{
    unsigned int pivot;
    int j;

    for (int i = 1; i < len ; i++)
    {
        pivot = data[i];
        j = i - 1;

        while (j>= 0 && data[j] > pivot)
        {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j+1] = pivot;
    }
    return data;
}