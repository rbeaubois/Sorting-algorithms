#include "tim.h"
#include <bits/stdc++.h>
using namespace std;
const int RUN = 32;

// this function sorts array from left index to
// to right index which is of size atmost RUN
void insertionSort(unsigned int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        unsigned int temp = arr[i];
        int j = i - 1;
        while (arr[j] > temp && j >= left)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// merge function merges the sorted runs
void merge(unsigned int arr[], int l, int m, int r)
{
    // original array is broken in two parts
    // left and right array
    int len1 = m - l + 1, len2 = r - m;
    unsigned int left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;

    // after comparing, we merge those two array
    // in larger sub array
    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // copy remaining elements of left, if any
    while (i < len1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }

    // copy remaining element of right, if any
    while (j < len2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}

// iterative Timsort function to sort the
// array[0...n-1] (similar to merge sort)
unsigned int* Tim::sort(unsigned int data[], int len)
{
    // Sort individual subarrays of size RUN
    for (int i = 0; i < len; i += RUN)
        insertionSort(data, i, min((i + 31), (len - 1)));

    // start merging from size RUN (or 32). It will merge
    // to form size 64, then 128, 256 and so on ....
    for (int size = RUN; size < len; size = 2 * size)
    {
        // pick starting point of left sub array. We
        // are going to merge arr[left..left+size-1]
        // and arr[left+size, left+2*size-1]
        // After every merge, we increase left by 2*size
        for (int left = 0; left < len; left += 2 * size)
        {
            // find ending point of left sub array
            // mid+1 is starting point of right sub array
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (len - 1));

            // merge sub array arr[left.....mid] &
            // arr[mid+1....right]
            merge(data, left, mid, right);
        }
    }
    return data;
}
