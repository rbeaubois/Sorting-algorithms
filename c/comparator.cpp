#include "comparator.h"

#include <iostream>
#include <chrono>
using namespace std;

int Comparator::process(unsigned int d[], int len) {
    auto start = chrono::steady_clock::now();
    sort(d, len);
    auto end = chrono::steady_clock::now();
    check(d, len);
    return chrono::duration_cast<chrono::microseconds>(end-start).count();
}

void Comparator::check(unsigned int data[], int len) {
    unsigned long nbrE = 0;
    for(int i = 1; i < len; i++) {
        nbrE+=(data[i-1]>data[i]);
        //if(data[i-1]>data[i])cout << i << " " << data[i-1] << " " << data[i] << endl;
    }
    if (nbrE) {
        cout << "Sort error: " << nbrE << " values are not sorted" << endl;
    }
}
