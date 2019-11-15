#include "bubble.h"

unsigned int* Bubble::sort(unsigned int data[], int len) {
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len-i-1; j++) {
            if (data[j] > data[j+1]) {
                unsigned int a = data[j];
                data[j] = data[j+1];
                data[j+1] = a;
            }
        }
    }
    return data;
}
