#include "comparator.h"

#include <iostream>
#include <chrono>
using namespace std;

// Process sort and check with elasped time calculation
int Comparator::process(unsigned int data[], int len) {
    auto start = chrono::steady_clock::now();
    sort(data, len);
    auto end = chrono::steady_clock::now();
    check(data, len);
    return chrono::duration_cast<chrono::microseconds>(end-start).count();
}

// Check if data are sorted
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