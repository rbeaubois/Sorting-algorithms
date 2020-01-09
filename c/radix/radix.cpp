#include "radix.h"
#include <omp.h>

/* ********************************* Implement radix sort  **************************************** */
unsigned int* Radix::sort(unsigned int data[], int len) {
	radix_sort(data, len);
	return data;
}

/* ********************************* Radix sort by byte **************************************** */
// Sort for every byte
void radix_sort(unsigned int *array1, int n){
    unsigned int shift = 0;
    unsigned int *array2 = (unsigned int*)malloc(n*sizeof(unsigned int));
    count_sort(array1, array2, n, shift);
    shift+=SHIFT;
    count_sort(array2, array1, n, shift);
    shift+=SHIFT;
    count_sort(array1, array2, n, shift);
    shift+=SHIFT;   
    count_sort(array2, array1, n, shift); 
    free(array2);
}

// Sort by byte
void count_sort(unsigned int *array_src, unsigned int *array_dst, int n, unsigned int shift){
    int i, count[NB_VALUES] = {0}; //Values from 0 to 15 -> 16 values for a nibble

    // Count occurences for each nibble
    for (i = 0; i < n; i++){
        count[(array_src[i]>>shift)&MASK]++;
    }

    // Translate count into real position in output 
    // Array highest index for highest values 
    for (i = 1; i < NB_VALUES; i++) 
        count[i] += count[i - 1]; 

    // Fill output array 
    for (i = n - 1; i >= 0; i--) 
    { 
        array_dst[count[(array_src[i]>>shift)&MASK] - 1] = array_src[i]; 
        count[(array_src[i]>>shift)&MASK]--; 
    } 
}

/* ********************************* Radix sort by byte with opti **************************************** */
// Sort for every byte
void radix_sort_v2(unsigned int *array1, int n){
    unsigned int shift = 0;
    unsigned int *array2 = (unsigned int*)malloc(n*sizeof(unsigned int));
    int count_1[NB_VALUES] = {0};
    int count_2[NB_VALUES] = {0};
    int count_3[NB_VALUES] = {0};
    int count_4[NB_VALUES] = {0};

    count_occ_v2(array1, n, count_1, count_2, count_3, count_4);

    sort_occ_v2(array1, array2, n, shift, count_1);
    shift+=SHIFT;
    sort_occ_v2(array2, array1, n, shift, count_2);
    shift+=SHIFT;
    sort_occ_v2(array1, array2, n, shift, count_3);
    shift+=SHIFT;   
    sort_occ_v2(array2, array1, n, shift, count_4); 
    
    free(array2);
}

// Count occurences
void count_occ_v2(unsigned int *array_src, int n, int c1[], int c2[], int c3[], int c4[]){
    int i; //Values from 0 to 15 -> 16 values for a nibble
    unsigned int tmp;

    // Count occurences for each nibble
    for (i = 0; i < n; i++){
        tmp = array_src[i];
        c1[tmp&MASK]++;
        c2[(tmp>>SHIFT)&MASK]++;
        c3[(tmp>>(2*SHIFT))&MASK]++;
        c4[(tmp>>(3*SHIFT))&MASK]++;
    }

    // Translate count into real position in output 
    // Array highest index for highest values 
    for (i = 1; i < NB_VALUES; i++){
        c1[i] += c1[i - 1]; 
        c2[i] += c2[i - 1]; 
        c3[i] += c3[i - 1]; 
        c4[i] += c4[i - 1]; 
    }
}

// Sort by byte
void sort_occ_v2(unsigned int *array_src, unsigned int *array_dst, int n, unsigned int shift, int count[]){
    // Fill output array 
    int i = 0;
    for (i = n - 1; i >= 0; i--) 
    { 
        array_dst[count[(array_src[i]>>shift)&MASK] - 1] = array_src[i]; 
        count[(array_src[i]>>shift)&MASK]--; 
    } 
}


/* ********************************* Radix sort by digit  **************************************** */
// Sort by digit for every digit
void radix_sort_digit(unsigned int *array, int n){
    unsigned int max = get_max(array, n);   // find number of digits

    for (unsigned int exp = 1 ; max/exp > 0 ; exp*=10) // example : max = 2350 et exp = 1000 -> 2.3 which means last digit
    {
        count_sort(array, (unsigned int*)&n, exp, 0);
    }
}

// Get max to know number of digits
unsigned int get_max(unsigned int *array, int n){
    unsigned int max = array[0];

    for (int i = 0; i < n; i++)
    {
        if (array[i]>max)
            max = array[i];
    }

    return max;
}

// Sort by digit for a digit
void count_sort_digit(unsigned int *array, int n, unsigned int exp){
    unsigned int *output = (unsigned int*)malloc(n*sizeof(unsigned int));
    int i, count[10] = {0};

    if(output == NULL)
    {
        printf("Failed to allocate");
    }

    // Count occurences for each digit values | example : digit 9 -> 8 occurences
    for (i = 0; i < n; i++){
        count[(array[i]/exp)%10]++;
    }

    // Change count[i] so that count[i] now contains actual 
    //  position of this digit in output[] 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 

    // Build the output array 
    for (i = n - 1; i >= 0; i--) 
    { 
        output[count[ (array[i]/exp)%10 ] - 1] = array[i]; 
        count[ (array[i]/exp)%10 ]--; 
    } 
  
    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (i = 0; i < n; i++) 
        array[i] = output[i]; 

    free(output);
}

