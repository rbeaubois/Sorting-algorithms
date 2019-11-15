#include "../comparator.h"

unsigned int* Bubble::sort(unsigned int data[], int len) {
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len-i-1; j++) {
            if (d[j] > d[j+1]) {
                unsigned int a = d[j];
                d[j] = d[j+1];
                d[j+1] = a;
            }
        }
    }
    return d;
}
