#ifndef RADIX_H
#define RADIX_H

#include <stdio.h>
#include <stdlib.h>

// Data size
#define NB_DATA			65536

// Type of data
#define U_INT           32
#define DATA_TYPE       U_INT

// Masks
#define M_BYTE          0x000000FF
#define MASK            M_BYTE

// Number of possible values with mask
#define V_BYTE          256
#define NB_VALUES       V_BYTE

// Number of bits for the mask
#define B_BYTE          8
#define SHIFT           B_BYTE       

/* ********************************* Radix sort by byte **************************************** */
// Sort for every byte
void radix_sort(unsigned int *array1, int n);

// Sort by byte
void count_sort(unsigned int *array_src, unsigned int *array_dst, int n, unsigned int shift);


/* ********************************* Radix sort by byte with opti **************************************** */
// Sort by byte but trying to use parallelisable operations (might be better for FPGA implementation)
void radix_sort_v2(unsigned int *array1, int n);
// Count occurences
void count_occ_v2(unsigned int *array_src, int n, int c1[], int c2[], int c3[], int c4[]);
// Sort by byte
void sort_occ_v2(unsigned int *array_src, unsigned int *array_dst, int n, unsigned int shift, int count[]);

#endif
