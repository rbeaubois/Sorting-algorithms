#include "libcSorter.h"

#include <iostream>
#include <stdlib.h>

int intcmp(const void* p1, const void* p2) {
	return (*(const int*) p1 > *(const int*) p2);
}

unsigned int* LibcSorter::sort(unsigned int data[], int len) {
	qsort(data, len, sizeof(int), intcmp);
    return data;
}
