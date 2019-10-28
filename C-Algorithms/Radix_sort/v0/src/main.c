#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE   64000


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
void count_sort(unsigned int *array, int n, unsigned int exp){
    unsigned int *output = malloc(n*sizeof(unsigned int));
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

// Sort by digit for every digit
void radix_sort(unsigned int *array, int n){
    unsigned int max = get_max(array, n);   // find number of digits

    for (unsigned int exp = 1 ; max/exp > 0 ; exp*=10) // example : max = 2350 et exp = 1000 -> 2.3 which means last digit
    {
        count_sort(array, n, exp);
    }
}

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


    printf("\nBefore\n");
    print_array(array, 100);
    clock_t begin   = clock();
    radix_sort(array, ARRAY_SIZE);
    clock_t end     = clock();
    double elapsed_time = (double)(end-begin)/CLOCKS_PER_SEC;

    printf("\nAfter\n");
    print_array(array, 100);
    
    printf("Elapsed time : %lf\n", elapsed_time);


    
    return 0;
}
