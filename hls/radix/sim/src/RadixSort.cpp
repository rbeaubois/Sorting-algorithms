#include "RadixSort.h"

void count_sort(sc_uint<DATA_TYPE> *array_src, sc_uint<DATA_TYPE> *array_dst, sc_uint<ADDR_SIZE> n, sc_uint<8> shift){
    sc_uint<ADDR_SIZE> i = 0;
    sc_uint<ADDR_SIZE> count[NB_VALUES] = {0};

    // Count occurences for each nibble
    for (i = 0; i < n; i++){
        count[array_src[i].range(SHIFT+shift-1,shift)]++;
    }

    // Translate count into real position in output 
    // Array highest index for highest values 
    for (i = 1; i < NB_VALUES; i++) 
        count[i] += count[i - 1]; 

    // Fill output array   
    for (sc_int<ADDR_SIZE+1> j = n-1 ; j >= 0; j--) 
    { 
        count[array_src[j].range(SHIFT+shift-1,shift)]--;
        array_dst[count[array_src[j].range(SHIFT+shift-1,shift)]] = array_src[j];  
    }    
}

void radix_sort_byte(sc_uint<DATA_TYPE> *array1, sc_uint<DATA_TYPE> *array2, sc_uint<ADDR_SIZE> n){
    sc_uint<8> shift = 0;
    count_sort(array1, array2, n, shift);
    shift+=SHIFT;
    count_sort(array2, array1, n, shift);
    shift+=SHIFT;
    count_sort(array1, array2, n, shift);
    shift+=SHIFT;   
    count_sort(array2, array1, n, shift); 
}


void RadixSort::do_sort(){
	sc_uint<ADDR_SIZE> i = 0;

	while( true ){
            for (i = 0; i < ARRAY_SIZE; i++)
            {
                array1[i] = e.read();   
            }

			radix_sort_byte(array1, array2, ARRAY_SIZE);

            for (i = 0; i < ARRAY_SIZE; i++)
            {
                s.write(array1[i]);
            }
	}
}
