#include "trident.h"

#include <stdio.h>

void trident_sort(unsigned int data[], int len) {
	bitonicsort(data, len);
}

// si = swap offset
// gs = sub group size
void bitonicsort(unsigned int* const data, unsigned int const step) {
	unsigned int const tsize = (1<<step);
	for (unsigned int i = 0; i < step; i++) {
		unsigned int si = 1 << i;	//si = 1<<(i-j)
		unsigned int gs = si << 1;	//gs = 1<<(i-j+1)

		for (unsigned int k = 0; k < tsize; k += gs) {
			for (unsigned int l = 0; l < si; l++) {
				swapcmp(&data[k+l], &data[k-l+gs-1]);
			}
		}
		for (unsigned int j = 1; j <= i; j++) {
			gs >>= 1;
			si >>= 1;

			for (unsigned int k = 0; k < tsize; k += gs) {
				for (unsigned l = 0; l < si; l++) {
					swapcmp(&data[k+l], &data[k+l+si]);
				}
			}
		}
	}
}

void swapcmp(unsigned int* a, unsigned int* b) {
	if (*a > *b) {
		unsigned int buf = *b;
		*b = *a;
		*a = buf;
	}
}
