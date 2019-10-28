#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Number of elements
#define ARRAY_SIZE      64000

// Type of data
#define U_INT           32
#define DATA_TYPE       U_INT

// Masks
#define M_3b            0x00000007
#define M_NIBBLE        0x0000000F
#define M_BYTE          0x000000FF
#define MASK            M_BYTE

// Number of possible values with mask
#define V_3b            8
#define V_NIBBLE        16
#define V_BYTE          256
#define NB_VALUES       V_BYTE

// Number of bits for the mask
#define B_3b            3
#define B_NIBBLE        4
#define B_BYTE          8
#define SHIFT           B_BYTE          

// Sort by nibble
void count_sort(unsigned int *array, int n, unsigned int shift){
    unsigned int *output = malloc(n*sizeof(unsigned int));
    int i, count[NB_VALUES] = {0}; //Values from 0 to 15 -> 16 values for a nibble

    if(output == NULL)
    {
        printf("Failed to allocate");
    }

    // Count occurences for each nibble
    for (i = 0; i < n; i++){
        count[(array[i]>>shift)&MASK]++;
    }

    // Translate count into real position in output 
    // Array highest index for highest values 
    for (i = 1; i < NB_VALUES; i++) 
        count[i] += count[i - 1]; 

    // Create output array 
    for (i = n - 1; i >= 0; i--) 
    { 
        output[count[(array[i]>>shift)&MASK] - 1] = array[i]; 
        count[(array[i]>>shift)&MASK]--; 
    } 
  
    // Copy the output in the array
    for (i = 0; i < n; i++) 
        array[i] = output[i]; 

    free(output);
}

// Sort for every nibbles
void radix_sort(unsigned int *array, int n){
    for (unsigned int shift = 0 ; shift<DATA_TYPE ; shift+=SHIFT) // example : max = 2350 et exp = 1000 -> 2.3 which means last digit
    {
        count_sort(array, n, shift);
    }
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
    unsigned int array[ARRAY_SIZE] = {0};
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
            array[j] = tmp;
            j++;
        }

    // Print array before sorting
        printf("\nBefore\n");
        print_array(array, 100);

    // Sorting
        clock_t begin   = clock();
        radix_sort(array, ARRAY_SIZE);
        clock_t end     = clock();
        double elapsed_time = (double)(end-begin)/CLOCKS_PER_SEC;

    // Print array after sorting
        printf("\nAfter\n");
        print_array(array, 100);
    
    // Elasped time
        printf("Elapsed time : %lf\n", elapsed_time);
    
    // Check
        for (size_t i = 0; i < ARRAY_SIZE-1; i++)
        {
            if(array[i]>array[i+1]){
                printf("Wrong sorting\n");
                return 1;
            }   
        }
        printf("Correct sorting\n");

    return 0;
}
