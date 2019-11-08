#ifndef COMPARATOR_H
#define COMPARATOR_H

#include <iostream>
#include <chrono>
#include <unistd.h>

class Comparator {
private:
    virtual unsigned int* sort(unsigned int data[], int len);
public:
    int process(unsigned int data[], int len);
};

#endif
