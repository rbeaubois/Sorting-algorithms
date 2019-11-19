#include "trident.h"

#include <stdio.h>

#define BITONIC_SORTER_SIZE 16

Trident::Trident() {

}

Trident::~Trident() {

}

unsigned int* Trident::sort(unsigned int data[], int len) {
	/*
	for (int i = 0; i<len; i++) {
		printf("%8x\t", data[i]);
	}
	printf("\n");
	*/
	bitonicsort(data, 15);
	/*
	for (int i = 0; i<len; i++) {
		printf("%8x\t", data[i]);
	}
	printf("\n");
	*/
	return data;
}

void qs_divide(unsigned int data[], int len) {
	
}

void bitonicsort(unsigned int* data, unsigned int step) {
	unsigned int tsize = (1<<step);
	for (unsigned int i = 0; i < step; i++) {
		//printf("step: %d\n", i);
		for (unsigned int j = 0; j <= i; j++) {
			//printf("\tsubstep: %d\n", j);
			int group_size = 1<<(i-j+1);
			//printf("\t\tgroup_size: %d\n", group_size);
			unsigned int swap_interval = 1 << (i-j);
			//printf("\t\tswap_interval: %d\n", swap_interval);
			if (j==0) {
				for (unsigned int k = 0; k < tsize; k += group_size) {
					for (unsigned l = 0; l < swap_interval; l++) {
						//printf("\t\te[%d] <-> e[%d]\n", k+l, k-l+group_size-1);
						swapcmp(&data[k+l], &data[k-l+group_size-1]);
					}
				}
			} else {
				for (unsigned int k = 0; k < tsize; k += group_size) {
					for (unsigned l = 0; l < swap_interval; l++) {
						//printf("\t\te[%d] <-> e[%d]\n", k+l, k+l+swap_interval);
						swapcmp(&data[k+l], &data[k+l+swap_interval]);
					}
				}
			}
			/*
			for (unsigned int u = 0; u < tsize; u++) {
				printf("%8x\t", data[u]);
			}
			printf("\n\n");
			*/
		}
	}
}

inline void swapcmp(unsigned int* a, unsigned int* b) {
	if (*a > *b) {
		unsigned int buf = *b;
		*b = *a;
		*a = buf;
	}
}
