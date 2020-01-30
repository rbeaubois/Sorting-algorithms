#include "bubble.h"

void swap(unsigned int* a, unsigned int* b){
	unsigned int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubble_sort(unsigned int data[], int len) {
	int i,j;
	unsigned int a, b, c, d;
	bool toggle =false;

    for(i = 0; i < len; i++) {
        for(j = 0; j < len-i-1; j++) {
#pragma HLS DEPENDENCE variable=a intra WAR true
#pragma HLS DEPENDENCE variable=data array intra RAW true
#pragma HLS PIPELINE
        	if(data[i+1] > data[i])
        	{
        		swap(&(data[i+1]), &(data[i]));
        	}
        }
    }
}
