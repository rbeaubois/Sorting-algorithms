#include "trident.h"

#include <stdio.h>

#define BITONIC_SORTER_SIZE 16

Trident::Trident() {

}

Trident::~Trident() {

}

unsigned int* Trident::sort(unsigned int data[], int len) {
	return data;
}

void qs_divide(unsigned int data[], int len) {
	
}

void bitonicsort(unsigned int* data, unsigned int step) {
	for (unsigned int i = 0; i<step; i++) {
		for (unsigned int j = 0; j<i; j++) {
			int group_size = 1<<(i-j+1);
			printf("group_size: %d\n", group_size);
		}
	}
}
