#include "splitter.h"

#include <iostream>
using namespace std;


Splitter::Splitter(unsigned int* med, unsigned int* imed, unsigned int nbr_med) {
    medians = med;
    imedians = imed;
    nbr_median = nbr_med;
}

void sort_recur(unsigned int data[], unsigned int a, unsigned int b, unsigned int medians[], unsigned int imedians[], unsigned int k) {
    if (b < a || b-a <=0)return;
    //std::cout << "Quick " << a << " " << b << std::endl;
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
    for(unsigned int i = 0; i < k; i++) {
        unsigned int imed = imedians[i];
        if (a <= imed && imed <= b) {
            //cout << "Med " << i << " " << imed << endl;
            if (ikey == imed) {
                medians[i] = key;
                //cout << "Med found" << endl;
            } else if (imed < ikey) {
                //cout << "Med -" << endl;
                if (medians[i] == 0) sort_recur(data, a, ikey, medians, imedians, k);
            } else if (imed > ikey) {
                //cout << "Med +" << endl;
                if (medians[i] == 0) sort_recur(data, ikey+1, b, medians, imedians, k);
            }
        }
    }
}

unsigned int* Splitter::sort(unsigned int data[], int len) {
    sort_recur(data, 0, len, medians, imedians, nbr_median);
    return data;
}
