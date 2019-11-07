#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Number of elements
#define ARRAY_SIZE      64000

// Type of data
#define U_INT           32
#define DATA_TYPE       U_INT

// Masks
#define M_NIBBLE        0x0000000F
#define M_BYTE          0x000000FF
#define MASK            M_BYTE

// Number of possible values with mask
#define V_NIBBLE        16
#define V_BYTE          256
#define NB_VALUES       V_BYTE

// Number of bits for the mask
#define B_NIBBLE        4
#define B_BYTE          8
#define SHIFT           B_BYTE          

// Sort by nibble
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

    // Create output array 
    for (i = n - 1; i >= 0; i--) 
    { 
        array_dst[count[(array_src[i]>>shift)&MASK] - 1] = array_src[i]; 
        count[(array_src[i]>>shift)&MASK]--; 
    } 
}

// Sort for every nibbles
void radix_sort(unsigned int *array1, unsigned int *array2, int n){
    unsigned int shift = 0;
    count_sort(array1, array2, n, shift);
    shift+=SHIFT;
    count_sort(array2, array1, n, shift);
    shift+=SHIFT;
    count_sort(array1, array2, n, shift);
    shift+=SHIFT;   
    count_sort(array2, array1, n, shift); 
}

// Print <n> elements of unsigned int array
void print_array(unsigned int *array, int n){
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%u\t", array[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    unsigned int array1[ARRAY_SIZE] = {0};
    unsigned int array2[ARRAY_SIZE] = {0};
    unsigned int tmp;
    int j = 0;
    char buffer[16]={0};

    FILE *fp;

    // Generate array from file
        if ((fp = fopen("../../../Data/random.txt","r")) == NULL)
        {
            printf("failed to open");
            exit(1);
        }

        while(j<ARRAY_SIZE){
            fgets(buffer, 16, fp);
            sscanf(buffer, "%u\n", &tmp);
            array1[j] = tmp;
            j++;
        }

    // Print array before sorting
        printf("\nBefore\n");
        print_array(array1, 100);

    // Sorting
        clock_t begin   = clock();
        radix_sort(array1, array2, ARRAY_SIZE);
        clock_t end     = clock();
        double elapsed_time = (double)(end-begin)/CLOCKS_PER_SEC;

    // Print array after sorting
        printf("\nAfter\n");
        print_array(array1, 100);
    
    // Elasped time
        printf("Elapsed time : %lf\n", elapsed_time);
    
    // Check
        for (size_t i = 0; i < ARRAY_SIZE-1; i++)
        {
            if(array1[i]>array1[i+1]){
                printf("Wrong sorting\n");
                return 1;
            }   
        }
        printf("Correct sorting\n");

    return 0;
}
