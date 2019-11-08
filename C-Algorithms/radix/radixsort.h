
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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


/* ********************************* Radix sort by byte **************************************** */
// Sort for every byte
void radix_sort(unsigned int *array1, unsigned int *array2, int n);

// Sort by byte
void count_sort(unsigned int *array_src, unsigned int *array_dst, int n, unsigned int shift);



/* ********************************* Radix sort by digit  **************************************** */
// Sort by digit for every digit
void radix_sort_digit(unsigned int *array, int n);

// Sort by digit for a digit
void count_sort_digit(unsigned int *array, int n, unsigned int exp);

// Get max to know number of digits
unsigned int get_max(unsigned int *array, int n);

