#include "quick.h"

#include <iostream>

void sort_recur(unsigned int data[], unsigned int a, unsigned int b) {
    if (b < a || b-a <=1)return;
    unsigned int key = data[a];
    unsigned int ikey = a;
    for(unsigned int i = a+1; i < b; i++) {
        //std::cout << "Quick " << a << " " << b << " " << i << " " << key << " " << ikey << " " << data[i] << std::endl;
        if (data[i] < key) {
            data[ikey] = data[i];
            ikey++;
            data[i] = data[ikey];
        }
    }
    data[ikey] = key;
    sort_recur(data, a, ikey);
    sort_recur(data, ikey+1, b);
}


unsigned int* Quick::sort(unsigned int data[], int len) {
    sort_recur(data, 0, len);
    return data;
}
